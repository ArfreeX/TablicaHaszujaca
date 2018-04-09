#pragma once
#include <iostream>
#include "CLinkedList.h"
#include <string>

class CHashTable
{
public:
	CHashTable();
	void add(std::string &value, std::string &key);
	const std::string search(std::string &key);
	void remove(std::string &key);
	void printArray();
	~CHashTable();
private:
	unsigned hash(std::string &key);

	const unsigned TABLE_SIZE = 23;
	const unsigned PRIMARY_KEY[3] = { 7,37,503 };
	CLinkedList *array;

};


