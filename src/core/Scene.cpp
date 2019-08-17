#include "Scene.h"

using namespace vunor;

Scene::Scene(): _lastDefaultDepth(0)
{
    _window = Window::GetInstance();
    _shader = std::make_unique<Shader>();

}

void Scene::Add(std::shared_ptr<Node> node, int depth)
{
    if(_nodes.find(depth) == _nodes.end())
    {
        std::vector<std::shared_ptr<Node>> localNodeList;
        _nodes[depth] = localNodeList;
    }
    _nodes[depth].push_back(node);
}

void Scene::Add(std::shared_ptr<Node> node)
{
    Add(node, _lastDefaultDepth++);
}

void Scene::Remove(std::shared_ptr<Node> node)
{

}

void Scene::RenderLoop()
{
    while (! _window->ShouldClose())
    {
        _window->ShowFPS();
        _window->ProcessInput();
     
        Render();
     
        _window->SwapBuffers();
    }
    _window->Terminate();
}

void Scene::Render()
{   
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
 
    _shader->Use();
    for(auto &depthLevel: _nodes)
    {
        for(auto &node: depthLevel.second)
        {
            node->Render();
        }
    }   
}
