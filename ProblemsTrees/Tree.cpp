#include "Tree.h"

void Tree::deleteTree(TreeNode* node)
{
	if (node != NULL)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

void Tree::insert(int el)
{
	TreeNode* tmp = root, *prev = NULL;

	while (tmp != NULL)
	{
		prev = tmp;
		if (tmp->isLT(el))
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if (root == NULL)
		root = new TreeNode(el);
	else
	{
		if (prev->isLT(el))
			prev->right = new TreeNode(el);
		else
			prev->left = new TreeNode(el);
	}
}

void Tree::preorder(TreeNode* node)
{
	if (node != NULL)
	{
		node->visit();
		preorder(node->left);
		preorder(node->right);
	}
}

int Tree::height()
{
	return height(root, 0);
}

int Tree::height(TreeNode* node, int h)
{
	if (node != NULL)
	{
		int lh = height(node->left, h + 1);
		int rh = height(node->right, h + 1);
		if (rh > lh)
			return rh;
		else
			return lh;
	}
	else
		return h;
}

int Tree::depth(int el)
{
	return depth(root, 0, el);
}

int Tree::depth(TreeNode* node, int d, int el)
{
	if (node == NULL)
		return 0;

	if (node->value == el)
		return d + 1;
	
	int dl = depth(node->left, d + 1, el);
	int dr = depth(node->right, d + 1, el);
	
	if (dl == 0 && dr == 0)
		return 0;
	else return dl > 0 ? dl : dr;
}

void Tree::mirror(TreeNode* node)
{
	if (node == NULL)
		return;

	mirror(node->left);
	mirror(node->right);

	TreeNode* p = node->left;
	node->left = node->right;
	node->right = p;
	

}

level Tree::maxNumLevel()
{
	int height = this->height();
	int* levels = (int*)calloc(height, sizeof(int)); //all zeros in array with calloc
	level* max = new level();

	getNumLevel(root, 0, levels);

	max->level = 0;
	max->numOfNodes = levels[0];

	for (int i = 1; i < height; i++)
	{
		if (levels[i] > max->numOfNodes)
		{
			max->level = i;
			max->numOfNodes = levels[i];
		}
	}
	free(levels);
	return *max;
}

void Tree::getNumLevel(TreeNode* node, int level, int* array)
{
	if (node == NULL)
		return;
	array[level]++;
	getNumLevel(node->left, level + 1, array);
	getNumLevel(node->right, level + 1, array);
}
