#ifndef _TREE_H_
#define _TREE_H_

/*
Nodes
*/
struct sTNode {
	sTNode* parent;
	sTNode** children;
	int value;
};

/*
Controls
*/
class sT {
public:
	sT(const unsigned int& CPN);
	~sT();
	int& operator[](unsigned int index);
	void printPath(unsigned int index);
private:
	sTNode* head;
	const unsigned int CHILDREN_PER_NODE;
	void remove(sTNode* curr);
};
#endif
