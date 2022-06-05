#pragma once
#include "Attribute.h"


Attribute::Attribute(const MyString& type, const MyString& text) : XMLobject(type, text)
{
	setType(type);
	setText(text);
}

//Attribute::Attribute(const Attribute& other) : XMLobject(other){  }

//Attribute& Attribute::operator=(const Attribute& other)
//{
//	XMLobject::operator=(other);
//	//ToString();
//	return *this;
//}

//void Attribute::setValue(const XMLobject& textToSet)
//{
//	/*size_t length = strlen(textToSet);*/
//}

void Attribute::setValue(const XMLobject& textToSet)
{
	/*delete[] this->text;
	int length = strlen(textToSet);
	char* temp = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = textToSet[i];
	}
	temp[length] = '\0';
	this->getText(text) = temp;*/

}

MyString Attribute::getKey() const
{
	return key;
}

MyString Attribute::getValue() const
{
	return value;
}
