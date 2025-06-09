//
// Created by Asus on 6/2/2025.
//
#include "number.h"
int main(){
    Number m = {.list = NULL, .size = 0, .length = 0, .flag = pos};
    char buffer[] =  "874380";
    m = *(Number_SET(buffer));
    Number_PRINT(&m);    

    return 0;
}


