//
//  Engine.cpp
//  MicroRender
//
//  Created by Anderson Bucchianico on 06/09/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#include "Engine.hpp"

// Attributes Implementations
// =============================================================================

Engine * eng;



// Static Callback Functions Implementations
// =============================================================================

void keyPressedCallback(uchar key, GLint x, GLint y) {
    eng->setKeyPressed(key);
}
void keyReleaseCallback(uchar key, int x, int y) {
    eng->setKeyReleased(key);
}
void reshapeCallback (int w, int h) {
    eng->reshapeScreen(w, h);
}
void displayCallback() {
    eng->prepareFramebuffer();
}
void timerCallback(int value) {
    eng->manageProgramTime();
}



// Constructors Implementations
// =============================================================================

Engine::Engine() {
    this->setTimerSeconds(0.0);
    this->setTimerMinutes(0.0);
    this->setTimerHours(0.0);
    
    this->clearColor.red = 0.08;
    this->clearColor.green = 0.08;
    this->clearColor.blue = 0.08;
    this->clearColor.alpha = 0.00;
}

Engine::Engine(Window win) {
    this->setWidth(win.getWidth());
    this->setHeight(win.getHeight());
    this->setTitle(win.getTitle());
    this->setAspectRatio(win.getAspectRatio());
    
    this->setTimerSeconds(0.0);
    this->setTimerMinutes(0.0);
    this->setTimerHours(0.0);
    
    this->clearColor.red = 0.08;
    this->clearColor.green = 0.08;
    this->clearColor.blue = 0.08;
    this->clearColor.alpha = 0.00;
    
    this->isActive = true;
}



// Methods Implementations
// =============================================================================

void Engine::initializeEngine(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(this->Window::getWidth(), this->Window::getHeight());
    glutInitWindowPosition(
        this->Window::getWidth()/2,
        this->Window::getHeight()/2
    );
    glutCreateWindow(this->Window::getTitle());
    glClearColor(
        this->clearColor.red,
        this->clearColor.green,
        this->clearColor.blue,
        this->clearColor.alpha
    );
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glutKeyboardFunc(keyPressedCallback);
    glutKeyboardUpFunc(keyReleaseCallback);
    glutMouseFunc(NULL);
    glutReshapeFunc(reshapeCallback);
    glutDisplayFunc(displayCallback);
    glutTimerFunc(0,timerCallback,0);
    eng = this;
}

void Engine::startRenderingLoop() {
    this->glVendor   = (char*)glGetString(GL_VENDOR);
    this->glRenderer = (char*)glGetString(GL_RENDERER);
    this->glVersion  = (char*)glGetString(GL_VERSION);
    glutMainLoop();
}

void Engine::reshapeScreen(int width, int height) {
    glViewport(0.0, 0.0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (camera.getActiveProjectionMode() == 0x0) {
        camera.useOrthographicProjection();
    } else if (camera.getActiveProjectionMode() == 0x1) {
        camera.usePerspectiveProjection();
    }
    camera.updatePosition();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    this->Window::setWidth(width);
    this->Window::setHeight(height);
}

void Engine::manageProgramTime() {
    this->manageKeyboardResponse();
    if (this->getIsActive()) {
        this->programActualSysTime = std::chrono::system_clock::to_time_t (
            std::chrono::system_clock::now()
        );
        this->timer.seconds =  difftime(
            this->programActualSysTime,
            this->programElapsedSeconds
        );
        if (this->timer.seconds >= 60) {
            this->timer.minutes++;
            this->setTimerSeconds(0);
        }
        this->prepareFramebuffer();
    }
    glutTimerFunc(1000/this->getFps(),timerCallback,0);
}

void Engine::drawOnScreen(Entity ent) {
    if (ent.getIsActive()) {
        glColor3f(
            ent.getColor().red,
            ent.getColor().green,
            ent.getColor().blue
        );
        glPushMatrix();
        glRotatef(ent.getRotation().angle,
            ent.getRotation().x,
            ent.getRotation().y,
            ent.getRotation().z
        );
        glBegin(ent.getObjectType());
        for (int v=0; v<ent.getVectorPointers().size(); v+=3) {
            glVertex3f(
               ent.getVectorPointers()[v]   + ent.getPosition().x,
               ent.getVectorPointers()[v+1] + ent.getPosition().y,
               ent.getVectorPointers()[v+2] + ent.getPosition().z
            );
        }
        glEnd();
        glPopMatrix();
    }
}

void Engine::manageKeyboardResponse() {
    this->manageKeyboardActionsListener(this->getKeyPressed());
    if (this->getKeyPressed() == this->getKeyReleased()) {
        this->setKeyPressed(0xFF);
        this->setKeyReleased(0xFF);
    }
}

void Engine::prepareFramebuffer() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    loadGameContentsLoop();
    glutSwapBuffers();
}


float Engine::randomNumberBetween(float min, float max) {
    float random = 0.0f;
    while (random < 0.25f) {
        random = (float)(rand() % 10) / 10;
    }
    return random;
}
 
// Getters and Setters Implementations
// =============================================================================

void Engine::setCamera(Camera camera) {
    this->camera = camera;
}

void Engine::setClearColor(float red,float green,float blue,float alpha) {
    this->clearColor.red   = red;
    this->clearColor.green = green;
    this->clearColor.blue  = blue;
    this->clearColor.alpha = alpha;
}

bool Engine::getIsActive() {
    return this->isActive;
}
void Engine::setIsActive(bool isActive) {
    this->isActive = isActive;
}

// ================================================================== FRAMERATE

ushort Engine::getFps() {
    return this->maximumFramesPerSecond;
}
void Engine::setMaxFps(ushort fps) {
    this->maximumFramesPerSecond = fps;
}

// ================================================================== KEYBOARDS

void Engine::setKeyPressed(uchar key) {
    this->keyPressed = key;
}
uchar Engine::getKeyPressed() {
    return this->keyPressed;
}

void Engine::setKeyReleased(uchar key) {
    this->keyReleased = key;
}
uchar Engine::getKeyReleased() {
    return this->keyReleased;
}

// ===================================================================== TIMERS

float Engine::getTimerSeconds(){
    return this->timer.seconds;
}
float Engine::getTimerMinutes(){
     return this->timer.minutes;
}
float Engine::getTimerHours(){
     return this->timer.hours;
}
void Engine::setTimerSeconds(float sec){
    if (sec == 0) {
        this->programElapsedSeconds = std::chrono::system_clock::to_time_t (
            std::chrono::system_clock::now()
        );
    }
    this->timer.seconds = sec;
}
void Engine::setTimerMinutes(float min){
    this->timer.minutes = min;
}
void Engine::setTimerHours(float hour){
    this->timer.hours = hour;
}
