#include "AttributeCollection.h"
#include "MyString.h"
#pragma warning(disable:4996)

void AttributeCollection::free()
{
	for (size_t i = 0; i < count; i++)
	{ delete attributes[i]; }
	delete[] attributes;
}

void AttributeCollection::copyFrom(const AttributeCollection& other)
{
	attributes = new Attribute * [other.capacity];
	count = other.count;
	capacity = other.capacity;

	for (size_t i = 0; i < count; i++)
	{
		attributes[i] = other.attributes[i];
	}
}

void AttributeCollection::resize()
{
	Attribute** newCollection = new Attribute * [capacity *= 2];
	for (size_t i = 0; i < count; i++)
		newCollection[i] = attributes[i];
	delete[] attributes;
	attributes = newCollection;
}

//adding attribute
void AttributeCollection::add(Attribute* attribute)
{
	if (count == capacity)
		resize();
	attributes[count] = attribute; //???
	count++;
}

AttributeCollection::AttributeCollection()
{
	count = 0;
	capacity = 0;
	attributes = new Attribute * [8];
}

AttributeCollection& AttributeCollection::operator=(const AttributeCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

AttributeCollection::~AttributeCollection()
{
	free();
}

//adding text and type
void AttributeCollection::add(const MyString& type, const MyString& text)
{
	Attribute* attribute = new Attribute(type, text);
	add(attribute);
}

size_t AttributeCollection::getCount() const
{
	return count;
}

MyString AttributeCollection::getAttributeValue(const MyString& key) const
{
	for (int i = 0; i < count; i++)
	{
		key.compare(key);
	}
	return "";
}

bool AttributeCollection::setAttributeValue(MyString& key,MyString& value)
{
	for (size_t i = 0; i < count; i++)
	{
		if (_stricmp(attributes[i]->getKey().c_str(), key.c_str()) == 0)
		{
			/*attributes[i]->setValue(value.c_str());*/
			return true;
		}
	}
	return false;
}

size_t AttributeCollection::findAttribute(const MyString& key)
{
	return 0;
}

bool AttributeCollection::deleteAttribute(const MyString& key)
{
	return false;
}

AttributeCollection::AttributeCollection(const AttributeCollection& other)
{
	copyFrom(other);
}
