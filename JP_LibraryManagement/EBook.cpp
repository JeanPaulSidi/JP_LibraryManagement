#include "EBook.h"
#include <string>

EBook::EBook(string title, string author, string iSBN, double fileSize) : Book(title, author, iSBN) 
{
	fileSize_ = fileSize;
}

double EBook::getFileSize()
{
	return fileSize_;
}

string EBook::displayBookInformation() 
{
	string information = "";

	information += Book::displayBookInformation();
	information += "FileSize (in MB): " + to_string(fileSize_);

	return information;

}
