#include "Node.h"

using namespace vunor;

uint16_t Node::GetId()
{
    static int id = 0;
    return id++;
}

void Node::SetPosition(Position position)
{
    _position = position; 
    _changed = true;
}
