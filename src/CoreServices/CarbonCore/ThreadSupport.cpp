
#include <pthread.h>
#include <errno.h>
#include "ThreadSupport.h"
#include <libSystem/libc/OSAtomic.h>

int TSInitMutex(TSMutex *mutex, Boolean recursive)
{
	pthread_mutexattr_t attr;

	pthread_mutexattr_init(&attr);
	if (recursive)
	{
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	}
	return pthread_mutex_init(&mutex->_mutex, &attr);
}

int TSDestroyMutex(TSMutex *mutex)
{
	return pthread_mutex_destroy(&mutex->_mutex);
}

int TSTryLockMutex(TSMutex *mutex)
{
	return 0; // TODO
}

int TSLockMutex(TSMutex *mutex, struct timespec *timeout)
{
	if (NULL == timeout)
	{
		return pthread_mutex_lock(&mutex->_mutex);
	}
	else if (0 == pthread_mutex_trylock(&mutex->_mutex))
	{
		return 0;
	}
	else
	{
		struct timespec abs_timeout;

		clock_gettime(CLOCK_REALTIME, &abs_timeout);
		abs_timeout.tv_sec += timeout->tv_sec;
		abs_timeout.tv_nsec += timeout->tv_nsec;
		if (abs_timeout.tv_nsec > 1000000000) 
		{
			abs_timeout.tv_sec++;
			abs_timeout.tv_nsec -= 1000000000;
		}
		
		return pthread_mutex_timedlock(&mutex->_mutex, &abs_timeout);
	}
}

int TSUnlockMutex(TSMutex *mutex)
{
	return pthread_mutex_unlock(&mutex->_mutex);
}

int TSInitCondition(TSCondition *cond)
{
	return pthread_cond_init(&cond->_cond, NULL);
}

int TSDestroyCondition(TSCondition *cond)
{
	return pthread_cond_destroy(&cond->_cond);
}

int TSSignalCondition(TSCondition *cond)
{
	return pthread_cond_signal(&cond->_cond);
}

int TSInitReaderWriterLock(TSReaderWriterLock *rwlock)
{
	int ret = TSInitMutex(&rwlock->_writerLock, false);
	if (0 == ret) ret = TSInitMutex(&rwlock->_condLock, false);
	if (0 == ret) ret = TSInitCondition(&rwlock->_cond);
	rwlock->_flags = 0;
	return ret;
}

int TSDestroyReaderWriterLock(TSReaderWriterLock *rwlock)
{
	int ret = TSAcquireReader(rwlock);
	if (0 == ret) ret = TSReaderToWriter(rwlock);
	if (0 == ret) ret = TSDestroyMutex(&rwlock->_condLock);
	if (0 == ret) ret = TSDestroyCondition(&rwlock->_cond);
	if (0 == ret) ret = TSUnlockMutex(&rwlock->_writerLock);
	if (0 == ret) ret = TSDestroyMutex(&rwlock->_writerLock);
	return ret;
}

#define WRITER_HAS_LOCK   0x80000000
#define WRITER_WAITING    0x40000000
#define FLAGS_MASK        0xC0000000
#define READER_COUNT_MASK 0x3FFFFFFF

int TSAcquireReader(TSReaderWriterLock *rwlock)
{
	while (1)
	{
		SInt32 flags = rwlock->_flags;

		// While there is a writer, wait for the writer to release
		while (flags & WRITER_HAS_LOCK)
		{
			int ret = TSLockMutex(&rwlock->_writerLock, NULL);
			if (0 != ret) return ret;
			TSUnlockMutex(&rwlock->_writerLock);
			flags = rwlock->_flags;
		}

		// Try to increment the reader count, if somebody else gets there first, try again
		if (OSAtomicCompareAndSwap32Barrier(flags, ((flags & FLAGS_MASK) | ((flags & READER_COUNT_MASK) + 1)), &rwlock->_flags)) return 0;
	}
}

int TSReleaseReader(TSReaderWriterLock *rwlock)
{
	SInt32 flags;
	int ret = 0;

	// Try to decrement the reader count until we are successful
	do
	{
		flags = rwlock->_flags;

	} while (!OSAtomicCompareAndSwap32Barrier(flags, ((flags & FLAGS_MASK) | ((flags & READER_COUNT_MASK) - 1)), &rwlock->_flags));

	// If there is a writer waiting, wake it up
	if (flags & WRITER_WAITING)
	{
		ret = TSLockMutex(&rwlock->_condLock, NULL);
		if (0 == ret)
		{
			if ((rwlock->_flags & (WRITER_WAITING | READER_COUNT_MASK)) == WRITER_WAITING)
			{
				ret = TSSignalCondition(&rwlock->_cond);
			}
			TSUnlockMutex(&rwlock->_condLock);
		}
	}

	return ret;
}

int TSReaderToWriter(TSReaderWriterLock *rwlock)
{
	int ret = 0;
	do
	{
		ret = TSTryLockMutex(&rwlock->_writerLock);
		if (0 != ret)
		{
			if (EBUSY != ret)
			{
				return ret;
			}

			// Mutex currently nabbed by somebody else, so hang out for a bit
			// with the reader lock released to avoid deadlocks
			if (0 == TSReleaseReader(rwlock))
			{
				struct timespec sleeptime = {0, 1};
				nanosleep(&sleeptime, NULL);
				TSAcquireReader(rwlock);
			}
		}
	} while (EBUSY == ret);

	// Now that we have acquired the writer lock, 
	return 0; // TODO
}

int TSWriterToReader(TSReaderWriterLock *rwlock)
{
	// Increment the reader count while at the same time clearing the writer flag
	SInt32 flags;
	do
	{
		flags = rwlock->_flags;
	} while (!OSAtomicCompareAndSwap32Barrier(flags, ((flags & WRITER_WAITING) | ((flags & READER_COUNT_MASK) + 1)), &rwlock->_flags));

	// Release the writer mutex
	TSUnlockMutex(&rwlock->_writerLock);
	return 0;
}

