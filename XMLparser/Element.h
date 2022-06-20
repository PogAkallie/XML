#pragma once
#pragma warning(disable:4996)
#include "AttributeCollection.h"
#include "ElementsCollection.h"
#include "MyString.h"

class Element :public XMLobject
{
private:

	AttributeCollection attributeCollection;
	ElementsCollection* elementCollection;
	size_t numberOfParents;
	size_t capacity;
	
	/*int setWhiteSpace(int cursor);*/
	void CopyElementsCollection(const Element& other);
	/*Element* getElement(char* type);*/
	bool SetAttributeValue(MyString& key, MyString& value);
	/*int addKey(bool isStart, int cursor);*/

	/*int copyStrToStr(const char*, int);*/
	

public:
	bool isElementClosed;

	Element(const MyString& type, const MyString& text);
	Element(const MyString& type);
	Element(const Element& other);
	Element& operator=(const Element& other);
	~Element();

	/*Element* getElement(MyString& type);*/

	void AddAttribute(const MyString& type, const MyString& text);

	Element* GetLastChild();
	void SetNumberOfParents(int number);
	int NumberOfParents();
	void AddText(const MyString& text);
	
	bool IsElementClosed();
	void CloseElement();
	ElementsCollection* getElementsCollection();
	/*const MyString getKey() const;*/

	bool ContainsAttribute(const MyString& key);
	const MyString& GetAttributeValue(const MyString& key);
	/*void SetAttributeValue(const MyString& key, const MyString& value);*/
	bool DeleteAttribute(const MyString& key);
};