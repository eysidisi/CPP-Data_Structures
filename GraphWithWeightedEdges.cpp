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

bool GraphWithWeightedEdges::AreNodesConnected(int* connectionArr, int index1, int index2)
{
	while (connectionArr[index1] >= 0)
	{
		index1 = connectionArr[index1];
	}

	while (connectionArr[index2] >= 0)
	{
		index2 = connectionArr[index2];
	}

	if (index1 != -1 && index1 == index2)
	{
		return true;
	}

	return false;
}

void GraphWithWeightedEdges::Connect(int* arr, int nodeA, int nodeB)
{
	if (arr[nodeA] == -1 && arr[nodeB] != -1)
	{
		arr[nodeA] == nodeB;

		while (arr[nodeB] >= 0)
		{
			nodeB = arr[nodeB];
		}

		arr[nodeB]--;
	}

	else if (arr[nodeB] == -1 && arr[nodeA] != -1)
	{
		arr[nodeB] == nodeA;

		while (arr[nodeA] >= 0)
		{
			nodeA = arr[nodeA];
		}

		arr[nodeA]--;
	}

	else if (arr[nodeA] == -1 && arr[nodeB] == -1)
	{
		arr[nodeA] = nodeB;
		arr[nodeB]--;
	}

	else
	{
		int tempA = nodeA;
		int tempB = nodeB;

		while (arr[nodeB] >= 0)
		{
			nodeB = arr[nodeB];
		}

		while (arr[nodeA] >= 0)
		{
			nodeA = arr[nodeA];
		}

		if (nodeA < nodeB)
		{
			arr[tempB] = tempA;
			arr[nodeA]--;
		}

		else
		{
			arr[tempA] = tempB;
			arr[nodeB]--;
		}

	}
}

bool GraphWithWeightedEdges::CheckIfNodesAreAllConnected()
{
	return true;
}

int GraphWithWeightedEdges::FindUnusedMinLink(int** arr, int size)
{
	int minVal = INT_MAX;
	int minIndex = -1;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[3][i] == 0 && arr[2][i] < minVal)
		{
			minIndex = i;
			minVal = arr[2][i];
		}
	}

	return minIndex;
}

GraphWithWeightedEdges::GraphWithWeightedEdges(int size)
	:size(size), linkArr(new int* [size]), numberOfEdges(0)
{
	for (size_t i = 0; i < size; i++)
	{
		linkArr[i] = new int[size];
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
	int** pathArr = new int* [2];

	for (int i = 0; i < 2; i++)
	{
		pathArr[i] = new int[size - 1];
	}

	int* connectionSet = new int[size];

	for (int i = 0; i < size; i++)
	{
		connectionSet[i] = -1;
	}


	int** linkDistanceArr = new int* [4];

	for (int i = 0; i < 4; i++)
	{
		linkDistanceArr[i] = new int[numberOfEdges];
	}

	int linkDistArrCol = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (linkArr[i][j] != INT_MAX)
			{
				linkDistanceArr[0][linkDistArrCol] = i;
				linkDistanceArr[1][linkDistArrCol] = j;
				linkDistanceArr[2][linkDistArrCol] = linkArr[i][j];
				linkDistanceArr[3][linkDistArrCol] = 0;
				linkDistArrCol++;
			}
		}
	}



	for (int j = 0; j < numberOfEdges; j++)
	{
		printf("from node: %d to node: %d = %d \n", linkDistanceArr[0][j],
			linkDistanceArr[1][j], linkDistanceArr[2][j]);
	}

	int pathArrColIndex = 0;

	for (int i = 0; i < numberOfEdges; i++)
	{
		int minUnusedLinkCol = FindUnusedMinLink(linkDistanceArr, numberOfEdges);

		if (!AreNodesConnected(connectionSet,
			linkDistanceArr[0][minUnusedLinkCol], linkDistanceArr[1][minUnusedLinkCol]))
		{
			Connect(connectionSet, linkDistanceArr[0][minUnusedLinkCol],
				linkDistanceArr[1][minUnusedLinkCol]);

			pathArr[0][pathArrColIndex] = linkDistanceArr[0][minUnusedLinkCol];

			pathArr[1][pathArrColIndex] = linkDistanceArr[1][minUnusedLinkCol];

			pathArrColIndex++;
		}

		linkDistanceArr[3][minUnusedLinkCol] = 1;
	}

	for (int i = 0; i < size-1; i++)
	{
		printf("\n From %d to %d ", pathArr[0][i], pathArr[1][i]);
	}

}
