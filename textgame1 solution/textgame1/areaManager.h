#include <vector>
#include <iostream>
#include "area.h"
#include "item.h"
using namespace std;

class areaManager {
public:
	vector<area>blocks;
	void initializeGame();
	int newLocation(int curr, string dir);
};