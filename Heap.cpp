#include "Heap.h"

Heap::Heap(int _capacity)
	: size(0), capacity(_capacity), arr(new int[_capacity])
{
}

Heap::~Heap()
{
	delete(arr);
}

void Heap::AddElement(int element)
{
	if (size == capacity - 1)
	{
		int* tempP = arr;
		capacity *= 2;
		arr = new int[capacity];
		delete(tempP);
	}

	arr[size] = element;
	size++;

	int currentPos = size - 1;

	while (currentPos > 0)
	{
		int parentNodeIndex = floor((currentPos - 1) / 2);

		if (arr[currentPos] > arr[parentNodeIndex])
		{
			int temp = arr[currentPos];
			arr[currentPos] = arr[parentNodeIndex];
			arr[parentNodeIndex] = temp;
			currentPos = parentNodeIndex;
		}
		else
		{
			break;
		}
	}
}

void Heap::DisplayLevelorder()
{
	int i = 0;

	while (i * 2 + 1 <= size - 1)
	{
		if (i == 0)
		{
			printf("%d ", arr[i]);
		}

		printf("%d ", arr[i * 2 + 1]);


		if ((i * 2 + 2) < size)
		{
			printf("%d ", arr[i * 2 + 2]);
		}

		i++;
	}
}

int Heap::Delete()
{
	int valueToReturn = arr[0];

	arr[0] = arr[size - 1];
	size--;
	int currentNodeIndex = 0;
	int leftChildIndex = 1;
	int rightChildIndex = 2;

	while (leftChildIndex < size - 1)
	{
		if ((rightChildIndex <= size - 1) && (arr[rightChildIndex] > arr[leftChildIndex] )&&
			(arr[rightChildIndex] > arr[currentNodeIndex]))
		{
			int temp = arr[rightChildIndex];
			arr[rightChildIndex] = arr[currentNodeIndex];
			arr[currentNodeIndex] = temp;
			currentNodeIndex = rightChildIndex;
			leftChildIndex = currentNodeIndex * 2 + 1;
			rightChildIndex = leftChildIndex + 1;
		}

		else if (arr[leftChildIndex] > arr[currentNodeIndex])
		{
			int temp = arr[leftChildIndex];
			arr[leftChildIndex] = arr[currentNodeIndex];
			arr[currentNodeIndex] = temp;
			currentNodeIndex = leftChildIndex;
			leftChildIndex = currentNodeIndex * 2 + 1;
			rightChildIndex = leftChildIndex + 1;
		}

		else
		{
			break;
		}
	}

	return valueToReturn;
}
