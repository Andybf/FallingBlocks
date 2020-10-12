//
//  Player.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "../MicroRender/Entity.hpp"

class Player final : public Entity {
    
private:
    
    // Attributes Declarations
    // =========================================================================
    
    uchar direction; // clockwise: 0=up, 1=right, 2=down, 3=left
    uchar tailSize;
    struct Position {
        float x;
        float y;
        float z;
    } position[200];
    
    
    
public:
    
    // Constructors Declarations
    // =========================================================================
    
    Player();

    
    
    // Methods Declarations
    // =========================================================================
    
    void moveBody();
    void decideDirection();
    void growTail();
    bool isCollidedWith();
    bool isCollidedWith(Player player);
    bool isCollidedWith(Entity target);
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    struct Position getHeadPosition();
    void setHeadPosition(float x, float y, float z);
    
    struct Position * getAllBodyPosition();
    void setAllBodyPosition(float x, float y, float z);
    
    void setDirection(uchar direction);
    uchar getDirection();
    
    uchar getTailSize();
    void setTailSize(uchar tailSize);
};

#endif /* Player_hpp */
