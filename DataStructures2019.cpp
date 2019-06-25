// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"

int main()
{
	BinaryTree <int> tree;

	int arr[6] = { 30,20,10,25,40,35 };

	tree.CreateBinarySearchTreeUsingPreorder(arr, 6);

	tree.InorderTraversal(tree.root);

	return 0;
}
