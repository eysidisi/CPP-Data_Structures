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

int main()
{
	const int size = 8;

	int arr[size] = { 5,1,7,2,12,0,52,-20 };

	Sort::QuickSort(arr, size);

	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
