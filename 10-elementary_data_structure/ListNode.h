// Name: Yang Cai
// Date: 11/18/2009


#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>
using namespace std;


class Node
{
	friend class LinkedList; // make LinkedList a friend
public:
	Node(string& name, int no); // constructor
	
private:
	string itemName;
	int itemNo;
	Node *next;
 
};
Node ::Node(string& name, int no){

    itemName = name;  
    itemNo = no;
    next = 0;

	}


#endif