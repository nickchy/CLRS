// =====================================================================================
// 
//       Filename:  Queue.hpp
// 
//    Description:  Implementation of Queue data strucutre  
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


#ifndef  QUEUE_H
#define  QUEUE_H
#include <vector>
#include <assert.h>    // For error-checking purposes

//-------------------------------------------------
// Main structure of Queue Class:
//-------------------------------------------------

template <class T>
class Queue
{
  public:
    Queue(int MaxSize=500);
    Queue(const Queue<T> &OtherQueue);
    ~Queue(void);

    inline void        Push(const T &Item); // Adds Item to the top
    inline T        Pop(void);              // Returns Item from the top
    inline const T &Peek(int Depth) const;  // Peek a depth downwards

  protected:
    T     *_data;           // The actual _data array
    int       _head;    // the head 
    int _tail;          // the tail
    const int _maxNum;        // Maximum number of elements
};

//-------------------------------------------------
// Implementation of Queue Class:
//-------------------------------------------------

// Queue Constructor function
template <class T>
Queue<T>::Queue(int MaxSize) :
    _maxNum( MaxSize )    // Initialize the constant
{
  _data = new T[_maxNum];
  _top = ;
}

// Queue Destructor function
template <class T>
Queue<T>::~Queue(void)
{
  delete[] _data;
}

// Push() function
template <class T>
inline void Queue<T>::Enqueue(const T &Item)
{
  // Error Check: Make sure we aren't exceeding the maximum storage space
  assert(_head - _tail > 1);
  
  _data[++_top] = Item;
}

// Pop() function
template <class T>
inline T Queue<T>::Pop(void)
{
  // Error Check: Make sure we aren't popping from an empty Queue
  assert(_top > 0);

  return _data[_top--];
}

// Peek() function
template <class T>
inline const T &Queue<T>::Peek(int Depth) const
{
  // Error Check: Make sure the depth doesn't exceed the number of elements
  assert(Depth < _top);

  return _data[ _top - (Depth + 1) ];
}

#endif   // ----- #ifndef STACK_H_INC  -----
