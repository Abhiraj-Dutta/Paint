#include <cstdlib>
#include <GL/glut.h>    
#include<iostream>

using namespace std;

GLsizei width, height;

float r, g, b, x, y;

bool check = false;
bool mouseDown = true;

void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        
   }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        mouseDown = false;

    }


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        check = true;

        x = mousex;
        y = 480 - mousey;
       
       
        
   }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        check = false;

        x = mousex;
        y = 480 - mousey;



    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;

    }

   
}

void display(void)
{
    glColor3f(0, 0, 1);
    glPointSize(10);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    cout << check << endl;

    if (check)
    {
        glBegin(GL_POINTS);
        glVertex2i(x, y);

        glEnd();
        
    }

    glFlush();
    glutPostRedisplay();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Paint");

    

    // initializing callbacks
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    

    glutMainLoop();
    return 0;
}