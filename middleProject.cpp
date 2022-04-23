#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

#define TRUE 1
#define FALSE 0

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#define POINT_LENGTH 10
#define MAX_POINT 1000

void init(void);
void display(void);
void middleButtonInit(void); 
void mouse(int button, int state, int x, int y);
void reshape(int new_w, int new_h);
void PassiveMotion(int x, int y);

void MakePoint(void);
void MakeCountPrint(int count);
void MakePolygon(void);
void MakeRubberBandLine(int x, int y);
int CheckDraggeArea(void);
void SpinDisplay(void);

int location[MAX_POINT][2];
int locationCount = 0;
int checkRightButton = FALSE;
int motionButton = FALSE;
int passiveButton = FALSE;
int rubberX, rubberY;
int draggeX1, draggeX2, draggeY1, draggeY2;
int passiveMouseX, passiveMouseY;
GLfloat spin = 0.0;

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("중간 프로젝트");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(MakeRubberBandLine);
	glutMainLoop();
}

void middleButtonInit(void) {
	locationCount = 0;
	rubberX = rubberY = 0;
	checkRightButton = FALSE;
	motionButton = FALSE;
	passiveButton = FALSE;
	draggeX1 = draggeX2 = draggeY1 = draggeY2 = 0;
	passiveMouseX = passiveMouseY = 0;
	glutPassiveMotionFunc(NULL);
	glutIdleFunc(NULL);
}

void mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		if (checkRightButton == FALSE && locationCount < MAX_POINT){
			location[locationCount][0] = x;
			location[locationCount++][1] = y;
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		if (checkRightButton == FALSE && locationCount < MAX_POINT){
			location[locationCount][0] = x;
			location[locationCount++][1] = y;
		}
		checkRightButton = TRUE;
	}

	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		middleButtonInit();
	}

	// 드래그 작업
	if (button == GLUT_LEFT_BUTTON && checkRightButton == TRUE) {
		if (state == GLUT_DOWN) {
			draggeX1 = x;
			draggeY1 = y;
		}

		if (state == GLUT_UP) {
			draggeX2 = x;
			draggeY2 = y;

			// 도형 전체가 드래그에 포함되었을떄
			if (CheckDraggeArea()) {
				passiveButton = TRUE;
				glutPassiveMotionFunc(PassiveMotion);
				glutIdleFunc(SpinDisplay);
			}
		}
	}
	glutPostRedisplay();
}

void init(void){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (passiveButton == FALSE) {
		for (int i = 0; i < locationCount; i++){
			int x = location[i][0], y = location[i][1];

			glPushMatrix();
			glTranslatef(x, y, 0.0f);
			MakePoint();
			MakeCountPrint(i);
			glPopMatrix();
			glEnd();
		}
	}

	if (checkRightButton==TRUE && passiveButton == FALSE)
		MakePolygon();

	if (passiveButton==TRUE) {
		glPushMatrix();
		glTranslatef(passiveMouseX , passiveMouseY , 0);
		glRotatef(spin, 0, 0, 1.0);
		glTranslatef(-passiveMouseX, -passiveMouseY, 0);
		MakePolygon();
		glPopMatrix();
	}

	if (motionButton == TRUE && checkRightButton == FALSE && locationCount) {
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
		glLineWidth(1.0f);
		glVertex3f(location[locationCount - 1][0], location[locationCount - 1][1], 0.0f);
		glVertex3f(rubberX, rubberY, 0.0f);
		glEnd();
	}

	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h) {

	float WidthFactor = (float)w / WINDOW_WIDTH;
	float HeightFactor = (float)h / WINDOW_HEIGHT;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0.0, WINDOW_WIDTH*WidthFactor, WINDOW_HEIGHT*HeightFactor, 0.0);
}

// 마우스가 욺직일때
void PassiveMotion(int x, int y) {
	passiveMouseX = x;
	passiveMouseY = y;

	glutPostRedisplay();
}

void MakePoint() {
	glColor3f(1, 1, 1);
	glPointSize(5.0);

	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.0);
	glEnd();

	glFlush();
}

void MakeCountPrint(int count) {
	char stringCount[MAX_POINT];

	glColor3f(1, 1, 1);
	itoa(count, stringCount, 10);
	glRasterPos3f(-5, -10, 0);

	for (int i = 0; i < strlen(stringCount); i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, stringCount[i]);
}

void MakePolygon() {
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);

	for (int i = 0; i < locationCount; i++){
		int x = location[i][0], y = location[i][1];
		glVertex3f(x, y, 0.0f);
	}

	glEnd();
}

void MakeRubberBandLine(int x, int y) {
	motionButton = TRUE;
	rubberX = x;
	rubberY = y;

	glutPostRedisplay();
}

// 그래그 구역 체크
int CheckDraggeArea(void) {
	int left = draggeX1 < draggeX2 ? draggeX1 : draggeX2;
	int right = draggeX1 > draggeX2 ? draggeX1 : draggeX2;
	int top = draggeY1 < draggeY2 ? draggeY1 : draggeY2;
	int bottom = draggeY1 > draggeY2 ? draggeY1 : draggeY2;

	for (int i = 0; i < locationCount; i++) {
		if (!(location[i][0] >= left && location[i][0] <= right)) return FALSE;
		if (!(location[i][1] >= top && location[i][1] <= bottom)) return FALSE;
	}

	return TRUE;
}

void SpinDisplay(void) {
	spin += 1.0;

	if (spin > 360.0)
		spin = spin - 360.0;

	glutPostRedisplay();
}


