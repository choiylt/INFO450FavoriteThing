// Inventory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "inventoryitem.h"
#include <iostream>
#include <fstream>
using namespace std;

const int LISTSIZE = 50;

int main()
{
	InventoryItem **mylist;
	int count = 0;
	int i;
	string fileLocation;
	string response = "Y";

	mylist = new InventoryItem*[LISTSIZE];

	cout << "Where would you like to save this file? ";
	getline(cin, fileLocation);

	// read from a file - get saved inventory itesm
	ifstream infile(fileLocation);
	if (infile)
	{
		while (!infile.eof())
		{
			string brand, media, genre, qty;
			getline(infile, brand, ',');
			if (brand.length())
			{
				getline(infile, brand, ',');
				getline(infile, qty, '\n');
				mylist[count] = new InventoryItem(brand, media, genre, stoi(qty));
				count++;
			}
		}
	}
	else
	{
		ofstream outfile(fileLocation);
		if (!outfile)
		{
			cout << "File could not be created. " << endl;
		}
	}

	//Introduction
	cout << "" << endl;
	cout << "Welcome to the Game Collection Tracker" << endl;
	cout << "" << endl;
	cout << "You will be asked to enter the game's name (no spaces)," << endl;
	cout << "the media type(i.e CD, cartidge, virtual, etc)"<< endl;
	cout << "the genre, and the barcode of the game." << endl;
	cout << "" << endl;

	// enter more???
	cout << "You have " << count << " records.  Do you wish to enter more?" << endl;
	cin >> response;


	// get inventory items from user
	while (response == "Y" || response == "y")
	{
		mylist[count] = new InventoryItem();
		if (mylist[count]->captureInventory() == 0)
			count++;

		cout << "Another one?" << endl;
		cin >> response;
	}

	// now that we have array populated w/ object, show them
	for (i = 0; i < count; i++)
	{
		mylist[i]->displayInventory();
	}

	//Save to a File
	ofstream outfile(fileLocation);
	if (!outfile.good())
	{
		cout << "ERROR - cant open file for output! " << endl;
		return -1;
	}
	// printing to console
	for (i = 0; i < count; i++)
	{
		outfile << mylist[i];
	}

	// cleaning up
	for (i = 0; i < count; i++)
	{
		delete mylist[i];
	}
	delete mylist;


	return 0;
}
