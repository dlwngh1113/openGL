//#define VIR_NUM 9
//#define PI 3.141592
//#include <Windows.h>
//#include<iostream>
//#include<time.h>
//#include<fstream>
//#include <stdio.h>
//#include <stdlib.h> 
//#include <vector>
//#include <math.h>
//#include<glm/glm/glm.hpp>
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
//void InsertData();
//double GetRad(int);
//bool PtInRect(GLfloat, GLfloat);
//
//GLuint program;
//int winWidth = 800, winHeight = 600;
//RECT rt = { 280, 210, 510, 400 };
//
//GLfloat g_vertex_buffer_data[VIR_NUM * 10]{ 0, };
//GLfloat g_color_buffer_data[VIR_NUM * 10]{ 0, };
//
//enum Direction {
//	TOLEFTDOWN,
//	TORIGHTDOWN,
//	TORIGHTUP,
//	TOLEFTUP
//};
//
//class Triangle {
//	GLfloat velocity;
//	Direction direction;
//	GLfloat vertex[VIR_NUM] = {
//		(GLfloat)(rand() % winWidth) * 0.001f, (GLfloat)(rand() % winHeight) * 0.001f, 0.0,
//		vertex[0] + 0.2f * (GLfloat)cos(GetRad(120)), vertex[1] + 0.2f * (GLfloat)sin(GetRad(120)), 0.0,
//		vertex[0] + 0.1f * (GLfloat)cos(GetRad(180)), vertex[1] + 0.1f * (GLfloat)sin(GetRad(180)), 0.0
//	};
//	GLfloat color[VIR_NUM];
//public:
//	Triangle() {
//		velocity = (GLfloat)(rand() % 7) * 0.01f + 0.01f;
//		//get random enum value
//		direction = static_cast<Direction>(rand() % TOLEFTUP);
//		for (int i = 0; i < VIR_NUM; ++i) {
//			color[i] = rand() % 100 * 0.01;
//		}
//	}
//	GLfloat GetVertex(int i) {
//		return vertex[i];
//	}
//	GLfloat GetColor(int i) {
//		return color[i];
//	}
//	void Difupdate() {
//		switch (direction)
//		{
//		case TOLEFTDOWN:
//			if (!PtInRect(vertex[0], vertex[1])) {
//				GLfloat tmp[VIR_NUM] = {
//					-0.3f, vertex[1], 0.0f,
//					-0.3f, vertex[1] - 0.1f, 0.0f,
//					-0.2f, vertex[1] - 0.05f, 0.0f
//				};
//				for (int i = 0; i < VIR_NUM; ++i)
//					vertex[i] = tmp[i];
//				direction = TORIGHTDOWN;
//			}
//			break;
//		case TORIGHTDOWN:
//			if (!PtInRect(vertex[0], vertex[1])) {
//				GLfloat tmp[VIR_NUM] = {
//					vertex[0], -0.3f,0.0f,
//					vertex[0] + 0.1f, -0.3f,0.0f,
//					vertex[0] + 0.05f, -0.2f, 0.0f
//				};
//				for (int i = 0; i < VIR_NUM; ++i)
//					vertex[i] = tmp[i];
//				direction = TORIGHTUP;
//			}
//			break;
//		case TORIGHTUP:
//			if (!PtInRect(vertex[0], vertex[1])) {
//				GLfloat tmp[VIR_NUM] = {
//					-0.3f, vertex[1], 0.0f,
//					-0.3f, vertex[1] - 0.1f, 0.0f,
//					-0.2f, vertex[1] - 0.05f, 0.0f
//				};
//				for (int i = 0; i < VIR_NUM; ++i)
//					vertex[i] = tmp[i];
//				direction = TOLEFTUP;
//			}
//			break;
//		case TOLEFTUP:
//			if (!PtInRect(vertex[0], vertex[1])) {
//				GLfloat tmp[VIR_NUM] = {
//					-0.3f, vertex[1], 0.0f,
//					-0.3f, vertex[1] - 0.1f, 0.0f,
//					-0.2f, vertex[1] - 0.05f, 0.0f
//				};
//				for (int i = 0; i < VIR_NUM; ++i)
//					vertex[i] = tmp[i];
//				direction = TOLEFTDOWN;
//			}
//			break;
//		}
//	}
//	void update() {
//		switch (direction)
//		{
//		case TOLEFTDOWN:
//			for (int i = 0; i < VIR_NUM; ++i) {
//				if (i % 3 != 2) {
//					vertex[i] -= velocity;
//					if (i % 3 == 0 && vertex[i] < -1.0f) {
//						reset();
//						direction = TORIGHTDOWN;
//					}
//					else if (PtInRect(vertex[0], vertex[1])) {
//						direction = TOLEFTUP;
//						vertex[1] += 0.01;
//						vertex[4] += 0.01;
//						vertex[7] += 0.01;
//					}
//				}
//			}
//			break;
//		case TORIGHTDOWN:
//			for (int i = 0; i < VIR_NUM; ++i) {
//				if (i % 3 == 0)
//					vertex[i] += velocity;
//				else if (i % 3 == 1) {
//					vertex[i] -= velocity;
//					if (vertex[i] < -1.0f) {
//						reset();
//						direction = TORIGHTUP;
//					}
//					else if (PtInRect(vertex[0], vertex[1])) {
//						direction = TORIGHTUP;
//						vertex[1] += 0.01;
//						vertex[4] += 0.01;
//						vertex[7] += 0.01;
//					}
//				}
//			}
//			break;
//		case TORIGHTUP:
//			for (int i = 0; i < VIR_NUM; ++i) {
//				if (i % 3 != 2) {
//					vertex[i] += velocity;
//					if ((i % 3 == 0 && vertex[i] > 1.0f)) {
//						reset();
//						direction = TOLEFTUP;
//					}
//					else if (PtInRect(vertex[0], vertex[1])) {
//						direction = TORIGHTDOWN;
//						vertex[1] -= 0.01;
//						vertex[4] -= 0.01;
//						vertex[7] -= 0.01;
//					}
//				}
//			}
//			break;
//		case TOLEFTUP:
//			for (int i = 0; i < VIR_NUM; ++i) {
//				if (i % 3 == 0)
//					vertex[i] -= velocity;
//				else if (i % 3 == 1) {
//					vertex[i] += velocity;
//					if (vertex[i] > 1.0f) {
//						reset();
//						direction = TOLEFTDOWN;
//					}
//					else if (PtInRect(vertex[0], vertex[1])) {
//						direction = TOLEFTDOWN;
//						vertex[1] -= 0.01;
//						vertex[4] -= 0.01;
//						vertex[7] -= 0.01;
//					}
//				}
//			}
//			break;
//		}
//	}
//	void reset() {
//		switch (direction)
//		{
//		case TOLEFTDOWN:
//		{
//			GLfloat tmp[VIR_NUM] = {
//				//-0.7f, (vertex[1] + vertex[4] + vertex[7]) / 3.0f + 0.05, 0.0f,
//				//-0.9f, (vertex[1] + vertex[4] + vertex[7]) / 3.0f + 0.1f, 0.0f,
//				//-0.9f, (vertex[1] + vertex[4] + vertex[7]) / 3.0f - 0.1f, 0.0f
//				-0.9f, vertex[1], 0.0f,
//				tmp[0] + 0.1f * (GLfloat)cos(GetRad(270)), tmp[1] + 0.1f * (GLfloat)sin(GetRad(270)), 0.0f,
//				tmp[0] + 0.2f * (GLfloat)cos(GetRad(330)), tmp[1] + 0.2f * (GLfloat)sin(GetRad(330)), 0.0f
//			};
//			for (int i = 0; i < VIR_NUM; ++i)
//				vertex[i] = tmp[i];
//		}
//		break;
//		case TORIGHTDOWN:
//		{
//			GLfloat tmp[VIR_NUM] = {
//				vertex[0], -0.9f, 0.0f,
//				tmp[0] + 0.1f * (GLfloat)cos(GetRad(0)), tmp[1] + 0.1f * (GLfloat)sin(GetRad(0)), 0.0f,
//				tmp[0] + 0.2f * (GLfloat)cos(GetRad(80)), tmp[1] + 0.2f * (GLfloat)sin(GetRad(80)), 0.0f
//			};
//			for (int i = 0; i < VIR_NUM; ++i)
//				vertex[i] = tmp[i];
//		}
//		break;
//		case TORIGHTUP:
//		{
//			GLfloat tmp[VIR_NUM] = {
//				0.9f, vertex[1] - 0.1f, 0.0f,
//				tmp[0] + 0.1f * (GLfloat)cos(GetRad(90)), tmp[1] + 0.1f * (GLfloat)sin(GetRad(90)), 0.0f,
//				tmp[0] + 0.2f * (GLfloat)cos(GetRad(160)), tmp[1] + 0.2f * (GLfloat)sin(GetRad(160)), 0.0f
//			};
//			for (int i = 0; i < VIR_NUM; ++i)
//				vertex[i] = tmp[i];
//		}
//		break;
//		case TOLEFTUP:
//		{
//			GLfloat tmp[VIR_NUM] = {
//				vertex[0], 0.9f, 0.0f,
//				tmp[0] + 0.1f * (GLfloat)cos(GetRad(180)), tmp[1] + 0.1f * (GLfloat)sin(GetRad(180)), 0.0f,
//				tmp[0] + 0.2f * (GLfloat)cos(GetRad(260)), tmp[1] + 0.2f * (GLfloat)sin(GetRad(260)), 0.0f
//			};
//			for (int i = 0; i < VIR_NUM; ++i)
//				vertex[i] = tmp[i];
//		}
//		break;
//		}
//	}
//}Triangles[10];
//
//int main(int argc, char** argv) // 윈도우 출력하고 콜백함수 설정
//{
//	srand((unsigned)time(NULL));
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(winWidth, winHeight);
//	glutCreateWindow("Example2");
//	glewInit();
//	Init();
//
//	glutKeyboardFunc(Keyboard);
//	glutDisplayFunc(drawScene);
//	glutTimerFunc(100, TimerFunction, 1);
//	glutMouseFunc(Mouse);
//	glutReshapeFunc(Reshape);
//	glutMainLoop();
//}
//
//double GetRad(int i)
//{
//	return (double)(i * (PI / 180));
//}
//
//bool PtInRect(GLfloat x, GLfloat y)
//{
//	bool tmp = false;
//	if (-0.3f < x && x < 0.3f)
//		tmp = true;
//	if (tmp)
//		if (-0.3f < y && y < 0.3f)
//			tmp = true;
//	return tmp;
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//		std::cout << x << " " << y << std::endl;
//}
//
//void Init()
//{
//	glEnable(GL_DEPTH_TEST);
//
//	//load and compile shaders 
//	Core::Shader_Loader shaderLoader;
//	program = shaderLoader.CreateProgram((char*)"Vertex_Shader5.vs", (char*)"Fragment_Shader5.fs");
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	InsertData();
//
//	winWidth = 800;
//	winHeight = 600;
//}
//
//GLvoid drawScene()
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//
//	//clear red 
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	//use the created program 
//	glUseProgram(program);
//
//	GLuint vertexbuffer;
//	glGenBuffers(1, &vertexbuffer);
//	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//	GLuint colorbuffer;
//	glGenBuffers(1, &colorbuffer);
//	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//	//원 그리기!
//	glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//
//	glBegin(GL_QUADS);
//	glVertex2f(-0.3f, 0.3f);
//	glVertex2f(-0.3f, -0.3f);
//	glVertex2f(0.3f, -0.3f);
//	glVertex2f(0.3f, 0.3f);
//	glEnd();
//	glDrawArrays(GL_TRIANGLES, 0, 3 * 10);
//
//	glDisableVertexAttribArray(0);
//	glDisableVertexAttribArray(1);
//
//	glutSwapBuffers();
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
//	return;
//}
//
//void TimerFunction(int value)
//{
//	for (int i = 0; i < 8; ++i)
//		Triangles[i].update();
//	for (int i = 8; i < 10; ++i)
//		Triangles[i].Difupdate();
//	InsertData();
//
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}
//
//void InsertData()
//{
//	for (int j = 0; j < 10; ++j) {
//		for (int i = 0; i < VIR_NUM; ++i) {
//			g_vertex_buffer_data[j * VIR_NUM + i] = Triangles[j].GetVertex(i);
//			g_color_buffer_data[j * VIR_NUM + i] = Triangles[j].GetColor(i);
//		}
//	}
//}