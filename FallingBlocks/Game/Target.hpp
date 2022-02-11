//
//  Target.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 28/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Target_hpp
#define Target_hpp

#include "../MicroRender/Entity.hpp"

class Target : public Entity {
    
private:
    
    // Attributes Declarations
    // =========================================================================
    
    float speed;
    
public:
    
    // Constructors Declarations
    // =========================================================================
    Target();
    
    
    // Methods Declarations
    // =========================================================================
    void fall();
    void generateNewPosition();
    
    
    // Getters and Setters Declarations
    // =========================================================================
    void setSpeed(float speed);
    float getSpeed();
    
    
};

#endif /* Target_hpp */
