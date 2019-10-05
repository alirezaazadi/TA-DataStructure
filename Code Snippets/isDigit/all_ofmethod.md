# all_of
**Defined in header :** [algorithm](http://www.cplusplus.com/reference/algorithm/)

```
template <class InputIterator, class UnaryPredicate>
  bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred);
```

Test condition on all elements in range
Returns true if pred returns true for all the elements in the range [first,last) or if the range is empty, and false otherwise.

The behavior of this function template is equivalent to:

```
template<class InputIterator, class UnaryPredicate>
  bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (!pred(*first)) return false;
    ++first;
  }
  return true;
}
```

**Parameters** 
* first, last :
    * Input iterators to the initial and final positions in a sequence. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
* pred :
    * Unary function that accepts an element in the range as argument and returns a value convertible to bool. The value returned indicates whether the element fulfills the condition checked by this function.
The function shall not modify its argument.
This can either be a function pointer or a function object.


**Return value**

true if pred returns true for all the elements in the range or if the range is empty, and false otherwise.

more : 

* [C PlusPlus : all_of](http://www.cplusplus.com/reference/algorithm/all_of/)
* [CPPReference : all, none, any_of](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of)