// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>    // For time()

#include <iostream>
#include "BinaryTreeNode.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "LinkedList.h"
#include "Sort.h"
#include "ChainHashTable.h"
#include "ProbingHashTable.h"

int main()
{
	srand(time(0));

	ProbingHashTable hashTable(2);

	for (int i = 0; i < 50; i++)
	{
		hashTable.AddElement(rand()%1000);
	}


	hashTable.Display();

	printf(" %d ", hashTable.FindElement(43));

	


	return 0;
}
