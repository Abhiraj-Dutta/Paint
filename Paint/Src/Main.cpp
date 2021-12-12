//#include "Vendors\imgui\imgui.h"
//#include "Vendors\imgui\imgui_impl_glut.h"
//#include "Vendors\imgui\imgui_impl_opengl2.h"

#include <GL/glut.h>    
#include<iostream>
#include<vector>


using namespace std;

GLsizei width, height;
int x, y;
int px, py;

float r, g, b;

bool check = false;
bool mouseDown = false;

std::vector< float > points;


int windowHeight;
int windowWidth;

void drawGUI()
{
    glColor3f(0.2, 0.2, 0.2);
    glRecti(0, 0, glutGet(GLUT_WINDOW_WIDTH), 50);

    
}



void movedMouse(int mouseX, int mouseY)
{
    x = mouseX;
    y = mouseY;
   
    
   /* glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, glutGet(GLUT_WINDOW_HEIGHT) -  y);
    glVertex2i(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    glEnd();*/

   
    points.push_back(x);
    points.push_back(y);
    
    
    mouseDown = true;
   
    
}


void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x = mousex;
        y = mousey;
        points.push_back(x);
        points.push_back(y);
        points.push_back(x);
        points.push_back(y);
       
        mouseDown = true;
        
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        
       
        points.clear();
    }
  

   
}
void draw()
{
    

    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    for (size_t i = 0; i < points.size(); i += 2)
    {
        glVertex2i(points[i], glutGet(GLUT_WINDOW_HEIGHT) - points[i + 1]);


    }

    glEnd();

   
        
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        for (size_t i = 0; i < points.size(); i += 2)
        {
        glVertex2i(points[i], glutGet(GLUT_WINDOW_HEIGHT) - points[i]);
    }
        glEnd();
    

}



void display(void)
{
    
    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    windowWidth = glutGet(GLUT_WINDOW_WIDTH);

    glClearColor(0.9f, 0.9f, 0.9f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPointSize(5);

    draw();
       

  

       
        
                
    
    
   

   drawGUI();
   

   glutSwapBuffers();

   
    glutPostRedisplay();
   
}

void init()
{
    glutDisplayFunc(display);
    
    glutMouseFunc(mouse);
    glutMotionFunc(movedMouse);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
    glClearColor(1, 1, 1, 1);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("Paint");

    
    init();
    
    
    



    
    glutMainLoop();

    
    
    return 0;
}