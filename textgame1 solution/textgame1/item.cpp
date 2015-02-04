#include <iostream>
#include "item.h"
#include <string>
#include <vector>
using namespace std;

item::item() {
	iD = "missing description;";
	iN = "missing name";
}
item::item(string n, string d, bool c) {
	iN = n;
	iD = d;
	canCarry = c;
}
void item::printDesc() {
	cout << iD << endl;
}
bool item::returnCarry() {
	return canCarry;
}