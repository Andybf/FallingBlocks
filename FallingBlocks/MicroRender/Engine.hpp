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
#include "Camera.hpp"

#define MR_ONE_SECOND_IN_MS 1000

class Engine final : public Window {
    
private:
    
    // Attributes Declarations
    // =========================================================================
    
    Camera camera;
    
    bool    isActive;
    ushort  maximumFramesPerSecond;
    uchar   keyPressed;
    uchar   keyReleased;
    
    char *  glVendor;
    char *  glRenderer;
    char *  glVersion;
    
    struct Color {
        float red;
        float green;
        float blue;
        float alpha;
    } clearColor;
    
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
    void startRenderingLoop();
    void drawOnScreen(Entity ent);
    void reshapeScreen(int w, int h);
    void manageProgramTime();
    void manageKeyboardResponse();
    void prepareFramebuffer();
    
    virtual void loadGameContentsLoop();
    virtual void manageKeyboardActionsListener(uchar keyPressed);
    
    static float randomNumberBetween(float min, float max);
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    bool getIsActive();
    void setIsActive(bool isActive);
    
    void setCamera(Camera camera);
    
    void setClearColor(float red,float green,float blue,float alpha);
    
    // ============================================================== FRAMERATE
    ushort getFps();
    void setMaxFps(ushort fps);
    
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
