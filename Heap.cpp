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
		int parentNodeIndex = floor((currentPos-1) / 2);

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
