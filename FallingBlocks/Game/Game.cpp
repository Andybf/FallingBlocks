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
Writter wt;



// Constructors Implementations
// =============================================================================

Game::Game() {
    this->points = 0;
    this->isScreenMessageActive = true;
}

Game::Game(int argc, char **argv) {
    this->points = 0;
    this->isScreenMessageActive = true;
    this->Initialize(argc, argv);
}



// Methods Implementations
// =============================================================================

void Game::Initialize(int argc, char **argv) {
    
    std::vector<GLfloat> vector {
        +0.1f, +0.9f, 0,
        +0.9f, +0.9f, 0,
        +0.9f, +0.1f, 0,
        +0.1f, +0.1f, 0
    };
    player = Player();
    player.Player::setPosition(10, 0, 0.1);
    player.setIsActive(true);
    player.setVectorPointers(vector);
    player.setColor(0.44,0.85,0.21,0);
    
    target = Target();
    target.setIsActive(true);
    target.Target::generateNewPosition();
    target.setVectorPointers(vector);
    target.setColor(0.76, 0.33, 0.81, 0.0);
    
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
    
    wt = Writter();
    
    Window * win = new Window(480, 480, (char*)"FallingBlocks");
    engine = Engine(*win);
    engine.setFps(5);
    engine.setClearColor(0.08, 0.08, 0.08, 0);
    engine.initializeEngine(argc, argv);
    engine.setOrthoProjection(0, SP_SCENERY_COLS, 0, SP_SCENERY_ROWS, -20, 20);
    engine.setPerspecProjection(90, engine.getAspectRatio(), 0.0, 100.0);
    engine.setActiveProjectionMode(0x0);
    engine.defineCallbackFunctions();
    game = *this;
}

void Game::restart() {
    this->points = 0;
    player.setDirection(0xff);
    player.setPosition(10, 0, 0);
    
    engine.setTimerMinutes(0);
    engine.setTimerSeconds(0);
    engine.setIsActive(true);
    
    target.setIsActive(true);
}

void Game::GameOver() {
    Writter wt = Writter();
    wt.setColor(1, 1, 1);
    wt.setFontFamilySize(GLUT_BITMAP_HELVETICA_18);
    
    wt.setPosition(engine.getWidth()/2-50, engine.getHeight()/2, -0.1f);
    wt.print((char*)"Game Over");
    
    wt.setPosition(engine.getWidth()/2-75, engine.getHeight()/2-20, -0.1f);
    wt.print((char*)"Press r to restart");
    
    wt.setPosition(engine.getWidth()/2-40, engine.getHeight()/2-40, -0.1f);
    wt.print((char*)"q to quit");
    
    engine.setIsActive(false);
}

void Engine::manageKeyboardActionsListener(uchar keyPressed) {
    switch (keyPressed) {
        case 9: // Tab key
            game.setIsScreenMessageActive(! game.getIsScreenMessagesActive() );
            break;
        case 97: //  a
            player.setDirection(0x3);
            break;
        case 100: // d
            player.setDirection(0x1);
            break;
        case 113: // q
            exit(0);
        case 114: // r
            game.restart();
            break;
        case 115: // s
            break;
        case 119: // w
            break;
        default:
            player.setDirection(0xFF);
    }
}

void Engine::loadGameContentsLoop() {
    
    // Messages on screen loop
    if (game.getIsScreenMessagesActive()) {
        
        wt.setPosition(0.25, 19.5, 1);
        wt.print(engine.glRenderer);
        
        wt.setPosition(0.25, 19, 1);
        wt.print(engine.glVendor);
        
        wt.setPosition(0.25, 18.5, 1);
        game.elapsedTimeMessage = (char*)calloc(10,sizeof(char*));
        sprintf(game.elapsedTimeMessage, "Time: %02.0f:%02.0f",this->getTimerMinutes(),this->getTimerSeconds());
        wt.print(game.elapsedTimeMessage);
        free(game.elapsedTimeMessage);
        
        wt.setPosition(0.25, 18, 1);
        char * pointsMsg = (char*)calloc(20,sizeof(char*));
        sprintf(pointsMsg, "Points: %i",game.getPoints());
        wt.print(pointsMsg);
        free(pointsMsg);
    }
    
    // Game script loop
    if (player.getIsActive()) {
        player.decideDirection();
        if (player.isCollidedWith() ) {
            // TODO
        }
        if (player.isCollidedWith(target)) {
            game.setPoints(game.getPoints()+1);
        }
        Engine::drawOnScreen(player);
    } else {
        game.GameOver();
    }
    
    target.fall();
    Engine::drawOnScreen(target);
    if (target.getPosition().y < 0) {
        target.generateNewPosition();
    }
    
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
   
