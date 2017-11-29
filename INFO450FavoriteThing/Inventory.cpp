// INFO450FavoriteThing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "inventoryitem.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


int InventoryItem::captureInventory()
{
	cout << "" << endl;
	cout << "Name? " << endl;
	cin >> brand;
	cin.ignore();
	cin.clear();
	cout << "" << endl;
	cout << "What media?" << endl;
	getline(cin, media);
	cout << "" << endl;
	cout << "What genre?" << endl;
	getline(cin, genre);
	cout << "" << endl;
	cout << "Barcode?" << endl;
	cin >> barcode;
	cout << "" << endl;
	//TBD - do error checking
	return 0;
}

void InventoryItem::displayInventory()
{
	cout << "******* " << brand << "*******" << endl;
	
	cout << "Media: " << media << endl;
	cout << "Genre: " << genre << endl;
	cout << "Barcode: " << barcode << endl; 
} 

// default constructor
InventoryItem::InventoryItem()
{
	brand = "";
	media = "";
	genre = "";
	barcode = 0;
}

// overloaded constructor
InventoryItem::InventoryItem(string b, string m, string g, int q)

{
	brand = b;
	media = m;
	genre = g;
	barcode = q;
}

ofstream& operator<<(ofstream &fs, InventoryItem *item)
{
	fs << item->brand << "," << item->media << "," << item->genre << "," << item->barcode << endl;
	return fs;
}
