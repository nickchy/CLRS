#include "LinearSort.hpp"
#include "List.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
//    typedef vector<int> vecint;
    
    cout<<argv[1]<<endl;
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
    MakeList(list1, length);
    MakeList(list2, length);
    // test function pointer
//    cout<<"Original List:\n";
//    PrintList(list1);
//   cout<<"count sort: \n\n";
//    cout<<"For double vector:\n";
//    PrintList(list2);
//    cout<<"Sort the double vector:\n";
//    SortAlgo<double>::RandomQuickSort(list2,0,length-1);
//    PrintList(list2);
    cout<<"For integer vector:\n";
    PrintList(list1);
    cout<<"Sort the int vector:\n";
    LinearSort::CountSort(list1,sortedList1,range);
    PrintList(sortedList1);
     
} 
