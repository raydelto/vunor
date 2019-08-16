#pragma once
#include <memory>
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif
#include <GLFW/glfw3.h>

namespace vunor
{

struct DestroyGLFWWindow
{

    void operator()(GLFWwindow* ptr)
    {
         glfwDestroyWindow(ptr);
    }
};

typedef std::unique_ptr<GLFWwindow, DestroyGLFWWindow> SmartGLFWwindow;

class Window
{
    public:
        static std::shared_ptr<Window> GetInstance();
        void SwapBuffers();
        bool ShouldClose();
        void ShowFPS();
        void ProcessInput();
        void Terminate();

    private:
        Window();
        void Init();
        SmartGLFWwindow _glfwWindow;
        static std::shared_ptr<Window> _instance;
                
        const char* _title = "Vunor Sandbox";
        // settings
        unsigned int _width;
        unsigned int _height;
};
} // namespace vunor