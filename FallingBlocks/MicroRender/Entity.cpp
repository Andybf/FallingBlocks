//
//  Entity.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Entity.hpp"

// Attributes Implementations
// =============================================================================



// Constructors Implementations
// =============================================================================

Entity::Entity () {
    this->color.red = 0;
    this->color.green = 0;
    this->color.blue = 0;
    
    this->position.x = 0;
    this->position.y = 0;
    this->position.z = 0;
    
    this->objectType = GL_POLYGON;
}

Entity::Entity (std::vector<GLfloat> objectVectors) {
    this->objectVectors = objectVectors;
    Entity();
}

// Methods Implementations
// =============================================================================



// Getters and Setters Implementations
// =============================================================================

bool Entity::getIsActive() {
    return this->isActive;
}

void Entity::setIsActive(bool isActive) {
    this->isActive = isActive;
}

struct Entity::Color Entity::getColor() {
    return this->color;
}
void Entity::setColor(struct Color color) {
    this->color = color;
}
void Entity::setColor(float red,float green,float blue,float alpha) {
    this->color.red = red;
    this->color.green = green;
    this->color.blue = blue;
    this->color.alpha = alpha;
}

struct Entity::Position Entity::getPosition() {
    return this->position;
}
void Entity::setPosition(float x, float y, float z) {
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;
}
void Entity::setPosition(struct Position position) {
    this->position.x = position.x;
    this->position.y = position.y;
    this->position.z = position.z;
}

std::vector<GLfloat> Entity::getVectorPointers() {
    return this->objectVectors;
}
void Entity::setVectorPointers(std::vector<GLfloat> newList) {
    this->objectVectors = newList;
}

char Entity::getObjectType() {
    return this->objectType;
}

void Entity::setObjectType(char objectType) {
    this->objectType = objectType;
}
