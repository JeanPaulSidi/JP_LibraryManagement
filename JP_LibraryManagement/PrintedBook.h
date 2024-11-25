#pragma once
#include "Book.h"

class PrintedBook : public Book
{
private:
	int numberOfPages_;

public:
	PrintedBook(string title, string author, string iSBN, int numberOfPages);

public:
	int getNumberOfPages();

public:
	string displayBookInformation() override;

};

