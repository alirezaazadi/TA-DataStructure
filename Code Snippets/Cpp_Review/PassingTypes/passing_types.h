#ifndef DATASTRUCTURE_PASSING_TYPES_H
#define DATASTRUCTURE_PASSING_TYPES_H

#include <iostream>

void passing_by_value(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    std::cout<<"In function :"<<std::endl;
    std::cout<<"x = " << a << " y = " << b << std::endl;
}

void passing_by_reference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    std::cout<<"In function :"<<std::endl;
    std::cout<<"x = " << a << " y = " << b << std::endl;
}

void passing_by_pointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    std::cout<<"In function :"<<std::endl;
    std::cout<<"x = " << *a << " y = " << *b << std::endl;
}
#endif //DATASTRUCTURE_PASSING_TYPES_H
