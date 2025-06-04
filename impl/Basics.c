//
// Created by Asus on 6/2/2025.
//
#define SIZE__DIS
#include "number.h"
#include "FD.h"
#define u64 size_t
void print(number* num) {
    if (num->flag == neg) printf("-");
    for (size_t i = 0; i < num->length; i++) {
        printf("%lu ", (num->list)[i]);
    }
}
void set(number* num,const char* buffer) {
    char* filtered_buff = (char*)simple_alloc(strlen(buffer));
    for (u64 i = 0; i < strlen(buffer); i++){
        if (buffer[i] == '\0') continue;
        filtered_buff += buffer[i];
    }
    simple_free(filtered_buff,strlen(buffer));
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
    assert(num == 0 | num == 1);
    if (num == 0) return neg;
    return pos;
}
bit char_to_bit(char num){
    return int_to_bit(num + '0'); 
}




#undef u64
