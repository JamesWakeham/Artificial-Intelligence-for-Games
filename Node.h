#pragma once
#include <glm\vec2.hpp>
class Node
{
public:
	glm::vec2 pos;
	Node * previous;
	float gScore;
	Node();
	Node(glm::vec2 _pos);
	Node(glm::vec2 _pos, Node* _previous, float _gScore);
	~Node();
};
