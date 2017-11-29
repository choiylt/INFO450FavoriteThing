#pragma once
#include <string>
using namespace std;

class InventoryItem
{
private:
	string brand;
	string media;
	string genre;
	int barcode;
public:
	int captureInventory();
	void displayInventory();
	InventoryItem();
	InventoryItem(string b, string m, string g, int q);

	friend ofstream& operator<<(ofstream &fs, InventoryItem *);
	friend ofstream& operator<<(ofstream &fs, InventoryItem *item);

};