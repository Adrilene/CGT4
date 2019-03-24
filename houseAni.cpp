#include <GL/glut.h>
#include <iostream>

using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

int pos_x = 0;
int pos_y = 0;
int larg_casa = 250;
int alt_casa = 325;

int passo_x = 1;
int passo_y = 1;

void desenhaCasa(void){
    
    glBegin(GL_QUADS);
        glColor3f(0.8, 0.52, 0.25);
        glVertex2i(pos_x,pos_y);
        glVertex2i(pos_x+250,pos_y);
        glVertex2i(pos_x+250,pos_y+200);
        glVertex2i(pos_x,pos_y+200);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.55, 0.28, 0.15);
        glVertex2i(pos_x+125,pos_y+325);
        glVertex2i(pos_x,pos_y+200);
        glVertex2i(pos_x+250,pos_y+200);
    glEnd();

    glBegin(GL_QUADS); 
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(pos_x+50,pos_y);
        glVertex2i(pos_x+130,pos_y);
        glVertex2i(pos_x+130,pos_y+170);
        glVertex2i(pos_x+50,pos_y+170);
    glEnd();

    glBegin(GL_QUADS); 
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(pos_x+150,pos_y+80);
        glVertex2i(pos_x+220,pos_y+80);
        glVertex2i(pos_x+220,pos_y+150);
        glVertex2i(pos_x+150,pos_y+150);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(pos_x+185,pos_y+80);
        glVertex2i(pos_x+185,pos_y+150);
        glVertex2i(pos_x+150,pos_y+115);
        glVertex2i(pos_x+220,pos_y+115);
    glEnd();
}

void Timer(int value){
    
    // Muda a direção quando chega na borda esquerda ou direita
      if(pos_x > LARGURA-larg_casa || pos_x < 0)
            passo_x = -passo_x;

    // Muda a direção quando chega na borda superior ou inferior
    if(pos_y > ALTURA-alt_casa || pos_y < 0)
          passo_y = -passo_y;
          
    // Verifica as bordas.  Se a window for menor e o 
    // quadrado sair do volume de visualização 
   if(pos_x > LARGURA-larg_casa)
         pos_x = LARGURA-larg_casa-1;

   if(pos_y > ALTURA-alt_casa)
         pos_y = ALTURA-alt_casa-1;

    // Move o quadrado
    pos_x += passo_x;
    pos_y += passo_y;

    // Redesenha o quadrado com as novas coordenadas 
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
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
    glutTimerFunc(25,Timer,1);
    Inicializa();
	glutMainLoop();
}