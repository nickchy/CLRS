#include "List.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
/**
 * Print all elements in list
 */
void PrintList(vector<int>& list) {
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

void MakeList(vector<int>& list, int length) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    unsigned int counter;

    for (counter = 0; counter < list.size(); counter++) {
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = rand() % 1000;
    }
}
