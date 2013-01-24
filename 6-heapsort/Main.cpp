#include <iostream>
#include "List.h"
#include "HeapSort.h"
#include <stdlib.h>
using namespace std;


int main(int argc, char *argv[])
{
    cout<<argv[1]<<endl;
    int length =atoi(argv[1]);
    int list[length];
    MakeList(list, length);

    // test function pointer
    void (*sort)(int [], int) = HeapSort;

    cout<<"parent of "<<7<<" is "<<Parent(7)<<"\n";
    cout<<"right of "<<7<<" is "<<Right(7)<<"\n";
    cout<<"left of "<<7<<" is "<<Left(7)<<"\n";

    PrintList(list, length);

    sort(list, length);

    PrintList(list, length);

    return 0;
}
