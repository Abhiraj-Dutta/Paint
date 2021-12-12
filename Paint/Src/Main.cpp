#include "Vendors\imgui\imgui.h"
#include "Vendors\imgui\imgui_impl_glut.h"
#include "Vendors\imgui\imgui_impl_opengl2.h"

#include <GL/glut.h>    
#include<iostream>
#include<vector>

using namespace std;

GLsizei width, height;
int x, y;

float r, g, b;

bool check = false;
bool mouseDown = false;

std::vector< float > points;

void movedMouse(int mouseX, int mouseY)
{
    x = mouseX;
    y = mouseY;
    cout << x << ", " << y << endl;
    
   /* glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, glutGet(GLUT_WINDOW_HEIGHT) -  y);
    glVertex2i(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
    glEnd();*/
    points.push_back(x);
    points.push_back(y);

    glFlush();
    
}
void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x = mousex;
        y = mousey;
        points.push_back(x);
        points.push_back(y);

    }
    

   
}

void display(void)
{
    ////imgui
    //ImGui_ImplOpenGL2_NewFrame();
    //ImGui_ImplGLUT_NewFrame();

    //ImGui::Begin("Hello, world!");
    //ImGui::Text("This is some useful text.");
    //ImGui::End();


    //ImGui::Render();
    //ImGuiIO& io = ImGui::GetIO();

    /*glClearColor(1.0f, 1.0f, 1.0f, 0.0);*/
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (size_t i = 0; i < points.size(); i += 2)
  {
        glVertex2i(points[i], glutGet(GLUT_WINDOW_HEIGHT) - points[i + 1]);
        glVertex2i(points[i], glutGet(GLUT_WINDOW_HEIGHT) - points[i + 1]);
   }
   glEnd();
  /*  ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());*/
    glFlush();
    glutPostRedisplay();
   
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(1, 1, 1, 1);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("Paint");

    

    // initializing callbacks
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(movedMouse);

    // Setup Dear ImGui context
    /*IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;*/
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    //// Setup Dear ImGui style
    //ImGui::StyleColorsDark();
    ////ImGui::StyleColorsClassic();

    //// Setup Platform/Renderer backends
    //ImGui_ImplGLUT_Init();
    //ImGui_ImplGLUT_InstallFuncs();
    //ImGui_ImplOpenGL2_Init();
    //

    glutMainLoop();

    /*ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();*/
    return 0;
}