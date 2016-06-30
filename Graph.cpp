#include "Graph.h"
#include <iostream>


Graph::Graph()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			grid[x][y] = Node(glm::vec2(x, y));
			if (x - 1 >= 0 && y - 1 >= 0)   AddConnection(&grid[x][y], &grid[x - 1][y - 1]);
			if (x - 1 >= 0 && y >= 0)       AddConnection(&grid[x][y], &grid[x - 1][y]);
			if (x - 1 >= 0 && y + 1 <= 10)  AddConnection(&grid[x][y], &grid[x - 1][y + 1]);

			if (x >= 0 && y - 1 >= 0)	    AddConnection(&grid[x][y], &grid[x][y - 1]);
			if (x >= 0 && y + 1 <= 10)	    AddConnection(&grid[x][y], &grid[x][y + 1]);

			if (x + 1 <= 10 && y - 1 >= 0)  AddConnection(&grid[x][y], &grid[x + 1][y - 1]);
			if (x + 1 <= 10 && y >= 0)      AddConnection(&grid[x][y], &grid[x + 1][y]);
			if (x + 1 <= 10 && y + 1 <= 10) AddConnection(&grid[x][y], &grid[x + 1][y + 1]);
		}
	}
}


Graph::~Graph()
{

}

Graph::Node * Graph::AddNode(int xPos, int yPos)
{
	grid[xPos][yPos] = Graph::Node(glm::vec2(xPos, yPos));
	return &grid[xPos][yPos];
}

void Graph::AddConnection(Node * n1, Node * n2)
{
	n1->connections.push_back(Edge(n2));
}

void Graph::FindShortestPath(Node * start, const std::list<Node*>& potentialEndNodes, std::list<Node*>& outPath)
{

}

void Graph::FindNodesInRange(std::vector<Node*>& outNodes, float xPos, float yPos, float radius)
{

}
