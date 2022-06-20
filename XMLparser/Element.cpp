#include "Element.h"
#include "MyString.h"

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
		attributeCollection = other.attributeCollection;
		numberOfParents = other.numberOfParents;
		isElementClosed = other.isElementClosed;
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

void Element::CloseElement()
{
	isElementClosed = true;
}

bool Element::IsElementClosed()
{
	return IsElementClosed;
}

ElementsCollection* Element::getElementsCollection()
{
	return elementCollection;
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

bool Element::DeleteAttribute(const MyString& key)
{
	return attributeCollection.deleteAttribute(key);
}
