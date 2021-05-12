#include "../include/input.hpp"

Input::Input() {
}

Input::~Input() {
}

void Input::processInput() {
    if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
    }
}
