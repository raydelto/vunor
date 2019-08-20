#pragma once

#include <string>
#include <vector>
#include "Node.h"
#include "Vertex.h"

namespace vunor
{
class Shape: public Node
{
public:
    void SetColor(Color color) { _color = color; }
    Color GetColor() const { return _color; }
protected:
    Color _color {1.0f, 1.0f, 1.0f};
};

} // namespace vunor
