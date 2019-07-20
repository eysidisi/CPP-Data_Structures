#include "Graph.h"
#include <cstdio>
#include "Queue.h"
#include "Stack.h"

Graph::Graph(int size)
	: size(size), nodeLinks(new int* [size]), visitArr(new bool[size])
{
	for (size_t i = 0; i < size; i++)
	{
		nodeLinks[i] = new int[size];
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == j)
			{
				nodeLinks[i][j] = 0;
			}
			else
			{
				nodeLinks[i][j] = -1;
			}
		}
	}

	ResetVisitArr();

	EnterElementLinks();
}

void Graph::EnterElementLinks()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((nodeLinks[i][j] != 1) && (nodeLinks[i][j] != 0))
			{
				printf("Is node %d linked to node %d? "
					"Press 1 for yes and any other number for no. \n", i, j);

				int in = 0;
				scanf("%d", &in);

				if (in == 1)
				{
					nodeLinks[i][j] = 1;
					nodeLinks[j][i] = 1;
				}

				else
				{
					nodeLinks[i][j] = 0;
					nodeLinks[j][i] = 0;
				}
			}
		}
	}
}

void Graph::ResetVisitArr()
{
	for (size_t i = 0; i < size; i++)
	{
		visitArr[i] = false;
	}
}

void Graph::BreadthFirstSearch(int nodeIndex)
{
	Queue<int> queue;

	queue.Enqueue(nodeIndex);

	while (!queue.IsEmpty())
	{
		int currentNode = queue.Dequeue();

		if (visitArr[currentNode] == false)
		{
			visitArr[currentNode] = true;
			printf("%d, ", currentNode);
		}

		for (int i = 0; i < size; i++)
		{
			if (nodeLinks[currentNode][i] == 1 && visitArr[i] == false)
			{
				printf("%d, ", i);
				visitArr[i] = true;
				queue.Enqueue(i);
			}
		}
	}

	ResetVisitArr();
}

void Graph::DepthFirstSearch(int startingNodeIndex)
{
	Stack<int> stack;

	stack.Push(startingNodeIndex);

	int currentNode;

	while (!stack.IsEmpty())
	{

		currentNode = stack.Pop();

		if (visitArr[currentNode] == false)
		{
			visitArr[currentNode] = true;
			printf("%d, ", currentNode);
		}

		for (size_t i = 0; i < size; i++)
		{
			if (nodeLinks[currentNode][i] == 1 && visitArr[i] == false)
			{
				stack.Push(currentNode);
				stack.Push(i);
				break;
			}
		}
	}

	ResetVisitArr();
}

void Graph::RecursiveDepthFirstSearch(int startingNodeIndex)
{
	static int flag = startingNodeIndex;

	if (visitArr[startingNodeIndex] == false)
	{
		printf("%d, ", startingNodeIndex);
		visitArr[startingNodeIndex] = true;
	}

	for (int i = 0; i < size; i++)
	{
		if (nodeLinks[startingNodeIndex][i] == 1 && visitArr[i] == false)
		{
			RecursiveDepthFirstSearch(i);
		}
	}

	if (flag == startingNodeIndex)
	{
		ResetVisitArr();
	}
}
