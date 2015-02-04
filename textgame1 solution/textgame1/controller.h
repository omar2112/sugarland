#ifndef controller_H
#define controller_H
#include <iostream>
#include "item.h"
#include "inventory.h"
#include "area.h"
//#include "controller.cpp"
using namespace std;

class controller {
public:
	string input;
	void transferItem(area &a1, inventory &i1, string s);
	void dropItemArea(area &a1, inventory &i1, string s);
	void examine(area a1, inventory i1, string s);
	string playerChoice(area &a1, inventory &i1);
	vector<string> StringSplit(const string &source);
};
#endif