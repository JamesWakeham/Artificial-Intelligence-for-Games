#include "Agent.h"



Agent::Agent()
{
}


Agent::~Agent()
{
}



void Agent::Start()
{
	pos = glm::vec2(rand() % 10, rand() % 10);

	std::list<Graph::Node*> endNodes = std::list<Graph::Node*>();
	endNodes.push_back(&graph->grid[rand() % 10][rand() % 10]);
	path = graph->FindShortestPath(&graph->grid[(int)pos.x][(int)pos.y], endNodes);
	target = path.back()->pos;
}

void Agent::Update()
{
	if (!scared) {
		if ((float)glm::distance(pos, target) < 0.1f) {
			if (path.size() > 1) path.pop_back();
			else {
				FindPath();
			}
			target = path.back()->pos;
		}
		vel = target - pos;
	} else if (scared){
	
	}
	vel = glm::normalize(vel);
	vel = vel*0.03f;
	pos = pos + vel;
}

void Agent::Seek(glm::vec2 _target)
{
	target = _target;
}

void Agent::FindPath()
{
	std::list<Graph::Node*> endNodes = std::list<Graph::Node*>();
	endNodes.push_back(&graph->grid[rand() % 10][rand() % 10]);
	path = graph->FindShortestPath(&graph->grid[(int)(pos.x+0.5f)][(int)(pos.y + 0.5f)], endNodes);
	target = path.back()->pos;
}
