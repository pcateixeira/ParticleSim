
#include "sceneTest.h"

SceneTest::SceneTest()
{}

// Inicializacao
void SceneTest::SetupRC()
{

    // Especifica que a cor de fundo da janela sera branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Limpa a janela e habilita o teste para eliminar faces ocultas por outras
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

	// habilita o uso de uma cor por face
    glShadeModel (GL_FLAT);

}

/* Funcao usada para especificar o volume de visualizacao
*  no caso de projecao ortografica
*  Executada quando PERSPECTIVA  = 0 (situacao inicial)
*/
void SceneTest::OrthoViewing()
{
	 // Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa matriz modelview com a identidade
	glLoadIdentity();
	// Especifica posicao do observador e do alvo
	gluLookAt (60.0,25.0,100.0,0.0,0.0,0.0, 0,1,0);

    // Especifica manipulacao da matriz de projecao
	glMatrixMode(GL_PROJECTION);
	// Inicializa matriz com a identidade
	glLoadIdentity();

    // Especifica a projecao ortografica

    glOrtho(-100.0,
            100.0,
            -100.0,
            100.0,
            2.0,240.0);

    glMatrixMode(GL_MODELVIEW);
}
// Chamada pela GLUT quando a janela e redimensionada
void SceneTest::ChangeSize(GLsizei w, GLsizei h)
{
    SceneTest foo;
	// Para prevenir uma divisão por zero
	if ( h == 0 )
		h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

    foo.OrthoViewing();        // no caso de projecao ortografica

    glutPostRedisplay();
}


// Minha funcao de desenho
void SceneTest::RenderScene()
{
	// Limpa a janela
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);


	glBegin(GL_LINES);
       // eixos coordanados x = vermelho, y = verde  z = azul
       glColor3f(1.0f, 0.0f, 0.0f);
       glVertex3i(-100,0,0);
       glVertex3i(100,0,0);

       glColor3f(0.0f, 1.0f, 0.0f);
       glVertex3i(0, -100,0);
       glVertex3i(0, 100,0);

       glColor3f(0.0f, 0.0f, 1.0f);
       glVertex3i(0,0,-100);
       glVertex3i(0,0,100);
    glEnd();

	// Desenha uma piramide de base quadrada (lado 20) com faces coloridas
    // localizada na origem, com altura 30
    glBegin(GL_QUADS);
       // face da base - preta
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex3i(-20,0,-20);
       glVertex3i(20,0,-20);
       glVertex3i(20,0,20);
       glVertex3i(-20,0,20);
    glEnd();

    glBegin(GL_TRIANGLES);
       // face voltada para eixo z positivo
       // azul
       glColor3f(0.0f, 0.0f, 1.0f);
       glVertex3i(-20,0,20);
       glVertex3i(20,0,20);
       glVertex3i(0,30,00);

       // face voltada para o eixo x positivo
       // amarela
       glColor3f(1.0f, 1.0f, 0.0f);
       glVertex3i(20,0,20);
       glVertex3i(20,0,-20);
       glVertex3i(0,30,00);

       // face voltada para o eixo z negativo
       // vermelha
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3i(20,0,-20);
       glVertex3i(-20,0,-20);
       glVertex3i(0,30,00);

       // face voltada para o eixo x negativo
       //  verde
       glColor3f(0.0f,1.0f, 0.0f);
       glVertex3i(-20,0,-20);
       glVertex3i(-20,0,20);
       glVertex3i(0,30,0);
     glEnd();

    glPushMatrix();
    glColor3f(0.7f, 0.2f, 0.3f);
    glRotatef(-90.0, 1, 0, 0);
    glutSolidCone(10.0, 100.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(30.0, 1, 0, 0);
    glTranslatef(10.0, 10.0, 10.0);
    glColor3f(0.3f, 0.7f, 0.7f);
    glutSolidTeapot(20);
    glPopMatrix();

	//Garante a execucao dos comandos de desenho
	// glFlush();
	glutSwapBuffers();
}

void SceneTest::drawShit()
{

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
	glutCreateWindow("Particle Simulator");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
}
