#pragma once

#include <string>
#include <vector>
#include "Shape.h"
#include "Vertex.h"
#include <glm/glm.hpp>

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
    glm::mat4 _model;
    glm::mat4 _view;
    glm::mat4 _projection;
    GLuint _modelLocation;
    GLuint _viewLocation;
    GLuint _projectionLocation;
    bool _uniformsInitialized = false;
};

} // namespace vunor
