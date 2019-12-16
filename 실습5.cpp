//#define PI 3.141592
//#define VIR_NUM 60
//#include <Windows.h>
//#include<iostream>
//#include<time.h>
//#include<fstream>
//#include <stdio.h>
//#include <stdlib.h> 
//#include <vector>
//#include <math.h>
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
//double GetRad(int);
//void ChangeValue(GLfloat*, int);
//
//GLuint program;
//int winWidth, winHeight;
//GLenum Mode = GL_LINE_LOOP;
//int index = 0;
//GLfloat g_vertex_buffer_data[VIR_NUM * 10]{ 0, };
//GLfloat g_color_buffer_data[VIR_NUM * 10]{};
//GLfloat Mouse_Ary[VIR_NUM];
//int None[3];
//
//int main(int argc, char** argv) // 윈도우 출력하고 콜백함수 설정
//{
//	srand((unsigned)time(NULL));
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(800, 600);
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
//void Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		//mx = (float)((x - (float)winWidth / 2.0) * (float)(1.0 / (float)(winWidth / 2.0)));
//		//my = -(float)((y - (float)winHeight / 2.0) * (float)(1.0 / (float)(winWidth / 2.0)));
//
//		float vertexPosition[VIR_NUM]{};
//		Mouse_Ary[index * 3] = x;
//		Mouse_Ary[index * 3 + 1] = y;
//		Mouse_Ary[index * 3 + 2] = 0;
//		for (int i = 0; i < VIR_NUM; ++i) {
//			if (i % 3 == 0)
//				vertexPosition[i] = (float)(((Mouse_Ary[index * 3] + Mouse_Ary[index * 3 + 2] * cos(GetRad(i * (360 / VIR_NUM)))) - (float)winWidth / 2.0) * (float)(1.0 / (float)(winWidth / 2.0)));
//			else if (i % 3 == 1)
//				vertexPosition[i] = -(float)(((Mouse_Ary[index * 3 + 1] + Mouse_Ary[index * 3 + 2] * sin(GetRad(i * (360 / VIR_NUM)))) - (float)winHeight / 2.0) * (float)(1.0 / (float)(winHeight / 2.0)));
//			else
//				vertexPosition[i] = 0;
//		}
//
//		for (int i = 0; i < VIR_NUM; ++i)
//			g_vertex_buffer_data[index * VIR_NUM + i] = vertexPosition[i];
//
//		index = (index + 1) % 10;
//	}
//}
//
//double GetRad(int i)
//{
//	return i * (PI / 180);
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
//
//	for (int i = 0; i < VIR_NUM * 10; ++i)
//		g_color_buffer_data[i] = rand() % 100 * 0.01;
//	for (int i = 2; i < VIR_NUM; i += 3)
//		Mouse_Ary[i] = rand() % 100;
//	for (int i = 0;i<3;++i)
//		None[i] = rand() % 10;
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
//	//glPolygonMode(GL_FRONT, Mode);	
//	for (int j = 0; j < 10; ++j) {
//		if(Mode == GL_LINE_LOOP)
//			glBegin(Mode);
//		else {
//			glPointSize(4);
//			glBegin(Mode);
//		}
//		for (int i = VIR_NUM * j; i < VIR_NUM * (j + 1); i = i + 3)
//			glVertex3f(g_vertex_buffer_data[i], g_vertex_buffer_data[i + 1], g_vertex_buffer_data[i + 2]);
//		glEnd();
//	}
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
//	//winWidth = w;
//	//winHeight = h;
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case '1':
//		Mode = GL_POINTS;
//		break;
//	case '2':
//		Mode = GL_LINE_LOOP;
//		break;
//	}
//}
//
//void TimerFunction(int value)
//{
//	float vertexPosition[VIR_NUM];
//	for (int j = 0; j < 10; ++j) {
//		ChangeValue(&Mouse_Ary[j * 3 + 2], j);
//		for (int i = 0; i < VIR_NUM; ++i) {
//			if (i % 3 == 0)
//				vertexPosition[i] = (float)(((Mouse_Ary[j * 3] + Mouse_Ary[j * 3 + 2] * cos(GetRad(i * (360 / VIR_NUM)))) - (float)winWidth / 2.0) * (float)(1.0 / (float)(winWidth / 2.0)));
//			else if (i % 3 == 1)
//				vertexPosition[i] = -(float)(((Mouse_Ary[j * 3 + 1] + Mouse_Ary[j * 3 + 2] * sin(GetRad(i * (360 / VIR_NUM)))) - (float)winHeight / 2.0) * (float)(1.0 / (float)(winWidth / 2.0)));
//			else
//				vertexPosition[i] = 0;
//		}
//		for (int i = 0; i < VIR_NUM; ++i)
//			g_vertex_buffer_data[j * VIR_NUM + i] = vertexPosition[i];
//	}
//
//
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}
//
//void ChangeValue(GLfloat* p, int j)
//{
//	if (j == None[0] || j == None[1] || j == None[2])
//		++p[0];
//	else if (++p[0] > 100)
//		p[0] = 0;
//}