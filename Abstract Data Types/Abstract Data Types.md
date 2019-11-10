# Introduction to Asymptotic Analysis


![](https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/images/ADT.png)

Objects (or data) may be stored on a computer using either

* Contiguous-based structures, or
* Node-based structures
of which the array and the linked list are prototypical examples.

A data structure is a container which uses either contiguous- or node-based structures or both to store objects (in member variables or instance variables) and is associated with functions (member functions or methods) which allow manipulation of the stored objects.

A data structure may be directly implemented in any programming language; however, we will see that there are numerous different data structures which can store the same objects. Each data structure has advantages and disadvantages; for example, both arrays and singly linked lists may be used to store data in an order defined by the user. To demonstrate the differences:

* Assuming we fill an array from the first position, an array allows the user to easily add or remove an object at the end of the array (assuming that all the entries have not yet been used),

* A singly linked list allows the user to easily add or remove an object at the start of the list and a singly linked list with a pointer to the last node (the tail) allows the user to easily add an object at the end of the list.

There are significant differences between these two structures as well:

* Arrays allow arbitrary access to the nth entry of the array, but

* A linked list requires the program to step through n − 1 entries before accessing the nth entry.


**Other differences include:**

* An array does not require new memory until it is full (in which case, usually all the entries must be copied over); but

* A singly linked list requires new memory with each new node.
There are many other differences where an operation which can be done easily in linked lists requires significant effort with an array or vice versa.

Modifications may be made to each of these structures to reduce the complications required: an array size can be doubled, a singly linked list can be woven into an array to reduce the required number of memory allocations; however, there are some problems and restrictions which cannot be optimized away. An optimization in one area (increasing the speed or reduction in memory required by either one function or the data structure as a whole) may result in a detrimental effect elsewhere (a decrease in speed or increase in memory by another function or the data structure itself). Thus, rather than speaking about specific data structures, we need to step back and define models for specific data structures of interest to computer and software engineers.

An abstract data type or ADT (sometimes called an abstract data type) is a mathematical model of a data structure. It describes a container which holds a finite number of objects where the objects may be associated through a given binary relationship. The operations which may be performed on the container may be basic (e.g., insert, remove, etc.) or may be based on the relationship (e.g, given an object (possibly already in the container), find the next largest object). We will find that we cannot optimize all operations simultaneously and therefore we will have to give requirements for which operations must be optimal in both time and memory. Thus, to describe an abstract data structure we must:

* Give the relationship between the objects being stored, and

* Specify the operations which are to be optimized with respect to time and/or space.


Most references simply list abstract data structures, however, after much consideration, the author realized it would be more logical to classify abstract data structures based on the relationships they purport to store. This, in the opinion of the author, provides a much more uniform understanding. Comments are welcome.

The Relationships
In addition to looking at a set, a container where no relationship is assumed to exist between the objects, we will also look at the following binary relationships:

* [**Linear ordering**](https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/Linear_ordering/),
* [**Hierarchical ordering**](https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/Hierarchical_ordering/),
* [**Partial ordering**](https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/Partial_ordering/),
* Equivalence relationship, and
* Adjacency relationship.

for more : [**Waterloo: Abstract Data Types**](https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/)
