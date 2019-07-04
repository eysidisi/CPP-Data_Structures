// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTreeNode.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "BubbleSort.h"	

int main()
{
	int arr[5] = { 2,1,14,22,3 };

	BubbleSort<int>::Sort(arr, 5);

	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
