// =====================================================================================
// 
//       Filename:  Stack.hpp
// 
//    Description:  Implementation of Stack data strucutre  
// 
//        Version:  1.0
//        Created:  01/31/2013 06:13:54 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nick Yang Cai ((nickchy)), nickchy1984@gmail.com
//        Company:  
// 
// =====================================================================================


#ifndef  STACK_H
#define  STACK_H
#include <assert.h>    // For error-checking purposes

//-------------------------------------------------
// Main structure of Stack Class:
//-------------------------------------------------

template <class T>
class Stack
{
  public:
    Stack(int MaxSize=500);
    Stack(const Stack<T> &OtherStack);
    ~Stack(void);

    inline void        Push(const T &Item); // Adds Item to the top
    inline T        Pop(void);              // Returns Item from the top
    inline const T &Peek(int Depth) const;  // Peek a depth downwards
    int GetTop();
  protected:
    T     *_data;           // The actual _data array
    int       _top;    // The current number of elements
    const int _maxNum;        // Maximum number of elements
};

//-------------------------------------------------
// Implementation of Stack Class:
//-------------------------------------------------

// Stack Constructor function
template <class T>
Stack<T>::Stack(int MaxSize) :
    _maxNum( MaxSize )    // Initialize the constant
{
  _data = new T[_maxNum];
  _top = -1;
}

// Stack Destructor function
template <class T>
Stack<T>::~Stack(void)
{
  delete[] _data;
}

// get the top index
    template < class T >
int Stack<T>::GetTop() 
{
    return _top;
}		// -----  end of method Stack<T>::GetTop  -----
// Push() function
template <class T>
inline void Stack<T>::Push(const T &item)
{
  // Error Check: Make sure we aren't exceeding the maximum storage space
  assert(_top < _maxNum);
  
  _data[++_top] = item;
}

// Pop() function
template <class T>
inline T Stack<T>::Pop(void)
{
  // Error Check: Make sure we aren't popping from an empty Stack
  assert(_top > -1);

  return _data[_top--];
}

// Peek() function
template <class T>
inline const T &Stack<T>::Peek(int Depth) const
{
  // Error Check: Make sure the depth doesn't exceed the number of elements
  assert(Depth < _top);

  return _data[ _top - (Depth + 1) ];
}

#endif   // ----- #ifndef STACK_H_INC  -----
