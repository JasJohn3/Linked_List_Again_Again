#include "List.h"
#include <iostream>

int main()
{
	List<int> My_List;

	My_List.Insert(1);
	My_List.Insert(2);
	My_List.Insert(3);
	My_List.Insert(4);
	My_List.display();
	My_List.Delete(3);
	My_List.display();
	My_List.Delete(4);
	My_List.display();
	My_List.Delete(1);
	My_List.display();
	My_List.Delete(2);
}