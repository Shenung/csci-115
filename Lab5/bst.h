#ifndef BST_H
#define BST_H

typedef void (*Op)(int);

class NODE
{
private:
	int value;
	NODE *left;
	NODE *right;
public:
	NODE(int E);
	~NODE();

	int getVal();
	NODE *getRight();
	NODE *getLeft();
	void setVal(int E);
	void setRight(NODE *r);
	void setLeft(NODE *l);

};

class BST
{
private:
	NODE *root;
	int nodeVisits;
	void OrderTemp(Op Wb, NODE *curr);
public:
	BST();
	~BST();

	void insertNode(int E);
	void insert(NODE *, int E);
	int getNodeV() const;
	void order(Op Wb);
	int printB(int a, int z) const;
};

#endif
