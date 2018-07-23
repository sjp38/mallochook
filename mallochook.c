#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>

typedef void *(*malloc_t)(size_t size);
typedef void (*free_t)(void *ptr);

void *malloc(size_t size)
{
	malloc_t malloc_fn;

	fprintf(stderr, "malloc(%zu) hooked\n", size);
	malloc_fn = (malloc_t)dlsym(RTLD_NEXT, "malloc");
	return malloc_fn(size);
}

void free(void *ptr)
{
	free_t free_fn;

	fprintf(stderr, "free(%p) hooked\n", ptr);
	free_fn = (free_t)dlsym(RTLD_NEXT, "free");
	free_fn(ptr);

	return;
}
