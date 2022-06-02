#include "AttributeCollection.h"
#pragma once

void AttributeCollection::free()
{
	for (size_t i = 0; i < count; i++)
		delete attributes[i];
	delete[] attributes;
}

void AttributeCollection::copyFrom(const AttributeCollection& other)
{
	attributes = new Attribute * [other.capacity];
	count = other.count;
	capacity = other.capacity;

	for (size_t i = 0; i < count; i++)
		attributes[i] = other.attributes[i];
}

void AttributeCollection::resize()
{
	Attribute** newCollection = new Attribute * [capacity *= 2];
	for (size_t i = 0; i < count; i++)
		newCollection[i] = attributes[i];
	delete[] attributes;
	attributes = newCollection;
}

int AttributeCollection::getAttributeStringLength(int index)
{
	if (index > count)
		return -1;
	MyString str = attributes[index];
}

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
	string = nullptr;
	stringCapacity = 300;
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

void AttributeCollection::add(const MyString& type, const MyString& text)
{
	Attribute* attribute = new Attribute(type, text);
	add(attribute);
}

size_t AttributeCollection::getCount() const
{
	return count;
}

const char* AttributeCollection::getAttributeValue(const char* key) const
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(attributes[i]->getKey(), key) == 0)
		{
			return attributes[i]->getValue();
		}
	}
	return nullptr;
}

bool AttributeCollection::setAttributeValue(const char* key, const char* value)
{
	for (size_t i = 0; i < count; i++)
	{
		if (_stricmp(attributes[i]->getKey(), key) == 0)
		{
			attributes[i]->setValue(value);
			return true;
		}
	}
	return false;
}

AttributeCollection::AttributeCollection(const AttributeCollection& other)
{
	copyFrom(other);
}
