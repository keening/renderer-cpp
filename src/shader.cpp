#include "../include/shader.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

Shader::Shader(const char *vertexPath, const char *fragPath) {
    std::ifstream vFile;
    std::ifstream fFile;
    std::string vCode;
    std::string fCode;
    std::stringstream vStr;
    std::stringstream fStr;

    vFile.open(vertexPath);
    vStr << vFile.rdbuf();
    vFile.close();
    vCode = vStr.str();
    
    const char* vShaderSrc = vCode.c_str();
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderSrc, NULL);
    glCompileShader(vertexShader);

    fFile.open(fragPath);
    fStr << fFile.rdbuf();
    fFile.close();
    fCode = fStr.str();

    const char* fShaderSrc = fCode.c_str();
    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fShaderSrc, NULL);
    glCompileShader(fragShader);

    fFile.close();

    program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

Shader::~Shader() {
}

void Shader::use() {
    glUseProgram(program);
}
