//
// Created by Asus on 6/2/2025.
//
#define SIZE__DIS
#include "number.h"
#include "FD.h"
#define u64 size_t
/*
static digit char_to_digit(char n);
static char digit_to_char(digit n);



void reverse(char* str) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left++] = str[right];
        str[right--] = temp;
    }
}

number_* number_SET(char* str){
  number_* num = simple_alloc(sizeof(number_));
  reverse(str);
  reserve_number_(num,strlen(str));
  for (int64_t i = 0; i < strlen(str); i++){
    *(num->list+(i)) = char_to_digit(*(str+(i)));
  }
  reverse(str);
}
void reserve_number_(number_* num,uint64_t n){
  if (num->size >= n){
    return;
  }
  simple_realloc(&(num->list),num->size,n);
  num->size = n;
}
void number_PRINT(number_* num){
  for (uint64_t i = 0; i < num->length; i++){
    printf("%c",digit_to_char(*(num->list+i)));
  }
  printf("\n");
}

static digit char_to_digit(char n){
  return (digit)((int)n );
}
static char digit_to_char(digit n){
  return  ((int)n)+'0';;
}*/
void print_number(number* num) {
    if (num->flag == neg) printf("-");
    for (int64_t i = (num->length - 1); i >= 0; i--) {
        printf("%" PRIu64, (num->list)[i]);
    }
    printf("  :- This has length %"PRIu64 "\n",num->length);
}
void ALLOCATE_number(number* num,u64 size){
    size = ceil(log2((pow(10,size+1) - 1)));
    #ifdef DEBUG
    printf("\nDEBUGGING INFO SIZE = %llu\n",size);
    #endif
    if (num->size >= size){
        return ;
    }
    simple_realloc(&(num->list),num->size*sizeof(uint64_t),size*sizeof(uint64_t));
    num->size = size;
}
void FREE_number(number* num){
    simple_free(num->list,num->size);
    num->length = num->size = 0;
    num->flag = pos;
}

/*
inline void str_2(char* mss){
    
}
static char* str_to_b(const char* mss){
    uint64_t size = strlen(mss);
    uint64_t size2 = ceil((pow(10,size+1) -1 ));
    char* buffer = simple_alloc(size2*sizeof(char));
    return buffer;
}
*/
void set_number(number* num,const char* buffer) {
    trim(buffer);
    ALLOCATE_number(num,strlen(buffer));
    if (strlen(buffer) <= 20){
        num->list[0] = strtoull(buffer,
                             NULL,0);
        num->length = 1;
    }else{
        
    }
}
int bit_to_int(bit num){
    if (num == pos) return 1;
    return 0;
}
char bit_to_char(bit num){
    if (num == pos) return '1';
    return '0';
}
bit int_to_bit(int num){
    if (!(num == 0 | num == 1)){
        int hello = __LINE__;
        fprintf(stderr,"Failed exction at %d\n",hello);
    }
    if (num == 0) return neg;
    return pos;
}
bit char_to_bit(char num){
    return int_to_bit(num + '0'); 
}




#undef u64
