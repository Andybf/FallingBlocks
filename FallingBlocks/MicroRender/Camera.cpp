//
//  Camera.cpp
//  FallingBlocks
//
//  Created by Anderson Bucchianico on 16/10/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Camera.hpp"

// Attributes Implementations
// =============================================================================



// Constructors/Destructors Implementations
// =============================================================================

Camera::Camera() {
    this->activeProjectionMode = 0x0;
    this->setEyePosition(0.0, 0.0, 1.0);
    this->setReferencePoint(0.0, 0.0, 0.0);
    this->setUpDirection(0.0, 1.0, 0.0);
}


// Methods Implementations
// =============================================================================

void Camera::updatePosition() {
    gluLookAt(
        this->eye.x,            this->eye.y,            this->eye.z,
        this->referencePoint.x, this->referencePoint.y, this->referencePoint.z,
        this->upDirection.x,    this->upDirection.y,    this->upDirection.z
    );
}

void Camera::useOrthographicProjection() {
    glOrtho(
        this->orthoProjection.west,
        this->orthoProjection.east,
        this->orthoProjection.south,
        this->orthoProjection.north,
        this->orthoProjection.behind,
        this->orthoProjection.front
    );
}

void Camera::usePerspectiveProjection() {
    gluPerspective(
        this->perspecProjection.fovy,
        this->perspecProjection.aspect,
        this->perspecProjection.zNear,
        this->perspecProjection.zFar
    );
}

// Getters and Setters Implementations
// =============================================================================

// =========================================================== CAMERA POSITIONS

struct Camera::Eye Camera::getEye() {
    return this->eye;
}
void Camera::setEyePosition(GLdouble x, GLdouble y, GLdouble z) {
    this->eye.x = x;
    this->eye.y = y;
    this->eye.z = z;
}

struct Camera::ReferencePoint Camera::getReferencePoint() {
    return this->referencePoint;
}
void Camera::setReferencePoint(GLdouble x, GLdouble y, GLdouble z) {
    this->referencePoint.x = x;
    this->referencePoint.y = y;
    this->referencePoint.z = z;
}

struct Camera::UpDirection Camera::getUpDirection() {
    return this->upDirection;
}
void Camera::setUpDirection(GLdouble x, GLdouble y, GLdouble z) {
    this->upDirection.x = x;
    this->upDirection.y = y;
    this->upDirection.z = z;
}

// ================================================================ PROJECTIONS

void Camera::setActiveProjectionMode(uchar activeProjectionMode) {
    this->activeProjectionMode = activeProjectionMode;
}
uchar Camera::getActiveProjectionMode() {
    return this->activeProjectionMode;
}

struct Camera::OrthographicProjection Camera::getOrthoProjection() {
    return this->orthoProjection;
}
void Camera::setOrthoProjection(float west, float east, float south,
                                float north, float behind, float front) {
    this->orthoProjection.west    = west;
    this->orthoProjection.east    = east;
    this->orthoProjection.south   = south;
    this->orthoProjection.north   = north;
    this->orthoProjection.behind  = behind;
    this->orthoProjection.front   = front;
}

struct Camera::PerspectiveProjection Camera::getPerspecProjection() {
    return this->perspecProjection;
}
void Camera::setPerspecProjection(GLdouble fovy, GLdouble aspect,
                                  GLdouble zNear, GLdouble zFar) {
    this->perspecProjection.fovy   = fovy;
    this->perspecProjection.aspect = aspect;
    this->perspecProjection.zNear  = zNear;
    this->perspecProjection.zFar   = zFar;
}
