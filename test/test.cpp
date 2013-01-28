/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2013 12:02:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nick Yang Cai ((nickchy)), nickchy1984@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include<limits>
using namespace std;



template <class T>
void Print(vector<T> a)
{
    for( class vector<T>::iterator i = a.begin(); i != a.end(); ++i)
    {
        cout<< *i << ' ';
    }
    cout<<endl;
}

int main()
{
  vector<int> A(3,100);
  vector<int>::iterator it = A.begin();          
//  A.insert(it+4, 1, 200);
    A.insert(it+A.size(), 1,-numeric_limits<int>::infinity() );
  Print(A);
   return 0;
}
