#pragma once
#include "MyString.h"
#include "Element.h"

class Element;
class ElementsCollection
{
private:
	Element** elements;
	size_t count;
	size_t elementCapacity;

	void free();
	void copyFrom(const ElementsCollection& other);
	void resize();

	size_t copyToString(const char*, size_t);//??
	
	bool isLastElementClosed();

	void addCurrentCollection(const MyString& type, const MyString& text);
	void addCurrentCollection(const MyString& type);
	void addCurrentCollection(Element* element);


public:

	ElementsCollection();
	ElementsCollection(const ElementsCollection& other);
	ElementsCollection& operator=(const ElementsCollection& other);
	~ElementsCollection();

	size_t getCount() const;
	Element* getElement(size_t position) const;
	Element* getElement(MyString& type) const;

	void add(const MyString& type, const MyString& text, const size_t parents = 0);
	void add(const MyString& type);

	void addAttributeToLastUnclosedEl(const MyString& type, const MyString& value);
	void addTextToLastUnclosedEl(const MyString& text);

	bool closeLast(const MyString& type);

	void AddElementToCollectionOfAllElementsInFile(Element*);
	const MyString& GetAttributeValueByOtherAttribute(const MyString&, const MyString&, const MyString&);
	bool SetAttributeValueByOtherAttribute(const MyString&, const MyString&, const MyString&, const MyString&);
	const MyString& getElementTextByAttribute(const MyString&, const MyString&);
	bool deleteAttributeByAttribute(const MyString&, const MyString&, const MyString&);

	Element* findElementByAttribute(const MyString& key, const MyString& value);
	bool addChildenToElement(const MyString&, const MyString&, const MyString&, const MyString&);

	const MyString& getChildrenString(const MyString& key, const MyString& value) const;
	const MyString& getNthChildrenString(const MyString& key, const MyString& value, const size_t n);


};