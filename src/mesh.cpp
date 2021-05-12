#include "../include/mesh.hpp"

Mesh::Mesh(float* vertices, unsigned int* indices, int vertSize, int indSize) {
    glGenVertexArrays(1, &mVao);

    glBindVertexArray(mVao);

    setupVbo(vertices, vertSize);
    setupIbo(indices, indSize);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &mVao);
    glDeleteBuffers(1, &mVbo);
}

void Mesh::setupVbo(float* vertices, int vertSize) {
    glGenBuffers(1, &mVbo);
    glBindBuffer(GL_ARRAY_BUFFER, mVbo);
    glBufferData(GL_ARRAY_BUFFER, vertSize, vertices, GL_STATIC_DRAW);
}

void Mesh::setupIbo(unsigned int* indices, int indSize) {
    glGenBuffers(1, &mIbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indSize, indices, GL_STATIC_DRAW);
}

void Mesh::draw() {
    // Need to change 6 to sizeof(indices) somehow. 
    glBindVertexArray(mVao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
