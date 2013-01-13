#ifndef LIBC_MALLOC_ZONE_H
#define LIBC_MALLOC_ZONE_H
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t malloc_zone_t;
typedef uintptr_t vm_size_t;

struct __darwin_malloc_statistics_t
{
	unsigned blocks_in_use;
	size_t size_in_use;
	size_t max_size_in_use;
	size_t size_allocated;
};


extern "C" {

malloc_zone_t* malloc_create_zone(vm_size_t start_size, unsigned flags);
void malloc_destroy_zone(malloc_zone_t *zone);
malloc_zone_t* malloc_default_zone();
malloc_zone_t* malloc_zone_from_ptr(const void *ptr);
void* malloc_zone_malloc(malloc_zone_t *zone, size_t size);
void* malloc_zone_calloc(malloc_zone_t *zone, size_t num_items, size_t size);
void* malloc_zone_valloc(malloc_zone_t *zone, size_t size);
void* malloc_zone_realloc(malloc_zone_t *zone, void *ptr, size_t size);
void* malloc_zone_memalign(malloc_zone_t *zone, size_t alignment, size_t size);
void malloc_zone_free(malloc_zone_t *zone, void *ptr);
void malloc_set_zone_name(malloc_zone_t *zone, const char *name);
const char *malloc_get_zone_name(malloc_zone_t *zone);

void malloc_zone_statistics(malloc_zone_t* zone, __darwin_malloc_statistics_t* stats);

// Collectable object functions
typedef malloc_zone_t auto_zone_t;
typedef int auto_memory_type_t;
typedef bool boolean_t;

auto_zone_t *objc_collectableZone(void);
void* auto_zone_allocate_object(auto_zone_t *zone, size_t size, auto_memory_type_t type, boolean_t initial_refcount_to_one, boolean_t clear);

typedef struct auto_weak_callback_block {
	struct auto_weak_callback_block *next;
	void (*callback_function)(void *arg1, void *arg2);
	void *arg1;
	void *arg2;
} auto_weak_callback_block_t;

void auto_assign_weak_reference(auto_zone_t *zone, const void *value, void *const*location, auto_weak_callback_block_t *block);

}

#endif

