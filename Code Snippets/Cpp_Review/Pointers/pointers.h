#ifndef DATASTRUCTURE_POINTERS_H
#define DATASTRUCTURE_POINTERS_H

#include <iostream>
#include "simple_class.h"

using namespace std;

int* return_array(int len){
    int* array = new int[len];
    for (int i = 0; i < len; ++i)
        array[i] = i;
    return array;
}

int get_array(int* array, int len){
    long long int re = 0;
    for (int i = 0; i < len; ++i)
        re += array[i];
    return re;
}

void pointer_and_reference(){
    int x_var = 10;
    int y_var = 20;

    int* a_ptr = &x_var;
    cout << "a_ptr value is :" << a_ptr << endl;
    cout << "and the value of above address is : " << *a_ptr <<
    " = x_var" << endl;
    cout << "==================" <<endl;
    int& b_ref = y_var;
    cout << "b_ref value is : " << b_ref << " = y_var"<< endl;
    cout << "b_ref address is : " << &b_ref << " = y_var address ("<< &y_var << ")" << endl;
}

void swap_two_pointers(simple* first, simple* second){
    cout << "Before swap : \n" << "first : a = " << first->a << " b = "
    << first->b << endl;
    cout << "first array:" << endl;
    for (int i = 0; i < first->len; ++i) {
        cout << first->array[i] << " ";
    }
    cout << endl;
    std::cout << "==============" << std::endl;
    cout << "second : a = " << second->a << " b = "
         << second->b << endl;
    cout << "second array:" << endl;
    for (int i = 0; i < first->len; ++i) {
        cout << second->array[i] << " ";
    }
    cout << endl;
    std::cout << "==============" << std::endl;

    simple* temp = first;
    first = second;
    second = temp;

    cout << "After swap : \n" << "first : a = " << first->a << " b = "
         << first->b << endl;
    cout << "first array:" << endl;
    for (int i = 0; i < first->len; ++i) {
        cout << first->array[i] << " ";
    }
    cout << endl;
    std::cout << "==============" << std::endl;
    cout << "second : a = " << second->a << " b = "
         << second->b << endl;
    cout << "second array:" << endl;
    for (int i = 0; i < first->len; ++i) {
        cout << second->array[i] << " ";
    }
    cout << endl;
    std::cout << "==============" << std::endl;

}

#endif //DATASTRUCTURE_POINTERS_H
