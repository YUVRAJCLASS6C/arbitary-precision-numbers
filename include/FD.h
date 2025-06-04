#ifndef FD___C___INCLUDE__
#define FD___C___INCLUDE__
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MMAP_DEF__(num) (mmap(NULL,(num),PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,0,0))
#include <stdlib.h>

inline void *simple_alloc(size_t num);
inline int get_fd(const char* filepath, int file_flag);
inline void simple_free(void* ptr,size_t size);
#endif
