/*
 * =====================================================================================
 *
 *       Filename:  SortAlgo.pp
 *
 *    Description:  SortAlgo template class body
 *
 *        Version:  1.0
 *        Created:  01/27/2013 05:14:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Nick Yang Cai ((nickchy)), nickchy1984@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "SortAlgo.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <limits>
#include "List.h"
/*
 *--------------------------------------------------------------------------------------
 *       Class:  SortAlgo
 *      Method:  SortAlgo
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
    template < class T >
SortAlgo< T >::SortAlgo ()
{
}  /* ----------  end of constructor of template class SortAlgo  ---------- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  SortAlgo
 *      Method:  ~SortAlgo
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
    template < class T >
SortAlgo< T >::~SortAlgo ()
{
}  /* ----------  end of destructor of template class SortAlgo  ---------- */


/*
 *--------------------------------------------------------------------------------------
 *       Class:  SortAlgo
 *      Method:  SortAlgo :: Merge
 * Description:  Merge two subarray into one in order, used for merge sort
 *--------------------------------------------------------------------------------------
 */
    template < class T >
void SortAlgo<T>::Merge (std::vector<T>& List, int low, int mid, int high)
{
   int n1 = mid - low + 1;
   int n2 = high - mid;

   std::vector<T> L;
   std::vector<T> R;
   L.resize(n1 + 1);
   R.resize(n2 + 1);
   
   for ( int i = 0 ; i < n1 ; i++ ) {
       L[i] = List[low + i];
   }

   for ( int i = 0 ; i < n2 ; i++ ) {
       R[i] = List[mid + 1 + i];
   }
    
   L[n1] = std::numeric_limits<T>::max();

   R[n2] = std::numeric_limits<T>::max();

   int j = 0, k = 0;

   for ( int i = low; i <= high ;i++ ) {
    
       if (L[j]<= R[k]) {
          List[i] = L[j];
          j++;
       }
       else {
           List[i] = R[k];
           k++;
       }
   }
}
   

    template < class T >
void SortAlgo<T>::MergeSort ( std::vector<T>& List,int low, int high)
{
    
    if ( low >= 0 && high < int(List.size())) {
        
        if ( low < high ) {
        
        int mid = (low + high )/2; 
        MergeSort(List, low, mid);
        MergeSort(List, mid+1, high);
        Merge(List, low, mid, high);
        
        }
    }
    else { 
        std::cout<<"inputed index error\n";
    }
}		/* -----  end of method SortAlgo<T>::MergeSort  ----- */

/* 
    template < class T >
int SortAlgo<T>::List::Partition ( vector<T>& List,int low, int high)
{
    T piviot = List[high];
    int i = low -1;

    for ( int j = low;j< high ;j++ ) {
        if(List[j]<= piviot)
        {
            i++;
            List::Swap(List, i ,j);
        }
    }

    List::Swap(List, (i+1), high);
    return i+1;
}
*/

    template < class T >
void SortAlgo<T>::QuickSort (std::vector<T>& List,int low, int high )
{
    if (low < high)
    {
        int q = List::Partition(List,low, high);
        QuickSort(List, low, q-1);
        QuickSort(List, q+1, high);
    }

}		/* -----  end of method SortAlgo<T>::QuickSort  ----- */

/* 
    template < class T >
int SortAlgo<T>::List::RandomPartition (vector<T>& List,int low, int high )
{
     int temp = low + rand() % (high-low + 1);
     List::Swap(List, temp, high);
     return List::Partition(List,low, high);
}		
*/

    template < class T >
void SortAlgo<T>::RandomQuickSort (std::vector<T>& List,int low, int high )
{
    if (low < high)
    {
        int q = List::RandomPartition(List,low, high);
        QuickSort(List, low, q-1);
        QuickSort(List, q+1, high);
    }

}		/* -----  end of method SortAlgo<T>::QuickSort  ----- */


