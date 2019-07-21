#include "GraphWithWeightedEdges.h"
#include <cstdio>
#include <climits> 

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
			printf("from: %d to %d \n", roadMap[i][0],roadMap[i][1]);
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
