#pragma once

#include <string>
#include "Node.h"
namespace vunor
{
class Triangle: public Node
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
private:
    GLuint _VBO;
    GLuint _VAO;
};

} // namespace vunor