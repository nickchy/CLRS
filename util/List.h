#ifndef  LIST_H
#define  LIST_H

#include<vector>
#include <iostream>
using namespace std;

    template <class T>
void PrintList(vector<T>& list) {
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

void MakeList(vector<int>&, int);
void MakeList(vector<double>&, int);

#endif   /* ----- #ifndef LIST_H_INC  ----- */
