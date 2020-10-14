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
    
    // Attributes Declarations
    // =========================================================================
    
    bool    isActive;
    ushort  maximumFramesPerSecond;
    uchar   keyPressed;
    uchar   keyReleased;
    char *  glVendor;
    char *  glRenderer;
    
    struct Color {
        float red;
        float green;
        float blue;
        float alpha;
    } clearColor;
    
    uchar activeProjectionMode;
    
    struct OrthographicProjection {
        float west;
        float east;
        float south;
        float north;
        float behind;
        float front;
    } orthoProjection;
    
    struct PerspectiveProjection {
        GLdouble fovy;
        GLdouble aspect;
        GLdouble zNear;
        GLdouble zFar;
    } perspecProjection;
    
    long programElapsedSeconds;
    long programActualSysTime;
    
    struct ProgramTime {
        float hours;
        float minutes;
        float seconds;
    } timer;

public:
    
    // Constructors Declarations
    // =========================================================================
    
    Engine();
    Engine(Window win);
    
    
    
    // Methods Declarations
    // =========================================================================
    
    void initializeEngine(int argc, char **argv);
    void defineCallbackFunctions();
    void drawOnScreen(Entity ent);
    virtual void loadGameContentsLoop();
    void reshapeScreen(int w, int h);
    void manageProgramTime();
    void manageKeyboardResponse();
    void prepareFramebuffer();
    virtual void manageKeyboardActionsListener(uchar keyPressed);
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    bool getIsActive();
    void setIsActive(bool isActive);
    
    void setClearColor(float red,float green,float blue,float alpha);
    
    // ============================================================ PROJECTIONS
    void setActiveProjectionMode(uchar activeProjectionMode);
    uchar getActiveProjectionMode();
    
    struct OrthographicProjection getOrthoProjection();
    void setOrthoProjection(float west, float east, float south,
                            float north, float behind, float front
                            );
    
    struct PerspectiveProjection getPerspecProjection();
    void setPerspecProjection(GLdouble fovy,
                              GLdouble aspect,
                              GLdouble zNear,
                              GLdouble zFar
                              );
    
    // ============================================================== FRAMERATE
    ushort getFps();
    void setFps(ushort fps);
    
    // ============================================================== KEYBOARDS
    void setKeyPressed(uchar key);\
    uchar getKeyPressed();
    
    void setKeyReleased(uchar key);
    uchar getKeyReleased();
    
    // ================================================================= TIMERS
    float getTimerSeconds();
    float getTimerMinutes();
    float getTimerHours();
    void setTimerSeconds(float sec);
    void setTimerMinutes(float min);
    void setTimerHours(float hour);
};

#endif /* Engine_hpp */
