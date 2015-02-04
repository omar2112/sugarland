#include <iostream>
#include <string>
#include <vector>
#include "area.h"
#include "item.h"
#include "areaManager.h"
#include "inventory.h"
#include "controller.h"
using namespace std;

void areaManager::initializeGame() {
	vector<item>myv;
	vector<item>emptyV;
	vector<item>v6;
	vector<item>playV;
	vector<item>shackV;
	vector<item>dogV;
	vector<item>downV;
	vector<item>dE2V;

	// Make it so G King funds his operation with marijuana grown by a farmer, and some bank launders it. 
	// Make it so there's a thumb drive in the ranch that can be plugged in later that contains backups
	// with bitcoin and senders and addresses, that the user can later interact with a computer with no internet. 

	//G King is a cult leader that wants to get rid of capitalism and create a city that is ruled by him. Like Jim Jones.
	//You have to fight G King and G Queen at the end. Bunch of dead people. 

	//Plot: you were part of the cult, but was drugged and placed in the park by another member to spare you.
	// he has keys to the city and left it to you. 

	int testnum;
	testnum = 0;
	item key1("key", "A brittle old skeleton key, should open basic locks. It doesn't look like it'll last more than a single use.", true);
	item trail1("trail", "a pebble trail leading outside the park.", false);
	item trees1("trees", "spruce trees all around the park. The sunshine breaks through the thick leaves.", false);
	item shack1("shack", "likely used for storage. something strong would be needed to break the chains.", false);
	item swings("swings", "a big swing set of four.", false);
	item jungle("jungle", "A big colourful jungle gym. There's chimes being pushed by the wind, creating an eerie melody.", false);
	item plaque("plaque", "A golden plaque sits on a pillar by the gate. The inscription reads: 'Central Park: Funded by the Gambit Group and Sugarland Historical Society.", false);
	item sign("sign", "The sign reads: Downtown Sugarland - there is a sticker with large red text on the sign: 'CLOSED BY ORDER OF G. KING.' The bridge, despite the notice, seems intact.", false);
	item dog("dog", "The dog is an adult komondor. He lifts his head and notices you, and quickly runs away. He seems to be headed the way you came.", false);
	item casino("casino", "The sign reads - 'Sugar Bridge Casino.' The building looks ransacked and grafittied", false);
	item grafitti("grafitti", "The legible grafitti reads: 'G. SMITH, 'G. MORRA'", false);
	item historical("historical", "Sugarland Historical Society is the sign on the building. The door is locked.", false);
	item statue("statue", "The inscription reads 'Sugarland welcomes King, who will free us from sin and turn desert into paradise.'", false);
	item usb("usb stick", "A usb flash drive. You'll need a computer to access the information.", false);

	myv.push_back(key1);
	myv.push_back(trail1);
	myv.push_back(trees1);
	v6.push_back(plaque);
	playV.push_back(swings);
	playV.push_back(jungle);
	shackV.push_back(shack1);
	dogV.push_back(dog);
	dogV.push_back(sign);
	dE2V.push_back(statue);

	downV.push_back(casino);
	downV.push_back(grafitti);


	area starting1("Central Park", "You're in the middle of a small park. There are sparse trees and a walking trail. The walking trail leads to entrances from the north and south.", myv, "Central Park - North Gate", "Central Park - East", "Central Park - South Gate", "Central Park - West");
	area starting2("Central Park - North Gate", "A winding trail downhill leads you to a gate. The gate is locked.", emptyV, "NA", "NA", "Central Park", "NA");
	area starting3("Central Park - South Gate", "The trail leads to a gate. The open gate is being pushed by the breeze.", emptyV, "Central Park", "NA", "Park Entrance - South", "NA");
	area starting4("Central Park - West", "There are swings and a big jungle gym here. There doesn't seem to be anyone around.", playV, "NA", "Central Park", "NA", "NA");
	area starting5("Central Park - East", "There's a large field of grass here. The tall grass brushes against your shins. At the end of the field there is a small shack with the door chained off.", shackV, "NA", "NA", "NA", "Central Park");
	area starting6("Park Entrance - South", "The dirt road goes west and east. To the north is the gate to the park. There is a plaque next to the gate.", v6, "Central Park - South Gate", "Main Road - East and 10th", "NA", "Main Road - West and 8th");
	area starting7("Main Road - East and 10th", "The road leads downhill and connects to a bridge across a wide river. There's a large sign casting a long shadow. A large dog seems to be lying in the shade.", dogV, "NA", "Downtown Sugarland - East Entrance", "Downtown Sugarland - East Entrance", "Park Entrance - South");
	area starting8("Downtown Sugarland - East Entrance", "There is a casino to the north and a diner south. The road continues east.", downV, "NA", "Downtown Sugarland - East and 2nd", "NA", "Main Road - East and 10th");
	area starting9("Main Road - West and 8th", "The road continues west. There are dog paw prints on the dirt road. To the north on the shoulder there is a car.", emptyV, "NA", "Park Entrance - South", "NA", "Farm Gate");
	area starting10("Farm Gate", "There is a wide open gate leading to a large farm.", emptyV, "NA", "Main Road - West and 8th", "NA", "NA");
	area starting11("Downtown Sugarland - East and 2nd", "The historical society building is north and the chamber of commerce is south. The road ends eastward with a a large statue of an imposing man", dE2V, "NA", "NA", "NA", "Downtown Sugarland - East Entrance");



	inventory i1;
	controller a1;
	blocks.push_back(starting1);
	blocks.push_back(starting2);
	blocks.push_back(starting3);
	blocks.push_back(starting4);
	blocks.push_back(starting5);
	blocks.push_back(starting6);
	blocks.push_back(starting7);

	blocks.push_back(starting8);
	blocks.push_back(starting9);
	blocks.push_back(starting10);
	blocks.push_back(starting11);
	string direction;
	do {
		direction = a1.playerChoice(blocks.at(testnum), i1);

		int newnum = newLocation(testnum, direction);
		if (newnum == -1) {
			cout << "Your can't move in that direction" << endl;
		}
		else {
			testnum = newnum;
		}
	} 
	while (direction != "0");

}
 
int areaManager::newLocation(int curr, string dir) {
	int num = -1;
	for (int i = 0; i < blocks.size(); i++) {
		if (blocks.at(curr).cardinalAccess(dir) == blocks.at(i).aName) {
			num = i;
		}
	}
	return num;
}

