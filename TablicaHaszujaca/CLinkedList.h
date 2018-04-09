#pragma once
#include <iostream>
#include <string>



class CLinkedList
{

public:
	CLinkedList();
	void add(std::string &key, std::string &value);

	void removeValue(std::string &key);
	//void removeOnIndex(int index);
	void removeOnFront();
	//void remove();

	const std::string findValue(std::string &key);
	/*std::string findOnIndex(int index, bool & success);*/

	void print();
	int getSize();

private:
	struct Element
	{
		std::string value;
		std::string key;
		Element *next;

		Element(std::string const & key, std::string const & value)
		{
			this->key = key;
			this->value = value;
			next = nullptr;
		}
	};

	int size;
	Element *head;
};

