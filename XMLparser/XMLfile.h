#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "ElementsCollection.h"
#include "MyString.h"
using namespace std;


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
	void resize();

	/*void addFileContentToCollection();*/
	size_t getFileSize(ifstream& f);
	void readFile(XMLfile*& ptr, size_t& idCount, ifstream& f);

	bool isIdTaken(MyString& id);
	bool isModified;
	bool isFail;

	/*MyString concatUniqueCharToId(MyString id, int number);*/
	/*MyString generateAutoId(int number);*/

	void addId(MyString id);

public:
	ElementsCollection elements;

	XMLfile() = default;
	XMLfile(const char* fileName);
	XMLfile(const MyString& other);
	XMLfile& operator=(const XMLfile& other);
	~XMLfile();

	bool ifFailed();

	const MyString select(const MyString& id, const MyString& key);
	bool set(const MyString& id, const MyString& key, const MyString& value);

	const MyString& text(const MyString& id);

	const MyString& Delete(const MyString& id, const MyString& key);

	void Save(ofstream& fileName);

	/*const MyString& Children(const MyString&);
	const MyString& Child(const MyString&, const int);*/
	/*const MyString& addChild(const MyString&, const MyString& , const MyString&);*/



};