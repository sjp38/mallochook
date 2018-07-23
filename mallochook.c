#include <stdio.h>

void *malloc(size_t size)
{
	fprintf(stderr, "malloc(%zu) hooked\n", size);

	return NULL;
}

void free(void *ptr)
{
	fprintf(stderr, "free(%p) hooked\n", ptr);
	return;
}
