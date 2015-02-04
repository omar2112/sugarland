#include <iostream>
#include <string>
#include <vector>
#include "area.h"
#include "item.h"
using namespace std;


	area::area() {
		aName = "noname";
		aDesc = "nodesc";
	}


	area::area(string aN, string aD, vector<item>v, string Nc, string Ec, string Sc, string Wc) {
		aName = aN;
		aDesc = aD;
		itemDrop = v;
		N = Nc;
		E = Ec;
		S = Sc;
		W = Wc;
	}

	area::area(string aN, string aD, string Nc, string Ec, string Sc, string Wc) {
		aName = aN;
		aDesc = aD;
		N = Nc;
		E = Ec;
		S = Sc;
		W = Wc;
	}

	void area::enter() {
		cout << aName << endl;
		cout << aDesc << endl;
			for (int i = 0; i < itemDrop.size(); i++) {
				if (itemDrop.at(i).returnCarry())
				cout << "There is a [" << itemDrop.at(i).iN << "] on the floor." << endl;
			}
	}
	
	string area::cardinalAccess(string cA) {
		if (cA == "north" || cA == "n") {
			return N;
		}
		else if (cA == "east" || cA == "e") {
			return E;
		}
		else if (cA == "south" || cA == "s") {
			return S;
		}
		else if (cA == "west" || cA == "w") {
			return W;
		}
		else {
			return "NA";
		}
	}

	string area::returnName() {
		return aName;
	}