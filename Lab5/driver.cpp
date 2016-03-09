#include<iostream>
#include<cstdlib>
#include<ctime>
#include"bst.h"
using namespace std;

void printB(int curr){
	cout << curr << endl;
}

int main()
{
	BST bin;
	bin.insertNode(2);
	bin.insertNode(6);
	bin.insertNode(3);
	bin.insertNode(1);
	bin.insertNode(9);
	bin.insertNode(12);

	cout << "nodes have been inserted: 2 6 3 1 9 12" << endl;

	bin.order(printB);
	system("pause");
	return 0;
}
