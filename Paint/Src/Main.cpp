#include<iostream>
#include<vector>

#include "GUI.h"

#define BLACK 0, 0, 0
#define WHITE 1, 1, 1
#define RED 1, 0, 0
#define GREEN 0, 1, 0
#define BLUE 0, 0, 1


using namespace std;


GUI gui;


int colorIndex;

int x;
int y;
bool mouseDown;
std::vector< float > points;







void movedMouse(int mouseX, int mouseY)
{
    x = mouseX;
    y = mouseY;

    if (mouseDown == true && x > 30 && y > 30 && x < gui.canvasX && y < gui.canvasY)
    {
        points.push_back(x);
        points.push_back(y);
    }
       
   
   
    
}


void mouse(int button, int state, int mousex, int mousey)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x = mousex;
        y = mousey;
    }
    if (button == GLUT_LEFT_BUTTON && x > 30 && y > 30 && x < gui.canvasX && y < gui.canvasY)
    {
        
        points.push_back(x);
        points.push_back(y);
        
       
        mouseDown = true;
        
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
        (gui.colorAbsPosX + 30) > x &&
        (gui.colorAbsPosY + glutGet(GLUT_WINDOW_HEIGHT)) - 30 > y &&
        (gui.colorAbsPosX + 50) < x &&
        (gui.colorAbsPosY + glutGet(GLUT_WINDOW_HEIGHT)) - 50 < y)
    {
        colorIndex = 1;
    }


    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        
       
        points.clear();
    }
    

   
}


void draw()
{
    

    glBegin(GL_POINTS);
    
    for (size_t i = 0; i < points.size(); i += 2)
    {
        glColor3f(0.0f, 0.0f, 0.0f);
        if (colorIndex == 1)
        {
            glColor3f(RED);
            cout << "color: " << "red" << endl;
        }
        glVertex2i(points[i], glutGet(GLUT_WINDOW_HEIGHT) - points[i + 1]);


    }

    glEnd();

   
        
 
}

void setup()
{
   
    glClearColor(0.9f, 0.9f, 0.9f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void display(void)
{
    

    setup();
    
    
    glPointSize(5);

    gui.drawCanvas(1890, 930);
    

    draw();     
    
    gui.drawDock();
    cout << colorIndex << endl;
   

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
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Paint");

    
    init();
    
    
    



    
    glutMainLoop();

    
    
    return 0;
}