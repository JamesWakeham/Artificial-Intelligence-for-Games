#include "Graph.h"
#include <iostream>
#include <memory>

Graph::Graph()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			grid[x][y] = Node(glm::vec2(x, y));
		}
	}	
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (x - 1 >= 0 && y - 1 >= 0)   AddConnection(&grid[x][y], &grid[x - 1][y - 1]);
			if (x - 1 >= 0)       AddConnection(&grid[x][y], &grid[x - 1][y]);
			if (x - 1 >= 0 && y + 1 < 10)  AddConnection(&grid[x][y], &grid[x - 1][y + 1]);

			if (y - 1 >= 0)	    AddConnection(&grid[x][y], &grid[x][y - 1]);
			if (y + 1 < 10)	    AddConnection(&grid[x][y], &grid[x][y + 1]);

			if (x + 1 < 10 && y - 1 >= 0)  AddConnection(&grid[x][y], &grid[x + 1][y - 1]);
			if (x + 1 < 10)      AddConnection(&grid[x][y], &grid[x + 1][y]);
			if (x + 1 < 10 && y + 1 < 10) AddConnection(&grid[x][y], &grid[x + 1][y + 1]);
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
	std::shared_ptr<Edge> connect(new Edge(n2));
	n1->connections.push_back(*connect);
}

void Graph::FindShortestPath(Node * start, std::list<Node*> potentialEndNodes)
{
	std::list<Node*> openList;
	std::list<Node*> closedList;

	Node* endNode = nullptr;

	openList.push_back(start);
	Graph::Node *currentNode = nullptr;
	while (!openList.empty()) 
	{
		openList.sort([](const Graph::Node* a, const Graph::Node* b) { return a->gScore < b->gScore; });
		currentNode = openList.front();
		bool isPotentialEnd =false;
		for each (Graph::Node var in grid)
		{
			if (&var == currentNode) {
				isPotentialEnd = true;
				break;
			}
		}
		if (isPotentialEnd) {
			openList.remove(currentNode);
			closedList.push_back(currentNode);
		}
		for each (Edge var in currentNode->connections)
		{
			std::list<Node*>::iterator findInClosed = std::find(closedList.begin(), closedList.end(), var.connection);
			if (findInClosed == closedList.end()) {
				//not found
				openList.push_back(var.connection);
				var.connection->gScore = currentNode->gScore + var.cost;
				var.connection->parent = currentNode;
			}
			else {
				//found
			}
		}
	}
	std::list<Graph::Node*> path;
	currentNode = endNode;
	while (currentNode != NULL) {
		currentNode->traversed = true;
		path.push_back(currentNode);
		currentNode = currentNode->parent;
	}
}

void Graph::FindNodesInRange(std::vector<Node*>& outNodes, float xPos, float yPos, float radius)
{

}
