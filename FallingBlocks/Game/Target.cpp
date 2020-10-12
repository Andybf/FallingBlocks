//
//  Target.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 28/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Target.hpp"

// Constructors Definitions
// =============================================================================

Target::Target() {
    this->Entity::setPosition(0,0,0);
}



// Methods Definitions
// =============================================================================

void Target::decidePositionWith(Player player) {
    
    setPosition();
    //Verify if the new position is not occupied by the player
    for (uchar i=199-player.getTailSize(); i<199; i++) {
        if (this->getPosition().x == player.getAllBodyPosition()[i].x &&
            this->getPosition().y == player.getAllBodyPosition()[i].y
        ) {
            this->setIsActive(false);
            setPosition();
            i = 199-player.getTailSize();
        }
    }
    this->setIsActive(true);
}



// Getters and Setters Definitions
// =============================================================================

void Target::setPosition() {
    if (! this->getIsActive() ) {
        this->Entity::setPosition(
            rand() % SP_SCENERY_ROWS,
            rand() % SP_SCENERY_COLS,
            0
        );
    }
}
