#ifndef  LIST_H
#define  LIST_H

#include<vector>
#include <iostream>
#include <stdlib.h>
namespace List
{
        template <class T>
    void PrintList(std::vector<T>& list) 
    {
        std::cout << "List: [";
        unsigned int counter;
        for (counter = 0; counter < list.size(); counter++) {
            if (counter == (list.size() - 1)) {
                std::cout << list[counter];
            } else {
                std::cout << list[counter] << ", ";
            }
        }
        std::cout << ("] \n");
    }

        template <class T>
    void Swap ( std::vector<T>& list, int i, int j)
    {
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }		/* -----  end of template function Swap  ----- */


        template < class T >
    int Partition ( std::vector<T>& List,int low, int high)
    {
        T piviot = List[high];
        int i = low -1;

        for ( int j = low;j< high ;j++ ) {
            if(List[j]<= piviot)
            {
                i++;
                Swap(List, i ,j);
            }
        }

        Swap(List, (i+1), high);
        return i+1;
    }		/* -----  end of method SortAlgo<T>::Partition  ----- */

      template < class T >
    int RandomPartition (std::vector<T>& List,int low, int high )
    {
         int temp = low + rand() % (high-low + 1);
         Swap(List, temp, high);
         return Partition(List,low, high);
    }	

    void MakeList(std::vector<int>&, int,int = 1000);
    void MakeList(std::vector<double>&, int);
} 
#endif   /* ----- #ifndef LIST_H_INC  ----- */
