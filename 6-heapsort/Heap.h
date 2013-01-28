#ifndef HEAP_H
#define HEAP_H
#include<vector>
using namespace std;
class Heap
{
    private:
        int m_maxHeapSize;
        int m_heapSize;

    public:
        vector<int> m_list;
        Heap(int, vector<int>);
        
        int Parent(int);
        int Left(int);
        int Right(int);
        void MaxHeapify(int);
        void BuildMaxHeap();
        void Sort();
        int Maximum();
        int ExtractMaximum();
        void IncreaseKey(int, int);
        void MaxHeapInsert(int);
        void SetMaxHeapSize(int);
//        void MaxHeapInsert(int); 
        int GetHeapSize() {return m_heapSize;}
        void ResetHeapSize() {m_heapSize = m_maxHeapSize;}
};
#endif
