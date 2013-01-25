#include <iostream>
#include "List.h"
#include "Heap.h"
#include <stdlib.h>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
    cout<<argv[1]<<endl;
    size_t length =atoi(argv[1]);
    vector<int> list;
    list.resize(length);
    MakeList(list, length);
    Heap ObjHeap = Heap(length, list);
    // test function pointer
    void (Heap::*sort)() =&Heap::Sort;

    cout<<"parent of "<<7<<" is "<<ObjHeap.Parent(7)<<"\n";
    cout<<"right of "<<7<<" is "<<ObjHeap.Right(7)<<"\n";
    cout<<"left of "<<7<<" is "<<ObjHeap.Left(7)<<"\n";

    PrintList(ObjHeap.m_list);

   (ObjHeap.*sort)();

    PrintList(ObjHeap.m_list);

    return 0;
}
