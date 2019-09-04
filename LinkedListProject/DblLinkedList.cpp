#include "pch.h"
#include "DblLinkedList.h"
#include "JDString.h"
#include <iostream>

using namespace std;

DblLinkedList::DblLinkedList() 
{
	head = tail = it = nullptr;

	count = 0;
}

DblLinkedList::DblLinkedList(const DblLinkedList& list)
{
	head = tail = it = nullptr;

	list.resetIterator();

	// Copy using iterator
	while (list.hasMore())
		push_back(list.next());

	count = list.getCount();
}

DblLinkedList::~DblLinkedList()
{
	removeAll();
}

DblLinkedList& DblLinkedList::operator = (const DblLinkedList& list)
{
	removeAll();

	list.resetIterator();

	// Copy using iterator
	while (list.hasMore())
		push_back(list.next());

	count = list.getCount();

	return *this;
}

bool DblLinkedList::insert(const JDString& argStr)
{
	if (!contains(argStr) && argStr.length() > 0)
	{
		Node * temp = new Node(argStr);

		if (isEmpty()) // Empty list
		{
			head = temp;
			tail = temp;

			count++;

			return true;
		}

		if (argStr > tail->data) // At tail
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;

			count++;

			return true;
		}

		if (argStr < head->data) // At head
		{
			temp->next = head;
			head->prev = temp;
			head = temp;

			count++;

			return true;
		}

		resetIterator();

		// Find spot
		while (hasMore())
		{
			if (it->data > argStr)
			{
				break;
			}

			next();
		}

		temp->next = it;
		temp->prev = it->prev;
		temp->prev->next = temp;
		temp->next->prev = temp;

		count++;

		resetIterator();

		return true;
	}

	return false;
}

bool DblLinkedList::insert(const char * argStr)
{
	return insert(JDString(argStr));
}

bool DblLinkedList::remove(const JDString& argStr)
{
	resetIterator();

	while (hasMore())
	{
		if (it->data == argStr)
		{
			if (isEmpty())
			{
				return false;
			}
			else if (head == tail) // Only has one node
			{
				head = tail = nullptr; // Reset head and tail
			}
			else if (it == head)
			{
				it->next->prev = nullptr;
				head = it->next;
			}
			else if (it == tail)
			{
				it->prev->next = nullptr;
				tail = it->prev;
			}
			else
			{
				it->prev->next = it->next;
				it->next->prev = it->prev;
			}

			delete it;

			resetIterator();

			count--;

			return true;
		}

		next();
	}

	return false;
}

bool DblLinkedList::remove(const char * argStr)
{
	return remove(JDString(argStr));
}

ostream& operator << (ostream& ostrm, const DblLinkedList& list)
{
	list.resetIterator();

	while (list.hasMore())
	{
		ostrm << list.next() << ' ';
	}

	return ostrm;
}

void DblLinkedList::push_back(const JDString& argStr) 
{
	// If the list does not contain the argStr
	Node* temp = new Node(argStr);

	// If empty list, set it up
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		// If non-empty list, set the
		// last node to the temp node
		// then set tail equal to temp
		temp->prev = tail;
		tail->next = temp;
		tail = tail->next;
	}

	count++;
}

bool DblLinkedList::contains(const JDString& argStr) const
{
	resetIterator();

	while (hasMore())
	{
		if (next() == argStr)
			return true;
	}

	return false;
}

bool DblLinkedList::isEmpty() const
{
	return head == nullptr && tail == nullptr
		? true : false;
}

void DblLinkedList::resetIterator() const 
{
	it = head;
}

bool DblLinkedList::hasMore() const 
{
	if (it == nullptr)
		return false;

	return true;
}

JDString DblLinkedList::next() const 
{
	JDString temp;
	
	if (it != nullptr)
		temp = it->data;

	it = it->next;

	return temp;
}

void DblLinkedList::testConnections() const
{
	resetIterator();

	bool hasFailed = false;
	
	while (it != tail)
	{
		if (it->next->prev != it)
		{
			hasFailed = true;
			break;
		}

		next();
	}

	if (hasFailed)
		cout << "\nTEST CONNECTIONS Failed!\n";
	else
		cout << "\nTEST CONNECTIONS Passed!\n";
}

void DblLinkedList::removeAll()
{
	while (!isEmpty())
	{
		remove(head->data);
	}
}

int DblLinkedList::getCount() const
{
	return count;
}