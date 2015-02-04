#ifndef inventory_H
#define inventory_H
#include <iostream>
#include <vector>
#include "item.h"
using namespace std;

class inventory {
public:
	vector<item>pocket;
	void displayPocket();
	void dropItem(string itemName);
};
#endif