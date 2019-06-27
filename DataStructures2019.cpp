// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"

int main()
{
	int arr[] = { 1,2,3 };

	BinaryTree<int> tree;

	for (size_t i = 0; i < 3; i++)
	{
		tree.root=tree.RecursiveInsertElementInBinaryTree(tree.root, arr[i]);
	}

	return 0;
}
