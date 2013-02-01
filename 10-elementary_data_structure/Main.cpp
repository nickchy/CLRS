#include "Stack.hpp"
#include "Queue.hpp"
#include "List.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
//    typedef vector<int> vecint;
    
    std::cout<<argv[1]<<std::endl;
    int length =atoi(argv[1]);
// generate random seed   
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
   Stack<int> StackInt(length);
   Stack<double> StackDouble(length);
   StackInt.Push(5);
   StackDouble.Push(5.0);
   std::cout<<"Peek -1 int: "<<StackInt.Peek(-1)<<" with index top now: "<< StackInt.GetTop()<<
       " and Peek -1 doublbe: "<<StackDouble.Peek(-1)<<" with index top now: "<<StackDouble.GetTop()<< "\n";

   std::cout<<"Pop int: "<<StackInt.Pop();
   std::cout<<" now index top is: "<< StackInt.GetTop()<<StackInt.GetTop();
   std::cout<<" and Pop double is : "<<StackDouble.Pop()<<" now index top is: "<<StackDouble.GetTop()<<" \n";

   std::cout<<"pop again int: "<<StackInt.GetTop()<<"and again: "<<StackInt.GetTop();

   std::cout<<"\nNow for QUEUE: \n";
   Queue<int> QueueInt(length);
   Queue<double> QueueDouble(length);
   QueueInt.EnQueue(5);
   QueueDouble.EnQueue(5.0);
   std::cout<<"After Enqueue 5: Int and Double head/tail are now:\n";
   std::cout<<QueueInt.GetHead()<<", "<<QueueInt.GetTail()<<"\n";
   std::cout<<QueueDouble.GetHead()<<", "<<QueueDouble.GetTail()<<"\n";
   std::cout<<"Dequeue int: "<<QueueInt.DeQueue();
   std::cout<<" now Head, tail is: "<< QueueInt.GetHead()<<", "<<QueueInt.GetTail()<<"\n";
   std::cout<<" and Dequeue double is : "<<QueueDouble.DeQueue()<<"\nnow index Head, Tail is: ";
   std::cout<<QueueDouble.GetHead()<<", "<<QueueDouble.GetTail()<<" \n";
   std::cout<<"test is empty "<<QueueDouble.IsEmpty();

   
   for ( int i= 0;i< length-1 ;i++ ) 
   {
      QueueDouble.EnQueue(5);
   }
  
   std::cout<<"Head and Tail: "<<QueueDouble.GetHead()<<", "<<QueueDouble.GetTail()<<"\n";
   std::cout<<"test is full "<<QueueDouble.IsFull();
    
   std::cout<<"\ntest enqueue when is full: \n";
   QueueDouble.EnQueue(5);
   std::cout<<"Head and Tail: "<<QueueDouble.GetHead()<<", "<<QueueDouble.GetTail()<<"\n";
   

}

