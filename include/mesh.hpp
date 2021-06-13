#ifndef MESH_H
#define MESH_H

#include <glew.h>

class Mesh {
public:
    Mesh(float* vertices, unsigned int* indices, int vertSize, int indSize);
    ~Mesh();

    void draw();
    void setupVbo(float* vertices, int vertSize);
    void setupIbo(unsigned int* indices, int indSize);
private:
    unsigned int mVbo, mVao, mIbo;
};

#endif
