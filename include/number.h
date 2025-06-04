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

#define SIZE sizeof(uint64_t)
#define part uint64_t
typedef enum{
    neg,
    pos
} bit;
inline int bit_to_int(bit);
inline char bit_to_char(bit);
inline bit int_to_bit(int);
inline bit char_to_bit(char);


typedef struct number {
    part* list;
    uint64_t size;
    uint64_t length;
    bit flag;
} number;
typedef struct numberpp {
    number num;
    void (*print)(number);
} numbercpp;

typedef struct number_EXTRABIG {
    FILE* fp;
} number_EXTRABIG;

inline void set(number* num,const char* buffer);
inline void print(number* num);


#ifndef SIZE__DIS
#undef SIZE


#define SIZE__DIS
#endif


#endif //NUMBER_HPP
