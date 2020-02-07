#include "pch.h"
#include "List.h"

// constructor
List::List()
{
	firstNode = NULL;
	size = 0;
}

// destructor
List::~List() { }

// add an item to the back of the list (append)
bool List::add(ItemType item)
{
	// create a new node to store the item
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	// add new node to the list
	if (isEmpty())				// list is empty
		firstNode = newNode;			// set first node to point to newnode
	else
	{
		Node* current = firstNode;		// list is not empty
		for (int i = 0; i < size - 1; i++)		// move to last node
			current = current->next;

		current->next = newNode;		// set last node to point to newnode
	}
	size++;					// increase the size by 1
	return true;  				// no size constraint
}



// add an item at a specified position in the list (insert)
bool List::add(int index, ItemType item)
{
	bool success = (index >= 0) && (index <= size);
	if (success)
	{
		// create a new node to store the item
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		// add new node to the list at the specified position
		if (index == 0) 	// inserting in front
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else		// inserting in the middle or end 
		{
			Node* temp = firstNode;
			for (int i = 0; i < index - 1; i++)  // move to the node before the index
				temp = temp->next;

			newNode->next = temp->next; // make new node point to node pointed to by temp	
			temp->next = newNode;	          // make temp point to the new node
		}
		size++;				          // increase the size by 1
	}
	return success;
}


// remove an item at a specified position in the list
void List::remove(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{
		if (index == 0) // remove front node
			firstNode = firstNode->next;
		else		// remove the node at the index
		{
			Node* current = firstNode;
			Node* previous = firstNode;

			for (int i = 0; i < index; i++) 	// move to node at the index
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next; // delete the node at the index
		}
		size--;					// decrease the size by 1
	}
}

// get (retrieve) an item at a specified position in the list
ItemType List::get(int index)
{
	ItemType item;		// default (not successful)
	bool success = index >= 0 && index < size;
	if (success)
	{
		Node* temp = firstNode;
		for (int i = 0; i < index; i++)  	// move to the node at the index
			temp = temp->next;

		item = temp->item;
	}
	return item;
}


// check if the list is empty
bool List::isEmpty() { return (size == 0); }

// check the size of the list
int List::getLength() { return size; }

// display the items in the list
void List::print()
{
	Node* temp = firstNode;

	while (temp != NULL)
	{
		cout << temp->item << "  ";		// print the item
		temp = temp->next;			// move to next node
	}
	cout << endl;
}