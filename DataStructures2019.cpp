// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTreeNode.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "LinkedList.h"
#include "Sort.h"
#include "ChainHashTable.h"
#include "LinearProbingHashTable.h"

int main()
{
	LinearProbingHashTable hashTable;

	hashTable.AddElement(3);

	hashTable.Display();

	hashTable.DeleteElement(3);

	hashTable.AddElement(103);

	hashTable.AddElement(27);
	hashTable.DeleteElement(21);
	hashTable.Display();

	


	return 0;
}
