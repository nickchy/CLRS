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
       
}; /* -----  end of template class SortAlgo  ----- */

#endif   /* ----- #ifndef SORTALGO_H_INC  ----- */
