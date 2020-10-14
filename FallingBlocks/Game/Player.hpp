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
    
    
    
public:
    
    // Constructors/Destructors Declarations
    // =========================================================================
    
    Player();

    
    
    // Methods Declarations
    // =========================================================================
    
    void decideDirection();
    bool isCollidedWith();
    bool isCollidedWith(Entity target);
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    void setDirection(uchar direction);
    uchar getDirection();
};

#endif /* Player_hpp */
