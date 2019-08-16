#pragma once

#include <map>
#include <vector>
#include "Node.h"
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif
#include "glfw/Window.h"
#include "Shader.h"

namespace vunor
{
class Scene
{
public:
    Scene();
    void Add(std::shared_ptr<Node> node, int depth);
    void Add(std::shared_ptr<Node> node);
    void Remove(std::shared_ptr<Node> node);
    void RenderLoop();

private:
    std::map<int, std::vector<std::shared_ptr<Node>>> _nodes;
    std::shared_ptr<Window> _window;
    int _lastDefaultDepth;
    std::unique_ptr<Shader> _shader;
    void Render();

};
} // namespace vunor