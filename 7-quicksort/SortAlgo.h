/*
 * =====================================================================================
 *
 *       Filename:  SortAlgo.h
 *
 *    Description:  header file for SortAlgo class
 *
 *        Version:  1.0
 *        Created:  01/27/2013 05:53:15 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Nick Yang Cai ((nickchy)), nickchy1984@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  SORTALGO_H
#define  SORTALGO_H

/* 
 * =====================================================================================
 *        Class:  SortAlgo
 *  Description:  sort algorithm for clrs
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <limits>
#include "SortAlgo.h"
using namespace std;
#include <vector>


template < class T >
class SortAlgo
{
    public:
        // ====================  LIFECYCLE     =======================================
          SortAlgo ()
        {
        }  /* ----------  end of constructor of template class SortAlgo  ---------- */

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  SortAlgo
         *      Method:  ~SortAlgo
         * Description:  destructor
         *--------------------------------------------------------------------------------------
         */
        ~SortAlgo ()
        {
        }  /* ----------  end of destructor of template class SortAlgo  ---------- */


        /*
         *--------------------------------------------------------------------------------------
         *       Class:  SortAlgo
         *      Method:  SortAlgo :: Merge
         * Description:  Merge two subarray into one in order, used for merge sort
         *--------------------------------------------------------------------------------------
         */
        static void Merge (vector<T>& List, int low, int mid, int high)
        {
           int n1 = mid - low + 1;
           int n2 = high - mid;

           vector<T> L;
           vector<T> R;
           L.resize(n1 + 1);
           R.resize(n2 + 1);
           
           for ( int i = 0 ; i < n1 ; i++ ) {
               L[i] = List[low + i];
           }
        
           for ( int i = 0 ; i < n2 ; i++ ) {
               R[i] = List[mid + 1 + i];
           }
            
           L[n1] = numeric_limits<T>::max();

           R[n2] = numeric_limits<T>::max();

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
           

       static void MergeSort ( vector<T>& List,int low, int high)
        {
            
            if ( low >= 0 && high < List.size()) {
                
                if ( low < high ) {
                
                int mid = (low + high )/2; 
                MergeSort(List, low, mid);
                MergeSort(List, mid+1, high);
                Merge(List, low, mid, high);
                
                }
            }
            else {
                cout<<"inputed index error\n";
            }
        }		/* -----  end of method SortAlgo<T>::MergeSort  ----- */
                
}; /* -----  end of template class SortAlgo  ----- */

#endif   /* ----- #ifndef SORTALGO_H_INC  ----- */
