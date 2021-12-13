#include <GL\glut.h>

#pragma once
class GUI
{
public:
	GUI();

	int canvasX;
	int canvasY;

	int colorAbsPosX;
	int colorAbsPosY;

	void drawDock();
	void drawColorPickers(int, int);
	void drawCanvas(int, int);

	void drawGUI();
};

