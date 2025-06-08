//
// Created by Asus on 6/2/2025.
//
#define SIZE__DIS
#include "number.h"
#define u64 size_t
void print_number(number* num) {
    if (num->flag == neg) printf("-");
    for (size_t i = 0; i < num->length; i++) {
        printf("%lu ", (num->list)[i]);
    }
}
void ALLOCATE_number(number* num,u64 size){
    size = ceil(log2((pow(10,size+1) - 1)));
    if (num->size >= size){
        return ;
    }
    num->list = realloc((num->list),size);
    num->size = size;
}
void trim(char *str) {
    // Trim leading space
    char *start = str;
    while (isspace((unsigned char)*start)) start++;

    // Trim trailing space
    char *end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Move trimmed string to the original pointer
    memmove(str, start, strlen(start) + 1);
}
void set_number(number* num,const char* buffer) {
    trim(buffer);
    ALLOCATE_number(num,strlen(buffer));
    if (strlen(buffer) <= 20){
        num->list[0] = strtoull(buffer,
                             NULL,0);
        num->length = 1;

    }else{
        printf("Not implemented\n");
            exit(1);
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
