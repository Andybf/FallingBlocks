//
//  PrintWritter.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 02/10/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef PrintWritter_hpp
#define PrintWritter_hpp

// Includes
// =============================================================================

#include "Window.hpp"
#include "../MicroRender/Camera.hpp"

class Writter {
  
private:
    
    // Attributes Declarations
    // =========================================================================
    
    Camera camera;
    
    char * message;
    void * font;
    
    struct Color {
        float red;
        float green;
        float blue;
    } color;
    
    struct Position {
        GLfloat x;
        GLfloat y;
        GLfloat z;
    } position;
    
public:
    
    // Constructors Declarations
    // =========================================================================
    
    Writter();
    Writter(Camera camera);
        
    
    
    // Methods Declarations
    // =========================================================================
    
    void print();
    void print(char * message);
    
    void setCamera(Camera camera);
    
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    char * getMessage();
    void setMessage(char * message);
    
    void setFontFamilySize(void * fontFamily);
    
    struct Color getColor();
    void setColor(float red, float green, float blue);
    
    struct Position getPosition();
    void setPosition(float x, float y, float z);
    
};

#endif /* PrintWritter_hpp */
