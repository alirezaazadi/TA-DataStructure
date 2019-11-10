# C++ Pointer


### "Regular" variables (not pointers)

To understand a pointer, let's review "regular" variables first. If you're familiar with a programming language without pointers like JavaScript, this is what you think when you hear "variable".

When declaring a variable by identifier (or name), the variable is synonymous with its value. 
 
 ```c++
int number = 3;
std::cout << "number is initialized with a value of " << number << "\n";
// Outputs: number is initialized with a value of 3
 ```

The value of the variable can be modified directly.

```c++
number++;
number = number * 2;
std::cout << "After modifying number, its value is now " << number << "\n";
// Outputs: After modifying number, its value is now 8
```

Every value lives at memory addresses. The memory address of a variable can be accessed using the `&` operator.

```c++
std::cout << "The number variable's value lives at memory address " << &number << "\n";
```

### What is a pointer?

A pointer is a variable that holds a memory address where a value lives. [ need a super brief description of why pointers are useful here ]

### Declare an empty pointer variable

A pointer is a variable that holds a memory address where a value lives.

A pointer is declared using the `*` operator before an identifier.

As C++ is a statically typed language, the type is required to declare a pointer. This is the type of data that will live at the memory address it points to.

```c++
int *numberPointer;
std::cout << "The numberPointer points to the memory address " << numberPointer << ".\n";
// Outputs: The numberPointer points to the memory address 0x0
```

We've initialized a pointer, but it points nowhere, it has no memory address. **Note that `0x0` is equivalent to `0`. It's just the hexadecimal representation of `0`, which memory addresses are expressed in**. 

### Set a pointer's memory address
We can set the memory address the pointer points to using the memory address of the `number` variable.

The memory address of any variable can be accessed using the `&` operator.

```c++
numberPointer = &number;
std::cout << "The numberPointer points to the memory address `" << numberPointer << "`, which is the memory address of number\n";
// Outputs: The numberPointer points to the memory address 0x1001054a0
// NOTE: if you run this code, you will get a different memory address.
```

### Declare a pointer while assigning its address a value

When declaring a pointer, we can alternatively instantiate a variable at its memory address. 

```c++
int *numberPointer = new int(3);
```

Instantiating a variable with the new operator **always** returns a pointer.

### Access and modify the value at a pointer's memory address

The value at the memory address pointed to can be accessed with the dereference operator, `*`.

```c++
*numberPointer = 4;
std::cout << "The variable's value has been modified using the pointer. The variable's value is now " << number << "\n";
// Outputs: The variable's value has been modified using the pointer. The variable's value is now 4
```

### The syntactical meaning of the `*` operator is confusing

We've shown that the asterisk operator `*` has two semantic meanings: to declare a pointer variable (i.e. `int *numberPointer`) and also to access the value a pointer points to (`*numberPointer = 4`). This is confusing but just part of the syntax we need to internalize.

### Why use pointers?

In C++, variables are passed to a function by value. When calling a function with an argument, a new variable is instantiated internally and assigned the value passed in the function call. 

Any modifications to the value inside the function are performed to this new variable; the variable that was invoked with the function call is unchanged.

```c++
void setValueToFive(int x)
{
    std::cout << &x << "\n";
    x = 5;
}

int x = 3;
setValueToFive( x );
std::cout << "The value of x is " << x << ", setValueToFive() did not modify x.\n";
// Outputs: The value of x is 3, setValueToFive() did not modify x
```

A function can be written to perform the same task but instead accept a pointer as the argument. This lowers the memory footprint of the program. Unnecessary duplicate variables aren't created. The function can modify the variable's value directly. Any modifications to the variable in the function affect the variable here in this scope too.

```c++
void setPointerValueToFive(int *x)
{
    *x = 5;
}

int x = 3;
setPointerValueToFive( &x );
std::cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
// Outputs: The value of x is 5, setPointerValueToFive() modified x
```

In C++ (not in C), you can pass a variable by reference by passing in a variable,
and defining the function's parameter like `int &x`. Any modifications to the variable inside the function will also affect the variable here in this scope too.

```c++
void setValueToFiveWithReference(int& x)
{
    x = 5;
}

int x = 3;
setValueToFiveWithReference( x );
std::cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
// Outputs: The value of x is 5, setPointerValueToFive() modified x
```

Which to use is a matter of style, and whether you want to perform pointer arithmetic in the function.
Google has [specific guidelines](https://google.github.io/styleguide/cppguide.html#Reference_Arguments) for which to use where.

The pointer is a variable in itself, and all variables are stored somewhere in memory.

We can see the memory address the pointer's memory address is stored.

(End of Section 1 : [ref](https://gist.github.com/ericandrewlewis/720c374c29bbafadedc9))

## Difference Between Pointer Values and Reference Values

References are generally implemented using pointers. **A reference is same object**, just with a different name and reference must refer to an object.
Since **references can’t be NULL**, they are safer to use.

* A pointer can be re-assigned while reference cannot.

* Pointers can iterate over an array, we can use ++ to go to the next item that a pointer is pointing to.

* A pointer is **a variable that holds a memory address**. A reference has the **same memory address** as the item it references.

* A pointer to a class/struct uses ‘->'(arrow operator) to access it’s members whereas a reference uses a ‘.'(dot operator)

* A pointer needs to be dereference with * to access the memory location it points to, whereas a reference can be used directly : 

```
int a = 20;
int* a_ptr = &a // a_ptr = 0x7ffe03823bc0 and *a_pt = 20
int& a_ref = a // a_ref = 20 and &a_ref = &a = 0x7ffe03823bc4
```

(End of section 2 [ref](https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/))

Is ``int* p;'' right or is ``int *p;'' right?
Both are "right" in the sense that both are valid C and C++ and both have exactly the same meaning. As far as the language definitions and the compilers are concerned we could just as well say ``int*p;'' or ``int * p;''
The choice between ``int* p;'' and ``int *p;'' is not about right and wrong, but about style and emphasis. C emphasized expressions; declarations were often considered little more than a necessary evil. C++, on the other hand, has a heavy emphasis on types.

A ``typical C programmer'' writes ``int *p;'' and explains it ``*p is what is the int'' emphasizing syntax, and may point to the C (and C++) declaration grammar to argue for the correctness of the style. Indeed, the * binds to the name p in the grammar.

A ``typical C++ programmer'' writes ``int* p;'' and explains it ``p is a pointer to an int'' emphasizing type. Indeed the type of p is int*. I clearly prefer that emphasis and see it as important for using the more advanced parts of C++ well.

The critical confusion comes (only) when people try to declare several pointers with a single declaration:

	int* p, p1;	// probable error: p1 is not an int*
Placing the * closer to the name does not make this kind of error significantly less likely.
	int *p, p1;	// probable error?
Declaring one name per declaration minimizes the problem - in particular when we initialize the variables. People are far less likely to write:
	int* p = &i;
	int p1 = p;	// error: int initialized by int*
And if they do, the compiler will complain.
Whenever something can be done in two ways, someone will be confused. Whenever something is a matter of taste, discussions can drag on forever. Stick to one pointer per declaration and always initialize variables and the source of confusion disappears.

(End of section three [ref](http://www.stroustrup.com/bs_faq2.html))

To learn more about pointers, reading these links are useful :
* [cplusplus/pointers](http://www.cplusplus.com/doc/tutorial/pointers/)
* [microsoft/smart-pointers](https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019)
