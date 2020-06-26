#include <memory>
#include <iostream>
#include "core/Scene.h"
#include "core/Triangle.h"
#include "core/glfw/Window.h"
#include <glm/glm.hpp>

using namespace vunor;


int main()
{
    glm::vec2 position = glm::vec2(300.0f,200.0f);
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    std::shared_ptr<Triangle> triangle = std::make_shared<Triangle>();
    triangle->SetSize({200,200});
    triangle->SetPosition(position);
    triangle->SetColor({0.5f, 0.35f, 0.0f});
    scene->Add(triangle);

    std::shared_ptr<Triangle> triangle2 = std::make_shared<Triangle>();
    triangle2->SetSize({100,100});
    triangle2->SetPosition({0.0f,0.0f});
    triangle2->SetColor({0.0f, 0.0f, 1.0f});
    scene->Add(triangle2);

    std::shared_ptr<Triangle> triangle3 = std::make_shared<Triangle>();
    triangle3->SetSize({100,100});
    triangle3->SetPosition({200.0f,200.0f});
    triangle3->SetColor({1.0f, 0.0f, 0.0f});
    scene->Add(triangle3);


    std::shared_ptr<Triangle> triangle4 = std::make_shared<Triangle>();
    triangle4->SetSize({40,40});
    triangle4->SetPosition({600.0f,400.0f});
    triangle4->SetColor({1.0f, 1.0f, 0.0f});
    scene->Add(triangle4);


    scene->RenderLoop();
    #ifdef _DEBUG
    std::cout << "execution end" << std::endl;
    #endif
    return 0;
}
