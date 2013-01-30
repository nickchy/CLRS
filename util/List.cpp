#include "List.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
/**
 * Print all elements in list
 */

void MakeList(vector<int>& list, int length, int range) {

    unsigned int counter;

    for (counter = 0; counter < list.size(); counter++) {
        // use rand() % 1000 will get random number between 1-range(default to be 1000)
        list[counter] = rand() %  range;
   }
}

void MakeList(vector<double>& list, int length) {
    unsigned int counter;

    for (counter = 0; counter < list.size(); counter++) {
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = (double)rand() / RAND_MAX;
    }
}
