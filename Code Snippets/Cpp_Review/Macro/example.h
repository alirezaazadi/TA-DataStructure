#ifndef DATASTRUCTURE_EXAMPLE_H
#define DATASTRUCTURE_EXAMPLE_H

#include <iostream>

#define _FUNC_(X, Y) \
while(X > 0){ \
    Y++; \
    X--; \
} \


void multi_line_macro(int x, int y) {
    _FUNC_(x, y);
    std::cout << y << std::endl;
}


#endif //DATASTRUCTURE_EXAMPLE_H
