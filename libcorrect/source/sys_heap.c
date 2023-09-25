#include "sys_heap.h"

void *sysMalloc(size_t size) {
    void * ptr = malloc(size);
    return ptr;
}

void sysFreeMem(void * ptr) {
    free(ptr);
}