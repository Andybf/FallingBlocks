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
    
    // Attributes Declarations
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
    
    struct Rotation {
        float angle;
        float x;
        float y;
        float z;
    } rotation;
    
public:
    
    // Constructors/Destructors Declarations
    // =========================================================================
    
    Entity ();
    Entity (std::vector<GLfloat> objectVectors);
    ~Entity ();
    
    
    
    // Methods Declarations
    // =========================================================================
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    bool getIsActive();
    void setIsActive(bool isActive);
    
    std::vector<GLfloat> getVectorPointers();
    void setVectorPointers(std::vector<GLfloat>);
    
    char getObjectType();
    void setObjectType(char objectType);
    
    // ================================================================= COLORS
    struct Color getColor();
    void setColor(struct Color color);
    void setColor(float red, float green, float blue, float alpha);
    
    // ============================================================== POSITIONS
    struct Position getPosition();
    void setPosition(float x, float y, float z);
    void setPositionX(float x);
    void setPositionY(float y);
    void setPositionZ(float z);
    
    // ============================================================== ROTATIONS
    struct Rotation getRotation();
    void setRotation(float angle, float x, float y, float z);
    void setRotationAngle(float angle);
    void setRotationX(float x);
    void setRotationY(float y);
    void setRotationZ(float z);

};

#endif /* Entity_hpp */
