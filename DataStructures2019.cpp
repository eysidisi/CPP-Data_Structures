// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"

int main()
{
	int arr[] = { 4,6,5,10,7 };

	BinaryTree<int> tree;

	for (size_t i = 0; i < 5; i++)
	{
		tree.RecursiveInsertElementInBinaryTree(tree.root, arr[i]);
	}

	tree.InorderTraversal(tree.root);

	return 0;
}
