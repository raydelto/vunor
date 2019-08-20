#include <iostream>
#include "core/Scene.h"
#include "core/Triangle.h"
#include "core/glfw/Window.h"

using namespace vunor;

int main()
{
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>();
    triangle->SetSize({200,200});
    triangle->SetPosition({400,300});
    triangle->SetColor({0.0f, 1.0f, 0.0f});
    scene->Add(triangle);
    scene->RenderLoop();
    return 0;
}
