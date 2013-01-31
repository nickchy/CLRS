// =====================================================================================
// 
//       Filename:  OrderStat.hpp
// 
//    Description:  order statistics
// 
//        Version:  1.0
//        Created:  01/31/2013 09:33:19 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Nick Yang Cai ((neickchy)), nickchy1984@gmail.com
//        Company:  
// 
// ====================================================================================



#ifndef  ORDERSTAT_H
#define  ORDERSTAT_H
#include "List.h"
#include <vector>
#include <cmath>
#include <cstdlib>

namespace OrderStat
{

    template <class T>
        void Max ( std::vector<T>& list, T& maxval)
        {
           int length = (int)list.size();
           maxval = list[0];
            for ( int i = 0 ;i<length ;i++ ) 
            {
              maxval = std::max(list[i],maxval); 
            }
        }		// -----  end of template function Max  -----

    template <class T>
        void Min ( std::vector<T>& list, T& minval)
        {
           int length = (int)list.size();
           minval = list[0];
            for ( int i = 0 ;i<length ;i++ ) 
            {
              minval = std::min(list[i],minval); 
            }
        }

    template <class T>
        void MinMax ( std::vector<T>& list, T& maxval, T& minval)
        {
           int length = (int)list.size();
           int j = 0;
           if(length % 2 ==0)
           {
               maxval = std::max(list[0],list[1]);
               minval = std::min(list[0],list[1]);
               j = 2;
           }
           else
           {
               minval=maxval=list[0];
               j = 1;
           }
           maxval = list[0];
           minval = list[0];
            for ( int k = j ;k<length ;k=k+2 ) 
            {
              T tempmax, tempmin;
              tempmax  = std::max(list[k], list[k+1]);
              tempmin  = std::min(list[k], list[k+1]);
              maxval = std::max(tempmax,maxval);
              minval = std::min(tempmin,minval);
            }
        }
    
 
    // ===  FUNCTION  ======================================================================
    //         Name:  RandinuzedSekectuin
    //  Description:  return the ith smallest element in list[low - high]
    // =====================================================================================
    template <class T>

        T RandomizedSelection ( std::vector<T>& list,int low, int high, int i)
        {
            if (low == high)
            {
                return list[low];
            }
            
            int q = List::RandomPartition( list,low, high);
            int k = q - low + 1;
            if (i == k)
            {
                return list[q];
            }
            else if(i < k)
            {
                return RandomizedSelection(list, low, q-1, i);
            }
            else
            {
                return RandomizedSelection(list, q+1, high, i-k);
            }
        }		// -----  end of template function RandomizedSelection  -----
}


#endif   // ----- #ifndef ORDERSTAT_H_INC  -----
