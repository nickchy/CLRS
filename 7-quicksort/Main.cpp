#include <iostream>
#include "List.h"
#include "SortAlgo.h"
#include <stdlib.h>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
    cout<<argv[1]<<endl;
    int length =atoi(argv[1]);
// generate random seed   
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    vector<int> list1;
    vector<double> list2;
    list1.resize(length);
    list2.resize(length);
    MakeList(list1, length);
    MakeList(list2, length);
    // test function pointer
    cout<<"Original List:\n";
    PrintList(list1);
    SortAlgo<int>::MergeSort(list1,2,length-2);
    cout<<"After sort from index 2 to "<<length-2<<endl;
    PrintList(list1);
    SortAlgo<int>::MergeSort(list1,0,length-1);
    cout<<"Sort the whole list:\n";
    PrintList(list1);
    cout<<"For double vector:\n";
    PrintList(list2);
    cout<<"Sort the double vector:\n";
    SortAlgo<double>::MergeSort(list2,0,length-1);
    PrintList(list2);
   // re create the list
    MakeList(list1, length);
    MakeList(list2, length);
   cout<<"Now, quick sort: \n\n";
    cout<<"For double vector:\n";
    PrintList(list2);
    cout<<"Sort the double vector:\n";
    SortAlgo<double>::QuickSort(list2,0,length-1);
    PrintList(list2);
    cout<<"For integer vector:\n";
    PrintList(list1);
    cout<<"Sort the int vector:\n";
    SortAlgo<int>::QuickSort(list1,0,length-1);
    PrintList(list1);
     
     MakeList(list1, length);
    MakeList(list2, length);
    cout<<"Now, random sampled quick sort: \n\n";
    cout<<"For double vector:\n";
    PrintList(list2);
    cout<<"Sort the double vector:\n";
    SortAlgo<double>::RandomQuickSort(list2,0,length-1);
    PrintList(list2);
    cout<<"For integer vector:\n";
    PrintList(list1);
    cout<<"Sort the int vector:\n";
    SortAlgo<int>::RandomQuickSort(list1,0,length-1);
    PrintList(list1);
     
} 
