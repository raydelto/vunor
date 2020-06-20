#pragma once

#include <string>
#include <vector>
#include "Node.h"
#include "Vertex.h"
#include <glm/glm.hpp>

namespace vunor
{
class Shape: public Node
{
public:
    void SetColor(glm::vec3 color) { _color = color; }
    glm::vec3 GetColor() const { return _color; }
protected:
    glm::vec3 _color {1.0f, 1.0f, 1.0f};
};

} // namespace vunor
