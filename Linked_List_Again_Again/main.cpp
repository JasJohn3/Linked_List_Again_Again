#include "List.h"
#include <iostream>
#include <string>


void Automated_int_Test();
void Automated_char_Test();
void Automated_string_Test();

int main()
{
	Automated_int_Test();
	Automated_char_Test();
	Automated_string_Test();

	List<int> User_List;
	while (true)
	{
		std::cout << "\t\tWelcome to the User Created List test suite!" << std::endl;
		std::cout << "This testing suite allows you to add integer values into a list." << std::endl;
		std::cout << "Please follow the Menu selection to begin adding values into your list." << std::endl;
		std::cout << "1.) Insert a value into the List" << std::endl;
		std::cout << "2.) Display the values stored in the list" << std::endl;
		std::cout << "3.) Find a value in the list" << std::endl;
		std::cout << "4.) Delete a value inside of the List" << std::endl;
		std::cout << "5.) Exit" << std::endl;

		int menu_select;
		std::cin >> menu_select;
		int User_Data;
		switch (menu_select)
		{
		case 1:
			system("cls");
			std::cout << "Please enter a value to insert: " << std::flush;
			std::cin >> User_Data;
			User_List.Insert(User_Data);
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		case 2:
			std::cout << "This is all of the Data stored in your list: " << std::flush;
			User_List.display();
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		case 3:
			std::cout << "Please enter a value to find: " << std::flush;
			std::cin >> User_Data;
			std::cout << "Data found at node " << User_List.find(User_Data) << std::endl;
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		case 4:
			std::cout << "Please enter a value to delete: " << std::flush;
			std::cin >> User_Data;
			User_List.Remove_NODE(User_Data);
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		case 5:
			exit(0);
		default:
			std::cout << "Invalid information entered." << std::endl;
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		}
	}

}

void Automated_int_Test()
{
	List<int> int_List;
	int_List.Insert(1);
	int_List.Insert(2);
	int_List.Insert(3);
	int_List.Insert(4);
	int_List.Insert(5);
	int_List.display();
	int_List.Remove_NODE(3);
	int_List.display();
	int_List.Remove_NODE(4);
	int_List.display();
	int_List.Remove_NODE(1);
	int_List.display();
	int_List.Remove_NODE(2);
	std::cout << "\nInteger Test Complete" << std::endl;
	system("pause");
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
	char_List.Remove_NODE(C);
	char_List.display();
	char_List.Remove_NODE(D);
	char_List.display();
	char_List.Remove_NODE(A);
	char_List.display();
	char_List.Remove_NODE(B);
	std::cout << "\nCharacter Test Complete" << std::endl;
	system("pause");
	
}

void Automated_string_Test()
{
	
	List<std::string> object_List;

	object_List.Insert("String 1");
	object_List.Insert("String 2");
	object_List.Insert("String 3");
	object_List.Insert("String 4");
	object_List.display();
	object_List.Remove_NODE("String 3");
	object_List.display();
	object_List.Remove_NODE("String 4");
	object_List.display();
	object_List.Remove_NODE("String 1");
	object_List.display();
	object_List.Remove_NODE("String 2");
	std::cout << "\nString Test Complete" << std::endl;
	system("pause");
	
}

