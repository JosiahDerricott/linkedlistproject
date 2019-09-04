/*
	Name: Josiah Derricott
	Section: S
	Program: P4 Linked List
	Description: This program is my creation of an ordered doubly linked 
		list class that uses my JDString as data for each node. I take in
		a lot of data from two input files, organize it, and output the
		sizes of each list to the console and the data to two outfiles.
*/

#include "pch.h"
#include "JDString.h"
#include "DblLinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

void changer(DblLinkedList list);

int main()
{
	DblLinkedList list1, list2, modList1, modList2;

	ifstream fin("infile1.txt");
	JDString tempStr;

	if (fin.fail())
	{
		cout << " >> ERROR: Could not read file!\n";

		exit(1);
	}

	while (!fin.eof())
	{
		fin >> tempStr;

		list1.insert(tempStr);
	}

	fin.close();
	fin.clear();

	fin.open("infile2.txt");

	if (fin.fail())
	{
		cout << " >> ERROR: Could not read file!\n";

		exit(1);
	}

	while (!fin.eof())
	{
		fin >> tempStr;

		list2.insert(tempStr);
	}

	fin.close();

	cout << "List 1 Size: " << list1.getCount() << endl
		<< "List 2 Size: " << list2.getCount() << endl
		<< "Mod List 1 Size: " << modList1.getCount() << endl
		<< "Mod List 2 Size: " << modList2.getCount() << endl << endl;

	modList1 = list1;
	modList2 = list2;

	cout << "List 1 Size: " << list1.getCount() << endl
		<< "List 2 Size: " << list2.getCount() << endl
		<< "Mod List 1 Size: " << modList1.getCount() << endl
		<< "Mod List 2 Size: " << modList2.getCount() << endl << endl;

	list1.resetIterator();
	list2.resetIterator();

	while (list2.hasMore())
		modList1.remove(list2.next());

	while (list1.hasMore())
		modList2.remove(list1.next());

	cout << "List 1 Size: " << list1.getCount() << endl
		<< "List 2 Size: " << list2.getCount() << endl
		<< "Mod List 1 Size: " << modList1.getCount() << endl
		<< "Mod List 2 Size: " << modList2.getCount() << endl << endl;

	changer(modList1);
	changer(modList2);

	cout << "List 1 Size: " << list1.getCount() << endl
		<< "List 2 Size: " << list2.getCount() << endl
		<< "Mod List 1 Size: " << modList1.getCount() << endl
		<< "Mod List 2 Size: " << modList2.getCount() << endl << endl;

	cout << "Created Count: " << JDString::getCreatedCount() << endl
		<< "Current Count: " << JDString::getCurrentCount() << endl;

	ofstream fout("outfile1.txt");

	fout << modList1;

	fout.close();
	fout.clear();

	fout.open("outfile2.txt");

	fout << modList2;

	fout.close();

	system("pause");
	return 0;
}

void changer(DblLinkedList list)
{
	list.insert("ZIP");
	list.insert("ZAP");

	cout << "Inside Changer Function ->\n\tSize of List: "
		<< list.getCount() << endl << endl;
}

// Console Output:
/*
	List 1 Size: 1104
	List 2 Size: 1040
	Mod List 1 Size: 0
	Mod List 2 Size: 0

	List 1 Size: 1104
	List 2 Size: 1040
	Mod List 1 Size: 1104
	Mod List 2 Size: 1040

	List 1 Size: 1104
	List 2 Size: 1040
	Mod List 1 Size: 759
	Mod List 2 Size: 695

	Inside Changer Function ->
			Size of List: 761

	Inside Changer Function ->
			Size of List: 697

	List 1 Size: 1104
	List 2 Size: 1040
	Mod List 1 Size: 759
	Mod List 2 Size: 695

	Created Count: 9375553
	Current Count: 3599
*/