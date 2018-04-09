#include "stdafx.h"
#include "CLinkedList.h"



CLinkedList::CLinkedList()
{
	size = 0;
	head = nullptr;
}

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
			it->next = new Element(key,value);
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
				size--;
				return;
			}

			buff = temp;
			temp = temp->next;
		};
	
}

//void CLinkedList::removeValue(std::string &key)
//{
//	Element *temp = head;
//	Element *buff = head;
//	if (temp == nullptr)
//		return;
//	else if (temp->key == key)
//	{
//		removeOnFront();
//	}
//	else {
//		while (temp->next != nullptr && temp->key != key)
//		{
//			buff = temp;
//			temp = temp->next;
//		}
//		if (temp->next == nullptr && temp->key == key)
//		{
//			buff->next = nullptr;
//			delete temp;
//		}
//		else if (temp->key == key)
//		{
//			buff->next = temp->next;
//			delete temp;
//		}
//	}
//}

//void CLinkedList::removeOnIndex(int index)
//{
//	if (index == 0)
//		removeOnFront();
//	else if (index < size && index > 0)
//	{
//		Element *it = head;
//		for (int i = 0; i < index - 1; i++)
//		{
//			it = it->next;
//		}
//		Element *el = it->next->next;
//		delete it->next;
//		it->next = el;
//		size--;
//	}
//	else
//		std::cout << "index out of array" << std::endl;
//}

void CLinkedList::removeOnFront()
{
	if (size != 0)
	{
		Element *el = head->next;
		delete head;
		head = el;
		size--;
	}
	else
		std::cout << "empty list!!!!!" << std::endl;
}

//void CLinkedList::remove()
//{
//	if (size != 0)
//	{
//		Element *it = head;
//		while (it->next->next != nullptr)
//		{
//			it = it->next;
//		}
//		delete it->next;
//		it->next = nullptr;
//		size--;
//	}
//}

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

//std::string CLinkedList::findOnIndex(int index, bool & success)
//{
//	if (index < size && index >= 0)
//	{
//		Element *el = head;
//		for (int i = 0; i < index; i++)
//		{
//			el = el->next;
//		}
//		success = true;
//		return el->value;
//	}
//
//	std::cout << "index out of LIST" << std::endl;
//	success = false;
//	return "null";
//}

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

int CLinkedList::getSize()
{
	return size;
}