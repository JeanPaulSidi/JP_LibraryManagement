#pragma once
#include "Book.h"

class EBook : public Book
{
private:
	double fileSize_;

public:
	EBook(string title, string author, string iSBN, double fileSize);

public:
	double getFileSize();

public:
	string displayBookInformation() override;

};

