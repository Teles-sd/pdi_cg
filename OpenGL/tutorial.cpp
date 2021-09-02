#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

GLint WINDOW_WIDTH  = 500,
      WINDOW_HEIGHT = 500;
      
void init();      
void draw_test();

int main (int argcp, char *argv[]){
    
    glutInit(&argcp, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    GLint screen_width  = glutGet(GLUT_SCREEN_WIDTH),
            screen_height = glutGet(GLUT_SCREEN_HEIGHT);  
    
    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_WIDTH);
    glutCreateWindow("Is this the window title?");

    init();
    glutDisplayFunc(draw_test);

    GLfloat x1=100.0, y1=100.0,
            x2=200.0, y2=100.0,
            x3=100.0, y3=250.0,
            x4=200.0, y4=150.0;

    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();

    GLfloat x5=300.0, y5=300.0,
            x6=400.0, y6=300.0,
            x7=300.0, y7=450.0,
            x8=400.0, y8=350.0;

    glBegin(GL_QUAD_STRIP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glVertex2f(x5, y5);
        glVertex2f(x6, y6);
        glVertex2f(x7, y7);
        glVertex2f(x8, y8);
    glEnd();
    
    GLfloat red=0.1,
            green=0.1,
            blue=0.1,
            size=20.0;
    glColor3f(red, green, blue);
    glPointSize(size);
    
    glDrawArrays(GL_QUADS, 0, 4);
    glDrawArrays(GL_QUAD_STRIP, 0, 8);
    glFinish();
  
    glutMainLoop();

    return EXIT_SUCCESS;
}

void init(){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void draw_test(){
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}
