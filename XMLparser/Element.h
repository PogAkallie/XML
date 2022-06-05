#pragma once
#include "AttributeCollection.h"
#include "ElementsCollection.h"

class Element :public XMLobject
{
private:

	AttributeCollection attributeCollection;
	ElementsCollection* elementColletion;
	size_t numberOfParents;
	
	int setWhiteSpace(int);
	void CopyElementsCollection(const Element& other);
	Element* getElement(char* type);
	bool SetAttributeValue(char* key, char* value);
	int addKey(bool, int);

	/*int copyStrToStr(const char*, int);*/
	

public:

	Element(const char*, const char*);
	Element(const char*);
	~Element();
	Element(const Element& other);
	Element& operator=(const Element& other);

	bool isElementClosed;
	Element* getElement(MyString& type) const;

	void AddAttribute(const char* type, const char* text);
	Element* GetLastChild();
	void SetNumberOfParents(int);
	int NumberOfParents();
	void AddText(const char* text);
	const char* GetAttributeValue(const char* key);
	bool IsElementClosed();
	void CloseElement();
	ElementsCollection* getElementsCollection();
	bool ContainsAttribute(const char* key);
	void SetAttributeValue(const char* key, const char* value);
	bool DeleteAttribute(const char* key);
};