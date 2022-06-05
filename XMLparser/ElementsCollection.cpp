#include "ElementsCollection.h"
#pragma once

ElementsCollection::ElementsCollection()
{
	count = 0;
	elementCapacity = 0;
	elements = new Element * [0];
}

ElementsCollection::ElementsCollection(const ElementsCollection& other)
{
	copyFrom(other);
}

ElementsCollection& ElementsCollection::operator=(const ElementsCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ElementsCollection::~ElementsCollection()
{
	free();
}

size_t ElementsCollection::getCount() const
{
	return count;
}

Element* ElementsCollection::getElement(size_t position) const
{
	if (position >= getCount())
		throw "Invalid Index";
	return elements[position];
}

void ElementsCollection::add(const MyString& type, const MyString& text, const size_t parents)
{
	if (count > 0)
	{
		if (getElement(count - 1)->isElementClosed())
		{
			addCurrentCollection(type, text);
			getElement(count - 1)->setNumberOfParents(parents);
		}
		else
		{
			getElement(count - 1)->getElemensCollection()->add(type, text, parents + 1);
		}
	}
	else
	{
		addCurrentCollection(type, text);
		getElement(count - 1)->setNumberOfParents(parents);
	}
}

void ElementsCollection::add(const MyString& type)
{
	add(type, "");
}

void ElementsCollection::free()
{
	for (size_t i = 0; i < count; i++)
		delete elements[i];
	delete[] elements;
}

void ElementsCollection::copyFrom(const ElementsCollection& other)
{
	elements = new Element * [other.elementCapacity];
	elementCapacity = other.elementCapacity;
	count = other.count;

	for (size_t i = 0; i < count; i++)
		elements[i] = other.elements[i];
}

void ElementsCollection::resize()
{
	Element** newCollection = new Element * [elementCapacity *= 2];
	for (size_t i = 0; i < count; i++)
		newCollection[i] = elements[i];
	delete[] elements;
	elements = newCollection;
}

bool ElementsCollection::isLastElementClosed()
{
	return (count==0 || getElement(count-1)->isElementClosed());
}

void ElementsCollection::addCurrentCollection(const MyString& type, const MyString& text)
{
	Element* element = new Element(type, text);
	addCurrentCollection(element);
}

void ElementsCollection::addCurrentCollection(const MyString& type)
{
	Element* element = new Element(type);
	addCurrentCollection(element);
}

void ElementsCollection::addCurrentCollection(Element* element)
{
	if (count == elementCapacity)
		resize();
	elements[count] = element;
	count++;
}
