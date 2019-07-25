#include "GraphWithWeightedEdges.h"

void GraphWithWeightedEdges::ConvertOneDimToTwoDim(int index, int* row, int* col)
{
	int a = 0;

	int rowEquation = ((2 * a * size) - (a * a) - a) / 2;

	while (index >= rowEquation)
	{
		a++;
		rowEquation = ((2 * a * size) - (a * a) - a) / 2;
	}

	if (a > 0)
		a--;

	*row = a;

	*col = (index - ((2 * a * size) - (a * a) - a) / 2) + a + 1;
}

bool GraphWithWeightedEdges::IsConnectedConnection(int index1, int index2)
{
	return (connectionArr[index1][index2] == 1);
}

void GraphWithWeightedEdges::Connect(int** arr, int nodeA, int nodeB)
{
	arr[nodeA][nodeB] = 1;
	arr[nodeB][nodeA] = 1;

	connectionArr[nodeA][nodeB] = 1;
	connectionArr[nodeB][nodeA] = 1;

	for (int i = 0; i < size; i++)
	{
		if (connectionArr[nodeA][i])
		{

		}
	}
}

bool GraphWithWeightedEdges::CheckIfNodesAreAllConnected()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (connectionArr[i][j] != 1)
			{
				return false;
			}
		}
	}

	return true;
}

GraphWithWeightedEdges::GraphWithWeightedEdges(int size)
	:size(size), linkArr(new int* [size]), numberOfEdges(0), connectionArr(new int* [size])
{
	for (size_t i = 0; i < size; i++)
	{
		linkArr[i] = new int[size];
		connectionArr[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == j)
			{
				linkArr[i][j] = INT_MAX;
				linkArr[j][i] = INT_MAX;
			}
			else
			{
				printf("Enter the weight of %d to %d.  "
					"If no connection is avaible enter -1\n", i, j);
				int in;
				scanf("%d", &in);

				if (in != -1)
				{
					numberOfEdges++;
					linkArr[i][j] = in;
					linkArr[j][i] = in;
				}

				else
				{
					linkArr[i][j] = INT_MAX;
					linkArr[j][i] = INT_MAX;
				}
			}
		}
	}
}

void GraphWithWeightedEdges::UsePrimSAlgorithm()
{
	int* nearArr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		nearArr[i] = size - 1;
	}
	int roadMapSize = size - 1;

	int** roadMap = new int* [roadMapSize];

	for (int i = 0; i < roadMapSize; i++)
	{
		roadMap[i] = new int[2];
	}

	int minDist = INT_MAX;
	int minDistI = 0;
	int minDistJ = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (linkArr[i][j] < minDist)
			{
				minDist = linkArr[i][j];
				minDistI = i;
				minDistJ = j;
			}
		}
	}

	roadMap[0][0] = minDistI;
	roadMap[0][1] = minDistJ;

	nearArr[minDistI] = -1;
	nearArr[minDistJ] = -1;


	int nearArrSize = size;
	int roadMapDestIndex = 1;

	for (int k = 0; k < size - 2; k++)
	{
		int dist = INT_MAX;
		int nodeIndexForSource = 0;
		int nodeIndexForDestination = 0;

		for (int j = 0; j < nearArrSize; j++)
		{
			if (nearArr[j] == -1)
			{
				for (int i = 0; i < nearArrSize; i++)
				{
					if (nearArr[i] != -1)
					{
						if (dist > linkArr[j][i])
						{
							nodeIndexForSource = j;

							nodeIndexForDestination = i;

							dist = linkArr[j][i];
						}

						if (linkArr[j][i] < linkArr[nearArr[i]][i])
						{
							nearArr[i] = j;
						}
					}
				}
			}
		}

		roadMap[roadMapDestIndex][0] = nodeIndexForSource;
		roadMap[roadMapDestIndex][1] = nodeIndexForDestination;

		nearArr[nodeIndexForDestination] = -1;

		roadMapDestIndex++;
	}

	delete[] nearArr;

	for (int i = 0; i < roadMapSize; i++)
	{
		printf("from: %d to %d \n", roadMap[i][0], roadMap[i][1]);
	}

	for (size_t i = 0; i < 2; i++)
	{
		delete[] roadMap[i];
	}
}

void GraphWithWeightedEdges::ShowGraph()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("From node: %d to node: %d distance is %d \n", i, j, linkArr[i][j]);
		}
	}
}

void GraphWithWeightedEdges::UseKruskalSAlgorithm()
{
	int** usedLinksArr = new int* [size];

	for (int i = 0; i < size; i++)
	{
		usedLinksArr[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			usedLinksArr[i][j] = -1;
		}
	}

	int tableSize = size * (size - 1) / 2;

	int* table = new int[tableSize];

	int* distanceArr = new int[tableSize];



	for (int i = 0; i < tableSize; i++)
	{
		table[i] = i;

		//???
		distanceArr[i] = i;
	}

	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			distanceArr[k] = linkArr[i][j];
			k++;
		}
	}


	// Use a simple sorting algorithm. Linear sort maybe?

	for (int j = 0; j < tableSize - 1; j++)
	{
		bool flag = false;
		int minElement = distanceArr[j];
		int minElementIndex = -1;


		for (int i = j + 1; i < tableSize; i++)
		{
			if (distanceArr[i] < minElement)
			{
				minElementIndex = i;
				minElement = distanceArr[i];
				flag = true;
			}
		}

		if (flag)
		{
			int temp = distanceArr[minElementIndex];

			distanceArr[minElementIndex] = distanceArr[j];

			distanceArr[j] = temp;

			temp = table[minElementIndex];

			table[minElementIndex] = table[j];

			table[j] = temp;
		}
	}


	for (int i = 0; i < tableSize; i++)
	{
		int row = 0;
		int col = 0;

		ConvertOneDimToTwoDim(table[i], &row, &col);

		bool isConnected = IsConnectedConnection(row, col);

		if (row == 2 && col == 4)
		{
			printf("asad");
		}

		if (!isConnected)
		{
			Connect(usedLinksArr, row, col);
			printf("Connection Arr: \n");

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					printf("ConnArr[%d][%d]: %d \n", i, j, connectionArr[i][j]);
				}
			}

			printf("usedLinksArr:\n");

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					printf("usedLinksArr[%d][%d]: %d \n", i, j, usedLinksArr[i][j]);
				}
			}


			if (CheckIfNodesAreAllConnected())
			{
				break;
			}
		}

	}

}
