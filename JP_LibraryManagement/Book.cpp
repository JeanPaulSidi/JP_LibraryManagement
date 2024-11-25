#include "Book.h"

Book::Book(string title, string author, string iSBN) 
{
	title_ = title;
	author_ = author;
	iSBN_ = iSBN;
}

string Book::getTitle()
{
	return title_;
}

string Book::getAuthor()
{
	return author_;
}

string Book::getISBN()
{
	return iSBN_;
}

string Book::displayBookInformation() 
{
	string information = "";

	information += "Title: " + title_ + '\n';
	information += "Author: " + author_ + '\n';
	information += "ISBN: " + iSBN_ + '\n';

	return information;

}
