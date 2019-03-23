#include <GL/glut.h>
#include <iostream>

using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

void desenhaCasa(void){
    
    glBegin(GL_QUADS);
        glColor3f(0.8, 0.52, 0.25);
        glVertex2i(0,0);
        glVertex2i(250,0);
        glVertex2i(250,200);
        glVertex2i(0,200);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.55, 0.28, 0.15);
        glVertex2i(125,325);
        glVertex2i(0,200);
        glVertex2i(250,200);
    glEnd();

    glBegin(GL_QUADS); 
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(50,0);
        glVertex2i(130,0);
        glVertex2i(130,170);
        glVertex2i(50,170);
    glEnd();

    glBegin(GL_QUADS); 
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(150,80);
        glVertex2i(220,80);
        glVertex2i(220,150);
        glVertex2i(150,150);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(185,80);
        glVertex2i(185,150);
        glVertex2i(150,115);
        glVertex2i(220,115);
    glEnd();
}
/* Função callback chamada para fazer o desenho */
void Desenha(void){
	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    desenhaCasa();   //desenha cabeça e tronco



    glPopMatrix();    
    /* Executa os comandos OpenGL */
	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void){
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
    glutDisplayFunc(Desenha);
    Inicializa();
	glutMainLoop();
}