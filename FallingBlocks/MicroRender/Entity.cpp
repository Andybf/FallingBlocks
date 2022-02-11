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



// Constructors/Destructors Implementations
// =============================================================================

Entity::Entity () {
    this->color.red = 0;
    this->color.green = 0;
    this->color.blue = 0;
    
    this->position.x = 0;
    this->position.y = 0;
    this->position.z = 0;
    
    this->rotation.angle = 0;
    this->rotation.x = 0;
    this->rotation.y = 0;
    this->rotation.z = 0;
    
    this->objectType = GL_POLYGON;
}

Entity::Entity (std::vector<GLfloat> objectVectors) {
    this->objectVectors = objectVectors;
    Entity();
}

Entity::~Entity () {
    //printf("The Entity qbject was destroyed.\n");
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

// ===================================================================== COLORS

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

// ================================================================== POSITIONS

struct Entity::Position Entity::getPosition() {
    return this->position;
}

void Entity::setPosition(float x, float y, float z) {
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;
}
void Entity::setPositionX(float x){
    this->position.x = x;
}
void Entity::setPositionY(float y) {
    this->position.y = y;
}
void Entity::setPositionZ(float z){
    this->position.z = z;
}

// ================================================================== ROTATIONS

struct Entity::Rotation Entity::getRotation() {
    return this->rotation;
}

void Entity::setRotation(float angle, float x, float y, float z) {
    this->rotation.angle = angle;
    this->rotation.x = x;
    this->rotation.y = y;
    this->rotation.z = z;
}
void Entity::setRotationX(float x){
    this->rotation.x = x;
}
void Entity::setRotationY(float y) {
    this->rotation.y = y;
}
void Entity::setRotationZ(float z){
    this->rotation.z = z;
}
