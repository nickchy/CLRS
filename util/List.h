#ifndef  LIST_H
#define  LIST_H

#include<vector>
#include <iostream>
using namespace std;

    template <class T>
void PrintList(vector<T>& list) 
{
   cout << "List: [";
    unsigned int counter;
    for (counter = 0; counter < list.size(); counter++) {
        if (counter == (list.size() - 1)) {
            cout << list[counter];
        } else {
            cout << list[counter] << ", ";
        }
    }
    cout << ("] \n");
}

    template <class T>
void Swap ( vector<T>& list, int i, int j)
{
    T temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}		/* -----  end of template function Swap  ----- */

void MakeList(vector<int>&, int,int = 1000);
void MakeList(vector<double>&, int);

#endif   /* ----- #ifndef LIST_H_INC  ----- */
