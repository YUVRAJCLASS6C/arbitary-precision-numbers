//
// Created by Asus on 6/2/2025.
//
#include "number.h"
int main(){
    char buffer[] =  "18031983498838813488348341884318348431840189713484";
    Number m = Number_SET2(buffer);
    Number_PRINT(&m);    
    char buffer2[] =  "10081438734181348314834181383479834834874837819000";
    Number m2 = Number_SET2(buffer2);
    Number_PRINT(&m2);
    Number m3 = Number_ADD2(&m2,&m);
    Number_PRINT(&m3);
    return 0;
}


