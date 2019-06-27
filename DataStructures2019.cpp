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

	int arr[8] = { 10,25,20,45,60,50,40,30};

	tree.CreateBinarySearchTreeUsingPostorder(arr, 8);

	tree.InorderTraversal(tree.root);

	return 0;
}
