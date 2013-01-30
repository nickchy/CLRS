/*
 * =====================================================================================
 *
 *       Filename:  LinearSort.hpp
 *
 *    Description: header file for linear sort algorithm 
 *
 *        Version:  1.0
 *        Created:  01/30/2013 10:08:28 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Nick Yang Cai ((nickchy)), nickchy1984@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef  LINEARSORT_H
#define  LINEARSORT_H

#include <vector>
#include <iostream>
#include <cmath>

namespace LinearSort
{
    typedef std::vector<int> vec;
    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  CountSort
     *  Description:  implement the counting sort
     * =====================================================================================
     */
    void CountSort (vec const& , vec& ,int ); 
    
    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  RadixSort
     *  Description:  Implement radix sort in 10 base
     * =====================================================================================
     */
    void RadixSort (vec const& , vec& ,int ); 
}


#endif   /* ----- #ifndef LINEARSORT_H_INC  ----- */
