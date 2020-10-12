//
//  Engine.hpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include "Window.hpp"

#define MR_ONE_SECOND_IN_MS 1000

class Engine final : public Window {
    
private:
    
    // Attributes
    // =========================================================================
    
    bool    isActive;
    void ** selectedFont;
    ushort  framesPerSecond;
    short   writePointerY;
    
    struct Color {
        float red;
        float green;
        float blue;
        float alpha;
    } clearColor;
    
    struct WorldProjection {
        float west;
        float east;
        float south;
        float north;
        float behind;
        float front;
    } worldProjection;
    
    long programElapsedSeconds;
    long programActualSysTime;
    
    struct ProgramTime {
        float hours;
        float minutes;
        float seconds;
    } timer;

public:
    
    // Constructors
    // =========================================================================
    
    Engine();
    Engine(Window win);
    
    
    
    // Methods
    // =========================================================================
    
    void initializeEngine(int argc, char **argv);
    void startProgramLoop();
    void drawOnScreen(Entity ent);
    virtual void loadGameContentsLoop();
    void reshapeScreen(int w, int h);
    void manageProgramTime();
    void prepareFramebuffer();
    virtual void manageKeyboardActionsListener(uchar keyPressed);
    
    
    
    // Getters and Setters
    // =========================================================================
    
    bool getIsActive();
    void setIsActive(bool isActive);
    
    ushort getFps();
    void setFps(ushort fps);
    
    struct WorldProjection getWorldProjection();
    void setWorldProjection(float west, float east, float south, float north, float behind, float front);
    
    void setClearColor(float red,float green,float blue,float alpha);
    
    float getTimerSeconds();
    float getTimerMinutes();
    float getTimerHours();
    void setTimerSeconds(float sec);
    void setTimerMinutes(float min);
    void setTimerHours(float hour);
};

#endif /* Engine_hpp */
