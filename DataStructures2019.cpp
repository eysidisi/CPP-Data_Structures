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
#include "Graph.h"

int main()
{
	Graph graph(8);
	while (true)
	{
		int in;
		printf("\nEnter value to start search: \n");
		scanf("%d", &in);
		graph.RecursiveDepthFirstSearch(in);
	}
	return 0;
}
