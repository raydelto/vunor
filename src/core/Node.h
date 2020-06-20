#pragma once

#include <string>
#include <glm/glm.hpp>
#include "Size.h"
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif

namespace vunor
{
class Node
{
public:
    Node();
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    void SetName(std::string name) { _name = name; }
    std::string GetName() { return _name; }
    int GetDepth() { return _depth; }
    void SetDepth(int depth) { _depth = depth; }
    void SetVisible(bool visible) { _visible = visible; }
    bool IsVisible() { return _visible; }
    void SetPosition(glm::vec2 position);
    glm::vec2 GetPosition() const{ return _position; }
    void SetSize(Size size) { _size = size; }
    Size GetSize() const{ return _size; }
    uint16_t GetId();
    void SetProgramId(GLuint programId) { _programId = programId; }

protected:
    std::string _name;
    uint8_t _depth;
    bool _visible;
    glm::vec2 _position;
    Size _size;
    bool _changed = true;
    GLuint _programId;
    virtual void UpdateVertexBuffer() = 0;
private:
    static int _instanceCount;
    uint16_t _id;

};

} // namespace vunor
