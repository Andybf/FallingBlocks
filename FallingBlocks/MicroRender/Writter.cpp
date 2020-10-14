//
//  PrintWritter.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 02/10/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Writter.hpp"

// Attributes Implementations
// =============================================================================



// Constructors Implementations
// =============================================================================

Writter::Writter() {
    this->setFontFamilySize(GLUT_BITMAP_HELVETICA_12);
    this->setColor(1, 1, 1);
}



// Methods Implementations
// =============================================================================

void Writter::print() {
    glColor3f(this->color.red, this->color.green, this->color.blue);
    glRasterPos3f(this->position.x, this->position.y, this->position.z);
    ushort charCounter = 0;
    while (this->message[charCounter] != '\0') {
        charCounter++;
    }
    for (int i=0; i<charCounter; i++) {
        glutBitmapCharacter(this->font, this->message[i]);
    }
}

void Writter::print(char * message) {
    this->setMessage(message);
    this->print();
}



// Getters and Setters Implementations
// =============================================================================

char * Writter::getMessage() {
    return this->message;
}
void Writter::setMessage(char * message) {
    this->message = message;
}

void Writter::setFontFamilySize(void * fontFamily) {
    this->font = fontFamily;
}

struct Writter::Color Writter::getColor() {
    return this->color;
}
void Writter::setColor(float red,float green,float blue) {
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
}

struct Writter::Position Writter::getPosition() {
    return this->position;
}
void Writter::setPosition(float x, float y, float z) {
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;
}
