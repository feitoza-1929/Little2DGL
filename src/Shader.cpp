#include <Shader.hpp>

using namespace std;

namespace L2DGL::Graphics
{
    Shader::Shader(const char *vexterPath, const char *fragmentPath)
    {
        const char *vertexCode = loadShaderCode(vexterPath);
        const char *fragmentCode = loadShaderCode(fragmentPath);

        int isSuccess;
        char logInfo[512];

        unsigned int vertexShader, fragmentShader;

        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexCode, NULL);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isSuccess);
        if(!isSuccess)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, logInfo);
            cout << "ERROR:SHADER::VERTEX::COMPILATION_FAILED\n"
                 << logInfo << endl;
        }

        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isSuccess);
        if (!isSuccess)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, logInfo);
            cout << "ERROR:SHADER::FRAGMENT::COMPILATION_FAILED\n"
                 << logInfo << endl;
        }

        Id = glCreateProgram();
        glAttachShader(Id, vertexShader);
        glAttachShader(Id, fragmentShader);
        glLinkProgram(Id);
        glGetProgramiv(Id, GL_LINK_STATUS, &isSuccess);
        if(!isSuccess)
        {
            glGetProgramInfoLog(Id, 512, NULL, logInfo);
            cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n"
                 << logInfo << endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    const char *Shader::loadShaderCode(const char *shaderPath)
    {
        const char *shaderSourceCode;
        ifstream shaderFile;
        shaderFile.exceptions(ifstream::failbit | ifstream::badbit);

        try
        {
            shaderFile.open(shaderPath);

            stringstream shaderStream;
            shaderStream << shaderFile.rdbuf();

            shaderFile.close();

            shaderSourceCode = shaderStream.str().c_str();
        }
        catch(ifstream::failure ex)
        {
            cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
        }
        return shaderSourceCode;
    }

    void Shader::setVariableFloat(char *name, float value)
    {
        glUniform1f(glGetUniformLocation(Id, name), value);
    }

    void Shader::setVariableFloat4(char *name, float* values)
    {
        glUniform4f(glGetUniformLocation(Id, name), values[0], values[1], values[2], values[3]);
    }

    void Shader::activate()
    {
        glUseProgram(Id);
    }
}