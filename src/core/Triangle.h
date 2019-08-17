#pragma once

#include <string>
#include <vector>
#include "Shape.h"
#include "Vertex.h"

namespace vunor
{
class Triangle: public Shape
{
public:
    Triangle();
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
private:
    GLuint _VBO;
    GLuint _VAO;
    std::vector<Vertex> _vertices;
    Color defaultColor {255.0f, 255.0f, 255.0f};
};

} // namespace vunor
