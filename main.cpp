//////#include<GL/glut.h>
//////#include <stdlib.h>
//////
//////void init(void) {
//////	glClearColor(0.0, 0.0, 0.0, 0.0);
//////	glShadeModel(GL_SMOOTH);
//////}
//////
//////void triangle(void) {
//////	glBegin(GL_TRIANGLES);
//////	glColor3f(1.0, 0.0, 0.0);
//////	glVertex2f(-0.5, -0.5);
//////	glColor3f(0.0, 1.0, 0.0);
//////	glVertex2f(0.5, -0.5);
//////	glColor3f(0.0, 0.0, 1.0);
//////	glVertex2f(-0.5, 0.5);
//////	glEnd();
//////}
//////
//////void display(void) {
//////	glClear(GL_COLOR_BUFFER_BIT);
//////	triangle();
//////	glFlush();
//////}
//////
//////void reshape(int new_w, int new_h) {
//////	glViewport(0, 0, new_w, new_h);
//////	float WidthFactor = (float)new_w / 300.0;
//////	float HeightFactor = (float)new_h / 300.0;
//////
//////	glMatrixMode(GL_PROJECTION);
//////	glLoadIdentity();
//////
//////	gluOrtho2D(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor);
//////}
//////
//////int main(int argc, char** argv) {
//////	glutInit(&argc, argv);
//////	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//////	glutInitWindowSize(300, 300);
//////	glutInitWindowPosition(100, 100);
//////	glutCreateWindow(argv[0]);
//////	init();
//////	glutDisplayFunc(display);
//////	glutReshapeFunc(reshape);
//////	glutMainLoop();
//////	return 0;
//////}
////
//////#include<GL/glut.h>
//////#include <stdio.h>
//////#include <stdlib.h>
//////
//////void init(void) {
//////	glClearColor(0.0, 0.0, 0.0, 0.0);
//////}
//////
//////void display(void) {
//////	glClear(GL_COLOR_BUFFER_BIT);
//////	glClearColor(0.0, 0.0, 0.0, 0.0);
//////	glFlush();
//////}
//////
//////void mouseProcess(int button, int state, int x, int y) {
//////	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
//////		printf("Left mouse button is pressed.. \a\n");
//////	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
//////		printf("Middle mouse button is pressed.. \a\n");
//////	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//////		printf("Right mouse button is pressed.. \a\n");
//////	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//////		printf("Left mouse button is released.. \a\n");
//////	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
//////		printf("Middle mouse button is released.. \a\n");
//////	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
//////		printf("Right mouse button is released.. \a\n");
//////
//////}
//////
//////void mousePassiveMotaion(int x, int y) {
//////	printf("Current mouse position: %d, %d\n", x, y);
//////}
//////
//////void mouseActiveMotion(int x, int y) {
//////	printf("Pressed mouse position: %d, %d\n", x, y);
//////}
//////
//////void mouseEntry(int state) {
//////	if (state == GLUT_LEFT)
//////		printf("Mouse is outside of window..\a\n");
//////	else if (state == GLUT_ENTERED)
//////		printf("Mouse is inside of window..\a\n");
//////}
//////
//////void keyboard(unsigned char key, int x, int y) {
//////	switch (key)
//////	{
//////	case 'a':
//////		printf("a is pressed.. %d, %d\a\n", x, y);
//////		break;
//////	case 'b':
//////		printf("b is pressed.. %d, %d\a\n", x, y);
//////		break;
//////
//////	case 27:
//////		exit(0);
//////		break;
//////	}
//////}
//////
//////int main(int argc, char** argv) {
//////	glutInit(&argc, argv);
//////	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//////	glutInitWindowSize(500, 500);
//////	glutInitWindowPosition(100, 100);
//////	glutCreateWindow("Mouse and keyboard");
//////	init();
//////	glutDisplayFunc(display);
//////	glutKeyboardFunc(keyboard);
//////	glutMouseFunc(mouseProcess);
//////	glutMainLoop();
//////	return 0;
//////}
////
//////#include <GL/glut.h>
//////#include <stdlib.h>
//////#include <stdio.h>
//////
//////#define size 50.0
//////
//////float w_height = 800;
//////float w_width = 800;
//////float square_x = 0, square_y = 400;
//////float square_dx = 0.1;
//////
//////void idleCallBack() {
//////	square_x += square_dx;
//////	if (square_x + size > w_width || square_x < 0) square_dx *= -1.0;
//////	glutPostRedisplay();
//////}
//////
//////void displayCallBack(void) {
//////	glClearColor(0.0, 0.0, 0.0, 1.0);
//////	glClear(GL_COLOR_BUFFER_BIT);
//////
//////	glMatrixMode(GL_PROJECTION);
//////	glLoadIdentity();
//////	glOrtho(0.0, w_width, 0.0, w_height, -1.0, 1.0);
//////
//////	glMatrixMode(GL_MODELVIEW);
//////	glLoadIdentity();
//////	glTranslatef(square_x, square_y, 0.0);
//////
//////	glColor3ub(255, 255, 0);
//////	glBegin(GL_POLYGON);
//////	glVertex2f(0, 0);
//////	glVertex2f(size, 0);
//////	glVertex2f(size, size);
//////	glVertex2f(0, size);
//////	glEnd();
//////
//////	glutSwapBuffers();
//////}
//////
//////void main(int argc, char** argv) {
//////	glutInit(&argc, argv);
//////
//////	glutInitWindowPosition(10, 10);
//////	glutInitWindowSize(w_width, w_height);
//////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//////	glutCreateWindow("Idle Callback");
//////
//////	glutDisplayFunc(displayCallBack);
//////	glutIdleFunc(idleCallBack);
//////
//////	glutMainLoop();
//////}
////
//
////#include <GL/glut.h>
////#include <GL/GLU.h>
////#include <GL/GL.h>
////#include <time.h>
////
////unsigned char PALETTE[16][3] = {
////	{255,255,255},
////	{0,255,255},
////	{255,0,255},
////	{0,0,255},
////	{192,192,192},
////	{128,128,128},
////	{0,128,128},
////	{128,0,128},
////	{0,0,128},
////	{255,255,0},
////	{0,255,0},
////	{128,128,0},
////	{0,128,0},
////	{255,0,0},
////	{128,0,0},
////	{0,0,0},
////};
////
////GLfloat Delta = 0.0;
////GLint Index = 0;
////GLfloat Red = 0.0;
////GLfloat Green = 0.0;
////GLfloat Blue = 0.0;
////
////void MyDisplay() {
////	Red = PALETTE[Index][0] / 255.0f;
////	Green = PALETTE[Index][1] / 255.0f;
////	Blue = PALETTE[Index][2] / 255.0f;
////	glColor3f(Red, Green, Blue);
////
////	glBegin(GL_LINES);
////	glVertex3f(-1.0 + Delta, 1.0, 0.0);
////	glVertex3f(1.0 - Delta, -1.0, 0.0);
////	glVertex3f(-1.0, -1.0 + Delta, 0.0);
////	glVertex3f(1.0, 1.0 - Delta, 0.0);
////	glEnd();
////	glutSwapBuffers();
////}
////
////void MyTimer(int value) {
////	if (Delta < 2.0f)Delta = Delta + 0.01;
////	else {
////		Delta = 0.0;
////		if (++Index >= 15) {
////			Index = 0;
////			glClear(GL_COLOR_BUFFER_BIT);
////		}
////	}
////	glutPostRedisplay();
////	glutTimerFunc(10, MyTimer, 1);
////}
////
////int main(int argc, char** argv) {
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
////	glutInitWindowSize(500, 500);
////	glutInitWindowPosition(0, 0);
////	glutCreateWindow("Timer Callback 예제");
////	glClearColor(0.0, 0.0, 0.0, 1.0);
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
////	glutTimerFunc(10, MyTimer, 1);
////	glutDisplayFunc(MyDisplay);
////	glutMainLoop();
////	return 0;
////}
//
////#include <GL/glut.h>
////#include <GL/GLU.h>
////#include <GL/GL.h>
////#include <time.h>
////#include <stdlib.h>
////
////static GLfloat spin = 0.0;
////
////void display(void) {
////	int r, g, b;
////	r = rand() % 256;
////	g = rand() % 256;
////	b = rand() % 256;
////
////	glClear(GL_COLOR_BUFFER_BIT);
////
////	glPushMatrix();
////	glRotatef(spin, 0.0, 0.0, 1.0);
////	glColor3f((GLfloat)r / 255, (GLfloat)g / 255, (GLfloat)b / 255);
////	glRectf(-25.0, -25.0, 25.0, 25.0);
////	glPopMatrix();
////
////	glutSwapBuffers();
////}
////
////void spinDisplay(void) {
////	spin = spin + 0.01;
////	if (spin > 360.0) spin = spin - 360.0;
////	glutPostRedisplay();
////}
////
////void init(void) {
////	glClearColor(0.0, 0.0, 0.0, 0.0);
////	glShadeModel(GL_FLAT);
////}
////
////void reshape(int w, int h) {
////	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////}
////
////void mouse(int button, int state, int x, int y) {
////	switch (button)
////	{
////	case GLUT_LEFT_BUTTON:
////		if (state == GLUT_DOWN) glutIdleFunc(spinDisplay);
////		break;
////	case GLUT_RIGHT_BUTTON:
////		if (state == GLUT_DOWN) glutIdleFunc(NULL);
////		break;
////	
////	default:
////		break;
////	}
////}
////int main(int argc, char** argv) {
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
////	glutInitWindowSize(250, 250);
////	glutInitWindowPosition(100, 100);
////	glutCreateWindow("02_5 사각형 회전");
////	init();
////	glutDisplayFunc(display);
////	glutReshapeFunc(reshape);
////	glutMouseFunc(mouse);
////	glutMainLoop();
////	return 0;
////}
//
////#include <GL/glut.h>
////#include <GL/GLU.h>
////#include <GL/GL.h>
////#include <time.h>
////#include <stdlib.h>
////
////static GLfloat spin = 0.0;
////
////void display(void) {
////	int r, g, b;
////	r = rand() % 256;
////	g = rand() % 256;
////	b = rand() % 256;
////
////	glClear(GL_COLOR_BUFFER_BIT);
////
////	glPushMatrix();
////	glRotatef(spin, 0.0, 0.0, 1.0);
////	glColor3f((GLfloat)r / 255, (GLfloat)g / 255, (GLfloat)b / 255);
////	glPopMatrix();
////
////	glutSwapBuffers();
////}
////
////void spinDisplay(void) {
////	spin = spin + 0.01;
////	if (spin > 360.0) spin = spin - 360.0;
////	glutPostRedisplay();
////}
////
////void init(void) {
////	glClearColor(0.0, 0.0, 0.0, 0.0);
////	glShadeModel(GL_FLAT);
////}
////
////void reshape(int w, int h) {
////	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////}
////
////void mouse(int button, int state, int x, int y) {
////	switch (button)
////	{
////	case GLUT_LEFT_BUTTON:
////		if (state == GLUT_DOWN) glutIdleFunc(spinDisplay);
////		break;
////	case GLUT_RIGHT_BUTTON:
////		if (state == GLUT_DOWN) glutIdleFunc(NULL);
////		break;
////
////	default:
////		break;
////	}
////}
////int main(int argc, char** argv) {
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
////	glutInitWindowSize(250, 250);
////	glutInitWindowPosition(100, 100);
////	glutCreateWindow("02_5 사각형 회전");
////	init();
////	glutDisplayFunc(display);
////	glutReshapeFunc(reshape);
////	glutMouseFunc(mouse);
////	glutMainLoop();
////	return 0;
////}
//
////#include<GL/glut.h>
////#include <stdlib.h>
////
////float v1[3] = { 75.0,400.0,0.0 };
////float v2[3] = { 150.0,100.0,0.0 };
////float v3[3] = { 225.0,400.0,0.0 };
////float v4[3] = { 300.0,100.0,0.0 };
////float v5[3] = { 375.0,400.0,0.0 };
////float v6[3] = { 450.0,100.0,0.0 };
////
////void init(void) {
////	glClearColor(0.0, 0.0, 0.0, 0.0);
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
////}
////
////void draw_points() {
////	glColor3f(1.0, 0.0, 0.0);
////
////	glPointSize(4);
////	glBegin(GL_POINTS);
////	glVertex3fv(v1);
////	glVertex3fv(v2);
////	glVertex3fv(v3);
////	glVertex3fv(v4);
////	glVertex3fv(v5);
////	glVertex3fv(v6);
////	glEnd();
////}
////
////void draw_lines() {
////	glColor3f(0.0, 1.0, 0.0);
////
////	glLineWidth(1);
////	glBegin(GL_LINES);
////	glVertex3fv(v1);
////	glVertex3fv(v2);
////	glVertex3fv(v3);
////	glVertex3fv(v4);
////	glVertex3fv(v5);
////	glVertex3fv(v6);
////	glEnd();
////}
////
////void draw_triangle_fan() {
////	glColor3f(0.0, 1.0, 0.0);
////
////	glBegin(GL_TRIANGLE_FAN);
////	glVertex3fv(v1);
////	glVertex3fv(v2);
////	glVertex3fv(v3);
////	glVertex3fv(v4);
////	glVertex3fv(v5);
////	glVertex3fv(v6);
////	glEnd();
////}
////
////void draw_eqads() {
////	glColor3f(0.0, 1.0, 0.0);
////
////	glBegin(GL_QUADS);
////	glVertex3fv(v1);
////	glVertex3fv(v2);
////	glVertex3fv(v4);
////	glVertex3fv(v3);
////	glEnd();
////}
////
////void draw_quad_strip() {
////	glColor3f(0.0, 1.0, 0.0);
////
////	glBegin(GL_QUAD_STRIP);
////	glVertex3fv(v1);
////	glVertex3fv(v2);
////	glVertex3fv(v3);
////	glVertex3fv(v4);
////	glVertex3fv(v5);
////	glVertex3fv(v6);
////	glEnd();
////}
////
////void draw_polygon() {
////	glColor3f(0.0, 1.0, 0.0);
////
////	glBegin(GL_POLYGON);
////	glVertex3fv(v1);
////	glVertex3fv(v2);
////	glVertex3fv(v4);
////	glVertex3fv(v5);
////	glVertex3fv(v3);
////	glEnd();
////}
////
////void display(void) {
////	glClear(GL_COLOR_BUFFER_BIT);
////	//draw_points();
////	//draw_triangle_fan();
////	//draw_eqads();
////	//draw_polygon();
////	//draw_polygon();
////	glFlush();
////}
////
////int main(int argc, char** argv) {
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
////	glutInitWindowSize(500, 500);
////	glutInitWindowPosition(300, 300);
////	glutCreateWindow("My first GL Program");
////	init();
////
////	glutDisplayFunc(display);
////	glutMainLoop();
////
////	return 0;
////}
//
//#include <GL/glut.h>
//#include <stdlib.h>
//
//#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES); \
//	glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();
//
//void init(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void display(void) {
//	int i;
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor3f(1.0, 1.0, 1.0);
//
//	glEnable(GL_LINE_STIPPLE);
//
//	glLineStipple(1, 0x0101);
//	drawOneLine(50.0, 125.0, 150.0, 125.0);
//	glLineStipple(1, 0x00FF);
//	drawOneLine(150.0, 125.0, 250.0, 125.0);
//	glLineStipple(1, 0x1C47);
//	drawOneLine(250.0, 125.0, 350.0, 125.0);
//
//	glLineWidth(5.0);
//	glLineStipple(1, 0x0101);
//	drawOneLine(50.0, 100.0, 150.0, 100.0);
//	glLineStipple(1, 0x00FF);
//	drawOneLine(150.0, 100.0, 250.0, 100.0);
//	glLineStipple(1, 0x1C47);
//	drawOneLine(250.0, 100.0, 350.0, 100.0);
//	glLineWidth(1.0);
//
//	glLineStipple(1, 0x1C47);
//	glBegin(GL_LINE_STRIP);
//		for (i = 0; i < 7; i++) glVertex2f(50.0 + ((GLfloat)i*50.0), 75.0);
//	glEnd();
//	
//	for (i = 0; i < 6; i++)
//		drawOneLine(50.0 + ((GLfloat)i*50.0), 50.0, 50.0 + ((GLfloat)(i + 1)*50.0), 50.0);
//
//	glLineStipple(5, 0x4C47);
//	drawOneLine(50.0, 25.0, 350.0, 25.0);
//
//	glDisable(GL_LINE_STIPPLE);
//	glFlush();
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
//}
//
//void keyboard(unsigned char key, int x, int y) {
//	switch (key)
//	{
//	case 27:
//		exit(0);
//		break;
//	}
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 150);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("My first GL Program");
//	init();
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//
//	return 0;
//}


//#include <GL/glut.h>
//#include <stdlib.h>
//
//float v1[3] = { -10.0,-35.0,0.0 };
//float v2[3] = { 10.0,-35.0,0.0 };
//float v3[3] = { 10.0,35.0,0.0 };
//float v4[3] = { -10.0,35.0,0.0 };
//
//void init(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-100.0, 400.0, -100.0, 400.0);
//}
//
//void draw_rectangle() {
//	glBegin(GL_POLYGON);
//	glVertex3fv(v1);
//	glVertex3fv(v2);
//	glVertex3fv(v3);
//	glVertex3fv(v4);
//	glEnd();
//}
//
//void draw_line() {
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_LINES);
//	glVertex3f(-100.0, 0.0, 0.0);
//	glVertex3f(400.0, 0.0, 0.0);
//	glVertex3f(0.0, -100.0, 0.0);
//	glVertex3f(0.0, 400.0, 0.0);
//	glEnd();
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	glLoadIdentity();
//	draw_line();
//
//	glColor3f(0.0, 0.0, 1.0);
//	draw_rectangle();
//
//	glLoadIdentity();
//	glTranslatef(100.0, 0.0, 0.0);
//	glRotatef(45.0, 0.0, 0.0, 1.0);
//	glColor3f(1.0, 0.0, 0.0);
//	draw_rectangle();
//
//	glLoadIdentity();
//	glRotatef(45.0, 0.0, 0.0, 1.0);
//	glTranslatef(100.0, 0.0, 0.0);
//	glColor3f(1.0, 1.0, 0.0);
//	draw_rectangle();
//
//	glFlush();
//}
//
//int main(int argc, char**argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(500, 500);
//	glutInitWindowSize(300, 300);
//	glutCreateWindow("glViewport Example");
//	init();
//
//	glutDisplayFunc(display);
//	glutMainLoop();
//}

//#include <GL/glut.h>
//
//void draw_triangle() {
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(0.0, 25.0);
//	glVertex2f(25.0, -25.0);
//	glVertex2f(-25.0, -25.0);
//	glEnd();
//}
//
//void draw_line() {
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_LINES);
//	glVertex2f(-50.0, 0.0);
//	glVertex2f(50.0, 0.0);
//	glVertex2f(0.0, -50.0);
//	glVertex2f(0.0, 50.0);
//	glEnd();
//}
//
//void display(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glLoadIdentity();
//	draw_line();
//	glColor3f(1.0, 1.0, 1.0);
//	draw_triangle();
//
//	glEnable(GL_LINE_STIPPLE);
//	glLineStipple(1, 0xF0F0);
//	glLoadIdentity();
//	glTranslatef(-20.0, 0.0, 0.0);
//	draw_triangle();
//
//	glLineStipple(1, 0xF00F);
//	glLoadIdentity();
//	glScalef(1.5, 0.5, 1.0);
//	draw_triangle();
//
//	glLineStipple(1, 0x8888);
//	glLoadIdentity();
//	glRotatef(90.0, 0.0, 0.0, 1.0);
//	draw_triangle();
//	glDisable(GL_LINE_STIPPLE);
//	glFlush();
//}
//
//void myinit(void) {
//	glShadeModel(GL_FLAT);
//}
//
//void myReshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-50.0, 50.0, -50.0*(GLfloat)h / (GLfloat)w,
//			50.0*(GLfloat)h / (GLfloat)w, -1.0, 1.0);
//	else
//		glOrtho(-50.0*(GLfloat)w / (GLfloat)h,
//			50.0*(GLfloat)w / (GLfloat)h, -50.0, 50.0, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("Object Transformation Program");
//	myinit();
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(myReshape);
//
//	glutMainLoop();
//}

//#include <GL/glut.h>
//#include <stdlib.h>
//
//void init(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//	glutWireTeapot(1.0);
//
//	glFlush();
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Transformation Teapot");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}

//#include <GL/glut.h>
//#include <stdlib.h>
//
//void init(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//	glutWireTeapot(1.0);
//
//	glFlush();
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//}
//
//int main(int argc, char**argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Transformation Teapot");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}

//#include <GL/glut.h>
//
//void draw_square() {
//	glBegin(GL_POLYGON);
//	glVertex2f(-0.2, 0.2);
//	glVertex2f(-0.2, -0.2);
//	glVertex2f(0.2, -0.2);
//	glVertex2f(0.2, 0.2);
//	glEnd();
// }
//
//void display() {
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor3f(1.0, 0.0, 0.0);
//	draw_square();
//
//	glPushMatrix();
//	
//	glColor3f(0.0, 1.0, 0.0);
//	glTranslatef(-0.6, 0.6, 0.0);
//	draw_square();
//
//	glPopMatrix();
//	glPushMatrix();
//
//	glColor3f(0.0, 0.0, 1.0);
//	glTranslatef(0.6, 0.6, 0.0);
//	glRotatef(45, 0.0, 0.0, 1.0);
//	draw_square();
//
//	glColor3f(1.0, 0.0, 1.0);
//	glScalef(1.2, 1.2, 1.0);
//	glTranslatef(-0.7, -0.7, 0.0);
//	draw_square();
//
//	glPopMatrix();
//
//	glColor3f(1.0, 1.0, 0.0);
//	glTranslatef(-0.6, -0.6, 0.0);
//	glScalef(1.2, 1.2, 1.0);
//	draw_square();
//
//	glFlush();
//}
//
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//
//	glViewport(0, 0, 400, 400);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Push Pop Matrix");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//}

//#include <GL/glut.h>
//#include <stdlib.h>
//
//void init(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//	glColor3f(1.0, 0.0, 0.0);
//	glutWireCube(1.0);
//
//	glPushMatrix();
//
//	glColor3f(0.0, 1.0, 0.0);
//	glTranslatef(-1.5, 0.0, 1.5);
//	glutWireCube(1.0);
//
//	glPopMatrix();
//
//	glColor3f(0.0, 0.0, 1.0);
//	glTranslatef(1.5, 0.0, 1.5);
//	glutWireCube(1.0);
//
//	glFlush();
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("투영 방법 예제");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}

//#include <GL/glut.h>
//
//void draw_rectangle() {
//	glBegin(GL_POLYGON);
//	glVertex2f(0.2, 0.4);
//	glVertex2f(0.8, 0.4);
//	glVertex2f(0.8, 0.6);
//	glVertex2f(0.2, 0.6);
//	glEnd();
//}
//
//void draw_point() {
//	glPointSize(5.0);
//	glBegin(GL_POINTS);
//	glVertex2f(0.5, 0.5);
//	glEnd();
//}
//
//void draw_lines() {
//	glBegin(GL_LINES);
//	glVertex2f(-1.0, 0.0);
//	glVertex2f(1.0, 0.0);
//	glVertex2f(0.0, -1.0);
//	glVertex2f(0.0, 1.0);
//	glEnd();
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//
//	glLoadIdentity();
//
//	glColor3f(1.0, 0.0, 0.0);
//	draw_rectangle();
//
//	glColor3f(0.0, 0.0, 1.0);
//	glTranslatef(0.5, 0.5, 0.0);
//	glRotatef(90.0, 0.0, 0.0, 1.0);
//	glTranslatef(-0.5, -0.5, 0.0);
//	draw_rectangle();
//
//	glColor3f(0.0, 0.0, 0.0);
//	draw_point();
//
//	glLoadIdentity();
//	glColor3f(0.0, 0.0, 0.0);
//	draw_lines();
//
//	glFlush();
//}
//
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//	glViewport(0, 0, 800, 800);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(800, 800);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("임의의 점에 대한 회전");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}

//#include<GL/glut.h>
//
//void display(void) {
//	GLdouble eqn[4] = { 0.0,1.0,0.0,0.0 };
//	GLdouble eqn2[4] = { 1.0,0.0,0.0,0.0 };
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//	glPushMatrix();
//	glTranslatef(0.0, 0.0, -3.0);
//
//	// clip lower half -- y < 0
//	glClipPlane(GL_CLIP_PLANE0, eqn);
//	glEnable(GL_CLIP_PLANE0);
//
//	// clip left half -- x < 0
//	glClipPlane(GL_CLIP_PLANE1, eqn2);
//	glEnable(GL_CLIP_PLANE1);
//
//	glRotatef(90.0, 1.0, 0.0, 0.0);
//	glutWireSphere(1.0, 20, 16);
//	glPopMatrix();
//	glFlush();
//}
//
//void myinit(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void myReshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	myinit();
//	glutDisplayFunc(display);
//	glutReshapeFunc(myReshape);
//	glutMainLoop();
//	return 0;
//}

//#include <GL/glut.h>
//
//void init(void);
//void display(void);
//void keyboard(unsigned char key, int x, int y);
//void reshape(int w, int h);
//
//static int year = 0, day = 0;
//
//void init(void){
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void display(void){
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//	glPushMatrix();
//	glutWireSphere(1.0, 20, 16);
//	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
//	glTranslatef(2.0, 0.0, 0.0);
//	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
//	glutWireSphere(0.2, 10, 8);
//	glPopMatrix();
//	glutSwapBuffers();
//
//	glutPostRedisplay();
//}
//
//void keyboard(unsigned char key, int x, int y){
//	switch (key)
//	{
//	case 'd':
//		day = (day + 10) % 360;
//		break;
//	case 'D':
//		day = (day - 10) % 360;
//		break;
//	case 'y':
//		year = (year + 5) % 360;
//		break;
//	case 'Y':
//		year = (year -5) % 360;
//		break;
//		default:
//			break;
//	}
//	glutPostRedisplay();
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//	glutPostRedisplay();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Planet");
//
//	init();
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//
//	glutMainLoop();
//
//	return 0;
//}

// 06-1 Pop up
//#include<GL/glut.h>
//#include<stdio.h>
//#include<stdlib.h>
//
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glFlush();
//}
//
//void main_menu_select(int value) {
//	switch (value)
//	{
//	case 1:
//		glutSetWindowTitle("First mode..");
//		printf("첫번째 메뉴를 선택하셨습니다.\n");
//		break;
//	case 2:
//		glutSetWindowTitle("Second mode..");
//		printf("두번째 메뉴를 선택하셨습니다.\n");
//		break;
//	case 3:
//		glutSetWindowTitle("Third mode..");
//		printf("세번째 메뉴를 선택하셨습니다.\n");
//		break;
//
//	case 666:
//		printf("프로그램 종료...\n");
//		exit(0);
//		break;
//	}
//}
//
//int main(int argc, char** argv) {
//	glutInitWindowSize(400, 400);
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutCreateWindow("Menu example by");
//	glutDisplayFunc(display);
//
//	glutCreateMenu(main_menu_select);
//	glutAddMenuEntry("First", 1);
//	glutAddMenuEntry("Second", 2);
//	glutAddMenuEntry("Third", 3);
//	glutAddMenuEntry("Quit", 666);
//
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	glutMainLoop();
//	return 0;
//}

// 06-2 Popup Sub Menu
//#include<stdlib.h>
//#include<GL/glut.h>
//#include<GL/GL.h>
//#include<GL/GLU.h>
//
//GLboolean IsSphere = true;
//GLboolean IsSmall = true;
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.5, 0.5, 0.5);
//	if ((IsSphere) && (IsSmall))
//		glutWireSphere(0.2, 15, 15);
//	else if ((IsSphere) && (!IsSmall))
//		glutWireSphere(0.4, 15, 15);
//	else if ((!IsSphere) && (IsSmall))
//		glutWireTorus(0.1, 0.3, 40, 20);
//	else
//		glutWireTorus(0.2, 0.5, 40, 20);
//	glFlush();
//}
//
//void MyMainMenu(int entryID) {
//	if (entryID == 1)
//		IsSphere = true;
//	else if (entryID == 2)
//		IsSphere = false;
//	else if (entryID == 3)
//		exit(0);
//	glutPostRedisplay();
//}
//
//void MySubMenu(int entryID) {
//	if (entryID == 1)
//		IsSmall = true;
//	else if (entryID == 2)
//		IsSmall = false;
//	glutPostRedisplay();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("OpenGL Sub menu example");
//
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//
//	GLint MySubMenuID = glutCreateMenu(MySubMenu);
//	glutAddMenuEntry("Small Object", 1);
//	glutAddMenuEntry("Big Object", 2);
//	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
//	glutAddMenuEntry("Draw Sphere", 1);
//	glutAddMenuEntry("Draw Torus", 2);
//	glutAddSubMenu("Change Size", MySubMenuID);
//	glutAddMenuEntry("Exit", 3);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}

// 06-3 Color Cube
//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//
//GLfloat MyVertices[8][3] = {
//	{-0.25,-0.25,0.25},
//	{-0.25,0.25,0.25},
//	{0.25,0.25,0.25},
//	{0.25,-0.25,0.25},
//	{-0.25,-0.25,-0.25},
//	{-0.25,0.25,-0.25},
//	{0.25,0.25,-0.25},
//	{0.25,-0.25,-0.25}
//};
//
//GLfloat MyColors[8][3] = {
//	{0.2,0.2,0.2},
//	{1.0,0.0,0.0},
//	{1.0,1.0,0.0},
//	{0.0,1.0,0.0},
//	{0.0,0.0,0.1},
//	{1.0,0.0,1.0},
//	{1.0,1.0,1.0},
//	{0.0,1.0,1.0},
//};
//
//GLubyte MyVertexList[24] = {
//	0,3,2,1,
//	2,3,7,6,
//	0,4,7,3,
//	1,2,6,5,
//	4,5,6,7,
//	0,1,5,4
//};
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFrontFace(GL_CCW);
//	glEnable(GL_CULL_FACE);
//	glEnableClientState(GL_COLOR_ARRAY);
//	glEnableClientState(GL_VERTEX_ARRAY);;
//	glColorPointer(3, GL_FLOAT, 0, MyColors);
//	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glRotatef(30.0, 1.0, 1.0, 1.0);
//	for (GLint i = 0; i < 6; i++)
//		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("OpenGL Vetex Array Example");
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}
