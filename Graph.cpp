#include "Graph.h"
#include <iostream>
#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Graph::Graph()
{
	srand(time(NULL));
	float randomNumb = rand() % 5 + 1;

	

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
			if (x - 1 >= 0)       AddConnection(&grid[x][y], &grid[x - 1][y], rand() % 3 );
			if (y - 1 >= 0)	    AddConnection(&grid[x][y], &grid[x][y - 1], rand() % 3 );
			if (y + 1 < 10)	    AddConnection(&grid[x][y], &grid[x][y + 1], rand() % 3 );
			if (x + 1 < 10)      AddConnection(&grid[x][y], &grid[x + 1][y], rand() % 3 );

			//if (x + 1 < 10 && y - 1 >= 0)  AddConnection(&grid[x][y], &grid[x + 1][y - 1], 1.41f);
			//if (x + 1 < 10 && y + 1 < 10) AddConnection(&grid[x][y], &grid[x + 1][y + 1], 1.41f);
			//if (x - 1 >= 0 && y - 1 >= 0)   AddConnection(&grid[x][y], &grid[x - 1][y - 1], 1.41f);
			//if (x - 1 >= 0 && y + 1 < 10)  AddConnection(&grid[x][y], &grid[x - 1][y + 1], 1.41f);
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

void Graph::AddConnection(Node * n1, Node * n2,float cost)
{
	std::shared_ptr<Edge> connect(new Edge(n2,n1));
	connect.get()->cost = cost;
	n1->connections.push_back(*connect);
}

void Graph::FindShortestPath(Node * start, std::list<Node*> potentialEndNodes)
{
	int gScore =0;
	//openList is list of nodes
	std::list<Node*> openList;
	//closed list is list of nodes
	std::list<Node*> closedList;
	//end node is not pointer set to null
	Node* endNode = nullptr;
	// start node to open list
	openList.push_back(start);

	Graph::Node *currentNode = nullptr;
	//while open list is not empty
	while (!openList.empty()) 
	{
		//sort openlist by gScore
		openList.sort([](const Graph::Node* a, const Graph::Node* b) { return a->gScore < b->gScore; });
		// current node is first item on openlist
		currentNode = openList.front();
		bool isPotentialEnd =false;

		//if current node is one of potential end nodes
		std::list<Node*>::iterator findInPotentialEnd = std::find(potentialEndNodes.begin(), potentialEndNodes.end(), currentNode);
		if (findInPotentialEnd == potentialEndNodes.end()) {
			//not found
		}
		else {			
			endNode = currentNode;
			break;
		}
		//if current node is one of potential end nodes
		//for each (Graph::Node var in grid)
		//{
		//	if (&var == currentNode) {
		//		isPotentialEnd = true;
		//	}
		//}
		//if (isPotentialEnd) {
		//	endNode = currentNode;
		//	break;
		//}

		//remove current node from open list
		openList.remove(currentNode);
		//add current node to closed list
		closedList.push_back(currentNode);

		//for all connections in current node
		for each (Edge var in currentNode->connections)
		{
			var.tested = true;
			
			//add connections to open list if not in closed list
			std::list<Node*>::iterator findInClosed = std::find(closedList.begin(), closedList.end(), var.connection);
			if (findInClosed == closedList.end()) {

				//not found, add to list
				openList.push_back(var.connection);
				var.connection->tested = true;


				//calculate gscore
				var.connection->gScore = currentNode->gScore + var.cost;

				//set parent
				var.connection->parent = currentNode;
			}
			else {
				//if found do nothing
			}
			//std::cout << "Node(" << var.connection->pos.x << "," << var.connection->pos.y << ") parent is Node(" << var.connection->parent->pos.x << "," << var.connection->parent->pos.y << ")" << std::endl;
		}
	}
	std::list<Graph::Node*> path;
	currentNode = potentialEndNodes.front();
	while (currentNode != NULL) {
		currentNode->traversed = true;
		path.push_back(currentNode);
		currentNode = currentNode->parent;
	}
	std::cout << "Path Generated with " << path.size() << " Hops" << std::endl;
}

void Graph::FindNodesInRange(std::vector<Node*>& outNodes, float xPos, float yPos, float radius)
{

}
