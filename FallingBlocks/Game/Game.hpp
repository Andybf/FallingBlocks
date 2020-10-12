//
//  Game.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 24/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "../MicroRender/Engine.hpp"
#include "../MicroRender/Writter.hpp"
#include "Player.hpp"
#include "Target.hpp"

#define SP_SCENERY_ROWS 20
#define SP_SCENERY_COLS 20

class Game {
    
private:
    
    // Attributes Declarations
    // =========================================================================
    int points;
    bool isScreenMessageActive;
    
    
public:
    
    // Constructors Declarations
    // =========================================================================
    Game();
    Game(int argc, char **argv);
    
    
    
    // Methods Declarations
    // =========================================================================
    void Initialize(int argc, char **argv);
    void GameOver();
    void restart();
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    int getPoints();
    void setPoints(int points);
    
    bool getIsScreenMessagesActive();
    void setIsScreenMessageActive(bool isScreenMessageActive);
};

#endif /* Game_hpp */
