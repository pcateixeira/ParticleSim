#ifndef SCENE_H
#define SCENE_H

#include <list>
#include <gl/gl.h>
#include <GL/glut.h>
#include "particle.h"

class Scene
{
public:
    Scene();

    // Metodos usados pela GLUT devem ser configurados como estaticos
    static void drawScene();
    static void changeWindowSize(GLsizei w, GLsizei h);
    static void initialize();

    bool renderScene();

private:
};

#endif // SCENE_H
