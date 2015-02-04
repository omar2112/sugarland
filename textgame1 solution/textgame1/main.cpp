#include <iostream>
#include "area.h"
#include "item.h"
#include "inventory.h"
#include "controller.h"
#include "areaManager.h"
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

int main() {
	areaManager a1;
	a1.initializeGame();
	system("pause");
	return 0;
}