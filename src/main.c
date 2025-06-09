//
// Created by Asus on 6/2/2025.
//
#include "number.h"
int main(){
    char buffer3[] = "108508050270950129";
    char buffer[] =  "18031983498838813488348341884318348431840189713484";
    Number m = Number_SET2(buffer3);
    Number_PRINT(&m);    
    char buffer2[] =  "10081438";
    Number m2 = Number_SET2(buffer);
    Number_PRINT(&m2);
    Number * m3 = Number_Mul(&m2,&m);
    Number_PRINT(m3);
    return 0;
}


