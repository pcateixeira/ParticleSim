#include "scene.h"

Scene::Scene()
{}

// Função callback de redesenho da janela de visualização
void Scene::drawScene()
{
	// Muda para o sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa a matriz de transformação corrente
	glLoadIdentity();

	// Limpa a janela de visualização com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Desenha um objeto modelado com transformações hierárquicas

	glColor3f(1.0f,0.0f,0.0f);

    Point3D pos1(1,1,1);

    glBegin(GL_POINTS);
        glVertex3i(pos1.getX(), pos1.getY(), pos1.getZ());
    glEnd();

	// Executa os comandos OpenGL
	glFlush();
}

// Função callback chamada quando o tamanho da janela é alterado
void Scene::changeWindowSize(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior,
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura)
	{
		gluOrtho2D (-25.0f, 25.0f, -25.0f*altura/largura, 25.0f*altura/largura);
	}
	else
	{
		gluOrtho2D (-25.0f*largura/altura, 25.0f*largura/altura, -25.0f, 25.0f);
	}
}

// Função responsável por inicializar parâmetros e variáveis
void Scene::initialize ()
{
	// Define a cor de fundo da janela de visualização como preto
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

bool Scene::renderScene() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(5,5);
	glutInitWindowSize(800,600);
	glutCreateWindow("Particle Simulator");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(drawScene);

	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(changeWindowSize);

	// Chama a função responsável por fazer as inicializações
	initialize();

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();
}
