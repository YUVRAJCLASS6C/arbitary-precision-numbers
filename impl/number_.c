#include "number.h"
static digit char_to_d(char c){
  return (digit)(c - '0');
}
static char digit_to_c(digit d){
  return (((int)d)+'0');
}
Number * Number_SET(char* str){
  Number num = NULL_number_;
  Number_r(&num,strlen(str)+1);
  for (uint64_t i = 0; i < strlen(str);i++){
    num.list[i] = char_to_d(str[i]);
    num.size++;
  }
  return &num;
}
Number Number_SET2(char* str){
  Number num = NULL_number_;
  Number_r(&num,strlen(str)+1);
  for (uint64_t i = 0; i < strlen(str);i++){
    num.list[i] = char_to_d(str[i]);
    num.size++;
  }
  return num;
}
void Number_r(number_* num,uint64_t n){
  if (num->length >= n){
    return;
  }
  else {
    simple_realloc(&(num->list),num->length,n);
    num->length = n;
  }
}
void Number_PRINT(number_* num){
  for (uint64_t i = 0; i < num->size; i++){
    printf("%c",digit_to_c(num->list[i]));
  }
  printf("\n");
}

