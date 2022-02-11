//
//  Window.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

// OpenGL Includes
// =============================================================================

#ifdef _WIN32
    #define GLUT_DISABLE_ATEXIT_HACK
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif
#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif
#ifdef __APPLE__
    // OpenGL is deprecated in macOS Mojave and above
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#endif



// C Includes
// =============================================================================

#include <stdio.h>
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
#include <chrono>
#include<thread> 



// Type Declarations
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
    
    void setAspectRatio(float aspectRatio);
    float getAspectRatio();
    
};

// Engine Includes
#include "Entity.hpp"

#endif /* Window_hpp */
