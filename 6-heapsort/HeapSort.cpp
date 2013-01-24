#include<iostream>

using namespace std;

int Parent(int i)
{
    //return floor((i+1)/2)
    return ((i+1) >> 1) -1;
}

int Left(int i)
{
    //return 2*(i+1) -1
    return (i << 1) +1;
}

int Right(int i)
{
    //return 2*(i+1) +1 -1
    return (i << 1) + 2;
}

void MaxHeapify(int A[], int i, int heapSize)
{
    int l = Left(i);
    int r = Right(i);
    int largest;

    if(l < heapSize && A[l] > A[i] )
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    
    if(r < heapSize && A[r] > A[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        int temp = A[i];
            A[i] = A[largest];
            A[largest] = temp;
        //  recursively build heap
            MaxHeapify(A,largest,heapSize)
    }

}
