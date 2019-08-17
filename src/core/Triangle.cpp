#include "Triangle.h"
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif
#include <GLFW/glfw3.h>

using namespace vunor;

Triangle::Triangle()
{
    Init();
}

void Triangle::Init()
{
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //right
        0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  //Top
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f //left
    };

    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);

    //Triangle 1
    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    //Cleaning up
    glBindBuffer(GL_ARRAY_BUFFER, NULL);
    glBindVertexArray(NULL);
}

void Triangle::Update()
{
}

void Triangle::Render()
{
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(NULL);
}


