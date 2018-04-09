#include "stdafx.h"
#include "CHashTable.h"


	CHashTable::CHashTable()
	{
		array = new CLinkedList[TABLE_SIZE];
	}

	void CHashTable::add(std::string &key, std::string &value)
	{
		array[hash(key)].add(key,value);
	}

	const std::string CHashTable::search(std::string &key)
	{
		return array[hash(key)].findValue(key);
	}

	void CHashTable::remove(std::string &key)
	{
		array[hash(key)].removeValue(key);
	}

	void CHashTable::printArray()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			std::cout << i << ". ";
			array[i].print();
			std::cout << std::endl;
		}

	}

	unsigned CHashTable::hash(std::string &key)
	{
		unsigned sum = PRIMARY_KEY[0];
		for (int i = 0; i < key.length(); i++)
			sum = sum * PRIMARY_KEY[1] ^ ((unsigned)key[i] * PRIMARY_KEY[2]);
		return sum % TABLE_SIZE;
	}

	CHashTable::~CHashTable()
	{
		delete[] array;
	}

