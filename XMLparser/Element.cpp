#include "Element.h"
#include "MyString.h"

int Element::setWhiteSpace(int cursor) // nedovurshena
{
	for (size_t i = 0; i < numberOfParents * 5; cursor++, i++);
	return 0;
}

void Element::CopyElementsCollection(const Element& other)
{
	elementCollection = new ElementsCollection(*other.elementCollection);
}

bool Element::SetAttributeValue(MyString& key, MyString& value)
{
	bool isSucceed = attributeCollection.setAttributeValue(key, value);
	if (!isSucceed)
	{
		for (int i = 0; i < elementCollection->getCount()/*&&!isSucceed*/; i++)
			isSucceed = elementCollection->getElement(i)->SetAttributeValue(key, value);
	}
	return isSucceed;
}

int Element::addKey(bool isStart, int cursor)
{
	cursor = '<';
	if (!isStart)
		cursor = '/';
	//int typeLength = strlen(type);
	//for (int i = 0; i < typeLength; cursor++, i++)
	//{
	//	if (cursor == capacity)
	//	{}	//resize
	//}
	//if (isStart)
	//{
	//	int attributeLength = 0;
	//}

	return 0;
}

Element::Element(const MyString& type, const MyString& text) : XMLobject(type, text)
{
	elementCollection = new ElementsCollection();
	numberOfParents = 0;
	isElementClosed = false; //problem
}


Element::Element(const MyString& type) :XMLobject(type, "")
{
	elementCollection = new ElementsCollection();
	numberOfParents =0;
	isElementClosed = false; //problem
}

Element::Element(const Element& other) : XMLobject(other)
{
	CopyElementsCollection(other);
	attributeCollection = other.attributeCollection;
	numberOfParents = other.numberOfParents;
	isElementClosed = other.isElementClosed;
}

Element& Element::operator=(const Element& other)
{
	if (this != &other)
	{
		XMLobject::operator=(other);
		CopyElementsCollection(other);
	/*	attributeCollection = other.attributeCollection;
		numberOfParents = other.numberOfParents;
		isElementClosed = other.isElementClosed*/;
	}
	return *this;
}

Element::~Element()
{
	delete elementCollection;
}

void Element::AddAttribute(const MyString& type, const MyString& text)
{
	attributeCollection.add(type, text);
}

Element* Element::GetLastChild()
{
	if (getElementsCollection()->getCount() == 0)
		return nullptr;

	return getElementsCollection()->getElement(getElementsCollection()->getCount()-1);
}

void Element::SetNumberOfParents(int number)
{
	if (number < 0)
		throw " Invalid value";
	numberOfParents = number;
}

int Element::NumberOfParents()
{
	return numberOfParents;
}

void Element::AddText(const MyString& textToAdd) //problem
{
	setText(textToAdd);
}

bool Element::IsElementClosed()
{
	return IsElementClosed;
}

void Element::CloseElement()
{
	isElementClosed = true;
}

ElementsCollection* Element::getElementsCollection()
{
	return elementCollection;
}

const MyString Element::getKey() const
{
	return nullptr; //greshno 
}

bool Element::ContainsAttribute(const MyString& key)
{
	int result = attributeCollection.findAttribute(key);
	if (result == -1)
		return false;
	return true;
}

const MyString& Element::GetAttributeValue(const MyString& key)
{
	return attributeCollection.getAttributeValue(key);
}

void Element::SetAttributeValue(const MyString& key, const MyString& value)
{
	/*attributeCollection.setAttributeValue(key, value);*/
}

bool Element::DeleteAttribute(const MyString& key)
{
	return attributeCollection.deleteAttribute(key);
}
