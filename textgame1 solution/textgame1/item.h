#ifndef item_H
#define item_H
#include <iostream>
#include <vector>
using namespace std;
class item {
public:
	string iN;
	string iD;
	bool canCarry;
	item();
	item(string n, string d, bool c);
	void printDesc();
	bool returnCarry();
};
#endif