#include <iostream>
#include "OOP/general.h"
#include "Macro/example.h"
#include "PassingTypes/passing_types.h"
#include "Pointers/pointers.h"
#include "Pointers/simple_class.h"

void test_my_math();

void test_macro();

void test_passing_types();


void test_pointers();

int main() {
//    test_my_math();
//    test_macro();
//test_passing_types();
//    test_pointers();
    return 0;
}

void test_pointers() {
//    pointer_and_reference();
    int *arr_1 = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr_1[i] = i;
    }

    int *arr_2 = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr_2[i] = -i;
    }
    int a = 1, b = 2, c = 3, d = 4;
    simple *f = new simple(a, b, arr_1, 10);
    simple *s = new simple(c, d, arr_2, 10);

    swap_two_pointers(f, s);
}

void test_passing_types() {
    int x = 10;
    int y = 20;
    std::cout << "Before Swap : \n" << "x = " << x << " y = " << y << std::endl;
    std::cout << "==============" << std::endl;
//    passing_by_value(x, y);
//    passing_by_reference(x, y);
    passing_by_pointer(&x, &y);
    std::cout << "==============" << std::endl;
    std::cout << "After Swap : \n" << "x = " << x << " y = " << y << std::endl;


}

void test_macro() {
    multi_line_macro(5, 0);
}

void test_my_math() {
    std::cout << "INT" << std::endl;
    my_math<int> test;
    try {
        std::cout << test.division(4, 0) << std::endl;
    } catch (std::overflow_error &e) {
        std::cout << e.what() << std::endl;
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
    std::cout << test.diff_all() << std::endl;
    int *arr_ = new int[5];
    arr_[0] = 10;
    arr_[1] = 20;
    arr_[2] = 30;
    std::cout << test.diff_all(arr_, 3);
}
