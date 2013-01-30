/*
 * =====================================================================================
 *
 *       Filename:  LinearSort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/30/2013 11:13:47 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Nick Yang Cai ((nickchy)), nickchy1984@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "LinearSort.hpp"
#include <stdlib.h>

namespace LinearSort
{


    typedef std::vector<int> vecint;

        void CountSort(vecint const& list, vecint& sortedList,int num) 
    {

        vecint countvec(num);

        for ( int i = 0;i < num ;i++ )
        {
            countvec[i] = 0;
        }


        for ( int j = 0; j < (int)list.size() ; j++ ) 
        {
            countvec[list[j]]++;
        }

        for (int k = 1; k < num ; k ++ )
        {
            countvec[k] += countvec[k-1];
        }

        sortedList.resize(list.size());

        for ( int j = (int)list.size() - 1; j>=0 ;j-- )
        {
            sortedList[countvec[list[j]]-1] = list[j];
            countvec[list[j]]--;
        }

    }

        /* 
         * ===  FUNCTION  ======================================================================
         *         Name:  RadixSort
         *  Description:  implementation of radix sort and assume integer type input and has 
         *                range
         * =====================================================================================
         */
        void RadixSort (vecint const& list, vecint& sortedList,int num)
        {
               
        }		/* -----  end of function RadixSort  ----- */

}


