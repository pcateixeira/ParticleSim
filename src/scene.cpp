#include "scene.h"

Scene::Scene()
{}

// Fun��o callback de redesenho da janela de visualiza��o
void Scene::drawScene()
{
	// Muda para o sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa a matriz de transforma��o corrente
	glLoadIdentity();

	// Limpa a janela de visualiza��o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Desenha um objeto modelado com transforma��es hier�rquicas

	glColor3f(1.0f,0.0f,0.0f);

    Point3D pos1(1,1,1);

    glBegin(GL_POINTS);
        glVertex3i(pos1.getX(), pos1.getY(), pos1.getZ());
    glEnd();

	// Executa os comandos OpenGL
	glFlush();
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void Scene::changeWindowSize(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as vari�veis
	largura = w;
	altura = h;

	// Especifica as dimens�es da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (esquerda, direita, inferior,
	// superior) mantendo a propor��o com a janela de visualiza��o
	if (largura <= altura)
	{
		gluOrtho2D (-25.0f, 25.0f, -25.0f*altura/largura, 25.0f*altura/largura);
	}
	else
	{
		gluOrtho2D (-25.0f*largura/altura, 25.0f*largura/altura, -25.0f, 25.0f);
	}
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Scene::initialize ()
{
	// Define a cor de fundo da janela de visualiza��o como preto
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

bool Scene::renderScene() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(5,5);
	glutInitWindowSize(800,600);
	glutCreateWindow("Particle Simulator");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(drawScene);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(changeWindowSize);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	initialize();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();
}
