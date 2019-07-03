// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTreeNode.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Heap.h"

int main()
{
	Heap heap;
	
	heap.AddElement(11);
	heap.AddElement(12);
	heap.AddElement(20);
	heap.AddElement(7);
	heap.AddElement(8);
	heap.AddElement(25);
	heap.AddElement(30);

	heap.DisplayLevelorder();
	return 0;
}
