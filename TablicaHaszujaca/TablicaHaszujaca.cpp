// TablicaHaszujaca.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


std::string search(std::string input, CHashTable &test)
{
	return test.search(input);

}
void add(std::string &input, std::string &input2 , CHashTable &test)
{
	test.add(input,input2);
}
void remove(std::string input, CHashTable &test)
{
	test.remove(input);
}

void menu()
{
	CHashTable test;

	std::string input = "";
	std::string input2 = "";
	while (input != "koniec")
	{
		std::cin >> input;
		system("cls");
		if (input == "dodaj")
		{
			std::cin >> input;
			std::cin >> input2;
			add(input,input2, test);
		}
		else if (input == "usun")
		{
			std::cin >> input;
			remove(input, test);
		}
		else if (input == "szukaj")
		{
			std::cin >> input;
			std::cout << search(input, test) << std::endl;
		}

		test.printArray();
	}
}

int main()
{
	menu();
	system("PAUSE");
    return 0;
}


//---HASH-TABLE----//

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


//---LIST----//

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


void CLinkedList::add(std::string &key, std::string &value)
{
	if (head == nullptr)
		head = new Element(key, value);
	else
	{
		Element *it = head;
		while (it->next != nullptr)
		{
			it = it->next;
		}
		if (findValue(key) == "Invalid key")
			it->next = new Element(key, value);
	}
	size++;
}

void CLinkedList::removeValue(std::string &key)
{
	Element *temp = head;
	Element *buff = head;
	if (temp == nullptr)
		return;
	else if (temp->key == key)
		removeOnFront();
	else
		while (temp != nullptr)
		{

			if (temp->key == key)
			{
				if (temp->next == nullptr)
				{
					delete temp;
					buff->next = nullptr;
				}
				else
				{
					buff->next = temp->next;
					delete temp;
				}
				return;
			}

			buff = temp;
			temp = temp->next;
		};

}

const std::string CLinkedList::findValue(std::string &key)
{
	Element *el = head;
	for (int i = 0; el != nullptr; i++, el = el->next)
	{
		if (el->key == key)
		{
			return el->value;
		}
	}
	return "Invalid key";
}


void CLinkedList::print()
{
	Element* it = head;
	if (it == nullptr)
	{
		std::cout << "0";
		return;
	}
	while (it->next != nullptr)
	{
		std::cout << it->value << " - > ";
		it = it->next;
	}
	std::cout << it->value;
}