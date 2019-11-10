#ifndef DATASTRUCTURE_SIMPLE_CLASS_H
#define DATASTRUCTURE_SIMPLE_CLASS_H

class simple{
public:
    int a, b;
    int len;
    int* array = nullptr;

    simple(int &, int &, int*const, int);
};

simple::simple(int & x, int & y, int* input, int l) :
a(x), b(y), len(l){
    this->array = input;
}

#endif //DATASTRUCTURE_SIMPLE_CLASS_H
