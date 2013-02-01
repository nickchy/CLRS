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

    inline void EnQueue(const T &Item); // Adds Item to the top
    inline T DeQueue(void);              // Returns Item from the top
    inline bool IsFull();
    inline bool IsEmpty();
    inline const int GetHead();
    inline const int GetTail();
  protected:
    T     *_data;           // The actual _data array
    int       _head;    // the head 
    int _tail;          // the tail
    const int _maxNum;        // Maximum number of elements
    inline int  MoveNext(int pos) const;

};

//-------------------------------------------------
// Implementation of Queue Class:
//-------------------------------------------------

// Queue Constructor function
template <class T>
Queue<T>::Queue(int MaxSize) :
    _maxNum( MaxSize )    // Initialize the constant
{
  _data = new T[_maxNum+1];   // need N+1 array size to implement N queue 
  _head = _tail = 0;
}

// Queue Copy Constructor function
template <class T>
Queue<T>::Queue(const Queue &OtherQueue) :
                _maxNum( OtherQueue._maxNum )  // Initialize the constant
{
  _tail = OtherQueue._tail;
  _head       = OtherQueue._head;
  _data      = new T[_maxNum + 1];
  for (int i = 0; i < _maxNum; i++)
  {
    _data[i] = OtherQueue._data[i];
  }
}
// Queue Destructor function
template <class T>
Queue<T>::~Queue(void)
{
  delete[] _data;
}

// find the next head/tail index with wrap around
  template < class T >
inline int Queue<T>::MoveNext (int pos ) const
{
  assert( pos <= _maxNum);
  return (pos + 1) % (_maxNum + 1);

}		// -----  end of method Queue<T>::Next  -----


  template < class T >
inline const int Queue<T>::GetHead()
{
  return _head;
}
		// -----  end of method Queue<T>::GetHead  -----

  template < class T >
inline const int Queue<T>::GetTail()
{
  return _tail;
}
		// -----  end of method Queue<T>::GetHead  -----


  template < class T >
inline bool Queue<T>::IsFull ()
{
  if(MoveNext(_tail) == _head)
  {
    return true;
  }
  else
  {
    return false;
  }
}		// -----  end of method Queue<T>::IsFull  -----

  template < class T >
inline bool Queue<T>::IsEmpty ()
{
  if(_tail == _head)
  {
    return true;
  }
  else
  {
    return false;
  }
}
// Push() function
template <class T>
inline void Queue<T>::EnQueue(const T &Item)
{
  // Error Check: Make sure we aren't exceeding the maximum storage space
  assert(!IsFull());
  
  _data[_tail] = Item;
  _tail = MoveNext(_tail);
}

// Pop() function
template <class T>
inline T Queue<T>::DeQueue(void)
{
  // Error Check: Make sure we aren't popping from an empty Queue
  assert(!IsEmpty());

  T item = _data[_head];
  _head = MoveNext(_head);

  return item;
}

#endif   // ----- #ifndef QUEUE_H  -----
