#ifndef FD___C___INCLUDE__
#define FD___C___INCLUDE__
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#if defined(__linux__)
  #include <sys/mman.h>
  #define MMAP_DEF__(num) (mmap(NULL,(num),PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,-1,0))
#else
  #define MMAP_DEF__(num) malloc(num)
#endif
void *simple_alloc(size_t num);
int get_fd(const char* filepath, int file_flag);
void simple_realloc(void** ptr, size_t old_s, size_t new_s);
void simple_free(void* ptr,size_t size);
#endif
