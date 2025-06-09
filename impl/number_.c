#include "number.h"
#include "FD.h"




static void add_d(digit a, digit b, digit c, digit * sum, digit * carry){
  uint8_t info = (int)a + (int)b + (int)c ;
  *sum = (digit)(info % 10);
  *carry = (digit)((info - (*sum))/10);
}
static digit char_to_d(char c){
  return (digit)(c - '0');
}
static char digit_to_c(digit d){
  return (((int)d)+'0');
}
Number * Number_SET(char* str){
  trim(str);
  Number * num = simple_alloc(sizeof(Number));
  num->list = NULL;
  num->length = 0;
  num->size = 0;
  num->flag = pos;
  Number_r(num,strlen(str)+1);
  for (uint64_t i = 0; i < strlen(str);i++){
    num->list[i] = char_to_d(str[strlen(str) -(i+1)]);
    num->size++;
  }
  return num;
}
Number Number_SET2(char* str){
  trim(str);
  Number num;
  num.list = NULL;
  num.length = 0;
  num.size = 0;
  num.flag = pos;
  Number_r(&num,strlen(str)+1);
  for (uint64_t i = 0; i < strlen(str);i++){
    num.list[i] = char_to_d(str[strlen(str) - (i+1)]);
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
    printf("%c",digit_to_c(num->list[num->size - (i+1)]));
  }
  printf("\n");
}
static Number Mul_by_d(const Number * a,const uint8_t c){
  uint8_t iter = c;
  Number num = {0};
  Number_r(&num,a->length+1);
  for (int8_t i = 0; i < iter; i++){
    num = Number_ADD2(&num,a);
  }
  return num;
}
static void Mul_10(Number * a){
  digit * ptr = (digit*)simple_alloc((a->size +1)*sizeof(digit));
  memcpy(ptr+1,a->list,a->size);
  simple_free(a->list,a->length);
  a->list = ptr;
  a->size++;
}
static void Mul_10_n(Number * a, uint8_t n){
  for (uint8_t i = 0; i < n;i++){
    Mul_10(a);
  }
}
Number Number_Mul2(Number * a, Number * b){
  Number r = NULL_number_;
  /*
  if (a->size < b->size){
    return Number_Mul2(b,a);
  }
  */
  for (uint64_t i = 0; i < b->size; i++){
    Number val = Mul_by_d(a,((int)(b->list[i])));
    Mul_10_n(&val,i);
    r = Number_ADD2(&r,&val);
  }
  return r;
}
Number * Number_Mul(Number * a, Number * b){
  Number * r = (Number *)simple_alloc(sizeof(Number));
  /*
  if (a->size < b->size){
    return Number_Mul2(b,a);
  }
  */
  for (uint64_t i = 0; i < b->size; i++){
    Number val = Mul_by_d(a,((int)(b->list[i])));
    Mul_10_n(&val,i);
    *r = Number_ADD2(r,&val);
  }
  return r;
}
Number Number_ADD2(Number * a, Number * b){
  Number r = NULL_number_;
  if (a->size >= b->size){
    Number_r(&r,a->length +1);
    Number_r(b,a->length);
    digit sum = zero;
    digit carry = zero; 
    uint64_t i;
    for (i = 0; i < a->size; i++){
      add_d(a->list[i],b->list[i],carry,&sum,&carry);
      r.list[i] = sum;
    }
    r.size = carry == 0 ? a->size: a->size +1;
    r.list[a->size] = carry;
    return r;
  }
  return Number_ADD2(b,a);
}
Number * Number_ADD(Number * a, Number * b){
  Number* r = simple_alloc(sizeof(Number));
  if (a->size >= b->size){
    Number_r(r,a->length +1);
    Number_r(b,a->length);
    digit sum = zero;
    digit carry = zero; 
    uint64_t i;
    for (i = 0; i < a->size; i++){
      add_d(a->list[i],b->list[i],carry,&sum,&carry);
      r->list[i] = sum;
    }
    r->size = carry == 0 ? a->size: a->size +1;
    r->list[a->size] = carry;
    return r;
  }
  return Number_ADD(b,a);
}

