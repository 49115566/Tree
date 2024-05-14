#include <iostream>
#include "tree.h"
using namespace std;

/*
  Test the tree
*/
int main() {
	int val;
	unsigned int index;
	sT tree(3);
	char repeat;

	do {
		cout << "enter the value to be stored: ";
		cin >> val;
		cout << "enter the index at which it will be stored: ";
		cin >> index;
		tree[index] = val;

		cout << "enter an index to view: ";
		cin >> index;
		cout << "value: " << tree[index] << endl;

		cout << "repeat? <y/n> ";
		cin >> repeat;
	} while (repeat == 'y');
	return 0;
}
