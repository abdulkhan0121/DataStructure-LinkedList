//============================================================================
// Name        : Lab8AK.cpp
// Author      : Abdul Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "mydoublelist.h"
using namespace std;

int main() {
	mylist *newList = new mylist();
	bool loop = true;
	int num;
	int choice;
	while (loop) {
		cout << "(1)insert (2)remove (3)search (4)make empty (5)output list"
				<< endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter a number: " << endl;
			cin >> num;
			newList->insert(num);
			break;
		case 2:
			cout << "Enter a number: " << endl;
			cin >> num;
			newList->remove(num);
			break;
		case 3:
			int found;
			cout << "Enter a number: " << endl;
			cin >> num;
			found = newList->nextData(num);
			if (found == 1) {
				cout << "The number was found!" << endl;
			} else {
				cout << "The number was not found." << endl;
			}
			break;
		case 4:
			newList->makeEmpty();
			break;
		case 5:
			newList->myCurrent = newList->myHead;
			if (newList->myCurrent == NULL) {
				cout << "There is nothing in the list!" << endl;
			} else {
				while (newList->myCurrent != NULL) {
					cout << newList->myCurrent->info << endl;
					newList->myCurrent = newList->myCurrent->next;
				}

			}
			break;
		}

	}
}
