#include <GL/glut.h> //inclua a biblioteca glut
#include <stdio.h>
#include "headers/Vertex.hpp"
#include "headers/Matrix.hpp"
#include "headers/MatrixStack.hpp"

using namespace std;
void init() {
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(-20, 20, -15, 15); // estabeleca a area de visualizacao
}
// a seguir e discriminada a nossa fincao de exibicao chamada display. Temos
// tres objetos com suasrespectiva cores.
      // Algumas funcoes novas serao apresentadas.
      // glPushMatrix(); cria uma nova matrix na pilha de matrizes.
      // glPopMatrix(); retira uma matriz da pilha de matrizes.
      // glRotatef(ang,x,y,z); rotaciona objetos em torno da origem. O primeiro
      // argumento e o angulo da rotacao em radianos. Os outros argumentos estao
      // relacionados aos eixos de rotacao. Se voce usar 
      //(90, 1, 0, 0)sera rotacionado 90 graus em torno do eixo X..
      // glScalef(sx,sy,sz);
      // glTranslatef(tx,ty,tz);
void display() {

    float theta = 90;
    glClear(GL_COLOR_BUFFER_BIT);

    //USANDO TRANSFORMACOES DO OPENGL
    glPushMatrix();
    glColor3f(0, 0, 1); // cor vermelha

    glTranslatef(3.5,-3.5,0);
    glRotatef(theta, 0, 0, 1);
    glTranslatef(-3.5,3.5,0);

    glBegin(GL_POLYGON); // comeca a desenhar
    glVertex2f(-1, -1);     // last vertex
    glVertex2f(0, 3);     // last vertex
    glVertex2f(1, -1);     // last vertex
    glEnd();               // termina o desenho

    glPopMatrix();

    //USANDO TRANSFORMACOES DA BIBLIOTECA DO TRABALHO
    Polygon polygon;
    polygon.addVertex(Vertex(-1,-1));
    polygon.addVertex(Vertex(0,3));
    polygon.addVertex(Vertex(1,-1));

    MatrixStack MS;
    MS.PushMatrix();
    MS.Translate(3.5,-3.5);
    MS.Rotate(theta);
    MS.Translate(-3.5,3.5);

    glColor3f(1, 0, 0); // cor vermelha

    Polygon transformed_polygon = polygon.apply(MS);
    glBegin(GL_POLYGON); // comeca a desenhar
    for(auto vertex : transformed_polygon.vertices)
    {
        glVertex2f(vertex.x, vertex.y);
    }
    glEnd();               // termina o desenho
    MS.PopMatrix();

    glFlush();
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Transformacoes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
