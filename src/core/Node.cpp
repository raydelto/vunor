#include "Node.h"

using namespace vunor;

int Node::_instanceCount = 0;

Node::Node()
{
    _id = _instanceCount;
    _instanceCount++;
    _position= glm::vec2(0.0f,0.0f);
}

uint16_t Node::GetId()
{
    return _id;
}

void Node::SetPosition(glm::vec2 position)
{
    _position = position; 
    _changed = true;
}
