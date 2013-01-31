#include "OrderStat.hpp"
#include "List.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
//    typedef vector<int> vecint;
    
    std::cout<<argv[1]<<std::endl;
    int length =atoi(argv[1]);
  /*   
    int range;

    if(argv[2]!=NULL)
    {
        range =atoi(argv[2]);
    }
    else
    {
        range = 1000;
    }

    */
// generate random seed   
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    std::vector<int> list1;
    std::vector<int> sortedList1;
    std::vector<double> list2;
    int maxint, minint;
    double maxdouble, mindouble;
    list1.resize(length);
    list2.resize(length);
    List::MakeList(list1, length);
    List::MakeList(list2, length);
    // test function pointer
//    std::cout<<"Original List:\n";
//    PrintList(list1);
    std::cout<<"max: \n\n";
    std::cout<<"For int vector:\n";
    List::PrintList(list1);
    
    OrderStat::Min<int>(list1,minint);   
    OrderStat::Max<int>(list1,maxint);
    std::cout<<"min of the intg vector is: "<<minint<<"\n";
    std::cout<<"max of the intg vector is: "<<maxint<<"\n";
    OrderStat::MinMax<int>(list1, maxint, minint);
    std::cout<<"from MinMax funciton, min is "<<minint<<" and max is: "<<maxint<<" \n";  
    
    
    std::cout<<"For double vector:\n";
    List::PrintList(list2);
    
    OrderStat::Min<double>(list2,mindouble);   
    OrderStat::Max<double>(list2,maxdouble);
    std::cout<<"min of the double vector is: "<<mindouble<<"\n";
    std::cout<<"max of the double vector is: "<<maxdouble<<"\n";
    OrderStat::MinMax<double>(list2, maxdouble, mindouble);
    std::cout<<"from MinMax funciton, min is "<<mindouble<<" and max is: "<<maxdouble<<" \n";  
    
    std::cout<<"For integer vector the third smallest member is:"<< OrderStat::RandomizedSelection<int>(list1, 0, length-1, 3)<<"\n";
    std::cout<<"For double vector the third smallest member is: "<< 
    OrderStat::RandomizedSelection<double>(list2, 0, length-1, 3)<<"\n";
     
} 
