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



//Static Functions Implementations
// =============================================================================

void keyboardCallback(uchar key, GLint x, GLint y) {
    eng->manageKeyboardActionsListener(key);
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
    writePointerY = win.getHeight();
    
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
    glutInitWindowPosition(this->Window::getWidth()/2, this->Window::getHeight()/2);
    glutCreateWindow(this->Window::getTitle());
    glClearColor(this->clearColor.red,this->clearColor.green,this->clearColor.blue,this->clearColor.alpha);
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
    eng = this;
}

void Engine::startProgramLoop() {
    glutKeyboardFunc(keyboardCallback);
    glutMouseFunc(NULL);
    glutReshapeFunc(reshapeCallback);
    glutDisplayFunc(displayCallback);
    glutTimerFunc(0,timerCallback,0);
    glutMainLoop();
}

void Engine::reshapeScreen(int width, int height) {
    glViewport(0.0, 0.0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(
            this->worldProjection.west,
            this->worldProjection.east,
            this->worldProjection.south,
            this->worldProjection.north,
            this->worldProjection.behind,
            this->worldProjection.front
    );
    glMatrixMode(GL_MODELVIEW);
    this->Window::setWidth(width);
    this->Window::setHeight(height);
}

void Engine::manageProgramTime() {
    if (this->getIsActive()) {
        this->programActualSysTime = std::chrono::system_clock::to_time_t ( std::chrono::system_clock::now() );
        this->timer.seconds =  difftime(this->programActualSysTime, this->programElapsedSeconds);
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
        glColor3f(ent.getColor().red, ent.getColor().green, ent.getColor().blue);
        glBegin(ent.getObjectType());
        for (int v=0; v<ent.getVectorPointers().size(); v+=3) {
            glVertex3f(
               ent.getVectorPointers()[v]   + ent.getPosition().x,
               ent.getVectorPointers()[v+1] + ent.getPosition().y,
               ent.getVectorPointers()[v+2] + ent.getPosition().z
            );
        }
        glEnd();
    }
}

void Engine::prepareFramebuffer() {
    glClear(GL_COLOR_BUFFER_BIT);
    loadGameContentsLoop();
    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


 
// Getters and Setters Implementations
// =============================================================================

struct Engine::WorldProjection Engine::getWorldProjection() {
    return this->worldProjection;
}

void Engine::setWorldProjection(float west, float east, float south,
                                float north, float behind, float front) {
    this->worldProjection.west = west;
    this->worldProjection.east = east;
    this->worldProjection.south = south;
    this->worldProjection.north = north;
    this->worldProjection.behind = behind;
    this->worldProjection.front = front;
}

bool Engine::getIsActive() {
    return this->isActive;
}
void Engine::setIsActive(bool isActive) {
    this->isActive = isActive;
}

ushort Engine::getFps() {
    return this->framesPerSecond;
}
void Engine::setFps(ushort fps) {
    this->framesPerSecond = fps;
}

void Engine::setClearColor(float red,float green,float blue,float alpha) {
    this->clearColor.red = red;
    this->clearColor.green = green;
    this->clearColor.blue = blue;
    this->clearColor.alpha = alpha;
}

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
        this->programElapsedSeconds = std::chrono::system_clock::to_time_t ( std::chrono::system_clock::now() );
    }
    this->timer.seconds = sec;
}
void Engine::setTimerMinutes(float min){
    this->timer.minutes = min;
}
void Engine::setTimerHours(float hour){
    this->timer.hours = hour;
}


