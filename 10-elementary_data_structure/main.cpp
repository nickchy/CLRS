// Name: Yang Cai
// Date: 11/18/2009

#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h" 
#include "ListNode.h" 
using namespace std;

void main()

{
    
int choice;

int number;
string name;

LinkedList List;
Node *newNode;
 

cout<<"Welcome to the shopping list program\n";

	do {
		cout<<"Please choose an option:\n1.  Add a new node at the beginning\n2.  Add a new node at the end\n3.  Remove the beginning node\n4.  Remove the end node\n5.  Remove a node from the list by entering an item number\n6.  Remove a node from the list by entering an item name\n7.  Print out the list\n8.  Quit the program\n";
		cin >> choice;
	    
	switch ( choice ) 
		{
		case 1:
			cout << "Please enter product number to insert at beginning:\n ";
			cin>>number;
			
			cout << "Please enter the name for the product: \n";
			cin>>name;
			
			newNode = new Node(name,number);

			List.addToStart( newNode );
			List.printList();
			break;
		  
		case 2:
			cout << "Please enter product number to insert at end: "<<endl;
			cin>>number;
			
			cout<<"Please enter the name for the product: "<<endl;
			cin>>name;
			
			newNode = new Node(name,number);

			List.addToEnd( newNode );
			List.printList();
			break;
		    
		case 3:
			List.removeFromStart();
		    List.printList();
		    
			break;

		case 4:
			List.removeFromEnd();
		    List.printList();
		    
			break;

		case 5:		
			cout << "Please enter product number to remove: \n";
            cin>>number;

			List.removeNodeFromList(number);
			List.printList();	
			
			break;

		case 6:
			cout << "Please enter product name to remove: \n";
            cin>>name;
			List.removeNodeFromList(name);
			
			List.printList();	

			break;

		case 7:
			List.printList();
			
			break;

		default:

			cout<<"please enter the appropriate choice number !"<<endl;
		break;

		} // end switch


} while ( choice !=8 );

	cout << "End list test\n\n";
    
} 
