//#include <Windows.h>
//#include<iostream>
//#include<time.h>
//#include<fstream>
//#include <stdio.h>
//#include <stdlib.h> 
//#include <vector>
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
//
//GLuint program;
//float mx, my;
//int winWidth, winHeight;
//
//int index;
//
//GLfloat g_vertex_buffer_data[3 * 3 * 4]{ 0, };
//GLfloat g_color_buffer_data[4 * 3 * 4]{};
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
//	for (int i = 0; i < 48; ++i) {
//		g_color_buffer_data[i] = rand() % 100 * 0.01;
//	}
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
//		std::cout << program << std::endl;
//		mx = (float)((x - (float)winWidth / 2.0) * (float)(1.0 / (float)(winWidth / 2.0)));
//		my = -(float)((y - (float)winHeight / 2.0) * (float)(1.0 / (float)(winWidth / 2.0)));
//
//		std::cout << mx << ", " << my << std::endl;
//
//		const float vertexPosition[] = {
//			mx - 0.1, my - 0.1, 0.0,
//			mx + 0.1, my - 0.1, 0.0,
//			mx, my + 0.1, 0.0
//		};
//
//		for (int i = 0; i < 9; ++i)
//			g_vertex_buffer_data[index * 9 + i] = vertexPosition[i];
//
//		index = (index + 1) % 4;
//	}
//}
//
//void Init()
//{
//	glEnable(GL_DEPTH_TEST);
//
//	//load and compile shaders 
//	Core::Shader_Loader shaderLoader;
//	program = shaderLoader.CreateProgram((char*)"Vertex_Shader3.vs", (char*)"Fragment_Shader3.fs");
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//}
//
//GLvoid drawScene()
//{
//	glClearColor(0.0, 0.5, 1.0, 1.0);
// 
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
//	// 삼각형 그리기!
//	glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//	glDrawArrays(GL_TRIANGLES, 0, 12); // 버텍스 0에서 시작해서; 총 3개의 버텍스로 -> 하나의 삼각형
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
//	gluPerspective(45, ratio, 1, 100);
//	glMatrixMode(GL_MODELVIEW);
//	winWidth = w;
//	winHeight = h;
//}
//
//void TimerFunction(int value)
//{
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}