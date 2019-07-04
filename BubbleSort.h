#pragma once
template<class T>
class BubbleSort
{
public:
	static void Sort(T arr[], int size);
};

template<class T>
void BubbleSort<T>::Sort(T arr[], int size)
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
