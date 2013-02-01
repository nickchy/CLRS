#include "Stack.hpp"
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
} 
