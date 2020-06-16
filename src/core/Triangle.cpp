#include "Triangle.h"
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif
#include <GLFW/glfw3.h>
#include "glfw/Window.h"
#include <iostream>

using namespace vunor;

Triangle::Triangle()
{
    Init();
}

Triangle::~Triangle()
{
    #ifdef _DEBUG
    std::cout << "Freeing up resources" << std::endl;
    #endif
    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_VBO);
}

void Triangle::UpdateVertexBuffer()
{
    if(_changed)
    {
        ComputeVertices();
        glBindVertexArray(_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)(2 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        _changed = false;

        //Cleaning up
        glBindBuffer(GL_ARRAY_BUFFER, NULL);
        glBindVertexArray(NULL);
    }
}

void Triangle::Init()
{
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
}

void Triangle::ComputeVertices()
{
    _vertices.clear();

    Vertex vertex1;
    vertex1.position = _position;
    _vertices.emplace_back(vertex1);

    Vertex vertex2;
    vertex2.position = {_position.x + _size.width, _position.y};
    _vertices.emplace_back(vertex2);

    Vertex vertex3;
    vertex3.position = {_position.x + (_size.width / 2), _position.y + _size.height};
    _vertices.emplace_back(vertex3);

    auto window = Window::GetInstance();

    for(auto &vertex: _vertices)
    {
        window->ToDeviceCoordinates(vertex.position);
        vertex.color = _color;
        #ifdef _DEBUG
            std::cout << "Vertex: " << vertex.position.x << ","<<vertex.position.y << std::endl;
        #endif
    }

}

void Triangle::Update()
{
}

void Triangle::Render()
{
    UpdateVertexBuffer();
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(NULL);
}


