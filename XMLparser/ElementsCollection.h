#pragma once
#include "MyString.h"
#include "Element.h"

class ElementsCollection
{
private:

	Element** elements;
	size_t count;
	size_t elementCapacity;

	void free();
	void copyFrom(const ElementsCollection& other);
	void resize();
	
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
	Element* getElement(int position);

	void add(const MyString& type, const MyString& text, int parents=0);
	void add(const MyString& type);

	/*void addAttributeToLastUnclosedEl(const MyString& type, const MyString& value);
	void addTextToLastUnclosedEl(const MyString& text);*/

	bool closeLast(const MyString& type);

	/*void AddElementToCollectionOfAllElementsInFile(Element*);*/
	const MyString& GetAttributeValueByOtherAttribute(const MyString& attrKey, const MyString& attrValue, const MyString& keySearched);
	bool SetAttributeValueByOtherAttribute(const MyString&, const MyString&, const MyString&, const MyString&);
	const MyString& getElementTextByAttribute(const MyString& attrKey, const MyString& attrValue); // geetValue ne e razpisana
	bool deleteAttributeByAttribute(const MyString&, const MyString&, const MyString&);

	Element* findElementByAttribute(const MyString& key, const MyString& value); //ne e misleno
	bool addChildenToElement(const MyString& attrKey, const MyString& attrValue, const MyString& elementName, const MyString& elementText);

	/*const MyString& getChildrenString(const MyString& key, const MyString& value) const;
	const MyString& getNthChildrenString(const MyString& key, const MyString& value, const size_t n);*/ //sus string


};