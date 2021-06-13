#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include <glew.h>
#include <glfw3.h>

class Window {
public:
    Window();
    ~Window();

    void present();
private:
    void init();

    GLFWwindow *window;
    static const int kScreenW = 640;
    static const int kScreenH = 480;
};

#endif
