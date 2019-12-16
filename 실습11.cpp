//#define VIR_NUM 40
//#define PI 3.141592
//#include <Windows.h>
//#include<iostream>
//#include<time.h>
//#include<fstream>
//#include <stdio.h>
//#include <stdlib.h> 
//#include <vector>
//#include <math.h>
//#include<string>
//#include<glm/glm/glm.hpp>
//#include<glm/glm/gtc/matrix_transform.hpp>
//#include<glm/glm/ext.hpp>
//#include<GL/glew.h>
//#include<GL/freeglut.h>
//#include<gl/freeglut_ext.h>
//#include"Shader_Loader.h"
//
//using namespace Core;
//
//GLvoid drawScene(GLvoid);
//void TimerFunction(int);
//void Init();
//void Mouse(int, int, int, int);
//void Reshape(int, int);
//void Keyboard(unsigned char key, int x, int y);
//void special(int, int, int);
//void DrawLine();
//double GetRad(int);
//
//GLuint program;
//int winWidth, winHeight;
//bool Isrotate;
//float degree;
//
//enum Scale {
//	SCALE_UP,
//	SCALE_DOWN
//};
//
//enum Shape {
//	TRIANGLE,
//	SPHERE
//}shape;
//
//enum Line {
//	SINE,
//	ZIGZAG,
//	SPRING
//}line;
//
//class SineLine {
//public:
//	GLfloat vertex_buffer_data[VIR_NUM * 3];
//	SineLine() {
//		float j = -1.0;
//		for (int i = 0; i < VIR_NUM * 3; ++i) {
//			if (i % 3 == 0)
//				vertex_buffer_data[i] = j;
//			else if (i % 3 == 1)
//				vertex_buffer_data[i] = sin(GetRad(j * (float)180));
//			else
//				vertex_buffer_data[i] = 0;
//			j += 0.02;
//		}
//	}
//	void draw(){
//		glBegin(GL_LINE_STRIP);
//		for (int i = 0; i < VIR_NUM * 3; i += 3)
//			glVertex3f(vertex_buffer_data[i], vertex_buffer_data[i + 1], vertex_buffer_data[i + 2]);
//		glEnd();
//	}
//}sine_line;
//
//class Spring {
//public:
//	GLfloat vertex_buffer_data[VIR_NUM * 3];
//	Spring() {
//		float j = -1.0;
//		int rad = 0;
//		for (int i = 0; i < VIR_NUM * 3; ++i) {
//			if (i % 3 == 0)
//				vertex_buffer_data[i] = j + cos(GetRad(rad)) / (float)3;
//			else if (i % 3 == 1)
//				vertex_buffer_data[i] = sin(GetRad(rad)) / (float)2;
//			else
//				vertex_buffer_data[i] = 0;
//			j += 0.02;
//			rad = (rad + 10) % 360;
//		}
//	}
//	void draw() {
//		glBegin(GL_LINE_STRIP);
//		for (int i = 0; i < VIR_NUM * 3; i += 3)
//			glVertex3f(vertex_buffer_data[i], vertex_buffer_data[i + 1], vertex_buffer_data[i + 2]);
//		glEnd();
//	}
//}spring;
//
//class Zigzag {
//public:
//	GLfloat vertex_buffer_data[VIR_NUM * 3];
//	Zigzag() {
//		float j = -1.0;
//		int t = -1;
//		float vel = -1.0f;
//		for (int i = 0; i < VIR_NUM * 3; ++i) {
//			if (i % 3 == 0)
//				vertex_buffer_data[i] = j;
//			else if (i % 3 == 1) {
//				switch (t)
//				{
//				case -1:
//					vertex_buffer_data[i] = vel;
//					if ((vel += 0.2f) > 1.0)
//						t = 1;
//					break;
//				case 1:
//					vertex_buffer_data[i] = vel;
//					if ((vel -= 0.2f) < -1.0)
//						t = -1;
//					break;
//				}
//			}
//			else
//				vertex_buffer_data[i] = 0;
//			j += 0.02;
//		}
//	}
//	void draw() {
//		glBegin(GL_LINE_STRIP);
//		for (int i = 0; i < VIR_NUM * 3; i += 3)
//			glVertex3f(vertex_buffer_data[i], vertex_buffer_data[i + 1], vertex_buffer_data[i + 2]);
//		glEnd();
//	}
//}zigzag;
//
//class Triangle {
//	GLfloat vertex_buffer_data[3 * 3] = {
//		sine_line.vertex_buffer_data[0], sine_line.vertex_buffer_data[1] + 0.05f, 0.0,
//		vertex_buffer_data[0] - 0.05f, vertex_buffer_data[1] - 0.05f, 0.0,
//		vertex_buffer_data[0] + 0.05f, vertex_buffer_data[1] - 0.05f, 0.0
//	};
//	float scale = 0;
//	int j = 0;
//	Scale sc = SCALE_UP;
//public:
//	bool Isscale = false;
//	bool Ismove = false;
//	glm::mat4 scaling(glm::mat4 MyMatrix) {
//		switch (sc)
//		{
//		case SCALE_UP:
//			if (scale + 0.05f < 2.0f)
//				scale += 0.05f;
//			else
//				sc = SCALE_DOWN;
//			break;
//		case SCALE_DOWN:
//			if (scale - 0.05f > 0.2f)
//				scale -= 0.05f;
//			else
//				sc = SCALE_UP;
//			break;
//		}
//		MyMatrix = glm::scale(MyMatrix, glm::vec3(1.0f, scale, 1.0f));
//		return MyMatrix;
//	}
//	glm::mat4 move(glm::mat4 MyMatrix) {
//		j = (j + 3) % (VIR_NUM * 3);
//		switch (line)
//		{
//		case SINE:
//			MyMatrix = glm::translate(MyMatrix, glm::vec3(sine_line.vertex_buffer_data[j] + 1.0f, sine_line.vertex_buffer_data[j + 1], sine_line.vertex_buffer_data[j + 2]));
//			break;
//		case ZIGZAG:
//			MyMatrix = glm::translate(MyMatrix, glm::vec3(zigzag.vertex_buffer_data[j] + 1.0f, zigzag.vertex_buffer_data[j + 1], zigzag.vertex_buffer_data[j + 2]));
//			break;
//		case SPRING:
//			MyMatrix = glm::translate(MyMatrix, glm::vec3(spring.vertex_buffer_data[j] + 1.0f, spring.vertex_buffer_data[j + 1], spring.vertex_buffer_data[j + 2]));
//			break;
//		}
//
//		return MyMatrix;
//	}
//	void draw() {
//		GLuint vertexbuffer;
//		glGenBuffers(1, &vertexbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//		glEnableVertexAttribArray(0);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		glDrawArrays(GL_TRIANGLES, 0, 9);
//		glDisableVertexAttribArray(0);
//	}
//	void active() {
//		glm::mat4 MyMatrix = glm::mat4(1.0f);
//		MyMatrix = glm::rotate(MyMatrix, glm::radians(degree), glm::vec3(0, 1, 0));
//		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//		if (Ismove)
//			MyMatrix = move(MyMatrix);
//		if (Isscale)
//			MyMatrix = scaling(MyMatrix);
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
//	}
//}triangle;
//
//class Sphere {
//	GLUquadricObj* qobj = gluNewQuadric();
//	float scale;
//	Scale sc;
//	int j;
//public:
//	bool Isscale = false;
//	bool Ismove = false;
//	GLfloat vertex_buffer_data[VIR_NUM * 3];
//	Sphere() {
//		int rad = 0;
//		for (int i = 0; i < VIR_NUM * 3; ++i) {
//			if (i % 3 == 0)
//				vertex_buffer_data[i] = cos(GetRad(rad));
//			else if (i % 3 == 1)
//				vertex_buffer_data[i] = sin(GetRad(rad));
//			else
//				vertex_buffer_data[i] = sin(GetRad(rad));
//			++rad;
//		}
//	}
//	glm::mat4 scaling(glm::mat4 MyMatrix) {
//		switch (sc)
//		{
//		case SCALE_UP:
//			if (scale + 0.05f < 2.0f)
//				scale += 0.05f;
//			else
//				sc = SCALE_DOWN;
//			break;
//		case SCALE_DOWN:
//			if (scale - 0.05f > 0.2f)
//				scale -= 0.05f;
//			else
//				sc = SCALE_UP;
//			break;
//		}
//		MyMatrix = glm::scale(MyMatrix, glm::vec3(1.0f, scale, 1.0f));
//
//		return MyMatrix;
//	}
//	void draw() {
//		gluSphere(qobj, 0.1, 20, 20);
//	}
//	void active() {
//		glm::mat4 MyMatrix = glm::mat4(1.0f);
//		MyMatrix = glm::rotate(MyMatrix, glm::radians(degree), glm::vec3(0, 1, 0));
//		if (Ismove)
//			MyMatrix = move(MyMatrix);
//		if (Isscale)
//			MyMatrix = scaling(MyMatrix);
//		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
//	}
//	glm::mat4 move(glm::mat4 MyMatrix) {
//		j = (j + 3) % (VIR_NUM * 3);
//		switch (line)
//		{
//		case SINE:
//			MyMatrix = glm::translate(MyMatrix, glm::vec3(sine_line.vertex_buffer_data[j], sine_line.vertex_buffer_data[j + 1], 0.0f));
//			break;
//		case ZIGZAG:
//			MyMatrix = glm::translate(MyMatrix, glm::vec3(zigzag.vertex_buffer_data[j], zigzag.vertex_buffer_data[j + 1], 0.0f));
//			break;
//		case SPRING:
//			MyMatrix = glm::translate(MyMatrix, glm::vec3(spring.vertex_buffer_data[j], spring.vertex_buffer_data[j + 1], 0.0f));
//			break;
//		}
//		return MyMatrix;
//	}
//}sphere;
//
//int main(int argc, char** argv)
//{
//	srand((unsigned)time(NULL));
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(winWidth, winHeight);
//	glutCreateWindow("Example2");
//	glewInit();
//	Init();
//
//	glutKeyboardFunc(Keyboard);
//	glutSpecialFunc(special);
//	glutDisplayFunc(drawScene);
//	glutTimerFunc(100, TimerFunction, 1);
//	glutMouseFunc(Mouse);
//	glutReshapeFunc(Reshape);
//	glutMainLoop();
//}
//
//double GetRad(int i)
//{
//	return (double)(i * PI / 180);
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		if (shape == TRIANGLE)
//			shape = SPHERE;
//		else
//			shape = TRIANGLE;
//	}
//}
//
//void Init()
//{
//	glDepthFunc(GL_LESS);
//
//	//load and compile shaders 
//	Core::Shader_Loader shaderLoader;
//	program = shaderLoader.CreateProgram((char*)"Vertex_Shader9.vs", (char*)"Fragment_Shader9.fs");
//
//	winWidth = 800;
//	winHeight = 700;
//}
//
//GLvoid drawScene()
//{
//	glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glUseProgram(program);
//
//	//그리는 코드
//	unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//	switch (line)
//	{
//	case ZIGZAG:
//	{
//		glm::mat4 TransMat = glm::mat4(1.0f);
//		TransMat = glm::rotate(TransMat, glm::radians(degree), glm::vec3(0, 1, 0));
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &TransMat[0][0]);
//		zigzag.draw();
//	}
//		break;
//	case SINE:
//	{
//		glm::mat4 TransMat = glm::mat4(1.0f);
//		TransMat = glm::rotate(TransMat, glm::radians(degree), glm::vec3(0, 1, 0));
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &TransMat[0][0]);
//		sine_line.draw();
//	}
//		break;
//	case SPRING:
//	{
//		glm::mat4 TransMat = glm::mat4(1.0f);
//		TransMat = glm::rotate(TransMat, glm::radians(degree), glm::vec3(0, 1, 0));
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &TransMat[0][0]);
//		spring.draw();
//	}
//		break;
//	}
//	switch (shape)
//	{
//	case TRIANGLE:
//		triangle.active();
//		triangle.draw();
//		break;
//	case SPHERE:
//		sphere.active();
//		sphere.draw();
//		break;
//	}
//
//	glm::mat4 LineMat = glm::mat4(1.0f);
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &LineMat[0][0]);
//	DrawLine();
//	glutSwapBuffers();
//}
//
//void DrawLine()
//{
//	//x축
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(5.0f, 0.0f, 0.0f);
//	glVertex3f(-5.0f, 0.0f, 0.0f);
//	glEnd();
//
//	////y축
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(0.0f, 5.0f, 0.0f);
//	glVertex3f(0.0f, -5.0f, 0.0f);
//	glEnd();
//
//	//z축
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(0.0f, 0.0f, 5.0f);
//	glVertex3f(0.0f, 0.0f, -5.0f);
//	glEnd();
//}
//
//void Reshape(int w, int h)
//{
//	if (h == 0)
//		h = 1;
//	float ratio = 1.0 * w / h;
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	glViewport(0, 0, w, h);
//
//	gluPerspective(45, ratio, 1, 1000);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key) 
//	{
//	case '1':
//		line = SINE;
//		break;
//	case '2':
//		line = ZIGZAG;
//		break;
//	case '3':
//		line = SPRING;
//		break;
//	case VK_ESCAPE:
//		exit(0);
//		break;
//	case 's':
//		triangle.Isscale = !triangle.Isscale;
//		sphere.Isscale = !sphere.Isscale;
//		break;
//	case 'm':
//		triangle.Ismove = !triangle.Ismove;
//		sphere.Ismove = !sphere.Ismove;
//		break;
//	case 'r':
//		Isrotate = !Isrotate;
//		break;
//	}
//}
//
//void special(int key, int x, int y)
//{
//	switch (key)
//	{
//
//	}
//}
//
//void TimerFunction(int value)
//{
//	glutPostRedisplay();
//	if (Isrotate)
//		degree += 5.0f;
//	glutTimerFunc(100, TimerFunction, 1);
//}