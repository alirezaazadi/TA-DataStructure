## atoi (cstdlib)

Convert string to integer
Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.

The function first discards as many whitespace characters (as in isspace) as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many base-10 digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed and zero is returned.

## stoi (String)

```
int stoi (const string&  str, size_t* idx = 0, int base = 10);
int stoi (const wstring& str, size_t* idx = 0, int base = 10);
```
Convert string to integer
Parses str interpreting its content as an integral number of the specified base, which is returned as an int value.

If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.

The function uses strtol (or wcstol) to perform the conversion (see [strtol](http://www.cplusplus.com/strtol) for more details on the process).

### Parameters
* str :
    * String object with the representation of an integral number.
* idx : 
    * Pointer to an object of type size_t, whose value is set by the function to position of the next character in str after the numerical value.
This parameter can also be a null pointer, in which case it is not used.

* base : 
    * Numerical base (radix) that determines the valid characters and their interpretation.
If this is 0, the base used is determined by the format in the sequence (see strtol for details). Notice that by default this argument is 10, not 0.

## size_t

size_t is the unsigned integer type of the result of sizeof , alignof (since C11) and offsetof, depending on the data model.

* **Notes**
    * size_t can store the maximum size of a theoretically possible object of any type (including array).

    * size_t is commonly used for array indexing and loop counting. Programs that use other types, such as unsigned int, for array indexing may fail on, e.g. 64-bit systems when the index exceeds UINT_MAX or if it relies on 32-bit modular arithmetic.

**read more :**
* [CPP Reference : size_t](https://en.cppreference.com/w/c/types/size_t)
* [C PLUSPLUS : atoi](http://www.cplusplus.com/reference/cstdlib/atoi/)
* [C PLUSPLUS : stoi](http://www.cplusplus.com/reference/string/stoi/)
* [C PLUSPLUS : sstream](http://www.cplusplus.com/reference/sstream/stringstream/)