
#include <pthread.h>
#include <time.h>
#include <CoreServices/MacTypes.h>

extern "C" {

/* Mutexes */
typedef struct
{
	pthread_mutex_t _mutex;
} TSMutex;

extern int TSInitMutex(TSMutex *mutex, Boolean recursive);
extern int TSDestroyMutex(TSMutex *mutex);
extern int TSTryLockMutex(TSMutex *mutex);
extern int TSLockMutex(TSMutex *mutex, struct timespec *timeout);
extern int TSUnlockMutex(TSMutex *mutex);

/* Conditions */
typedef struct
{
	pthread_cond_t _cond;
} TSCondition;

extern int TSInitCondition(TSCondition *cond);
extern int TSDestroyCondition(TSCondition *cond);

/* RW Locks */
typedef struct
{
	TSMutex         _writerLock;
	TSMutex         _condLock;
	TSCondition     _cond;
	volatile SInt32 _flags;
} TSReaderWriterLock;

extern int TSInitReaderWriterLock(TSReaderWriterLock *rwlock);
extern int TSDestroyReaderWriterLock(TSReaderWriterLock *rwlock);
extern int TSAcquireReader(TSReaderWriterLock *rwlock);
extern int TSReleaseReader(TSReaderWriterLock *rwlock);
extern int TSReaderToWriter(TSReaderWriterLock *rwlock);
extern int TSWriterToReader(TSReaderWriterLock *rwlock);

} // extern "C"
