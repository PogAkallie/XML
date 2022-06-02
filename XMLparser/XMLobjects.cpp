#include "XMLobjects.h"
#pragma warning(disable:4996)
#include <iostream>

//void XMLobject::copyFrom(const XMLobject& other)
//{
//	type = new char[strlen(other.type) + 1];
//	strcpy(type, other.type);
//
//	text = new char[strlen(other.text) + 1];
//	strcpy(text, other.text);
//
//
//	stringLength = other.stringLength;
//}

//void XMLobject::resizeString()
//{
//	char* newCollection = new char[capacity *= 2];
//	for (size_t i = 0; i < stringLength; i++)
//	{
//		newCollection[i] = string[i];
//	}
//	delete[] string;
//	string = newCollection;
//}

XMLobject::XMLobject(const MyString& type, const MyString& text)
{
	setType(type);
	setText(text);
}



//XMLobject& XMLobject::operator=(const XMLobject& other)
//{
//	if (this != &other)
//	{
//		fr
//	}
//}

//XMLobject::XMLobject(const XMLobject& other)
//{
//	copyFrom(other);
//}

//XMLobject& XMLobject::operator=(const XMLobject& other)
//{
//	if (this != &other)
//	{
//		free();
//		copyFrom(other);
//	}
//	return *this;
//}
//
//XMLobject::~XMLobject()
//{
//	free();
//}


const MyString& XMLobject::getType() const
{
	return type;
}

const MyString& XMLobject::getText() const
{
	return text;
}

size_t XMLobject::getCapacity() const
{
	return capacity;
}

void XMLobject::setType(const MyString& type)
{
	size_t typeLen = strlen(type.c_str());
	this->type = new char[typeLen + 1];
	strcpy(this->type.c_str(), type.c_str());
}

void XMLobject::setText(const MyString& text)
{
	size_t textLen = strlen(text.c_str());
	this->text = new char[textLen + 1];
	strcpy(this->text.c_str(), text.c_str());
}

void XMLobject::setCapacity(size_t newCapacity)
{
	this->capacity = newCapacity;
}

