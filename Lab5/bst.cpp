#include"BST.h"
#include<cstdlib>
using namespace std;

BST::BST()
{
	root = NULL;
	nodeVisits = 0;
}

BST::~BST()
{
	delete root;
}

NODE::NODE(int E)
{
	value = E;
	left = NULL;
	right = NULL;
}

NODE::~NODE()
{
	delete left;
	delete right;
}

NODE* NODE::getLeft()
{
	return left;
}
NODE* NODE::getRight()
{
	return right;
}

int NODE::getVal()
{
	return value;
}

void NODE::setLeft(NODE *l)
{
	left = l;
}

void NODE::setRight(NODE *r)
{
	right = r;
}


//This is optionally removalble
void NODE::setVal(int E)
{
	value = E;
}

int BST::getNodeV()const
{
	return nodeVisits;
}

void BST::insertNode(int E)
{
	if(root == NULL)
		root = new NODE(E);
	else
		insert(root, E);
}

void BST::insert(NODE *nodePtr, int E)
{
	if (nodePtr->getVal() >= E)
	{
		if (nodePtr->getLeft() == NULL)
		{
			nodePtr->setLeft(new NODE(E));
		}
		else
		{
			insert(nodePtr->getLeft(), E);
		}
	}
	else
		if (nodePtr->getRight () == NULL)
		{
			nodePtr->setRight(new NODE(E));
		}
		else
		{
			insert(nodePtr->getRight(), E);
		}
}

void BST::order(Op Wb){
	OrderTemp(Wb, root);
}

// inorder -> 2 1 3
// pre Order -> 1 2 3
// post order -> 2 3 1
void BST::OrderTemp(Op Wb, NODE *curr){
	if(curr == NULL) return;
	OrderTemp(Wb, curr->getLeft()); //2
	Wb(curr->getVal()); // 1
	OrderTemp(Wb, curr->getRight()); //3
}

/*
int BST::printB(int a, int z) const
{
	if (root == NULL)
	{
		cout << "Trees empty" << endl;
		return 0;
	}
	else
	{
		int send =
	}
}
*/
