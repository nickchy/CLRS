// =====================================================================================
// 
//       Filename:  LinkedList.hpp
// 
//    Description:  implementation of linked list
// 
//        Version:  1.0
//        Created:  02/01/2013 02:20:04 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nick Yang Cai ((nickchy)), nickchy1984@gmail.com
//        Company:  
// 
// =====================================================================================
#ifndef  LINKEDLIST_H_INC
#define  LINKEDLIST_H_INC

#include <iostream>
#include <stdio.h>

template <class T>
class Node
{
    T _data;
    Node<T>* _next;
    Node<T>* _prev;
    
    public:

         Node(T data)
        {
            _data = data;
            _next = NULL;
            _prev = NULL;
        }

        void setNext(Node* next)
        {
             _next = next;
        }

         Node* getNext()
        {
             return _next;
        }

        void setPrev(Node* prev)
        {
             _next = prev;
        }

         Node* getPrev()
        {
             return _prev;
        }

         T getData()
        {
             return _data;
        }          
};

template <class T>
class LinkedList
{
    Node<T> *_node;
    Node<T> *_currPtr;
    Node<T> *_nextPtr;
    Node<T> *_prevPtr;
    int size;
    
    public:
        LinkedList(T data)
          {
              _node = new Node<T>(data);
              _currPtr = _node;  //assignment between two pointers.
              _nextPtr = _node;
              _prevPtr = _node;
              size = 1;
          }

        LinkedList()
          {
              _node = NULL;
              _currPtr = NULL;  //assignment between two pointers.
              _nextPtr = NULL;
              _prevPtr = NULL;
              size = 0;
          }
        LinkedList* add(T data)  // return pointer type.
        {
           Node<T> *temp = new Node<T>(data);
           _currPtr->setNext(temp);
           _currPtr = temp;
           size++;
           cout<<datum<<" is added.";
           return this; //pointer type specification
        }

        T next()
        {
           T data = (*__nextPtr).getDatum();
           cout<<data<<" is visited.";
           __nextPtr = __nextPtr->getNext();
           return data;
        }
        int getSize()
        {
           return size;
        }   
};
#endif   // ----- #ifndef LINKEDLIST_H_INC  -----
