//
//  Player.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Player.hpp"

// Constructors Implementations
// =============================================================================

Player::Player() {
    this->direction = -1;
}



// Methods Implementations
// =============================================================================

void Player::decideDirection() {
     switch (this->direction) {
        case 0:
            this->setPositionY(this->getPosition().y + 1.0);
            break;
        case 1:
            this->setPositionX(this->getPosition().x + 1.0);
            break;
        case 2:
            this->setPositionY(this->getPosition().y - 1.0);
            break;
        case 3:
            this->setPositionX(this->getPosition().x - 1.0);
            break;
    }
}

bool Player::isCollidedWith() { //Player Colision on the walls
    return
        this->getPosition().x >= 20 || this->getPosition().x < 0 ||
        this->getPosition().y >= 20 || this->getPosition().y < 0;
}

bool Player::isCollidedWith(Entity target) {
    return
        this->getPosition().x == target.getPosition().x &&
        this->getPosition().y == target.getPosition().y;
}



// Getters and Setters Implementations
// =============================================================================

uchar Player::getDirection() {
    return this->direction;
}
void Player::setDirection(uchar direction) {
    this->direction = direction;
}
