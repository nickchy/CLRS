#include<iostream>
#include "Heap.h"
#include<vector>
#include<limits>
using namespace std;

Heap::Heap(int heapSize,vector<int> list)
{
    m_maxHeapSize = heapSize;
    m_heapSize = m_maxHeapSize;
    m_list.resize(m_heapSize);
    m_list = list;
    BuildMaxHeap();
}
//find the index of parent
int Heap::Parent(int i)
{
    //return floor((i+1)/2)
    return ((i+1) >> 1) -1;
}

//find the index of Left 
int Heap::Left(int i)
{
    //return 2*(i+1) -1
    return (i << 1) +1;
}

//find the index of Right
int Heap::Right(int i)
{
    //return 2*(i+1) +1 -1
    return (i << 1) + 2;
}
//heapify from certain index 
void Heap::MaxHeapify(int i)
{
    int l = Left(i);
    int r = Right(i);
    int largest;

    if(l < m_heapSize && m_list[l] > m_list[i] )
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    
    if(r < m_heapSize && m_list[r] > m_list[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        int temp = m_list[i];
            m_list[i] = m_list[largest];
            m_list[largest] = temp;
        //  recursively build heap
            MaxHeapify(largest);
    }
}

void Heap::BuildMaxHeap()
{
  ResetHeapSize();
  int brkpt = (m_heapSize >> 1) -1;
  for (int i = brkpt; i >=0; i--)
  {
      MaxHeapify(i);
  }
}

void Heap::Sort()
{
    BuildMaxHeap();
    int length = m_heapSize-1; 
    for(int i= length; i>0; i--)
    {
        int temp;
        temp = m_list[i];
        m_list[i] = m_list[0];
        m_list[0] = temp;
        m_heapSize--;
        MaxHeapify(0);
    }
}

int Heap::Maximum(){return m_list[0];};

int Heap::ExtractMaximum()
{
  if(m_heapSize < 1)
  {
    cout << "heap size underflow\n";

    return numeric_limits<int>::min();
  }
  else
  {
    int max = m_list[0];
    m_list[0] = m_list[m_heapSize-1];
    m_heapSize--;
    MaxHeapify(0);

    return max;
  }
}

void Heap::IncreaseKey(int i, int key)
{
    if(key<m_list[i])
    {
        cout<<"new key "<<key<<" is samller than current key "<<m_list[i]<<endl;
    }
    else
    {
        m_list[i] = key;

        while(i > 0 && m_list[Parent(i)]<m_list[i])
        {
            int temp = m_list[i];
            m_list[i]= m_list[Parent(i)];
            m_list[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}
            



