#pragma once
#include <iostream>
#include "MyString.h"

class XMLfile
{
private:
	MyString file;
	MyString contentFileSource;
	MyString* ids;
	size_t idCapacity;
	size_t idCount;
	size_t fileLength;

	void free();
	void copyFrom(const XMLfile& other);

	void addFileContentToCollection();
	void readFile(std::istream&);

	bool isIdTaken(const MyString& id);
	bool isModified;

	MyString concatUniqueCharToId(MyString id, int number);
	MyString generateAutoId(int number);

	void addId(MyString id);

public:
	

};