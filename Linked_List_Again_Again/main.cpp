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
	system("pause");
	My_List.Remove_NODE(3);
	system("pause");
	My_List.display();
	system("pause");
	My_List.Remove_NODE(4);
	system("pause");
	My_List.display();
	system("pause");
	My_List.Remove_NODE(1);
	system("pause");
	My_List.display();
	system("pause");
	My_List.Remove_NODE(2);
	system("pause");
}