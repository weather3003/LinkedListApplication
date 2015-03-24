//#Daryl Bagley
/****************************************************************************************
Implementation Name: List
Des:  This file contains the function definitions declared in the class List.
****************************************************************************************/

#include <iostream>
#include <string>
#include "List.h"

using namespace std;
 
/***************************************************************************************
Function Name: List (constructor)
Des: This constructor will create a List object with a head of NULL (empty list).
****************************************************************************************/
List::List()
{
	head = NULL;
	current = NULL;
}

/***************************************************************************************
Function Name: ~List (destructor)
Des: This function will destroy a List object by deallocating dynamically allocated 
     memory.
***************************************************************************************/
List::~List()
{
	Node* current = head;

	while (current != NULL)
	{
		head = head->next;
		delete current;
		current = head;
	}
}

/***************************************************************************************
Function Name: Insert
Des: Creates a dynamic node and stores the string passed within it
     Inserts the node into its correct alpha location in the list
	 Returns true if successful and false if memory allocation failed
***************************************************************************************/
bool List::Insert(ListType item)
{
	Node * addressOfInsertion = new Node;
	if (!addressOfInsertion) return false;			//Returns false if memory allocation fails 
	
	Node insertion;
	insertion.data = item;

	//if list empty
	if (head == NULL)
	{
		insertion.next = NULL;
		head = addressOfInsertion;
		current = head;				//for the sake of the Next function
		*addressOfInsertion = insertion;
		return true;
	}
	else
	{
		Node * currentNode = head;

		//if node is first alphabetically
		if (item.name.compare(currentNode->data.name) < 0)
		{
			//put new node at beginning
			insertion.next = currentNode;
			head = addressOfInsertion;
			*addressOfInsertion = insertion;
			return true;
		}
		else
		{
			//While the list data is shorter/earlier in alphabet
			while (currentNode->next != NULL && item.name.compare(currentNode->next->data.name) > 0)
			{
				currentNode = currentNode->next;
			}

			//put new node in 
			insertion.next = currentNode->next;
			currentNode->next = addressOfInsertion;
			*addressOfInsertion = insertion;
			return true;

		}
		return false; //For a weird occurence where no other conditions are met
	}
}

/***************************************************************************************
Function Name: Delete
Des: Deletes the node containing the string passed
	 Returns true if the deletion was successful and false if the string could not be 
	 found in the list
***************************************************************************************/
bool List::Delete(string deletionName)
{
	bool nodeDeleted = false;

	//if list not empty
	if (head)
	{
		Node* forDeletion;

		//if first node should be deleted
		if (head->data.name == deletionName)
		{
			forDeletion = head;
			head = head->next;
			delete forDeletion;
			
			nodeDeleted = true;
		}

		Node* currentNode = head;

		//While the list data is shorter/earlier in alphabet and there is another node
		while (currentNode->next != NULL && !nodeDeleted)
		{
			if (currentNode->next->data.name == deletionName)
			{
				forDeletion = currentNode->next;
				currentNode->next = currentNode->next->next;
				delete forDeletion;

				nodeDeleted = true;
			}
			currentNode = currentNode->next;
		}
	}
	
	return nodeDeleted;
}

/***************************************************************************************
Function Name: Edit
Des: Deletes an item and insert a new item, thus "editting" an item
	 Returns true if the edit succeeded and false if it failed
***************************************************************************************/
bool List::Edit(string deletion, ListType insertion)
{
	if (Delete(deletion))
	{
		Insert(insertion);
		return true;
	}
	else
		return false;
}

/***************************************************************************************
Function Name: Print
Des: Prints the list to the screen one data element (string) per line
	 Prints <empty> if no elements in list
***************************************************************************************/
void List::Print()
{
	if (head != NULL)
	{
		Node * currentNode = head;

		while (currentNode->next != NULL)
		{
			cout << currentNode->data.name << endl;
			currentNode = currentNode->next;
		}
		cout << currentNode->data.name << endl;
	}
	else
		cout << "<empty>" << endl;
}

/***************************************************************************************
Function Name: Next
Des: Returns the next object of the list type, starting at head (see insert)
     Overflow allows for resetting at a specific point; starts at 1 and	wraps from 
		end to beginning; STARTPOINT CANNOT GO BELOW ONE
***************************************************************************************/
bool List::Next(ListType& result)
{
	if (current == NULL)
		return false;
	else
	{
		result = current->data;
		current = current->next;
	}

	return true;
}

bool List::Next(ListType& result, int startPoint)
{
	if (current == NULL)
		return false;
	else
	{
		current = head;

		for (int index = 1; index < startPoint; index++)
		{
			if (current->next == NULL)
				current = head;
			else
				current = current->next;	
		}
		result = current->data;
		current = current->next;
	}

	return true;
}