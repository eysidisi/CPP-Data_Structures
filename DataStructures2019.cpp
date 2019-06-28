// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"

int main()
{
	int arr[] = { 5,3,7,4,6,8 };

	BinaryTree<int> tree;

	for (size_t i = 0; i < 6; i++)
	{
		tree.RecursiveInsertElementInBinaryTree(tree.root, arr[i]);
	}

	tree.DeleteElement(5,tree.root);

	tree.CheckAVLTree();

	tree.LevelorderTraversal();

	return 0;
}
