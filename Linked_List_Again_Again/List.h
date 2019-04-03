#pragma once
#ifndef LIST_H
#define LIST_H
#include <cstddef>
#include <iostream>

template <typename Type>
struct  NODE
{
	//You must declare these initial values to create a node.  Data is the value of the information stored within the node.
	//Next and Previous are values pointing to the Nodes being created in memory
	Type Data;
	NODE *next;
	NODE *previous;

	NODE()
	{
		//the constructor of the Node class assigns Null values to the pointers and the Data type
		//Removed Null value in Data to allow strings to be passed into the template <Type>.  Strings cannot be set to Null.
		Data/* = NULL*/;
		next = nullptr;
		previous = nullptr;
	}
};
template <typename Type>
class List
{
public:
	//constructor of List class
	List()
	{
		//This is the constructor for our list. It creates two Nodes head and tail and points them at each other.
		//Assign the head to an empty NODE.
		Head = new NODE<Type>;
		//Assign the Tail to an empty NODE.
		Tail = new  NODE<Type>;
		//Removed NULL assignment to allow for strings to be passed in as a data type.  Strings cannot be set to NULL.
		//Head->Data = NULL;
		Head->previous = nullptr;
		//Point our Head to our Tail using head->next
		Head->next = Tail;
		//Removed NULL assignment to allow for strings to be passed in as a data type.  Strings cannot be set to NULL.
		//Tail->Data = NULL;
		Tail->next = nullptr;
		//Point our Tail to the Head using Tail->previous
		Tail->previous = Head;
		//Head and tail are now connected.
	}
	~List()
	{

		//this is the deconstructor for our linked list.

		//we declare two NODE pointers to perform our delete functions to ensure no data loss.
		NODE<Type>* temp = Head;
		NODE<Type>* Remove_Node=nullptr;
		//while loop iterates through the list checking for null values at the end of the list.
		while (temp != nullptr)
		{
			//set Remove_Node to temp.  This creates a copy of our Node to store the Nodes pointer values and data until ready for deletion.
			Remove_Node = temp;
			//This line sets our temp node to the next Node in our list.
			temp = temp->next;
			//This uses our Remove_Node() Method from our class to remove any Nodes still in our list between the head and the tail.
			Remove_NODE(Remove_Node->Data);
		}
		//Finally, the two lines below delete the Head and the Tail which is prevented within our Remove_Node() Method to protect Data Loss.
		delete Head;
		delete Tail;
	}

	void insertion_sort()
	{
		NODE<Type>* current = Head->next;
		

		while (current->next != Tail)
		{
			NODE<Type> * compare = current->next;
			 if (current->Data > compare->Data)
			{
				NODE<Type>* temp = compare->next;
				compare->next = current;
				compare->previous = current->previous;
				current->previous->next = compare;
				current->previous = compare;
				current->next = temp;
				temp->previous = current;
				current = Head;
			}

			current = current->next;
		}
	}
	//Insert function uses a pointer to the NODE object and Insert()Method contains the type of data being passed into the list
	void Insert(Type Data)
	{
		//declaring an reference to an Object of NODE class using the variable current.
		NODE<Type> *current = new NODE<Type>();
		//Assigning a value to the Null value of data using the pointer
		current->Data = Data;
		//check to see if the list is empty.  If the list is empty assign head and tail to the value of current
		if (Head->next == nullptr)
		{
			Head->next = current;
			Tail->previous = current;
		}
		//If the list is not Empty insert a Node between the head or the last NODE in our list and the tail by moving the tail pointer.
		else
		{
			current->previous = Tail->previous;
			current->next = Tail;
			Tail->previous->next = current;
			Tail->previous = current;
		}

		
	}
	//This function searches for values contained within our list
	//NODE<Type>* is a pointer to a NODE
	//Type Value is the data we want to find in our list
	NODE<Type>* find(Type Value)
	{
		//We set our NODE pointer to the Head NODE to find the beginning of the list
		NODE<Type> * current = Head;
		//We search the list comparing our NODE->Data Value to the Value entered into our Method
		while (current->Data != Value)
		{
			//This line points our Current NODE to the next NODE in our list.
			current = current->next;
			//If we reach the Tail of our List and the Value is not found, we inform the user and return a null pointer.
			if (current==Tail)
			{
				std::cout << "\nThat Value does not exists within the List!" << std::endl;
				return nullptr;
			}
		}
		//return the NODE pointer
		return current;
	}
	//This Method removes NODEs between our Head and Tail.
	void Remove_NODE(Type value)
	{
		//We create a NODE pointer Delete_Node that calls our Method find() and passes the Data Value entered.
		NODE<Type> * Delete_Node=this->find(value);
		//This prevents our Delete Method from Deleting the Head and the Tail from our list.  It infoms the user that these items cannot be deleted.
		if (Delete_Node==nullptr||Delete_Node==Tail||Delete_Node==Head)
		{
			std::cout << "\nCannot Delete Node.  Invalid request!" << std::endl;
		}
		else
		{
			//This reassigns our pointer values to reconnect our List and remove the Current Node found.
			Delete_Node->next->previous = Delete_Node->previous;
			Delete_Node->previous->next = Delete_Node->next;
		}
	}
	//A simple display function that iterates through our list until a null pointer is found indicating the end of the list.
	void display() {
		NODE<Type>* head_pointer=Head;
		NODE<Type>* tail_pointer = Tail;
		//Searches through the list from the Head until there is a nullptr value indicating the end of the list
		//displays the Node->data value each time.
		while (head_pointer != nullptr)
		{
			std::cout << head_pointer->Data << " ";
			//change the head_pointer to the next Node in our list.
			head_pointer = head_pointer->next;
		}
		//Searches through the list from the tail until there is a nullptr value indicating the beginning of the list
		//displays the Node->data value each time.
		while (tail_pointer != nullptr)
		{
			std::cout << tail_pointer->Data << " ";
			//change the tail_pointer to the previous Node in our list.
			tail_pointer = tail_pointer->previous;
		}
		
	}


private:


	//Head and tails are pointers to an Area of Memory to show the beginning of the list and the end of the list.
	NODE<Type>* Head;
	NODE<Type>* Tail;
};
#endif
