#include <iostream>
#include "List.h"
#include "Heap.h"
#include <stdlib.h>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
    cout<<argv[1]<<endl;
    int length =atoi(argv[1]);
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

    ObjHeap.BuildMaxHeap();

    int key = ObjHeap.m_list[ObjHeap.GetHeapSize() - 2] + 500;
    cout<<"Rebuilt the heap:\n";
    PrintList(ObjHeap.m_list);
    
    ObjHeap.IncreaseKey(ObjHeap.GetHeapSize() - 2, key);
    cout<<"After Increased Key of index "<<ObjHeap.GetHeapSize()- 2<<" to "<< key <<"\n";
    
    PrintList(ObjHeap.m_list);
//    key = 600;
   cout<<"insert key to Insert into Heap: \n";
   cin>>key;
   ObjHeap.MaxHeapInsert(key);
   cout<<"After insertion, the heap is now:\n";
    PrintList(ObjHeap.m_list);
 
    return 0;
}
