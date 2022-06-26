#include "XMLfile.h"
#include "Element.h"
#include <iostream>
#include <fstream>
void printMenu()
{
	std::cout << "0 -> Open" << std::endl;

	std::cout << "1 -> Save" << std::endl;
	std::cout << "2 -> Save as" << std::endl;
	std::cout << "3 -> Print" << std::endl;
	std::cout << "4 -> Select" << std::endl;
	std::cout << "5 -> Set" << std::endl;
	std::cout << "6 -> Children" << std::endl;
	std::cout << "7 -> Child" << std::endl;
	std::cout << "8 -> Text" << std::endl;
	std::cout << "9 -> Delete" << std::endl;
	std::cout << "10 -> NewChild" << std::endl;
	std::cout << "11 -> Exit without saving" << std::endl;

}

int main()
{

	//char d[30];
	//char c[30];
	//std::cin >> d >> c;
	//
	int input = -1;
	/*std::cin >> input;*/
	XMLfile* file = nullptr;

	bool working = true;
	bool openedFile = false;
	printMenu();
	while (working)
	{

		std::cout << "Your command:" << std::endl;
		std::cin.clear();
		std::cin >> input;


		switch (input)
		{
		case 0:
		{
			char fileName[50];
			std::cout << "Enter the name of the file:" << std::endl;
			std::cin.clear();
			std::cin >> fileName;
			if (file != nullptr)
				delete file;
			file = new XMLfile(fileName);
			if (file->ifFailed())
				std::cout << "Error while opening file" << std::endl;
			else
			{
				std::cout << "File succesfully opened" << std::endl;
				openedFile = true;
			}
			break;
		}

		
		}

	}
}