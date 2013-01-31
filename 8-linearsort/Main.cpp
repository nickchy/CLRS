#include "LinearSort.hpp"
#include "List.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
//    typedef vector<int> vecint;
    
    std::cout<<argv[1]<<std::endl;
    int length =atoi(argv[1]);
    
    int range;

    if(argv[2]!=NULL)
    {
        range =atoi(argv[2]);
    }
    else
    {
        range = 1000;
    }
// generate random seed   
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    std::vector<int> list1;
    std::vector<int> sortedList1;
    std::vector<double> list2;
    list1.resize(length);
    list2.resize(length);
    List::MakeList(list1, length);
    List::MakeList(list2, length);
    // test function pointer
//    std::cout<<"Original List:\n";
//    List::PrintList(list1);
//   std::cout<<"count sort: \n\n";
//    std::cout<<"For double vector:\n";
//    List::PrintList(list2);
//    std::cout<<"Sort the double vector:\n";
//    SortAlgo<double>::RandomQuickSort(list2,0,length-1);
//    List::PrintList(list2);
    std::cout<<"For integer vector:\n";
    List::PrintList(list1);
    std::cout<<"Sort the int vector:\n";
    LinearSort::CountSort(list1,sortedList1,range);
    List::PrintList(sortedList1);
     
} 
