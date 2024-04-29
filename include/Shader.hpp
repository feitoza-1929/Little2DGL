#ifndef __SHADER_HPP
#define __SHADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

namespace L2DGE::Graphics
{
    class Shader
    {
    private:
        unsigned int Id;

    public:
        Shader() = default;
        Shader(const char *vexterPath, const char *fragmentPath);
        void setVariableFloat(const char *name, float value);
        void setVariableFloat2(const char *name, float *values);
        void setVariableFloat4(const char *name, float *values);
      void setVariableMatrix4(const char *name, float* values);
        void activate();
        unsigned int getId();
    };
}
#endif
