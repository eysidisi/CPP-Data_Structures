// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTreeNode.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "BubbleSort.h"	
#include "LinkedList.h"

int main()
{
	LinkedList list;

	list.AddElement(5);
	list.AddElement(4);
	list.AddElement(3);
	list.AddElement(52);
	list.AddElement(-4);
	list.AddElement(1);

	list.UseInsertionSort();
	list.Display();

	return 0;
}
