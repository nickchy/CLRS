#include<iostream>
#include "Heap.h"
using namespace std;

class Heap
{
    public:
    Heap(int heapSize,int list[])
    {
        _heapSizeOrig = heapSize;
        _heapSize = _heapSizeOrig;
        _list = new int[_heapSize];
        for(int i=0;i<_heapSize;i++)
        {
            _list[i] = list[i];
        }
    }
    //find the index of parent
    int Parent(int i)
    {
        //return floor((i+1)/2)
        return ((i+1) >> 1) -1;
    }

    //find the index of Left 
    int Left(int i)
    {
        //return 2*(i+1) -1
        return (i << 1) +1;
    }

    //find the index of Right
    int Right(int i)
    {
        //return 2*(i+1) +1 -1
        return (i << 1) + 2;
    }
    //heapify from certain index 
    void MaxHeapify(int i)
    {
        int l = Left(i);
        int r = Right(i);
        int largest;

        if(l < _heapSize && _list[l] > _list[i] )
        {
            largest = l;
        }
        else
        {
            largest = i;
        }
        
        if(r < _heapSize && _list[r] > _list[largest])
        {
            largest = r;
        }

        if(largest != i)
        {
            int temp = _list[i];
                _list[i] = _list[largest];
                _list[largest] = temp;
            //  recursively build heap
                MaxHeapify(largest);
        }
    }

    void BuildMaxHeap()
    {
      int brkpt = (_heapSize >> 1) -1;
      for (int i = brkpt; i >=0; i--)
      {
          MaxHeapify(A,i,_heapSize);
      }
    }

    void HeapSort()
    {
        BuildMaxHeap();
        
        for(int i= (_heapSize-1); i>0; i--)
        {
            int temp;
            temp = _list[i];
            _list[i] = _list[0];
            _list[0] = temp;
            MaxHeapify(0);
        }
    }
    private:
        //heapsize
        int _heapSizeOrig;
        int _heapSize;
        //array list
        int * _list;
        
}
