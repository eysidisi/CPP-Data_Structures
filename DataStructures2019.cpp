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
#include "GraphWithWeightedEdges.h"

int main()
{
	GraphWithWeightedEdges graph(4);

	graph.UsePrimSAlgorithm();
	return 0;
}
