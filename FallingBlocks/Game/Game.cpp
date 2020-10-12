//
//  Game.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 24/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Game.hpp"

Engine engine;
Game game;
Entity scenery;
Player player;
Target target;



// Constructors Implementations
// =============================================================================

Game::Game() {
    this->points = 0;
    this->isScreenMessageActive = true;
}

Game::Game(int argc, char **argv) {
    Game();
    this->Initialize(argc, argv);
}



// Methods Implementations
// =============================================================================

void Game::Initialize(int argc, char **argv) {
    
    Window * win = new Window(480, 480, (char*)"MicroRender");
    engine = Engine(*win);
    
    std::vector<GLfloat> vector {
        +0.1f, +0.9f, 0,
        +0.9f, +0.9f, 0,
        +0.9f, +0.1f, 0,
        +0.1f, +0.1f, 0
    };
    player = Player();
    player.setHeadPosition(10, 10, 0);
    player.setIsActive(true);
    player.setVectorPointers(vector);
    player.setColor(0.3, 0.3, 0.9, 0.0);
    
    target = Target();
    target.setPosition();
    target.setVectorPointers(vector);
    target.setColor(0.9,0.3,0.3,0);
    
    scenery = Entity();
    scenery.setColor(0.1, 0.1, 0.1, 0);
    scenery.setIsActive(true);
    scenery.setObjectType(GL_LINE_STRIP);
    scenery.setVectorPointers( std::vector<GLfloat> {
        +0.0f, +1.0f, 0,
        +1.0f, +1.0f, 0,
        +1.0f, +0.0f, 0,
        +0.0f, +0.0f, 0
    });
    
    engine.setFps(5);
    engine.setClearColor(0.08, 0.08, 0.08, 0);
    engine.initializeEngine(argc, argv);
    engine.setWorldProjection(0, SP_SCENERY_COLS, 0, SP_SCENERY_ROWS, -20, 20);
    engine.startProgramLoop();
    game = *this;
}

void Game::restart() {
    this->points = 0;
    player.setDirection(0xff);
    player.setTailSize(0);
    player.setAllBodyPosition(0, 0, 0);
    player.setHeadPosition(10, 10, 0);
    
    engine.setTimerMinutes(0);
    engine.setTimerSeconds(0);
    engine.setIsActive(true);
    
    target.setIsActive(false);
}

void Game::GameOver() {
    Writter wt = Writter();
    wt.setColor(1, 1, 1);
    wt.setFontFamilySize(GLUT_BITMAP_HELVETICA_18);
    
    wt.setPosition(engine.getWidth()/2-50, engine.getHeight()/2, -0.1);
    wt.print((char*)"Game Over");
    
    wt.setPosition(engine.getWidth()/2-75, engine.getHeight()/2-20, -0.1);
    wt.print((char*)"Press r to restart");
    
    wt.setPosition(engine.getWidth()/2-40, engine.getHeight()/2-40, -0.1);
    wt.print((char*)"q to quit");
    
    engine.setIsActive(false);
}

void Engine::manageKeyboardActionsListener(uchar keyPressed) {
    switch (keyPressed) {
        case 9: // Tab key
            game.setIsScreenMessageActive(! game.getIsScreenMessagesActive() );
            break;
        case 97: //  a
            player.setDirection( player.getDirection() != 0x1 ? 0x3 : player.getDirection() );
            break;
        case 100: // d
            player.setDirection( player.getDirection() != 0x3 ? 0x1 : player.getDirection() );
            break;
        case 113: // q
            exit(0);
        case 114: // r
            game.restart();
            break;
        case 115: // s
            player.setDirection( player.getDirection() != 0x0 ? 0x2 : player.getDirection() );
            break;
        case 119: // w
            player.setDirection( player.getDirection() != 0x2 ? 0x0 : player.getDirection() );
            break;
    }
}

void Engine::loadGameContentsLoop() {
    
    // Messages on screen loop
    if (game.getIsScreenMessagesActive()) {
        Writter wt = Writter();
        wt.setFontFamilySize(GLUT_BITMAP_HELVETICA_12);
        wt.setColor(1, 1, 1);
        wt.setPosition(5, this->getHeight()-15, -0.1);
        
        char * timePassedChar = (char*)calloc(10,sizeof(char*));
        sprintf(timePassedChar, "Time: %02.0f:%02.0f",this->getTimerMinutes(),this->getTimerSeconds());
        wt.print(timePassedChar);
        free(timePassedChar);
        
        char * pointsMsg = (char*)calloc(20,sizeof(char*));
        sprintf(pointsMsg, "Points: %i",game.getPoints());
        wt.setPosition(5, this->getHeight()-30, -0.1);
        wt.print(pointsMsg);
        free(pointsMsg);
        
        writePointerY = this->getHeight();
    }
    
    // Game script loop
    if (player.getIsActive()) {
        player.moveBody();
        player.decideDirection();
        if (player.isCollidedWith() || player.isCollidedWith(player) ) {
            game.GameOver();
        }
        if (player.isCollidedWith(target)) {
            game.setPoints(game.getPoints()+1);
            target.setIsActive(false);
            player.growTail();
        }
        // Game draw loop
        for (uchar i=199; i>=199-game.getPoints(); i--) {
            player.Entity::setPosition(
                player.Player::getAllBodyPosition()[i].x,
                player.Player::getAllBodyPosition()[i].y,
                player.Player::getAllBodyPosition()[i].z
            );
            Engine::drawOnScreen(player);
        }
    } else {
        game.GameOver();
    }
    
    target.decidePositionWith(player);
    Engine::drawOnScreen(target);
    
    for (char x=0; x<SP_SCENERY_COLS; x++) {
        for (char y=0; y<SP_SCENERY_ROWS; y++) {
            Engine::drawOnScreen(scenery);
            scenery.setPosition(x, y, 0);
        }
    }
}



// Getters and Setters Implementations
// =============================================================================

int Game::getPoints() {
    return points;
}
void Game::setPoints(int points){
    this->points = points;
}

bool Game::getIsScreenMessagesActive() {
    return this->isScreenMessageActive;
}

void Game::setIsScreenMessageActive(bool isScreenMessageActive) {
    this->isScreenMessageActive = isScreenMessageActive;
}
   
