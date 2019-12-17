// mylist.h header file
#ifndef _MYLIST_H
#define _MYLIST_H
#include <iostream>
using namespace std;
#include "stddef.h"
class mylist {
public:
	mylist();	// constructors/destructor
	mylist(const mylist &L);
	~mylist();

	const mylist& operator =(const mylist &rhs);       // assignment

	void startIteration();	        // iterators
	bool nextData(int &item);

	void insert(int item);	        // modifiers
	void remove(int item);
	void makeEmpty();

public:
	struct node {
		int info;
		node *next;
		node(int D, node *N) :
				info(D), next(N) {
		}
	};

	node *myHead;	// used for traversing the list
	node *myCurrent;
};

mylist::mylist() {
	myHead = NULL;
	myCurrent = NULL;
}
mylist::mylist(const mylist &L) {
	myHead = L.myHead;
	myCurrent = L.myCurrent;
}
mylist::~mylist() {
	makeEmpty();
	delete (this);
}

const mylist& mylist::operator =(const mylist &rhs) {
	return rhs;
}

void mylist::startIteration() {
	myCurrent = myHead;
	bool loop = true;
	while (loop) {
		cout << "! ";
		if (myCurrent == NULL) {
			loop = false;
		} else if (myCurrent->next == myHead) {
			loop = false;
		} else {
			myCurrent = myCurrent->next;
		}
	}
}
bool mylist::nextData(int &item) {
	if(myCurrent->next->info == NULL){
			return false;
		}
		if(myCurrent->next->info == item){
			return true;
		}
		return false;
}
void mylist::insert(int item) {
	node *temp = new node(0, NULL);
	temp->info = item;
	if (myHead == NULL) {
		myHead = temp;
		myHead->next = myHead;
	} else {
		startIteration();
		myCurrent->next = temp;
		temp->next = myHead;
	}
}
void mylist::remove(int item) {
	myCurrent = myHead;
	node *temp = new node(0, NULL);
	bool loop = true;
	while (loop) {
		if (myCurrent == myHead && myCurrent->info == item) {
			if (myHead->next == myHead) {
				myHead = NULL;
			}
			else{
			temp = myHead;
			myHead = myHead->next;
			startIteration();
			delete temp;
			myCurrent->next = myHead;
			}
		} else if (myCurrent->next == NULL) {
			loop = false;
		} else if (myCurrent->next->info == item) {
			if (myCurrent->next->next == NULL) {
				myCurrent->next = myHead;
			} else {
				temp = myCurrent->next;
				myCurrent->next = temp->next;
			}
		}

		if (myCurrent->next == myHead) {
			loop = false;
		} else {
			myCurrent = myCurrent->next;
		}
	}
}
void mylist::makeEmpty() {
//	temp = myHead;
//	bool loop = true;
//	while (loop) {
//		if (temp->next == NULL) {
//			free(temp);
//			loop = false;
//		} else {
//			myCurrent = temp;
//			temp = temp->next;
//			free(myCurrent);
//			myCurrent = myHead = NULL;
//		}
//	}
//	myHead = NULL;
//	myCurrent = NULL;
//	free(temp);

//	node *temp = new node(0, NULL);
//	myCurrent = myHead;
//	while(myCurrent->next != NULL){
//		temp = myCurrent;
//		free(myCurrent);
//		myCurrent = temp->next;
//	}
	myHead = NULL;
}
#endif
