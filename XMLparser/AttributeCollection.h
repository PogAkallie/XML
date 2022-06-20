#pragma once
#include "Attribute.h"

class AttributeCollection
{
private:

	Attribute** attributes;
	MyString key;
	MyString value;

	size_t count;
	size_t capacity;

	void free();
	void copyFrom(const AttributeCollection& other);
	void resize();

	void add(Attribute* attribute);

public:

	AttributeCollection();
	AttributeCollection(const AttributeCollection& other);
	AttributeCollection& operator=(const AttributeCollection& other);
	~AttributeCollection();

	void add(const MyString& type, const MyString& text);
	size_t getCount() const;


	MyString getAttributeValue(const MyString& key) const;
	bool setAttributeValue(MyString& key,MyString& value);


	size_t findAttribute(const MyString& key);//?
	bool deleteAttribute(const MyString& key);//?
};