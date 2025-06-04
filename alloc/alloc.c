#include "FD.h"


void *simple_alloc(size_t num){
  void* ptr = MMAP_DEF__(num);
  assert(ptr != (void * )(-1));
}

void simple_free(void* ptr,size_t size){
  int err = munmap(ptr, size);
  assert(err == 0);
}

int get_fd(const char* filepath, int file_flag){
  int fd = -1;
  if (file_flag == 0){
   fd = open(filepath,O_CREAT | O_WRONLY);
  }
  if (file_flag == 1){
   fd = open(filepath,O_APPEND | O_RDONLY); 
  }
  assert(fd != -1);
  return fd;
}
