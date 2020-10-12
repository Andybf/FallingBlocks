//
//  Target.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 28/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Target_hpp
#define Target_hpp

#include "Game.hpp"

class Target : public Entity {
    
private:
    
    // Attributes Declarations
    // =========================================================================
    
    
    
public:
    
    // Constructors Declarations
    // =========================================================================
    Target();
    
    
    // Methods Declarations
    // =========================================================================
    void decidePositionWith(Player player);
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    void setPosition();
    
    
};

#endif /* Target_hpp */