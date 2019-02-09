#include "List.h"
#include <iostream>
#include <string>

void Automated_int_Test();
void Automated_char_Test();
/*void Automated_OBJECT_Test();*/
int main()
{
	Automated_int_Test();
	Automated_char_Test();
	/*Automated_OBJECT_Test();*/

}
void Automated_int_Test()
{
	List<int> int_List;

	int_List.Insert(1);
	int_List.Insert(2);
	int_List.Insert(3);
	int_List.Insert(4);
	int_List.display();
	system("pause");
	int_List.Remove_NODE(3);
	system("pause");
	int_List.display();
	system("pause");
	int_List.Remove_NODE(4);
	system("pause");
	int_List.display();
	system("pause");
	int_List.Remove_NODE(1);
	system("pause");
	int_List.display();
	system("pause");
	int_List.Remove_NODE(2);
	system("pause");
	int_List.~List();
}
void Automated_char_Test()
{
	List<char> char_List;
	char A = 'A';
	char B = 'B';
	char C = 'C';
	char D = 'D';
	char_List.Insert(A);
	char_List.Insert(B);
	char_List.Insert(C);
	char_List.Insert(D);
	char_List.display();
	system("pause");
	char_List.Remove_NODE(3);
	system("pause");
	char_List.display();
	system("pause");
	char_List.Remove_NODE(4);
	system("pause");
	char_List.display();
	system("pause");
	char_List.Remove_NODE(1);
	system("pause");
	char_List.display();
	system("pause");
	char_List.Remove_NODE(2);
	system("pause");
	char_List.~List();
}
/*
void Automated_OBJECT_Test()
{

	List<Class_Some_Object> object_List;
	Class_Some_Object Object1;
	Class_Some_Object Object2;
	Class_Some_Object Object3;
	Class_Some_Object Object4;
	object_List.Insert(Object1.display);
	object_List.Insert(Object2.display);
	object_List.Insert(Object3.display);
	object_List.Insert(Object4.display);
	object_List.display();
	system("pause");
	object_List.Remove_NODE(3);
	system("pause");
	object_List.display();
	system("pause");
	object_List.Remove_NODE(4);
	system("pause");
	object_List.display();
	system("pause");
	object_List.Remove_NODE(1);
	system("pause");
	object_List.display();
	system("pause");
	object_List.Remove_NODE(2);
	system("pause");
	object_List.~List();
}
*/

