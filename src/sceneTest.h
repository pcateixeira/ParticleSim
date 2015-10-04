#ifndef SCENETEST_H
#define SCENETEST_H

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

class SceneTest
{
public:
    SceneTest();

    // Metodos usados pela GLUT devem ser configurados como estaticos
    void SetupRC();
    void OrthoViewing();
    static void ChangeSize(GLsizei w, GLsizei h);
    static void RenderScene();
    void drawShit();

private:
};

#endif // SCENETEST_H
