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

class Writter {
  
private:
    
    // Attributes
    // =========================================================================
    
    char * message;
    void * font;
    
    struct Color {
        float red;
        float green;
        float blue;
    } color;
    
    struct Position {
        short x;
        short y;
        short z;
    } position;
    
public:
    
    // Constructors
    // =========================================================================
    
    Writter();
    
    
    // Methods
    // =========================================================================
    
    void print();
    void print(char * message);
    
    
    // Getters and Setters
    // =========================================================================
    
    char * getMessage();
    void setMessage(char * message);
    
    void setFontFamilySize(void * fontFamily);
    
    struct Color getColor();
    void setColor(float red, float green, float blue);
    
    struct Position getPosition();
    void setPosition(short x, short y, short z);
    
};

#endif /* PrintWritter_hpp */
