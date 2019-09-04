/*
	Name: Josiah Derricott
	Section: S
	Program Name: P4 Linked List

	Description: This is my creation of an ordered doubly linked list
		class which stores JDStrings as data and has functions such as 
		insert() which inserts data in order. I also have a type of 
		iterator that allows for easy maneuvering of the linked list.
*/

#ifndef DBLLINKEDLIST_H
#define DBLLINKEDLIST_H

#include "JDString.h"

using namespace std;

class Node {
	public:
		Node() 
		{
			next = prev = nullptr;
		}

		Node(JDString _data) 
		{
			data = _data;
			next = prev = nullptr;
		}

		JDString data;
		Node *next;
		Node *prev;
};


class DblLinkedList {
	public:
		/*
			Constructor
		*/
		DblLinkedList();

		/*
			Copy Constructor
		*/
		DblLinkedList(const DblLinkedList & list);
		
		/*
			Destructor
		*/
		~DblLinkedList();

		/*
			Sets the current list equal to a new list
		*/
		DblLinkedList& operator = (const DblLinkedList& list);

		/* 
			Used to insert into the ordered list
		*/
		bool insert(const JDString& argStr);

		/*	
			Overloaded insert to accept a string of chars 
		*/
		bool insert(const char * argStr);

		/*
			Used to remove item from the list
		*/
		bool remove(const JDString& argStr);

		/*
			Overloaded remove to accept a string of chars
		*/
		bool remove(const char * argStr);

		/* 
			Returns true if list is empty 
		*/
		bool isEmpty() const;

		/*
			Returns true if the list contains the given string
		*/
		bool contains(const JDString& argStr) const;

		/*
			Returns true if the it has more nodes to iterate
		*/
		bool hasMore() const;

		/*
			Returns the string the it is currently pointing
			at and then moves the it one node forward
		*/
		JDString next() const;

		/* 
			Test to make sure each node's prev
			pointer points to the right node
		*/
		void testConnections() const;

		/*
			Used to set the iterator back at the beginning 
			of the list
		*/
		void resetIterator() const;

		/*
			Returns amount of nodes in list
		*/
		int getCount() const;

		/*
			Prints the list contents to a stream
		*/
		friend ostream& operator << (ostream& ostrm, const DblLinkedList& list);

	private:
		Node *head, *tail;
		mutable Node *it;
		int count;

		/*
			Used to insert into the list from the back
		*/
		void push_back(const JDString& argStr);

		/*
			Internal function that removes everything from
			the list
		*/
		void removeAll();
};

#endif


