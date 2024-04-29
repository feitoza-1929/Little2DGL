#include <Shader.hpp>

using namespace std;

namespace L2DGE::Graphics
{
    Shader::Shader(const char *vexterPath, const char *fragmentPath)
    {
        string vShaderStringCode, fShaderStringCode;

        ifstream vShaderFile, fShaderFile;
        vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
        fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

        try
        {
            vShaderFile.open(vexterPath);
            fShaderFile.open(fragmentPath);

            stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vShaderStringCode = vShaderStream.str();
            fShaderStringCode = fShaderStream.str();
        }
        catch (ifstream::failure ex)
        {
            cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
        }

        const char *vertexCode = vShaderStringCode.c_str();
        const char *fragmentCode = fShaderStringCode.c_str();

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
            cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                 << logInfo << endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Shader::setVariableFloat(const char *name, float value)
    {
        glUniform1f(glGetUniformLocation(Id, name), value);
    }

    void Shader::setVariableFloat2(const char *name, float* values)
    {
        glUniform2f(glGetUniformLocation(Id, name), values[0], values[1]);
    }

    void Shader::setVariableFloat4(const char *name, float* values)
    {
        glUniform4f(glGetUniformLocation(Id, name), values[0], values[1], values[2], values[3]);
    }

  void Shader::setVariableMatrix4(const char *name, float* values)
  {
    for(int i = 0; i < 16; i++)
    {
      std::cout << values[i] << " ";
    }
    std::cout << std::endl;
    glUniformMatrix4fv(glGetUniformLocation(Id, name), 1, GL_FALSE, values);
  }

    void Shader::activate()
    {
        glUseProgram(Id);
    }
}
