#pragma once
#include <iostream>
using namespace std;

class TreeNode
{
public:
	TreeNode* left, * right;
	int value;
public:
	TreeNode() { left = right = NULL; };
	TreeNode(int el)
	{
		left = right = NULL;
		value = el;
	}
	TreeNode(int el, TreeNode* l, TreeNode* r)
	{
		value = el; right = r; left = l;
	}
	bool isLT(int key)
	{
		return value < key;
	}
	bool isGT(int key)
	{
		return value > key;
	}
	bool isEQ(int key)
	{
		return value == key;
	}
	void setKey(int el) { value = el; }
	double getKey() { return value; }
	void visit() { cout << value << " "; }
};
