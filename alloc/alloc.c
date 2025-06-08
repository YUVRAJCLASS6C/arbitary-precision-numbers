#include "FD.h"
#include <string.h>

void *simple_alloc(size_t num){
  void* ptr = MMAP_DEF__(num);
  if (!(ptr != MAP_FAILED)){
    fprintf(stderr, "Failed excution at %d\n",__LINE__);
  }
  return ptr;
}

void simple_free(void* ptr,size_t size){
  int err = munmap(ptr, size);
  if (err == -1){
    int hello = __LINE__;
    fprintf(stderr,"Failed exction at %d\n",hello);
  }
}
void simple_realloc(void** ptr, size_t old_s, size_t new_s){
  void* n_ptr = simple_alloc(new_s);
  memcpy(n_ptr,*ptr,old_s);
  simple_free(*ptr,old_s);
  *ptr = n_ptr;
}
int get_fd(const char* filepath, int file_flag){
  int fd = -1;
  if (file_flag == 0){
   fd = open(filepath,O_CREAT | O_WRONLY);
  }
  if (file_flag == 1){
   fd = open(filepath,O_RDWR |O_APPEND ); 
  }
  if (!(fd != -1)){
    int hello = __LINE__;
    fprintf(stderr,"Failed exction at %d\n",hello);
  }
  return fd;
}
