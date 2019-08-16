#pragma once

#include <string>
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif

namespace vunor
{
class Shader
{
    public:
        Shader(std::string vertexShaderSourceFile, std::string fragmentShaderSourceFile);
        void Use();
    private:
        GLint _id;
        const char* LoadSource(std::string fileName);
        void Build();      
};
} // namespace vunor