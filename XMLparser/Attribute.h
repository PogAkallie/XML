#pragma once
#include "XMLobjects.h"
class Attribute :public XMLobject
{
private:
public:
	Attribute() = default;
	Attribute(const MyString& type, const MyString& text);

	/*Attribute(const Attribute& other);
	Attribute& operator=(const Attribute& other);*/


	void setValue(const XMLobject& textToSet);

};

