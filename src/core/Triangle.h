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
    ~Triangle();
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
private:
    GLuint _VBO;
    GLuint _VAO;
    std::vector<Vertex> _vertices;
protected:
    virtual void UpdateVertexBuffer() override;
private:
    void ComputeVertices();
};

} // namespace vunor
