//
//  Entity.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Window.hpp"

class Entity {
    
private:
    
    // Attributes
    // =========================================================================
    
    bool isActive;
    std::vector<GLfloat> objectVectors;
    char objectType;
    
    struct Color {
        float red;
        float green;
        float blue;
        float alpha;
    } color;
    
    struct Position {
        float x;
        float y;
        float z;
    } position;
    
    
    
public:
    
    // Constructors
    // =========================================================================
    
    Entity ();
    Entity (std::vector<GLfloat> objectVectors);
    
    
    
    // Methods
    // =========================================================================
    
    
    
    // Getters and Setters
    // =========================================================================
    
    bool getIsActive();
    void setIsActive(bool isActive);
    
    struct Color getColor();
    void setColor(struct Color color);
    void setColor(float red, float green, float blue, float alpha);
    
    struct Position getPosition();
    void setPosition(float x, float y, float z);
    void setPosition(struct Position position);
    
    std::vector<GLfloat> getVectorPointers();
    void setVectorPointers(std::vector<GLfloat>);
    
    char getObjectType();
    void setObjectType(char objectType);

};

#endif /* Entity_hpp */
