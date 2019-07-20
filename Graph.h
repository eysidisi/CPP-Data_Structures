#pragma once
class Graph
{
private:
	int size;
	bool *visitArr;
	int** nodeLinks;

private:
	void EnterElementLinks();
	void ResetVisitArr();

public:
	Graph(int size);
	void BreadthFirstSearch(int startingNodeIndex);
	void DepthFirstSearch(int startingNodeIndex);
	void RecursiveDepthFirstSearch(int startingNodeIndex);

};

