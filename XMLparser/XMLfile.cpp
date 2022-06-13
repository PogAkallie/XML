#include "XMLfile.h"
#include <iostream>
#include <fstream>
#include <cstring>

void XMLfile::free()
{
	for (size_t i = 0; i < idCount; i++)
		delete &ids[i];
	delete[] ids;
}

void XMLfile::copyFrom(const XMLfile& other)
{
	ids = new MyString[other.idCapacity];
	contentFileSource = other.contentFileSource;
	elements = other.elements;

	for (size_t i = 0; i < idCapacity; i++)
		ids[i] = other.ids[i];

	isFail = other.isFail;
	isModified = other.isModified;

	file = nullptr; //?




}

void XMLfile::resize()
{
	MyString* newCollection = new MyString  [idCapacity *= 2];
	for (size_t i = 0; i < idCount; i++)
		newCollection[i] = ids[i];
	delete[] ids;
	ids = newCollection;
}

size_t XMLfile::getFileSize(ifstream& f)
{
	size_t currentPosition = f.tellg();

	f.seekg(0, ios::end);
	size_t result = f.tellg();
	f.seekg(currentPosition);
	return result;
}

void XMLfile::readFile(XMLfile*& ptr, size_t& idCount, ifstream& f)
{
	size_t sizeOfFile = getFileSize(f);
	idCount = sizeOfFile / sizeof(XMLfile);
	ptr = new XMLfile[idCount];
	f.read((char*)ptr, sizeOfFile);
	//? char*
}

bool XMLfile::isIdTaken(MyString& id)
{
	for (int i = 0; i < idCount; i++)
	{
		if (strcmp(id.c_str(), ids[i].c_str()) == 0)
		{
			return true;
		}
	}
	return false;
}

void XMLfile::addId(MyString id)
{
	if (idCapacity == idCount)
		resize();

	int length = strlen(id.c_str());
	MyString tempStr = new char[length + 1];
	strcpy(tempStr.c_str(), id.c_str());
	tempStr[length] = '\0';

	ids[idCount] = tempStr;
	idCount++;

}

XMLfile::XMLfile(const char* fileName)
{
	std::ifstream f;
	f.open(fileName);
	if (!f.is_open())
	{
		file = nullptr;
		ids = nullptr;
		isFail = true;
		return;
	}

	size_t length = strlen(fileName);
	contentFileSource = new char[length + 1];
	strcpy(contentFileSource.c_str(), fileName);
	contentFileSource[length] = '\0';

	idCapacity = 5;
	ids = new MyString[idCapacity];
	/*readFile(f);*/
	/*addFileContentToCollection();*/
	isModified = true;
	f.close();

}

XMLfile::XMLfile(const MyString& other)
{
	copyFrom(other);
}

XMLfile& XMLfile::operator=(const XMLfile& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

XMLfile::~XMLfile()
{
	free();
}

bool XMLfile::ifFailed()
{
	return isFail;
}

const MyString XMLfile::select(const MyString& id, const MyString& key)
{
	const MyString result = elements.GetAttributeValueByOtherAttribute("id", id, key);
	if (result == nullptr)
		return "";
	return result;
}

bool XMLfile::set(const MyString& id, const MyString& key, const MyString& value)
{
	bool isSuccessful = elements.SetAttributeValueByOtherAttribute("id", id, key, value);
	if (isSuccessful)
		return true;
	return isSuccessful;
}

const MyString& XMLfile::text(const MyString& id)
{
	return elements.getElementTextByAttribute("id", id);
}

const MyString& XMLfile::Delete(const MyString& id, const MyString& key)
{
	bool isSuccessful = elements.deleteAttributeByAttribute("id", id, key);
	if (isSuccessful)
		isModified = true;
	return isSuccessful;
}



void XMLfile::Save(ofstream& fileName)
{
	fileName.write((const char*)ids, idCount * sizeof(XMLfile));	
}

const MyString& XMLfile::addChild(const MyString& id, const MyString& name, const MyString& text)
{
	bool isSuccessful = elements.addChildenToElement("id", id, name, text);
	if (isSuccessful)
		isModified = true;
	return isSuccessful;
}


