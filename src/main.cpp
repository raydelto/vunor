#include <iostream>
#include "core/Scene.h"
#include "core/Triangle.h"
#include "core/glfw/Window.h"

using namespace vunor;

int main()
{
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>();
    scene->Add(triangle);
    scene->RenderLoop();
    return 0;
}