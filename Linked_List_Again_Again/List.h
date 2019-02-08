#pragma once
#ifndef LIST_H
#define LIST_H
#include <cstddef>
#include <iostream>

template <typename Type>
struct  NODE
{
	//You must declare these initial values to create a node.  Data is the value of the information stored within the node.
	//Next and Previous are values pointing to Areas within the Heap memory
	Type Data;
	NODE *next;
	NODE *previous;

	NODE()
	{
		//the constructor of the Node class assigns Null values to the pointers and the Data type
		Data = NULL;
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
		Head = new NODE<Type>;
		Tail = new  NODE<Type>;
		Head->Data = NULL;
		Head->previous = nullptr;
		Head->next = Tail;
		Tail->Data = NULL;
		Tail->next = nullptr;
		Tail->previous = Head;
	}
	~List()
	{

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
		//If the list is not Empty point the value of tail to current; then point the value of previous to tail;  Last assign the current value of current too tail;
		else
		{
			current->previous = Tail->previous;
			current->next = Tail;
			Tail->previous->next = current;
			Tail->previous = current;
		}

		
	}
	NODE<Type>* find(Type Value)
	{
		NODE<Type> * current = Head;
		while (current->Data != Value)
		{
			current = current->next;
			if (current==Tail)
			{
				std::cout << "That Value does not exists within the List!" << std::endl;
				return nullptr;
			}
		}
		return current;
	}
	void Remove_NODE(Type value)
	{
		NODE<Type> * Delete_Node=this->find(value);
		if (Delete_Node==nullptr||Delete_Node==Tail||Delete_Node==Head)
		{
			std::cout << "Cannot Delete Node.  Invalid request!" << std::endl;
		}
		else
		{
			Delete_Node->next->previous = Delete_Node->previous;
			Delete_Node->previous->next = Delete_Node->next;
		}


	}

	void display() {
		NODE<Type>* pointer=Head;
		
		while (pointer != nullptr)
		{
			std::cout << pointer->Data << " ";
			pointer = pointer->next;
		}
	}


private:


	//Head and tails are pointers to an Area of Memory to show the beginning of the list and the end of the list.
	NODE<Type>* Head;
	NODE<Type>* Tail;
};
#endif
