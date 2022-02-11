//
//  Camera.hpp
//  FallingBlocks
//
//  Created by Anderson Bucchianico on 16/10/20.
//  Copyright © 2020 Anderson Bucchianico. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

// Includes
// =============================================================================

#include "Window.hpp"



class Camera {
  
private:
    
    // Attributes Declarations
    // =========================================================================
    
    struct Eye {
        GLdouble x;
        GLdouble y;
        GLdouble z;
    } eye;
    
    struct ReferencePoint {
        GLdouble x;
        GLdouble y;
        GLdouble z;
    } referencePoint;
    
    struct UpDirection {
        GLdouble x;
        GLdouble y;
        GLdouble z;
    } upDirection;
    
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
    
    
    
public:
    
    // Constructors Declarations
    // =========================================================================
    
    Camera();
    
    
    
    // Methods Declarations
    // =========================================================================
    
    void updatePosition();
    
    void useOrthographicProjection();
    void usePerspectiveProjection();
    
    
    
    // Getters and Setters Declarations
    // =========================================================================
    
    // ======================================================= CAMERA POSITIONS
    
    struct Eye getEye();
    void setEyePosition(GLdouble x, GLdouble y, GLdouble z);
    
    struct ReferencePoint getReferencePoint();
    void setReferencePoint(GLdouble x, GLdouble y, GLdouble z);
    
    struct UpDirection getUpDirection();
    void setUpDirection(GLdouble x, GLdouble y, GLdouble z);
    
    // ============================================================ PROJECTIONS
    
    void setActiveProjectionMode(uchar activeProjectionMode);
    uchar getActiveProjectionMode();
    
    struct OrthographicProjection getOrthoProjection();
    void setOrthoProjection(
        float west, float east, float south,
        float north, float behind, float front
    );
    
    struct PerspectiveProjection getPerspecProjection();
    void setPerspecProjection(
        GLdouble fovy,
        GLdouble aspect,
        GLdouble zNear,
        GLdouble zFar
    );
};

#endif /* Camera_hpp */
