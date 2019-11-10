#Friend Classes and Functions

In some circumstances, 
it is more convenient to grant member-level access to functions that are not members of a class
or to all members in a separate class.
Only the class implementer can declare who its friends are.
A function or class cannot declare itself as a friend of any class.
In a class definition, use the friend keyword and the name of a non-member function or other class to grant it access to the private and protected members of your class.
In a template definition, a type parameter can be declared as a friend.

**define a friend function :**
```
class Node { 
private: 
    int key; 
    Node* next; 
  
    /* Other members of Node Class */
    friend int LinkedList::search(); 
    // Only search() of linkedList 
    // can access internal members 
}; 
```

Following are some important points about friend functions and classes:

1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.

2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.

3) Friendship is not inherited

4) The concept of friends is not there in Java.

**define a friend class:**

```

#include <iostream> 
class A { 
private: 
    int a; 
  
public: 
    A() { a = 0; } 
    friend class B; // Friend Class 
}; 
  
class B { 
private: 
    int b; 
  
public: 
    void showA(A& x) 
    { 
        // Since B is friend of A, it can access 
        // private members of A 
        std::cout << "A::a=" << x.a; 
    } 
}; 
  
int main() 
{ 
    A a; 
    B b; 
    b.showA(a); 
    return 0; 
} 
```

to read more about friendship: 

* [CPPReference : friend](https://en.cppreference.com/w/cpp/language/friend)
* [C PLUS PLUS : Friendship and inheritance](http://www.cplusplus.com/doc/tutorial/inheritance/)
* [Docs.Microsoft : friend](https://docs.microsoft.com/en-us/cpp/cpp/friend-cpp?view=vs-2019)
* [Geeks for Geeks : Friend class and function in C++](https://www.geeksforgeeks.org/friend-class-function-cpp/)