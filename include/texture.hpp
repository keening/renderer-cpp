#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <GL/glew.h>

class Texture {
public:
    Texture(const char* texturePath);
    ~Texture();

    unsigned int texture;
    void bindTexture();
private:
};

#endif
