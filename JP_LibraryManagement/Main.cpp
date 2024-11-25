#include <iostream>
#include <string>
#include <conio.h>
#include "Library.h"
using namespace std;


void displayIntroduction() 
{

	cout << "*************************************************" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "*              LIBRARY  MANAGEMENT              *" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "Press any key to start the program... ";

	_getch();
	system("cls");
	
}

void displayMenu()
{

	cout << "What would you like to do?" << endl;
	cout << endl;
	cout << "1. Add Printed Book" << endl;
	cout << "2. Add EBook" << endl;
	cout << "3. Display the Books Inventory" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
}

int getMenuChoice()
{
	int choice;

	cout << "Enter your choice: ";
	cin >> choice;

	while (cin.fail() || choice < 1 || choice > 4)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Invalid input; Please enter whole number between  1 and 4: ";
		cin >> choice;
	}

	return choice;
}

void getNewBookInfo(string* pTitle, string* pAuthor, string* pISBN, int* pNumberOfPages)
{
	cout << "Adding new printed book to the library..." << endl;
	cout << endl;

	cout << "Enter the book title: ";
	cin.ignore(INT_MAX, '\n');
	getline(cin, *pTitle);
	cout << "Enter the book author: ";
	getline(cin, *pAuthor);
	cout << "Enter the book ISBN: ";
	getline(cin, *pISBN);

	cout << "Enter the number of pages: ";
	cin >> *pNumberOfPages;
	while (cin.fail() || *pNumberOfPages <= 0)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Invalid input; Please enter a whole number greater than 0: ";
		cin >> *pNumberOfPages;
	}
	cout << endl;
}

void getNewBookInfo(string* pTitle, string* pAuthor, string* pISBN, double* pFileSize)
{
	cout << "Adding new Ebook to the library..." << endl;
	cout << endl;

	cout << "Enter the book title: ";
	cin.ignore(INT_MAX, '\n');
	getline(cin, *pTitle);
	cout << "Enter the book author: ";
	getline(cin, *pAuthor);
	cout << "Enter the book ISBN: ";
	getline(cin, *pISBN);

	cout << "Enter the file size (in MB): ";
	cin >> *pFileSize;
	while (cin.fail() || *pFileSize <= 0)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Invalid input; Please enter an number greater than 0: ";
		cin >> *pFileSize;
	}
	cout << endl;
}

void returnToMenu() 
{
	cout << endl;
	cout << "Press any key to return to the menu... ";
	_getch();
	system("cls");

}


int main()
{
	string title = "";
	string author = "";
	string iSBN = "";
	int numberOfPages = 0;
	double fileSize = 0;
	int MenuChoice;
	string message;

	while (true)
	{
		displayIntroduction();

		Library libraryManager;

		cout << "Welcome back!" << endl;

		do
		{
			displayMenu();

			MenuChoice = getMenuChoice();

			switch (MenuChoice)
			{
			case 1:
				system("cls");

				getNewBookInfo(&title, &author, &iSBN, &numberOfPages);
				message = libraryManager.addBook(title, author, iSBN, numberOfPages);
				cout << message << endl;

				returnToMenu();
				break;

			case 2:
				system("cls");

				getNewBookInfo(&title, &author, &iSBN, &fileSize);
				message = libraryManager.addBook(title, author, iSBN, fileSize);
				cout << message << endl;

				returnToMenu();
				break;

			case 3:
				system("cls");

				message = libraryManager.displayBooksList();

				if (message == "")
				{
					cout << "The library is empty; you should start by adding books." << endl;
				}
				else
				{
					cout << message << endl;
				}

				returnToMenu();

				break;

			case 4:
				libraryManager.deallocateMemory();
				system("cls");
				break;

			default:
				break;
			}

		} while (MenuChoice != 4);

	}

	return 0;
}


