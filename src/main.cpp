#include "../include/window.hpp"
#include "../include/mesh.hpp"
#include "../include/shader.hpp"
#include "../include/input.hpp"
#include "../include/texture.hpp"

int main(int argc, char *argv[]) {
    Window w;   
    Input i;
    Shader s("./shaders/vertex.glsl", "./shaders/frag.glsl");

    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    Mesh m(vertices, indices, sizeof(vertices), sizeof(indices));
    Texture t("./assets/default.jpg");

    while (!glfwWindowShouldClose(glfwGetCurrentContext())) {
        i.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        t.bindTexture();
        s.use();
        m.draw();
        w.present();
    }
    return 0;
}
