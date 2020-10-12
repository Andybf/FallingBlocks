//
//  Window.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Window.hpp"

// Constructors Implementations
// =============================================================================

Window::Window() {
    
}
Window::Window(ushort width, ushort height, char * title) {
    this->width = width;
    this->height = height;
    this->title = title;
    this->aspectRatio = height / width;
    Window();
}



// Methods Implementations
// =============================================================================

void Window::close() {
    exit(0);
}



// Getters and Setters Implementations
// =============================================================================

ushort Window::getWidth() {
    return this->width;
}
void Window::setWidth(ushort w) {
    this->width = w;
}

ushort Window::getHeight() {
    return this->height;
}
void Window::setHeight(ushort h) {
    this->height = h;
}

char * Window::getTitle() {
    return this->title;
}
void Window::setTitle(char * t) {
    this->title = t;
}
