#include "List.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

/**
 * Print all elements in list
 */
namespace List{
    
    void MakeList(std::vector<int>& list, int length, int range) {

        unsigned int counter;

        for (counter = 0; counter < list.size(); counter++) {
            // use rand() % 1000 will get random number between 1-range(default to be 1000)
            list[counter] = rand() %  range;
       }
    }

    void MakeList(std::vector<double>& list, int length) {
        unsigned int counter;

        for (counter = 0; counter < list.size(); counter++) {
            // use rand() % 1000 will get random number between 1-1000
            list[counter] = (double)rand() / RAND_MAX;
        }
    }
}
