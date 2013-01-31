#include <iostream>
#include "List.h"
#include "SortAlgo.h"
#include <stdlib.h>
#include <vector>


int main(int argc, char *argv[])
{
    std::cout<<argv[1]<<std::endl;
    int length =atoi(argv[1]);
// generate random seed   
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    std::vector<int> list1;
    std::vector<double> list2;
    list1.resize(length);
    list2.resize(length);
    List::MakeList(list1, length);
    List::MakeList(list2, length);
    // test function pointer
    std::cout<<"Original List:\n";
    List::PrintList(list1);
    SortAlgo<int>::MergeSort(list1,2,length-2);
    std::cout<<"After sort from index 2 to "<<length-2<<std::endl;
    List::PrintList(list1);
    SortAlgo<int>::MergeSort(list1,0,length-1);
    std::cout<<"Sort the whole list:\n";
    List::PrintList(list1);
    std::cout<<"For double vector:\n";
    List::PrintList(list2);
    std::cout<<"Sort the double vector:\n";
    SortAlgo<double>::MergeSort(list2,0,length-1);
    List::PrintList(list2);
   // re create the list
    List::MakeList(list1, length);
    List::MakeList(list2, length);
   std::cout<<"Now, quick sort: \n\n";
    std::cout<<"For double vector:\n";
    List::PrintList(list2);
    std::cout<<"Sort the double vector:\n";
    SortAlgo<double>::QuickSort(list2,0,length-1);
    List::PrintList(list2);
    std::cout<<"For integer vector:\n";
    List::PrintList(list1);
    std::cout<<"Sort the int vector:\n";
    SortAlgo<int>::QuickSort(list1,0,length-1);
    List::PrintList(list1);
     
     List::MakeList(list1, length);
    List::MakeList(list2, length);
    std::cout<<"Now, random sampled quick sort: \n\n";
    std::cout<<"For double vector:\n";
    List::PrintList(list2);
    std::cout<<"Sort the double vector:\n";
    SortAlgo<double>::RandomQuickSort(list2,0,length-1);
    List::PrintList(list2);
    std::cout<<"For integer vector:\n";
    List::PrintList(list1);
    std::cout<<"Sort the int vector:\n";
    SortAlgo<int>::RandomQuickSort(list1,0,length-1);
    List::PrintList(list1);
     
} 
