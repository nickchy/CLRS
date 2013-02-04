// Name: Yang Cai
// Date: 11/18/2009

#ifndef LINKEDLIST_LI
#define LINKEDLIST_LI

#include <iostream>
#include <string>
#include "ListNode.h" 
#include "LinkedList.h" 
using namespace std;


class LinkedList
{
public:
	LinkedList(); // constructor
	~LinkedList(); // destructor
	int size() const; // check the size of the LinkedList
	void addToStart(Node *); //add to the start
	void addToEnd(Node *); //add to the end
	void printList(); // print
	bool removeFromStart(); // remove the beginning
	bool removeFromEnd(); // remove the end
	void removeNodeFromList(int); // remove a item by no
	void removeNodeFromList(string); // remove a itme by name 

private:
	Node *myHead;
	Node *myTail;
	int mySize;

};


LinkedList::LinkedList()  //  constructor
{
	myHead = 0;
	myTail = 0;
	mySize = 0;

}

LinkedList::~LinkedList()  // destructor
{
	if (mySize != 0) // List is not empty
	{
		//cout<<"Destroying nodes...\n";

		Node *currentPtr=myHead;
		Node *tempPtr;

		while (currentPtr!=0) // delete remaining nodes
		{
			tempPtr=currentPtr;

			currentPtr=currentPtr->next;

			delete tempPtr;

		}
	}

	//cout << "All noes destroyed\n\n";
}



void LinkedList::addToStart(Node *value) // add node at from front
{
	Node *newPtr = value;

	if (mySize ==0)
		myHead = myTail = newPtr;
	else 
	{
		newPtr->next = myHead;
		myHead = newPtr;
	}

	mySize++;
}



void LinkedList::addToEnd(Node *value) // add node from back
{
    Node *newPtr = value;
    
    if ( mySize==0 )  // List is empty

		myHead = myTail = newPtr;
    
    else 
	{  
		myTail->next = newPtr;

		myTail = newPtr;

       
    } 

	mySize++;
  
} 



bool LinkedList::removeFromStart() // delete node from front
{
	if (mySize==0)  

		return false;  
	else
	{

		if ( myHead == myTail )
			myHead = myTail = 0;

        else
			myHead=myHead->next;

		mySize--;
  
        return true;  // delete successful
	}
}



bool LinkedList::removeFromEnd() // delete node from back
{

	if (mySize == 0)  

		return false;

	else if (myHead == myTail)
			myHead = myTail = 0;

        else 
		{
			Node *currentPtr = myHead;
           
			while (currentPtr->next!=myTail ) { // find the element right before the last one

				currentPtr=currentPtr->next; 
			}

 
            myTail = currentPtr;

            currentPtr->next = 0;
  
        }
  
		mySize--;
		
		return true;  // delete successful

	}



int LinkedList::size() const
{
	return mySize; 
}


void LinkedList::printList()
{
	if (mySize==0) 
	{
		cout << "The list is empty\n\n";
        return;

    } // end if
  
    Node *currentPtr = myHead;
   
	cout<<"The list is: "<<endl;
	cout<<"ItemNO\t\tItemName"<<endl;
  
    while ( currentPtr != 0 ) 
	{
		cout<<currentPtr->itemNo<<"\t\t"<<currentPtr->itemName<<endl;

		currentPtr = currentPtr->next;
  
    } 
  
     cout << "\n\n";

}
  

void LinkedList::removeNodeFromList(int no) //remove by number
{
	if ( mySize==0 )  
	{
		cout<<"The list is empty!\n"<<endl;
		return;
	} 


    if (myHead->itemNo == no) // if it is the first one

		{
			removeFromStart();
			return;

		}

	if (myTail->itemNo == no) // if it is the last one
		{
			removeFromEnd();
			return;
			
		}


			Node *currentPtr = myHead;
			Node *nextPtr = myHead->next;

			while (nextPtr->itemNo!= no && nextPtr != myTail)
			{

				currentPtr = nextPtr;
				nextPtr = currentPtr->next;

			}

			if (nextPtr == myTail)
				{
					cout<<"The item is not in the list.\n"<<endl;	
				}

				else 
				{

					currentPtr->next = nextPtr->next;

					delete nextPtr;

					mySize--;
					
				}
			return;
		}



void LinkedList::removeNodeFromList(string name) {   // remove by name

	if ( mySize==0 )  
	{
		cout<<"The list is empty!\n"<<endl;
		return;
	
	} 


    if (myHead->itemName == name) // if it is the first one

		{
			removeFromStart();
			return;

		}

	if (myTail->itemName == name) // if it is the last one
		{
			removeFromEnd();
			return;
			
		}


			Node *currentPtr = myHead;
			Node *nextPtr = myHead->next;

			while (nextPtr->itemName!= name && nextPtr != myTail)
			{

				currentPtr = nextPtr;
				nextPtr = nextPtr->next;

			}

			if (nextPtr == myTail)
				{
					cout<<"The item is not in the list.\n"<<endl;	
				}

				else 
				{

					currentPtr->next = nextPtr->next;

					delete nextPtr;
					mySize--;
					
				}
}



#endif
