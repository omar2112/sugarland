#ifndef area_H
#define area_H
#include <iostream>
#include <vector>
#include "item.h"
using namespace std;
class area {
public:
	string aName;
	string aDesc;
	string N;
	string E;
	string S;
	string W;
	vector<item>itemDrop;
	area();
	area(string An, string Ad, vector<item>v, string Nc, string Ec, string Sc, string Wc);
	area::area(string aN, string aD, string Nc, string Ec, string Sc, string Wc);
	void enter();
	string cardinalAccess(string cA);
	string returnName();

};
#endif 