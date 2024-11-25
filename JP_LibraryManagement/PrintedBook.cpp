#include "PrintedBook.h"
#include <string>

PrintedBook::PrintedBook(string title, string author, string iSBN, int numberOfPages) : Book(title, author, iSBN) 
{
	numberOfPages_ = numberOfPages;
}

int PrintedBook::getNumberOfPages()
{
	return numberOfPages_;
}

string PrintedBook::displayBookInformation() 
{
	string information = "";

	information += Book::displayBookInformation();
	information += "Number of pages: " + to_string(numberOfPages_);

	return information;

}