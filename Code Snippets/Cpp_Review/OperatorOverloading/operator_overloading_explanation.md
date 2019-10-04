# Operator Overloading 

Operator overloading: define new functionality for an operator for user-defined classes.
_This means_ C++ can provide the operators with a special meaning for a data type, this ability is known as operator overloading.


The most common example is the "+" operator in the string.
by "+" operator, you can append to string to each other exactly like Concat function. 

it means "+" is like a function, it returns something (in here, string) and it takes parameters(in here a string)

look at this example :
```
String String::operator+(String const &second) {
    return String(base_string.append(second.base_string));
}
```

in the above example, we defined a new functionality and new define for 
(user-defined) String class, so it takes another String object
and in the function, we call the append method and return a new object from the String class.


### Why can't I overload dot, ::, sizeof, etc.? 
[Ref](http://www.stroustrup.com/bs_faq2.html#overload-dot)
Most operators can be overloaded by a programmer. The exceptions are
	. (dot)  ::  ?:  sizeof
There is no fundamental reason to disallow overloading of ?:. I just didn't see the need to introduce the special case of overloading a ternary operator. Note that a function overloading expr1?expr2:expr3 would not be able to guarantee that only one of expr2 and expr3 was executed.
Sizeof cannot be overloaded because built-in operations, such as incrementing a pointer into an array implicitly depends on it. Consider:
```
X a[10];
X* p = &a[3];
X* q = &a[3];
p++;	// p points to a[4]
   		// thus the integer value of p must be
   		// sizeof(X) larger than the integer value of q
```
Thus, sizeof(X) could not be given a new and different meaning by the programmer without violating basic language rules.
In N::m neither N nor m are expressions with values; N and m are names known to the compiler and :: performs a (compile time) scope resolution rather than an expression evaluation. One could imagine allowing overloading of x::y where x is an object rather than a namespace or a class, but that would - contrary to first appearances - involve introducing new syntax (to allow expr::expr). It is not obvious what benefits such a complication would bring.

Operator . (dot) could in principle be overloaded using the same technique as used for ->. However, doing so can lead to questions about whether an operation is meant for the object overloading . or an object referred to by . For example:
```
class Y {
	public:
		void f();
		// ...
	};

	class X {	// assume that you can overload .
		Y* p;
		Y& operator.() { return *p; }
		void f();
		// ...
	};

	void g(X& x)
	{
		x.f();	// X::f or Y::f or error?
	}
```
This problem can be solved in several ways. At the time of standardization, it was not obvious which way would be best

**To learn more about operator overloading, reading these links are useful :** 
* [CPP Reference: Operator overloading](https://en.cppreference.com/w/cpp/language/operators)
* [GFG: Operator overloading](https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019)
* [Wikipedia : Operator overloading](https://en.wikipedia.org/wiki/Operator_overloading)