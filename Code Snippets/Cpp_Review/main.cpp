#include <iostream>
#include "OOP/general.h"
#include "Macro/example.h"

void test_my_math();
void test_macro();

int main() {
//    test_my_math();
    test_macro();
    return 0;
}

void test_macro() {

    multi_line_macro* testMacro = new multi_line_macro();
    testMacro->test();
}

void test_my_math() {
    std::cout << "INT" << std::endl;
    my_math<int> test;
    try{
        std::cout << test.division(4, 0) << std::endl;
    }catch (std::overflow_error &e){
        std::cout<< e.what() << std::endl;
    }
    std::cout << test.add(4, 4) << std::endl;
    std::cout << test.multiply(4, 3) << std::endl;
    test.add_num(1);
    test.add_num(2);
    test.add_num(3);
    test.add_num(4);
    test.add_num(5);
    test.add_num(6);
    test.add_num(7);
    test.add_num(8);
    test.add_num(9);
    std::cout<< test.diff_all() << std::endl;
    int* arr_ = new int[5];
    arr_[0] = 10;
    arr_[1] = 20;
    arr_[2] = 30;
    std::cout<< test.diff_all(arr_, 3);
}
