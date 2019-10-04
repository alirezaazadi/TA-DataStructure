#ifndef DATASTRUCTURE_OPERATOR_OVERLOADING_H
#define DATASTRUCTURE_OPERATOR_OVERLOADING_H

#include <string>

using namespace std;

class String {
public:
    String(string const &);

    string base_string;

    String operator+(String const &);
    friend std::ostream &operator<<(std::ostream &, String const &);
};

String String::operator+(String const &second) {
    return String(base_string.append(second.base_string));
}

String::String(string const &str) :
        base_string(str) {

}

std::ostream &operator<<(std::ostream &stream, String const &op) {
    return stream << op.base_string;
}

#endif //DATASTRUCTURE_OPERATOR_OVERLOADING_H
