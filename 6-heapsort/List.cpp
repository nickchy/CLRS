#include "List.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
/**
 * Print all elements in list
 */
void PrintList(int list[], int length) {
   cout << "List: [";
    int counter;
    for (counter = 0; counter < length; counter++) {
        if (counter == length - 1) {
            cout << list[counter];
        } else {
            cout << list[counter] << ", ";
        }
    }
    cout << ("] \n");
}

void MakeList(int list[], int length) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int counter;

    for (counter = 0; counter < length; counter++) {
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = rand() % 1000;
    }
}
