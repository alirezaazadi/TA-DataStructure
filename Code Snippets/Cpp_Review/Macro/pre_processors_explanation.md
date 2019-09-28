#Pre-Processors

**What are pre-processors ?**

Preprocessors are programs that process our source code before compilation
Preprocessor programs provide preprocessors directives which tell the compiler to 
preprocess the source code before compiling. All of these preprocessor directives begin with
a ‘#’ (hash) symbol. This (‘#’) symbol at the beginning of a statement in a C/C++ program
indicates that it is a pre-processor directive. We can place these preprocessor directives anywhere in our program

**Pre-processors like what ?**
* include
* define
* ifndef 
* etc ...

**Pre-processors types** :
1. Macro (**#define**) : 
piece of code in a program which is given some name.
Whenever this name is encountered by the compiler 
the compiler replaces the name with the actual piece of code.

**_look example file_**

2. File inclusion :
    * Header File or Standard files (**#include <...>**)
    * User-defined files (**#include "..."**)
    
3. Conditional compilation (**#ifdef ... #endif**) :
Conditional Compilation directives are type of directives which helps to compile a specific portion of the program or to skip compilation of some specific part of the program based on some conditions.

4. Other directives

For more : [GFG](https://www.geeksforgeeks.org/cc-preprocessors/)
