#include "scene.h"

Scene::Scene() :
    camera(Point3D(60,25,100)),
    eye(Point3D(0, 0, 0)),
    upVector(Vector3D(0, 1, 0)),
    windowWidth(800),
    windowHeight(600)
{}

void Scene::initialize()
{
    // Especifica que a cor de fundo da janela seja branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Limpa a janela e habilita o teste para eliminar faces ocultas por outras
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

	// habilita o uso de uma cor por face
    glShadeModel (GL_FLAT);

}

void Scene::orthoViewing()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Especifica posicao do observador e do alvo
	gluLookAt ( camera.getX(), camera.getY(), camera.getZ(),
                eye.getX(), eye.getY(), eye.getZ(),
                upVector.getX(), upVector.getY(), upVector.getZ());

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    // Especifica a projecao ortografica
    glOrtho(-100.0,
            100.0,
            -100.0,
            100.0,
            2.0,240.0);

    glMatrixMode(GL_MODELVIEW);
}

void Scene::changeSize(GLsizei w, GLsizei h)
{
    Scene foo;

	// Para prevenir uma divisão por zero
	if ( h == 0 )
		h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

    foo.orthoViewing();

    glutPostRedisplay();
}

void Scene::renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

	Particle p1( Point3D(20,0,100), 1, 2);
	Point3D position1 = p1.getPosition();

    glPointSize(p1.getSize());
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3i(position1.getX(), position1.getY(), position1.getZ());
    glEnd();



	Particle p2( Point3D(50,0,30), 1, 3);
	Point3D position2 = p2.getPosition();

    glPointSize(p2.getSize());
    glBegin(GL_POINTS);
        glColor3f(0.7f, 0.0f, 0.4f);
        glVertex3i(position2.getX(), position2.getY(), position2.getZ());
    glEnd();



	Particle p3( Point3D(80,70,-25), 1, 8);
	Point3D position3 = p3.getPosition();

    glPointSize(p3.getSize());
    glBegin(GL_POINTS);
        glColor3f(0.2f, 0.3f, 0.9f);
        glVertex3i(position3.getX(), position3.getY(), position3.getZ());
    glEnd();



	Particle p4( Point3D(-20,0,15), 1, 6);
	Point3D position4 = p4.getPosition();

    glPointSize(p4.getSize());
    glBegin(GL_POINTS);
        glColor3f(0.9f, 0.3f, 0.1f);
        glVertex3i(position4.getX(), position4.getY(), position4.getZ());
    glEnd();



	Particle p5( Point3D(40,-30,23), 1, 12);
	Point3D position5 = p5.getPosition();

    glPointSize(p5.getSize());
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.5f, 0.5f);
        glVertex3i(position5.getX(), position5.getY(), position5.getZ());
    glEnd();


	//Garante a execucao dos comandos de desenho
	glFlush();
	glutSwapBuffers();
}

void Scene::drawScene()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth,windowHeight);
	glutCreateWindow("Particle Simulator");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	initialize();
	glutMainLoop();
}

Point3D Scene::getCamera() const {
    return camera;
}
void Scene::setCamera(Point3D value) {
    camera = value;
}

Point3D Scene::getEye() const {
    return eye;
}
void Scene::setEye(Point3D value) {
    eye = value;
}

Vector3D Scene::getUpVector() const {
    return upVector;
}
void Scene::setUpVector(Vector3D value) {
    upVector = value;
}

int Scene::getWindowWidth() const {
    return windowWidth;
}
void Scene::setWindowWidth(int value) {
    windowWidth = value;
}

int Scene::getWindowHeight() const {
    return windowHeight;
}
void Scene::setWindowHeight(int value) {
    windowHeight = value;
}
