#pragma once
#include "MyString.h"

class XMLobject
{

private:

	MyString type; //unique id
	MyString text;
	MyString string;
	size_t stringLength;
	size_t capacity;


public:

	XMLobject(const MyString& type, const MyString& text);



	const MyString& getType() const;
	const MyString& getText() const;

	size_t getCapacity() const;

	void setType(const MyString& type);
	void setText(const MyString& text);

	void setCapacity(size_t newCapacity);

	///*virtual*/ void createString() = 0;




};