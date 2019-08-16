#pragma once

#include <string>
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
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    void SetName(std::string name) { _name = name; }
    std::string GetName() { return _name; }
    int GetDepth() { return _depth; }
    void SetDepth(int depth) { _depth = depth; }
    void SetVisible(bool visible) { _visible = visible; }
    bool IsVisible() { return _visible; }
    uint16_t GetId();

protected:
    std::string _name;
    uint8_t _depth;
    bool _visible;
};

} // namespace vunor