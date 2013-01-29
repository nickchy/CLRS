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
#include <vector>

using namespace std;

template < class T >
class SortAlgo
{
    public:
        // ====================  LIFECYCLE     =======================================
          SortAlgo ();

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  SortAlgo
         *      Method:  ~SortAlgo
         * Description:  destructor
         *--------------------------------------------------------------------------------------
         */
        ~SortAlgo ();
       
        /*
         *--------------------------------------------------------------------------------------
         *       Class:  SortAlgo
         *      Method:  SortAlgo :: Merge
         * Description:  Merge two subarray into one in order, used for merge sort
         *--------------------------------------------------------------------------------------
         */
        static void Merge (vector<T>& List, int low, int mid, int high);

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  SortAlgo
         *      Method:  SortAlgo :: MergeSort
         * Description:  Merge sort algorithm
         *--------------------------------------------------------------------------------------
         */
        static void MergeSort ( vector<T>& List,int low, int high);
       /* 
        * ===  FUNCTION  ======================================================================
        *         Name:  Partition
        *  Description: used in quick sort, find the piviot point  
        * =====================================================================================
        */
       static int Partition ( vector<T>& List, int Low,int high);

       /*
        *--------------------------------------------------------------------------------------
        *       Class:  SortAlgo
        *      Method:  SortAlgo :: QuickSort
        * Description:  implement quicksort algorithm
        *--------------------------------------------------------------------------------------
        */
       static void QuickSort( vector<T>& List, int Low,int high);    

        /* 
        * ===  FUNCTION  ======================================================================
        *         Name:  RandomPartition
        *  Description: used in quick sort, find the piviot point and apply random sampling  
        * =====================================================================================
        */
       static int RandomPartition ( vector<T>& List, int Low,int high);

       /*
        *--------------------------------------------------------------------------------------
        *       Class:  SortAlgo
        *      Method:  SortAlgo :: RandomQuickSort
        * Description:  implement quicksort algorithm
        *--------------------------------------------------------------------------------------
        */
       static void RandomQuickSort( vector<T>& List, int Low,int high);    

       
}; /* -----  end of template class SortAlgo  ----- */


#endif   /* ----- #ifndef SORTALGO_H_INC  ----- */
