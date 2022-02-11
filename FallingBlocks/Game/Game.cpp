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
std::vector<Target> targets;
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
    
    game = *this;
    
    std::vector<GLfloat> vector {
        +0.1f, +0.1f, 0,
        +0.1f, +0.9f, 0,
        +0.9f, +0.9f, 0,
        +0.9f, +0.1f, 0,
    };
    player = Player();
    player.Player::setPosition(10, 0, -0.1);
    player.setIsActive(true);
    player.setVectorPointers(vector);
    player.setColor(0.44,0.85,0.21,0);
    
    for (char x=0; x<5; x++) {
        targets.push_back(Target());
        targets[x].setIsActive(true);
        targets[x].setSpeed(Engine::randomNumberBetween(0.25f, 1));
        targets[x].Target::generateNewPosition();
        targets[x].setVectorPointers(vector);
        targets[x].setColor(0.76, 0.33, 0.81, 0.0);
    }
    
    scenery = Entity();
    scenery.setColor(0.2, 0.2, 0.2, 0);
    scenery.setIsActive(true);
    scenery.setObjectType(GL_LINE_STRIP);
    scenery.setVectorPointers( std::vector<GLfloat> {
        +0.0f, +0.0f, 0,
        +0.0f, +1.0f, 0,
        +1.0f, +1.0f, 0,
        +1.0f, +0.0f, 0,
        +0.0f, +0.0f, 0,
    });
    
    Window * win = new Window(480, 480, (char*)"FallingBlocks");
    
    Camera camera = Camera();
    camera.setOrthoProjection(0, SP_SCENERY_COLS, 0, SP_SCENERY_ROWS, -20, 20);
    camera.setPerspecProjection(90, win->getAspectRatio(), 1, 20.0);
    camera.setActiveProjectionMode(0x1);
    camera.setEyePosition(10, 6, 12);
    camera.setReferencePoint(10, 25, -50);
    
    wt = Writter(camera);
    
    engine = Engine(*win);
    engine.setCamera(camera);
    engine.setMaxFps(30);
    engine.setClearColor(0.08, 0.08, 0.08, 0);
    engine.initializeEngine(argc, argv);
    engine.startRenderingLoop();
}

void Game::restart() {
    this->points = 0;
    player.setDirection(0xff);
    player.setPosition(10, 0, 0);
    
    engine.setTimerMinutes(0);
    engine.setTimerSeconds(0);
    engine.setIsActive(true);
    
}

void Game::GameOver() {
    wt.setFontFamilySize(GLUT_BITMAP_HELVETICA_18);
    
    wt.setPosition(8, 10, -0.1);
    wt.print((char*)"Game Over");
    
    wt.setPosition(8, 9, -0.1);
    wt.print((char*)"Press r to restart");
    
    wt.setPosition(8, 8, -0.1);
    wt.print((char*)"q to quit");
    
    wt.setFontFamilySize(GLUT_BITMAP_HELVETICA_12);
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
        
        wt.setPosition(0.25, 19.5, -0.1);
        wt.print(engine.glRenderer);
        
        wt.setPosition(0.25, 19, -0.1);
        wt.print(engine.glVendor);
        
        wt.setPosition(0.25, 18.5, -0.1);
        wt.print(engine.glVersion);
        
        wt.setPosition(0.25, 17.5, -0.1);
        game.elapsedTimeMessage = (char*)calloc(10,sizeof(char*));
        sprintf(game.elapsedTimeMessage, "Time: %02.0f:%02.0f",this->getTimerMinutes(),this->getTimerSeconds());
        wt.print(game.elapsedTimeMessage);
        free(game.elapsedTimeMessage);
        
        wt.setPosition(0.25, 17, -0.1);
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
        
        for (char x=0; x<targets.size(); x++) {
            if (player.isCollidedWith(targets[x])) {
               game.GameOver();
            }
            targets[x].fall();
            if (targets[x].getPosition().y < 0) {
                targets[x].generateNewPosition();
                targets[x].setSpeed(Engine::randomNumberBetween(0.25f, 1));
                game.setPoints(game.getPoints()+1);
            }
        }
    } else {
        game.GameOver();
    }
    
    for (char x=0; x<targets.size(); x++) {
        Engine::drawOnScreen(targets[x]);
    }
    Engine::drawOnScreen(player);
    
    for (float x=0; x<SP_SCENERY_COLS; x++) {
        for (float y=0; y<SP_SCENERY_ROWS; y++) {
            scenery.setPosition(x, y, -0.2);
            Engine::drawOnScreen(scenery);
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
   
