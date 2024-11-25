#pragma once
#include <iostream>
using namespace std;

class Book
{
private:
	string title_;
	string author_;
	string iSBN_;

public:
	Book(string title, string author, string iSBN);

public:
	string getTitle();
	string getAuthor();
	string getISBN();

public:
	virtual string displayBookInformation();

};

