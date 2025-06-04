#include "FD.h"


inline void *simple_alloc(size_t num){
  void* ptr = MMAP_DEF__(num);
  assert(ptr != (void * )(-1));
}

inline void simple_free(void* ptr,size_t size){
  int err = munmap(ptr, size);
  assert(err == 0);
}

inline int get_fd(const char* filepath, int file_flag){
  int fd = -1;
  if (file_flag == 0){
   fd = open(filepath,O_CREAT | O_WRONLY);
  }
  if (file_flag == 1){
   fd = open(filepath,O_PATH); 
  }
  assert(fd != -1);
  return fd;
}
