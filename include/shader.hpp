#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>

#include <GL/glew.h>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragPath);
    ~Shader();
   
    void use();
    unsigned int program;
private:
};

#endif
