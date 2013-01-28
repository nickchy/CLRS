#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "List.h"

using namespace std;
/**
 * Print all elements in list
 */

void MakeList(vector<int>& list, int length) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    unsigned int counter;

    for (counter = 0; counter < list.size(); counter++) {
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = rand() %  1000;
    }
}

void MakeList(vector<double>& list, int length) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    unsigned int counter;

    for (counter = 0; counter < list.size(); counter++) {
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = (double)rand() / RAND_MAX;
    }
}
