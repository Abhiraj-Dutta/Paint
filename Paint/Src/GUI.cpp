#include "GUI.h"


GUI::GUI()
{
    this->colorAbsPosX = 0;
    this->colorAbsPosY = 0;
    this->canvasX = 0;
    this->canvasY = 0;
    
}

void GUI::drawDock()
{
    glColor3f(0.7, 0.7, 0.7);
    glRecti(0, 0, glutGet(GLUT_WINDOW_WIDTH), 100);
    this->drawColorPickers(colorAbsPosX, colorAbsPosY);
}

void GUI::drawColorPickers(int x, int y)
{
    glColor3f(1, 0, 0);
    glRecti(x + 30, y + 30, x + 50, y + 50);

    glColor3f(0, 1, 0);
    glRecti(x + 60, y + 30, x + 80, y + 50);

    glColor3f(0, 0, 1);
    glRecti(x + 90, y + 30, x + 110, y + 50);

    glColor3f(1, 1, 0);
    glRecti(x + 120, y + 30, x + 140, y + 50);

    glColor3f(1, 0.75, 0.79);
    glRecti(x + 150, y + 30, x + 170, y + 50);

    glColor3f(1, 1, 1);
    glRecti(x + 180, y + 30, x + 200, y + 50);

    glColor3f(0, 0, 0);
    glRecti(x + 210, y + 30, x + 230, y + 50);
}

void GUI::drawCanvas(int sizeX, int sizeY)
{
    glColor3f(1, 1, 1);
    glRecti(30, 1050, sizeX, glutGet(GLUT_WINDOW_HEIGHT) - sizeY);
    this->canvasX = sizeX;
    this->canvasY = sizeY;
}

