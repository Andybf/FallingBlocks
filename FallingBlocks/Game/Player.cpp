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
    this->tailSize = 0;
    this->direction = -1;
}



// Methods Implementations
// =============================================================================

void Player::moveBody() {
    for (uchar i=199-this->tailSize; i<199; i++) {
        this->position[i].x = this->position[i+1].x;
        this->position[i].y = this->position[i+1].y;
        this->position[i].z = 0;
    }
}

void Player::decideDirection() {
     switch (this->direction) {
        case 0:
            this->position[199].y += 1.0;
            break;
        case 1:
            this->position[199].x += 1.0;
            break;
        case 2:
             this->position[199].y -= 1.0;
            break;
        case 3:
            this->position[199].x -= 1.0;
            break;
    }
}

bool Player::isCollidedWith() { //Player Colision on the walls
    return
        this->position[199].x >= 20 || this->position[199].x < 0 ||
        this->position[199].y >= 20 || this->position[199].y < 0;
}

bool Player::isCollidedWith(Player player) {
    for (int i=199-this->tailSize; i<199; i++) {
        if (this->position[199].x == this->position[i].x &&
            this->position[199].y == this->position[i].y)
        {
            return true;
        }
    }
    return false;
}

bool Player::isCollidedWith(Entity target) {
    return
        this->position[199].x == target.getPosition().x &&
        this->position[199].y == target.getPosition().y;
}

void Player::growTail() {
    this->tailSize++;
    this->position[199-this->tailSize].x = this->position[199-this->tailSize+1].x;
    this->position[199-this->tailSize].y = this->position[199-this->tailSize+1].y;
}



// Getters and Setters Implementations
// =============================================================================

struct Player::Position Player::getHeadPosition() {
    return this->position[199];
}
void Player::setHeadPosition(float x, float y, float z) {
    this->position[199].x = x;
    this->position[199].y = y;
    this->position[199].z = z;
}

struct Player::Position * Player::getAllBodyPosition() {
    struct Player::Position * pos = (struct Position*)
                                    malloc(sizeof(struct Position*)*200);
    pos = this->position;
    return pos;
}

void Player::setAllBodyPosition(float x, float y, float z) {
    for (uchar i=0; i<200; i++) {
        this->position[i].x = x;
        this->position[i].y = y;
        this->position[i].z = z;
    }
}

uchar Player::getDirection() {
    return this->direction;
}
void Player::setDirection(uchar direction) {
    this->direction = direction;
}

uchar Player::getTailSize() {
    return this->tailSize;
}

void Player::setTailSize(uchar tailSize) {
    this->tailSize = tailSize;
}
