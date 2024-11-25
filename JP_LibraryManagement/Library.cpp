#include "Library.h"
#include "PrintedBook.h"
#include "EBook.h"
#include <string>

Library::Library() 
{
	booksCounter_ = 0;
	printedBooksCounter_ = 0;
	eBooksCounter_ = 0;
}

string Library::addBook(string title, string author, string iSBN, int numberOfPages) 
{
	string message = "";

	if (booksCounter_ < size(pBook))
	{
		pBook[booksCounter_] = new PrintedBook(title, author, iSBN, numberOfPages);
		printedBooksCounter_++;
		booksCounter_++;
		cout << endl;
		message = "Book added to the library successfully.";
	}
	else
	{
		message = "Sorry,the library is full; you cannot add more books.";
	}

	return message;

}

string Library::addBook(string title, string author, string iSBN, double fileSize) 
{
	string message = "";

	if (booksCounter_ < size(pBook))
	{
		pBook[booksCounter_] = new EBook(title, author, iSBN, fileSize);
		eBooksCounter_++;
		booksCounter_++;
		cout << endl;
		message = "Book added to the library successfully.";
	}
	else
	{
		message = "Sorry,the library is full; you cannot add more books.";
	}

	return message;

}

string Library::displayBooksList() 
{
	string list = "";

	if (booksCounter_ > 0)
	{
		list += "************* Books inventory *************** \n\n";
		list += "Books: " + to_string(booksCounter_) + '\n';
		list += "Printed Books: " + to_string(printedBooksCounter_) + '\n';
		list += "EBooks: " + to_string(eBooksCounter_) + '\n';
		list += "\n\n";

		for (int i = 0; i < booksCounter_; i++)
		{
			list += "   Book" + to_string(i + 1) + ":" + '\n';
			list += pBook[i]->displayBookInformation();
			list += "\n\n";
		}

		list += "******************************************** \n";
	}
	
	return list;

}

void Library::deallocateMemory()
{
	for (int i = 0; i < booksCounter_; i++)
	{
		delete pBook[i];
		pBook[i] = nullptr;
	}
}
