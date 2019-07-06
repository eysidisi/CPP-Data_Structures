#pragma once
#include <cstdio>
namespace Sort
{
	/// Startpoint is inclusive
	void ShiftElementsToLeft(int arr[], int startPoint)
	{
		int i = 0;

		while (i < startPoint)
		{
			arr[i] = arr[i + 1];
			i++;
		}
	}


	void InsertionSort(int arr[], int size)
	{
		if (size <= 1)
			return;

		for (int i = 0; i < size; i++)
		{
			int elementToSort = arr[i];

			int sortingIndex = i - 1;

			while (sortingIndex >= 0 && arr[sortingIndex] > elementToSort)
			{
				arr[sortingIndex + 1] = arr[sortingIndex];
				sortingIndex--;
			}

			arr[sortingIndex + 1] = elementToSort;
		}
	}

	template<class T>
	void BubbleSort(T arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			bool anySwapIsDone = false;

			for (size_t j = 0; j < size - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					T temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					anySwapIsDone = true;
				}
			}

			if (!anySwapIsDone)
				break;
		}
	}

	void SelectionSort(int arr[], int size)
	{
		for (size_t sortingElementIndex = 0; sortingElementIndex < size; sortingElementIndex++)
		{
			int i, k;
			i = k = sortingElementIndex;

			while (k < size)
			{
				if (arr[k] < arr[i])
				{
					i = k;
				}

				k++;
			}

			int temp = arr[sortingElementIndex];
			arr[sortingElementIndex] = arr[i];
			arr[i] = temp;
		}
	}

	void QuickSort(int arr[], int size)
	{
		if (size == 1) return;

		int startIndex = 1;
		int endIndex = size - 1;
		int elementToSort = arr[0];
		
		while ( startIndex != endIndex)
		{
			if (arr[startIndex] < elementToSort)
			{
				startIndex++;
			}

			if (startIndex == endIndex)
				break;

			if (arr[endIndex] > elementToSort)
			{
				endIndex--;
			}

			if (startIndex == endIndex)
				break;

			if (arr[startIndex] >= elementToSort && arr[endIndex] <= elementToSort)
			{
				int temp = arr[startIndex];
				arr[startIndex] = arr[endIndex];
				arr[endIndex] = temp;
			}
		}

		if (startIndex == endIndex)
		{
			if (arr[startIndex] > elementToSort)
			{
				ShiftElementsToLeft(arr, startIndex - 1);
				arr[startIndex - 1] = elementToSort;
				QuickSort(&arr[startIndex], size - startIndex);
				QuickSort(&arr[0], startIndex);
			}

			else
			{
				ShiftElementsToLeft(arr, startIndex);
				arr[startIndex] = elementToSort;
				QuickSort(&arr[startIndex + 1], size - startIndex - 1);
				QuickSort(&arr[0], startIndex);
			}
		}
	}

}
