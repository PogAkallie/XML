#include "ElementsCollection.h"


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

Element* ElementsCollection::getElement(int position) 
{
	if (position >= getCount())
		throw "Invalid Index";
	return elements[position];
}

//ElementsCollection& ElementsCollection::getElement(size_t position) const
//{
//	if (position >= count)
//		throw "invalid index";
//	ElementsCollection** newElements = new ElementsCollection * [elementCapacity];
//	position = elementCapacity;
//	return newElements[position];
//}

//ElementsCollection& ElementsCollection::getElement(MyString& type) const
//{
//	return;
//}

void ElementsCollection::add(const MyString& type, const MyString& text, int parents)
{
	Element* e;
	if (count > 0)
	{
		if (e->IsElementClosed())
		{
			addCurrentCollection(type, text);
			getElement(count - 1)->SetNumberOfParents(parents);
		}
		else
		{
			getElement(count - 1)->getElementsCollection()->add(type, text, parents + 1);
		}
	}
	else
	{
		addCurrentCollection(type, text);
		getElement(count - 1)->SetNumberOfParents(parents);
	}
}

void ElementsCollection::add(const MyString& type)
{
	add(type, "");
}

bool ElementsCollection::closeLast(const MyString& type)
{
	if (isLastElementClosed())
		return false;
	else
	{
		if (!getElement(count - 1)->getElementsCollection()->isLastElementClosed())
			return getElement(count - 1)->getElementsCollection()->closeLast(type);
		else
		{
			if (strcmp(getElement(count - 1)->getKey().c_str(), type.c_str()) == 0)
			{
				getElement(count - 1)->CloseElement();
				return true;
			}
			else
				return false;
		}
	}
	return false;
}

const MyString& ElementsCollection::GetAttributeValueByOtherAttribute(const MyString& attrKey, const MyString& attrValue, const MyString& keySearched)
{
	Element* searched = findElementByAttribute(attrKey, attrValue);
	if (searched == nullptr)
		return nullptr;
	return searched->GetAttributeValue(keySearched);

}

bool ElementsCollection::SetAttributeValueByOtherAttribute(const MyString& attrKey, const MyString& attrValue, const MyString& attrNameToChangeValue, const MyString& attrValueToChangeValue)
{
	Element* searched = findElementByAttribute(attrKey, attrValue);
	if (searched == nullptr)
		return false;
	searched->SetAttributeValue(attrNameToChangeValue, attrValueToChangeValue);
	return true;
}

const MyString& ElementsCollection::getElementTextByAttribute(const MyString& attrKey, const MyString& attrValue)
{
	Element* searched = findElementByAttribute(attrKey, attrValue);
	if (searched == nullptr)
		return "";
	/*return  searched->getValue();*/
}

bool ElementsCollection::deleteAttributeByAttribute(const MyString& attrKey, const MyString& attrValue, const MyString& keySearched)
{
	Element* searched = findElementByAttribute(attrKey, attrValue);
	if (searched == nullptr)
		return false;
	return searched->DeleteAttribute(keySearched);
}

Element* ElementsCollection::findElementByAttribute(const MyString& key,const MyString& value)
{
	Element* el;
	if (count == 0)
		return nullptr;
	//for (int i = 0; i < count; i++)
	//{
	//	const MyString k = elements[i]->GetAttributeValue(key).c_str();
	//	if (strcmp(k.c_str(), value == 0)) //==?
	//		return elements[i];
	//	else
	//		el = elements[i]->getElementsCollection()->findElementByAttribute(key, value);
	//	if (el != nullptr)
	//		return el;
	//}
	return nullptr;
}

bool ElementsCollection::addChildenToElement(const MyString& attrKey, const MyString& attrValue, const MyString& elementName, const MyString& elementText)
{
	Element* searched = findElementByAttribute(attrKey, attrValue);
	if (searched == nullptr)
		return false;
	searched->getElementsCollection()->add(elementName, elementText, searched->NumberOfParents() + 1);
	searched->getElementsCollection()->closeLast(elementName);
	return true;
	return false;
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
	return /*(count==0 || getElement(count-1)->isElementClosed())*/;
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
