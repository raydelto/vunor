#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace vunor;

Shader::Shader(std::string vertexShaderSourceFile, std::string fragmentShaderSourceFile)
{
    // vertex shader
    GLint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexShaderSource = LoadSource(vertexShaderSourceFile);
    const char *fragmentShaderSource = LoadSource(fragmentShaderSourceFile);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }
    // fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // link shaders
    _id = glCreateProgram();
    glAttachShader(_id, vertexShader);
    glAttachShader(_id, fragmentShader);
    glLinkProgram(_id);
    // check for linking errors
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Use()
{
    glUseProgram(_id);
}

const char* Shader::LoadSource(std::string fileName)
{
	std::stringstream ss;
	std::ifstream file;

	try
	{
		file.open(fileName, std::ios::in);

		if (!file.fail())
		{
			ss << file.rdbuf();
		}
		file.close();
	}
	catch (std::exception ex)
	{
		std::cerr << "Error while  reading " << fileName << " shader filename!" << std::endl;
	}

	return ss.str().c_str();    
}

void Shader::Build()
{

}
