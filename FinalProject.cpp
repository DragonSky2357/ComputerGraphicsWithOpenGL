///*
//1,2,3,4,5 카메라 제어
//ESC - quit
//
//*/
//
#include <GL/glut.h>
#include <iostream>
#include <cmath>

#include "MeshFactory.h"
#include "ObjMesh.h"

using namespace std;

void Display();
void Reshape(int w, int h);
void Keyboard(int key, int x, int y);
void Timer(int value);
void Idle();
void Grid();
void main_menu_select(int value);
void DrawPartition();
void key(unsigned char key, int x, int y);

ObjMesh objMesh;

#define WIDTH 1280
#define HEIGHT 720

int zoomSize = 400;
int leftAngle = 0;

//camera
float camPos[3] = { 0, 15, 25 };
float cntPos[3] = { 0, 0, 0 };
float a = 0;

void material_selection(float ambr, float ambg, float ambb,
	float difr, float difg, float difb,
	float specr, float specg, float specb, float shine){
	float material_amb[4] = { ambr,ambg,ambb,1.0 };
	float material_dif[4] = { difr,difg,difb,1.0 };
	float material_spec[4] = { specr,specg,specb,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, material_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_spec);
	glMaterialf(GL_FRONT, GL_SHININESS, shine* 128.0);
}

void Init()
{
	CMeshFacotry::LoadObjModel("treasure_chest.obj", &objMesh);

	glDepthFunc(GL_LESS); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing

	glClearColor(0.0, 0.0, 0.0, 1.0); //clear the screen to black

	glEnable(GL_SMOOTH);

	GLfloat ambient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat diffuse[] = { 5.0,5.0,5.0,1.0 };
	GLfloat specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat position[] = { 1.0,1.0,1.0,1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glFrontFace(GL_CW);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	material_selection(0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 0.6);
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("OBJ file Loader");

	Init();

	glutIgnoreKeyRepeat(1);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutReshapeFunc(Reshape);
	glutSpecialFunc(Keyboard);
	glutKeyboardFunc(key);
	glutIdleFunc(Idle);

	glutCreateMenu(main_menu_select);
	glutAddMenuEntry("Gold", 1);
	glutAddMenuEntry("Rubby", 2);
	glutAddMenuEntry("Bronze", 3);
	glutAddMenuEntry("Emerald", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer

	glMatrixMode(GL_MODELVIEW);


	// 좌상(위)
	glViewport(0, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(camPos[0], zoomSize, 0, cntPos[0], cntPos[1], cntPos[2], 1.0, 0.0, 0.0);
	Grid();

	DrawPartition();
	//objMesh.Render();
	glutSolidTeapot(5.0);
	//우상(옆)
	glViewport(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(camPos[0], zoomSize, zoomSize, cntPos[0], cntPos[1], cntPos[2], 0.0, 1.0, 0.0);
	Grid();

	DrawPartition();
	//objMesh.Render();
	glutSolidTeapot(5.0);

	//좌하(앞)
	glViewport(0, 0, WIDTH / 2, HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(-zoomSize, 0, 0, cntPos[0], cntPos[1], cntPos[2], 0.0, 1.0, 0.0);
	Grid();

	DrawPartition();
	//objMesh.Render();
	glutSolidTeapot(5.0);

	// 우하(무작위)
	glViewport(WIDTH / 2, 0, WIDTH / 2, HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(camPos[0], zoomSize, zoomSize, cntPos[0], cntPos[1], cntPos[2], 0.0, 1.0, 0.0);
	Grid();

	DrawPartition();
	//objMesh.Render();
	glutSolidTeapot(5.0);

	glutSwapBuffers(); //swap the buffers
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 100000.0);
	glMatrixMode(GL_MODELVIEW);
}

void Keyboard(int key,int x, int y)
{
	cout << key << endl;
	if (key == 27) {
		exit(0);
	}
	switch (key)
	{
	case GLUT_KEY_UP:
		zoomSize -= 5;
		break;
	case GLUT_KEY_DOWN:
		zoomSize += 5;
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
}

void key(unsigned char key, int x, int y) {
	if (key == '1') {
		camPos[0] = -5; camPos[1] = 10; camPos[2] = 15;
		cntPos[0] = -5; cntPos[1] = 5; cntPos[2] = 0;
	}
	else if (key == '2') {
		camPos[0] = 7; camPos[1] = 10; camPos[2] = 20;
		cntPos[0] = 5; cntPos[1] = 7; cntPos[2] = 0;
	}
	else if (key == '3') {
		camPos[0] = 0; camPos[1] = 15; camPos[2] = 25;
		cntPos[0] = 0; cntPos[1] = 8; cntPos[2] = 0;
	}
	else if (key == '4') {
		camPos[0] = 20; camPos[1] = 20; camPos[2] = 25;
		cntPos[0] = 0; cntPos[1] = 7; cntPos[2] = 0;
	}
	else if (key == '5') {
	/*	material_selection(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065, 0.4);
		glutPostRedisplay();*/
	}

}
void Idle()
{
	Display();
}

void Grid()
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	for (int i = -50; i < 50; i++)
	{
		glBegin(GL_LINES);
		glNormal3f(0, 1, 0);
		glVertex3f(i, 0, -50);
		glVertex3f(i, 0, 50);
		glEnd();
	}

	for (int i = -50; i < 50; i++)
	{
		glBegin(GL_LINES);
		glNormal3f(0, 1, 0);
		glVertex3f(-50, 0, i);
		glVertex3f(50, 0, i);
		glEnd();
	}

	glPopMatrix();
}

void DrawPartition() {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glNormal3f(0, 1, 0);
	glVertex3f(50.0, 0.0, 0.0);
	glVertex3f(-50.0, 0.0, 0.0);

	glEnd();
	glPopMatrix();
}

void main_menu_select(int value) {
	switch (value)
	{
	case 1:
		material_selection(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065, 0.4);
		glutPostRedisplay();
		break;
	case 2:
		material_selection(0.1745, 0.01175, 0.01175, 0.61424, 0.04136, 0.04136, 0.727811, 0.626959, 0.626959, 0.6);
		glutPostRedisplay();
		break;
	case 3:
		material_selection(0.2125, 0.1275, 0.054, 0.714, 0.4284, 0.18144, 0.393548, 0.271906, 0.166721, 0.2);
		glutPostRedisplay();
		break;
	case 4:
		material_selection(0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 0.6);
		glutPostRedisplay();
		break;
	case 666:
		exit(0);
		break;
	}
}
