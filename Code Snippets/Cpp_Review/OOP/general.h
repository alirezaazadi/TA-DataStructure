//
// Created by alireza on 9/26/19.
//

#ifndef DATASTRUCTURE_GENERAL_H
#define DATASTRUCTURE_GENERAL_H

#define _MULTIPLY_(X, Y) X * Y
#define _ADD_(X, Y) X + Y
#define _DIVIDE_(X, Y) X / Y
#define MAX_LENGTH 1000

#include <iostream>
#include <exception>
class test{

};
template<class generic>
class my_math {
private:
//    generic inputs[MAX_LENGTH];
    int array_index;
    const int a = 10;
    generic *inputs = nullptr;

public:
    my_math(); //empty constructor
    ~my_math(); //destructor

    generic add(generic const &, generic const &) const;

    generic division(generic const &, generic const &) const;

    generic diff_all(void) const;

    generic diff_all(generic *const, int const &) const;

    void add_num(generic const &);

    void clear_all(void);

    generic multiply(generic const &first, generic const &second) const {
        return _MULTIPLY_(first, second);
    }
    friend class test;
};


template<class generic>
void my_math<generic>::add_num(const generic &number) {
    this->inputs[this->array_index] = number;
    this->array_index++;
}

template<class generic>
void my_math<generic>::clear_all(void) {
    for (int i = 0; i < this->array_index; ++i)
        this->inputs[i] = 0;

    return;
}

template<class generic>
generic my_math<generic>::add(const generic &first, const generic &second) const {
    return _ADD_(first, second);
}

template<class generic>
generic my_math<generic>::division(const generic &first, const generic &second) const {
    if (second == 0)
        throw std::overflow_error("Division by 0 is invalid");
    return _DIVIDE_(first, second);
}

template<class generic>
generic my_math<generic>::diff_all(void) const {
    int sign_ = 1;
    generic re_ = 0;
    for (int i = 0; i < this->array_index; i++) {
        re_ += sign_ * this->inputs[i];
        sign_ = -1 * sign_;
    }

    return re_;
}

template<class generic>
generic my_math<generic>::diff_all(generic *const numbers, int const &len) const {

    int sign_ = 1;
    generic re_ = 0;

    for (int i = 0; i < len; i++) {
        re_ += sign_ * numbers[i];
        sign_ = -1 * sign_;
    }

    return re_;
}

template<class generic>
my_math<generic>::my_math() :
        array_index(0) {
//    inputs = {};
    inputs = new generic[MAX_LENGTH];

}

template<class generic>
my_math<generic>::~my_math() {
    delete[] inputs;
//    delete[] inputs;
}

#endif //DATASTRUCTURE_GENERAL_H
