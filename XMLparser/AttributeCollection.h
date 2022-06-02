#pragma once
#include "Attribute.h"

class AttributeCollection
{
private:

	Attribute** attributes;
	MyString string;
	size_t stringCapacity;
	size_t count;
	size_t capacity;

	void free();
	void copyFrom(const AttributeCollection& other);
	void resize();

	int getAttributeStringLength(int index);//not written
	void add(Attribute* attribute);
	void createString();

public:

	AttributeCollection();
	AttributeCollection(const AttributeCollection& other);
	AttributeCollection& operator=(const AttributeCollection& other);
	~AttributeCollection();

	void add(const MyString& type, const MyString& text);
	/*char* ToString(); */
	size_t getCount() const;

	const char* getAttributeValue(const char* key) const;
	bool setAttributeValue(const char* key, const char* value);

	size_t findAttribute(const char* key);
	bool deleteAttribute(const char* key);
};