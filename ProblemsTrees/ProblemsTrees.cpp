#include <iostream>
#include "Tree.h"

int main()
{
	Tree tree;
	tree.insert(26);
	tree.insert(20);
	tree.insert(16);
	tree.insert(32);
	tree.insert(12);
	tree.insert(36);
	tree.insert(34);
	tree.insert(18);
	tree.insert(35);
	tree.insert(15);
	tree.insert(25);
	tree.insert(28);
	tree.insert(31);
	tree.insert(29);

	TreeNode* root = tree.getRoot();

	tree.preorder(root);

	//problem 1
	cout << "\nHeight is: " << tree.height() << endl;
	//problem 2
	cout << "\nDepth of node with value 25 is: " << tree.depth(25) << endl;
	cout << "\nDepth of node with value 10 is: " << tree.depth(10) << endl;
	cout << "\nDepth of node with value 34 is: " << tree.depth(34) << endl;
	//problem 3
	tree.mirror(root);
	tree.preorder(root);

	//problem 4
	level max = tree.maxNumLevel();
	cout << "\nLevel " << max.level << " has highest number of nodes: " << max.numOfNodes << endl;
}

