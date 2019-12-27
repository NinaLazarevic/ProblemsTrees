#pragma once
#include "TreeNode.h"

struct level
{
	int level;
	int numOfNodes;
};

class Tree
{
protected:
	TreeNode* root;
public:
	Tree() { root = NULL; }
	~Tree() { deleteTree(root); }
	void deleteTree(TreeNode* node);
	bool isEmpty() { return root == NULL; }
	void insert(int el);
	void preorder(TreeNode* node);
	TreeNode* getRoot() { return root; }

	int height();
	int height(TreeNode* node, int h);

	int depth(int el);
	int depth(TreeNode* node, int d, int el);

	void mirror(TreeNode* node);

	level maxNumLevel();
	void getNumLevel(TreeNode* node, int level, int* array);
};
