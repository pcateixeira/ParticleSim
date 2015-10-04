#ifndef SCENE_H
#define SCENE_H

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include "particle.h"

class Scene
{
public:
    Scene();

    void initialize();
    void orthoViewing();

    // Metodos usados pela GLUT devem ser descritos como estaticos
    static void changeSize(GLsizei w, GLsizei h);
    static void renderScene();

    void drawScene();

    Point3D getCamera() const;
    void setCamera(Point3D value);

    Point3D getEye() const;
    void setEye(Point3D value);

    Vector3D getUpVector() const;
    void setUpVector(Vector3D value);

    int getWindowWidth() const;
    void setWindowWidth(int value);

    int getWindowHeight() const;
    void setWindowHeight(int value);


private:
    Point3D camera;
    Point3D eye;
    Vector3D upVector;
    int windowWidth;
    int windowHeight;
};

#endif // SCENE_H
