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
        Shader();
        void Use();
        GLuint GetId() { return _id; }
    private:
        GLuint _id;
};
} // namespace vunor
