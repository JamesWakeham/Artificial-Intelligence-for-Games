#pragma once
#include <glm\glm.hpp>
#include <iostream>
#include <glm\geometric.hpp>
#include <glm\trigonometric.hpp>
#include <list>
#include "Graph.h"


class Agent
{
public:
	std::list<Graph::Node*> path;
	glm::vec2 pos;
	glm::vec2 vel;
	glm::vec2 target;
	Graph* graph;
	bool scared;
	Agent();
	~Agent();
	void Start();
	void Update();
	void Seek(glm::vec2 _target);
	void FindPath();
};

