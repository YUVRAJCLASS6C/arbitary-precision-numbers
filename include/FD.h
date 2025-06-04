#ifndef FD___C___INCLUDE__
#define FD___C___INCLUDE__
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MMAP_DEF__(num) (mmap(NULL,(num),PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,0,0))
#include <stdlib.h>


#endif
