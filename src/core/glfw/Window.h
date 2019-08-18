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
enum class Direction
{
    X,
    Y
};

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
        void SetSize(unsigned int width, unsigned int height);
        unsigned int GetWidth()  { return _width; }
        unsigned int GetHeight() { return _height; }
        float ToDeviceCoordinates(unsigned int coordinate, Direction direction);

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
