#ifndef DATASTRUCTURE_EXAMPLE_H
#define DATASTRUCTURE_EXAMPLE_H

#define _FUNC_(X, Y) \
while(X > 0){ \
    Y++; \
    X--; \
} \

#include <iostream>

using namespace std;

class multi_line_macro {
private:
    int x, y;
public:
    multi_line_macro() :
            x(5), y(0) {}

    void test() {
        _FUNC_(x, y);
        cout << y;
    }
};

#endif //DATASTRUCTURE_EXAMPLE_H
