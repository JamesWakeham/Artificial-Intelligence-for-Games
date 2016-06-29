#include "Node.h"

Node::Node()
{
	pos = glm::vec2(0,0);
	previous = nullptr;
	gScore =0;
}

Node::Node(glm::vec2 _pos)
{
	pos = _pos;
	previous = nullptr;
	gScore = 0;
}


Node::Node(glm::vec2 _pos, Node * _previous, float _gScore)
{
	pos = _pos;
	previous = _previous;
	gScore = _gScore;
}

Node::~Node()
{
}
