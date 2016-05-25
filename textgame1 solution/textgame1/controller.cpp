#include <iostream>
#include <vector>
#include "controller.h"
#include "item.h"
#include "area.h"
#include "inventory.h"
#include <string>
using namespace std;

void controller::transferItem(area &a1, inventory &i1, string s) {
	int n = -1;
	for (int i = 0; i < a1.itemDrop.size(); i++) {
		if (a1.itemDrop.at(i).iN == s && a1.itemDrop.at(i).returnCarry()) {
			i1.pocket.push_back(a1.itemDrop.at(i));
			cout << "Picked up the " << s << "." << endl;
			n = i;
		}
	}
	if (n != -1) {
		a1.itemDrop.erase(a1.itemDrop.begin() + n);
	}

}

void controller::dropItemArea(area &a1, inventory &i1, string s) {
	int n = -1;
	for (int i = 0; i < i1.pocket.size(); i++) {
		if (i1.pocket.at(i).iN == s) {
			a1.itemDrop.push_back(i1.pocket.at(i));
			cout << "Dropped " << s << "" << endl;
			n = i;
		}
	}
	if (n != -1) {
		i1.pocket.erase(i1.pocket.begin() + n);
	}
}

void controller::examine(area a1, inventory i1, string s) {
	bool found = false;
	for (int i = 0; i < a1.itemDrop.size(); i++) {
		if (a1.itemDrop.at(i).iN == s) {
			cout << a1.itemDrop.at(i).iD << endl;
			found = true;
		}
	}
	
	for (int i = 0; i < i1.pocket.size(); i++) {
		if (i1.pocket.at(i).iN == s) {
			cout << i1.pocket.at(i).iD << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "That can't be found here." << endl;
	}
}

string controller::playerChoice(area &a1, inventory &i1) {
	a1.enter();
	string test;
	string tempinput;
	
		do
		{
		getline(cin, test);
		vector<string>newsplit;
		newsplit = StringSplit(test);

		if (test == "north" || test == "south" || test == "east" || test == "west" || test == "n" || test == "e" || test == "s" || test == "w") {
			return test;
		}
		if (newsplit.empty()) {
			cout << "Please enter a valid command" << endl;
		}

		if (newsplit.at(0) == "examine" && newsplit.size() == 1) {
			cout << "examine what?" << endl;
			getline(cin, tempinput);
			newsplit.push_back(tempinput);
			examine(a1, i1, newsplit.at(1));
		}
		else if (newsplit.at(0) == "examine" && newsplit.size() != 1) {
			examine(a1, i1, newsplit.at(1));
		}
		else if (newsplit.at(0) == "take" && newsplit.at(1) == "key") {
			transferItem(a1, i1, newsplit.at(1));
		}
		else if (newsplit.at(0) == "inventory") {
			i1.displayPocket();
		}
		else if (newsplit.at(0) == "drop") {
			dropItemArea(a1, i1, newsplit.at(1));
		}
		else if (newsplit.at(0) == "look") {
			a1.enter();
		}
		else if (newsplit.at(0) == "weast") {
			cout << "Weast? What kind of compass are you reading?" << endl;
		}
		else if (newsplit.at(0) == "about") {
			cout << "Sugarland - freeware text adventure by qwervo. http://steamcommunity.com/id/qwervo/" << endl;
		}
		else {
			cout << "Please enter a valid command." << endl;
			
		}
		} while (test != "0");
	return test;
}

vector<string> controller::StringSplit(const string &source)
{
	const char *delimiter = " ";
	bool keepEmpty = false;
	std::vector<std::string> results;

	size_t prev = 0;
	size_t next = 0;

	while ((next = source.find_first_of(delimiter, prev)) != std::string::npos)
	{
		if (keepEmpty || (next - prev != 0))
		{
			results.push_back(source.substr(prev, next - prev));
		}
		prev = next + 1;
	}

	if (prev < source.size())
	{
		results.push_back(source.substr(prev));
	}

	return results;
}
