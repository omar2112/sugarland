#include <iostream>
#include <vector>
#include "inventory.h"
#include <string>
using namespace std;

void inventory::displayPocket() {
	cout << "Inventory:" << endl;
	if (pocket.size() == 0) {
		cout << "You're not carrying anything." << endl;
	}
	for (int i = 0; i < pocket.size(); i++) {
		cout << pocket.at(i).iN << endl;
	}
}

void inventory::dropItem(string itemName) {
	int n = -1;
	for (int i = 0; i < pocket.size(); i++) {
		if (pocket.at(i).iN == itemName) {
			n = i;
		}
	}
	if (n != -1) {
		pocket.erase(pocket.begin() + n);
	}
}