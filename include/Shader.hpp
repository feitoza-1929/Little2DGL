#ifndef __SHADER_HPP
#define __SHADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

namespace L2DGL::Graphics
{
    class Shader
    {
    private:
        unsigned int Id;

    public:
        Shader() = default;
        Shader(const char *vexterPath, const char *fragmentPath);
        void setVariableFloat(char *name, float value);
        void setVariableFloat4(char *name, float *values);
        void activate();
        unsigned int getId();
    };
}
#endif