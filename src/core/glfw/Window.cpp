#include "Window.h"
#include <iostream>
#include <sstream>

using namespace vunor;

void Resize(GLFWwindow *window, int width, int height);

Window::Window():_width(800), _height(600)
{
    Init();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(_glfwWindow.get());
}

std::shared_ptr<Window> Window::GetInstance()
{
    if(!_instance)
    {
        _instance.reset(new Window());
    }
    return _instance;
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(_glfwWindow.get());
    glfwPollEvents();
}

void Window::Init()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
#endif

    // glfw window creation
    // --------------------
    // _glfwWindow = std::make_unique<GLFWwindow>(glfwCreateWindow(_width, _height, _title, NULL, NULL));
    _glfwWindow.reset(glfwCreateWindow(_width, _height, _title, NULL, NULL));
    // _glfwWindow.reset(glfwCreateWindow(_width, _height, _title, NULL, NULL));
    if (_glfwWindow == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(_glfwWindow.get());
    glfwSetFramebufferSizeCallback(_glfwWindow.get(), Resize);

	#ifdef __APPLE__
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
    }	
	#else
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
	}
	#endif    
}

void Window::Terminate()
{
    glfwTerminate();
}

void Window::ProcessInput()
{
    if (glfwGetKey(_glfwWindow.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(_glfwWindow.get(), true);
}

void Resize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::ShowFPS()
{
	static double previousSeconds = 0.0;
	static int frameCount = 0;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime(); // returns number of seconds since GLFW started, as double float

	elapsedSeconds = currentSeconds - previousSeconds;

	// Limit text updates to 4 times per second
	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerFrame = 1000.0 / fps;

		// The C++ way of setting the window title
		std::ostringstream outs;
		outs.precision(3);	// decimal places
		outs << std::fixed
			<< _title << "    "
			<< "FPS: " << fps << "    "
			<< "Frame Time: " << msPerFrame << " (ms)";
		glfwSetWindowTitle(_glfwWindow.get(), outs.str().c_str());

		// Reset for next average.
		frameCount = 0;
	}

	frameCount++;
}
