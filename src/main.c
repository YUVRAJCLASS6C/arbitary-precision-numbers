//
// Created by Asus on 6/2/2025.
//
#include "number.h"
int main(){
    number m = {.list = NULL, .size = 0, .length = 0, .flag = pos};
    char buffer[] =  "874380";
    set_number(&m,buffer);
    print_number(&m);
    return 0;
}


