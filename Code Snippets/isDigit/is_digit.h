#ifndef DATASTRUCTURE_IS_DIGIT_H
#define DATASTRUCTURE_IS_DIGIT_H

#include <string>
#include <algorithm>

class number_evaluate {
public:
    number_evaluate(std::string const);

    bool is_digit_method_1(void) const;

    bool is_digit_method_2(void) const;

private:
    std::string number = "";
};

bool number_evaluate::is_digit_method_1(void) const {
    //work for both negative and positive integers (without positive sign)

    if (!number.find_first_of('-')) // check if the first element of string not to be - (for negetive number)
       return all_of(number.begin() + 1, number.end(), ::isdigit);
    else
        return all_of(number.begin(), number.end(), ::isdigit);// all of them are  digits or not
}

bool number_evaluate::is_digit_method_2(void) const {
    //only for positive integers (without sign)

    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] < 48 || number[i] > 57)
            return false;
    }
    return true;
}

number_evaluate::number_evaluate(std::string const input) :
        number(input) {}

#endif //DATASTRUCTURE_IS_DIGIT_H
