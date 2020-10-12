//
//  Window.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

// OpenGL is obsolete in macOS Mojave and above
// =============================================================================

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>



// C Includes
// =============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif



// C++ Includes
// =============================================================================

#include <iostream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>



// Type Definitions
// =============================================================================

typedef unsigned short ushort;
typedef unsigned char uchar;
typedef const char cchar;
typedef unsigned const char ucchar;



class Window {
    
private:
    
    // Attributes Declarations
    // =========================================================================
    
    ushort width;
    ushort height;
    char * title;
    float aspectRatio;
    
    
    
public:
    
    // Constructors Declarations
    // =========================================================================
    
    Window();
    Window(ushort width, ushort height, char * title);
    
    
    
    // Methods Declarations
    // =========================================================================
    
    void close();
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    ushort getWidth();
    void setWidth(ushort w);
    
    ushort getHeight();
    void setHeight(ushort h);
    
    char * getTitle();
    void setTitle(char * t);
};

// Engine Includes
#include "Entity.hpp"

#endif /* Window_hpp */
