//
//  Target.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 28/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Target.hpp"

// Constructors Definitions
// =============================================================================

Target::Target() {
    this->Entity::setPosition(10,20, -0.1);
}



// Methods Definitions
// =============================================================================

void Target::fall() {
    this->Entity::setPosition(
        this->getPosition().x,
        this->getPosition().y - this->speed,
        -0.1
    );
}

void Target::generateNewPosition() {
    this->Entity::setPosition( rand() % 20, 20, -0.1);
}



// Getters and Setters Definitions
// =============================================================================

void Target::setSpeed(float speed) {
    this->speed = speed;
}

float Target::getSpeed() {
    return this->speed;
}
