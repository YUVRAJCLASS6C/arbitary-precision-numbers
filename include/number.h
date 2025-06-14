//
// Created by Asus on 6/2/2025.
//

#ifndef NUMBER_H_INCLUDE
#define NUMBER_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#define SIZE sizeof(uint64_t)
#define part uint64_t
typedef enum{
    neg,
    pos
} bit;
int bit_to_int(bit);
char bit_to_char(bit);
bit int_to_bit(int);
bit char_to_bit(char);

typedef enum {
    zero = 0,
    one = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9
} digit;
typedef struct number_ {
    digit* list;
    uint64_t size;
    uint64_t length;
    bit flag;
} number_;
#define Number number_
typedef struct number {
    part* list;
    uint64_t size;
    uint64_t length;
    bit flag;
} number;
typedef struct numberpp {
    number num;
    void (*print)(number);
} numberpp;

typedef struct number_EXTRABIG {
    FILE* fp;
} number_EXTRABIG;
#define NULL_number_ ((Number){.list = NULL, .length = 0, .size = 0,.flag = pos})
void set_number(number* num,const char* buffer);
void print_number(number* num);

Number * Number_SET(char* str);
Number Number_SET2(char* str);
void Number_r(number_* num,uint64_t n);
void Number_PRINT(number_* num);
#ifndef SIZE__DIS
#undef SIZE


#define SIZE__DIS
#endif


#endif //NUMBER_HPP
