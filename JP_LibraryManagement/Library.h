#pragma once
#include "Book.h"

class Library
{
private:
	Book* pBook[10];
	int booksCounter_;
	int printedBooksCounter_;
	int eBooksCounter_;

public:
	Library();

public:
	string addBook(string title, string author, string iSBN, int numberOfPages);

	string addBook(string title, string author, string iSBN, double fileSize);

	string displayBooksList();

	void deallocateMemory();
};

