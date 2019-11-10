#ifndef EVAL_STRING_UTILITY_H
#define EVAL_STRING_UTILITY_H

#include <string>
#include <sstream>

class String {
private:
    std::string base_str = "";

public:
    int last_index = 0;

    String(const std::string &);

    std::string *split(const char &delimiter = ' ');

};

std::string *String::split(const char &delimiter) {
    std::string *str_array = new std::string[this->base_str.length()];

    std::istringstream stream(this->base_str);
    std::string token;


    for (this->last_index = 0; getline(stream, token, delimiter); this->last_index++)
        str_array[last_index] = token;


    std::string *last_array = new std::string[this->last_index];

    std::copy(str_array + 0, str_array + last_index, last_array);

    return last_array;
}

String::String(const std::string &input) :
        base_str(input) {}

#endif //EVAL_STRING_UTILITY_H
