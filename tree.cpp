#include <iostream>
#include "tree.h"
using namespace std;


sT::sT(const unsigned int& CPN) : CHILDREN_PER_NODE(CPN) {
	head = nullptr;
}

sT::~sT() {
	if (head) remove(head);
}

/*
Recursive method to delete all lower branches & the current branch.
*/
void sT::remove(sTNode* curr) {
	for (int i = 0; i < CHILDREN_PER_NODE; i++) {
		if (curr->children[i]) remove(curr->children[i]);
	}
	cout << "Deleting: " << curr->value << endl;
	delete[] curr->children;
	delete curr;
}

/*
GENERAL:
i = n^k

FORMULA FOR LAYER CUTOFFS:
									  	        i
n(1) = 0						          = 0		1
n(2) = 2^1					        	= 2		2
n(3) = 2^2 + 2^1				      = 6		4
n(4) = 2^3 + 2^2 + 2^1	  		= 14	8
n(5) = 2^4 + 2^3 + 2^2 + 2^1	= 30	16

2(i - 1)


										          i
n(1) = 0						          = 0		1
n(2) = 3^1						        = 3		3
n(3) = 3^2 + 3^1				      = 12	9
n(4) = 3^3 + 3^2 + 3^1			  = 39	27
n(5) = 3^4 + 3^3 + 3^2 + 3^1	= 120	81

3/2(i - 1)


									          	i
n(1) = 0					          	= 0		1
n(2) = 4^1					        	= 4		4
n(3) = 4^2 + 4^1				      = 20	16
n(4) = 4^3 + 4^2 + 4^1			  = 84	64
n(5) = 4^4 + 4^3 + 4^2 + 4^1	= 340	256

4/3(i - 1)


_(i - 1) / (n - 1) * n_


FORMULA FOR SORTING WITHIN A LAYER:
					i
t(1):	/1 % 2		1
t(2):	/2 % 2		2
t(3):	/4 % 2		4

/i % 2


					i
t(1):	/1 % 2		1
t(2):	/3 % 2		3
t(3):	/9 % 2		9

/i % 3


					i
t(1):	/1 % 2		1
t(2):	/4 % 2		4
t(3):	/16 % 2		16

/i % 4


_/i % n_
*/
int& sT::operator[](unsigned int index) {
	//create & initialize most pointers
	sTNode* prev = head, * curr = head;
	unsigned int i;

	//find/make the spot
	for (i = 1; index > (i - 1) / (CHILDREN_PER_NODE - 1) * CHILDREN_PER_NODE; i *= CHILDREN_PER_NODE) {
		if (!curr) {
			curr = new sTNode;
			curr->children = new sTNode * [CHILDREN_PER_NODE];
			for (int j = 0; j < CHILDREN_PER_NODE; j++) curr->children[j] = nullptr;
			curr->parent = prev;
			if (prev) prev->children[(index / (i / CHILDREN_PER_NODE)) % CHILDREN_PER_NODE] = curr;
			else head = curr;
		}

		prev = curr;
		curr = curr->children[(index / i) % CHILDREN_PER_NODE];
	}

	//create & add the node if needed
	if (!curr) {
		curr = new sTNode;
		curr->children = new sTNode * [CHILDREN_PER_NODE];
		for (int j = 0; j < CHILDREN_PER_NODE; j++) curr->children[j] = nullptr;
		curr->parent = prev;
		if (prev) prev->children[(index / (i / CHILDREN_PER_NODE)) % CHILDREN_PER_NODE] = curr;
		else head = curr;
	}

	//return the value
	return curr->value;
}

/*
SEE NOTES FOR OPERATOR[]
*/
void sT::printPath(unsigned int index) {
	//create & initialize most pointers
	sTNode* prev = head, * curr = head;
	unsigned int i;

	//find/make the spot
	for (i = 1; index > (i - 1) / (CHILDREN_PER_NODE - 1) * CHILDREN_PER_NODE; i *= CHILDREN_PER_NODE) {
		if (!curr) {
			curr = new sTNode;
			curr->children = new sTNode * [CHILDREN_PER_NODE];
			for (int j = 0; j < CHILDREN_PER_NODE; j++) curr->children[j] = nullptr;
			curr->parent = prev;
			if (prev) prev->children[(index / (i / CHILDREN_PER_NODE)) % CHILDREN_PER_NODE] = curr;
			else head = curr;
		}

		cout << curr->value << endl;

		prev = curr;
		curr = curr->children[(index / i) % CHILDREN_PER_NODE];
	}

	//create & add the node if needed
	if (!curr) {
		curr = new sTNode;
		curr->children = new sTNode * [CHILDREN_PER_NODE];
		for (int j = 0; j < CHILDREN_PER_NODE; j++) curr->children[j] = nullptr;
		curr->parent = prev;
		if (prev) prev->children[(index / (i / CHILDREN_PER_NODE)) % CHILDREN_PER_NODE] = curr;
		else head = curr;
	}

	cout << curr->value << endl;
}
