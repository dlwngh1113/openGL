//#define VIR_NUM 3
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
//void DrawLine();
//
//GLuint program;
//int winWidth, winHeight;
//GLUquadricObj* qobj;
//GLenum Mode;
//BOOL Rotate;
//BOOL culling;
//
//enum Shape{
//	RECTANGLE,
//	TRIANGLE
//}shape;
//
//class Cuboid {
//public:
//	const GLfloat g_vertex_buffer_data[VIR_NUM * 3 * 12] = {
//	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
//	-1.0f,-1.0f, 1.0f,
//	-1.0f, 1.0f, 1.0f, // triangle 1 : end
//
//	1.0f, 1.0f,-1.0f, // triangle 2 : begin
//	-1.0f,-1.0f,-1.0f,
//	-1.0f, 1.0f,-1.0f, // triangle 2 : end
//
//	1.0f,-1.0f, 1.0f,
//	-1.0f,-1.0f,-1.0f,
//	1.0f,-1.0f,-1.0f,
//
//	1.0f, 1.0f,-1.0f,
//	1.0f,-1.0f,-1.0f,
//	-1.0f,-1.0f,-1.0f,
//
//	-1.0f,-1.0f,-1.0f,
//	-1.0f, 1.0f, 1.0f,
//	-1.0f, 1.0f,-1.0f,
//
//	1.0f,-1.0f, 1.0f,
//	-1.0f,-1.0f, 1.0f,
//	-1.0f,-1.0f,-1.0f,
//
//	-1.0f, 1.0f, 1.0f,
//	-1.0f,-1.0f, 1.0f,
//	1.0f,-1.0f, 1.0f,
//
//	1.0f, 1.0f, 1.0f,
//	1.0f,-1.0f,-1.0f,
//	1.0f, 1.0f,-1.0f,
//
//	1.0f,-1.0f,-1.0f,
//	1.0f, 1.0f, 1.0f,
//	1.0f,-1.0f, 1.0f,
//
//	1.0f, 1.0f, 1.0f,
//	1.0f, 1.0f,-1.0f,
//	-1.0f, 1.0f,-1.0f,
//
//	1.0f, 1.0f, 1.0f,
//	-1.0f, 1.0f,-1.0f,
//	-1.0f, 1.0f, 1.0f,
//
//	1.0f, 1.0f, 1.0f,
//	-1.0f, 1.0f, 1.0f,
//	1.0f,-1.0f, 1.0f
//	};
//	GLfloat colorbuffer[VIR_NUM * 3 * 12] = {
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//1
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//2
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//3
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//4
//		
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//5
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//6
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//7
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//8
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//9
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//10
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//11
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f//12
//	};
//	float rad = 30.0;
//}cuboid;
//
//class Facade {
//public:
//	const GLfloat g_vertex_buffer_data[VIR_NUM * 3 * 6] = {
//		0.0f, 1.0f, 0.0f,// { Front }
//		-1.0f,-1.0f, 1.0f, // { Front }
//		1.0f,-1.0f, 1.0f,// { Front }
//
//		0.0f, 1.0f, 0.0f,// { Right }
//		1.0f,-1.0f, 1.0f,// { Right }
//		1.0f,-1.0f,-1.0f,// { Right }
//
//		0.0f, 1.0f, 0.0f,// { Back }
//		1.0f,-1.0f,-1.0f,// { Back }
//		-1.0f,-1.0f,-1.0f, // { Back }
//
//		0.0f, 1.0f, 0.0f,// { Left }
//		-1.0f,-1.0f,-1.0f, // { Left }
//		-1.0f,-1.0f, 1.0f, // { Left }
//
//		-1.0f, -1.0f, 1.0f,
//		-1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, 1.0f, //{ bottom }
//
//		-1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, 1.0f//{ bottom }
//	};
//	const GLfloat g_color_buffer_data[VIR_NUM * 3 * 6] = {
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//1
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//2
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//3
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//4
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//5
//
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//6
//	};
//	float rad = 30.0;
//}facade;
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
//	glutDisplayFunc(drawScene);
//	glutTimerFunc(100, TimerFunction, 1);
//	glutMouseFunc(Mouse);
//	glutReshapeFunc(Reshape);
//	glutMainLoop();
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//}
//
//void Init()
//{
//	glEnable(GL_DEPTH_TEST);
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
//	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	if (culling) {
//		glEnable(GL_CULL_FACE);
//		glFrontFace(GL_CCW);
//		glCullFace(GL_BACK);
//	}
//	else
//		glDisable(GL_CULL_FACE);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glUseProgram(program);
//
//	switch (shape) {
//	case RECTANGLE:
//	{
//		glm::mat4 transformMat = glm::mat4(1.0f);
//		transformMat = glm::scale(transformMat, glm::vec3(0.3f, 0.3f, 0.3f));
//		transformMat = glm::rotate(transformMat, (GLfloat)glm::radians(-30.0), glm::vec3(1.0, 0.0, 0.0));
//		transformMat = glm::rotate(transformMat, (GLfloat)glm::radians(cuboid.rad), glm::vec3(0.0, 1.0, 0.0));
//
//		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &transformMat[0][0]); //--- modelTransform 변수에 변환 값 적용하기
//
//		GLuint vertexbuffer;
//		glGenBuffers(1, &vertexbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(cuboid.g_vertex_buffer_data), cuboid.g_vertex_buffer_data, GL_STATIC_DRAW);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//		GLuint colorbuffer;
//		glGenBuffers(1, &colorbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(cuboid.colorbuffer), cuboid.colorbuffer, GL_STATIC_DRAW);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//		glEnableVertexAttribArray(0);
//		glEnableVertexAttribArray(1);
//		glPolygonMode(GL_FRONT_AND_BACK, Mode);
//		glDrawArrays(GL_TRIANGLES, 0, VIR_NUM * 12);
//		glDisableVertexAttribArray(0);
//		glDisableVertexAttribArray(1);
//	}
//		break;
//	case TRIANGLE:
//	{
//		glm::mat4 transformMat = glm::mat4(1.0f);
//		transformMat = glm::scale(transformMat, glm::vec3(0.3f, 0.3f, 0.3f));
//		transformMat = glm::rotate(transformMat, (GLfloat)glm::radians(-30.0), glm::vec3(1.0, 0.0, 0.0));
//		transformMat = glm::rotate(transformMat, (GLfloat)glm::radians(facade.rad), glm::vec3(0.0, 1.0, 0.0));
//
//		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &transformMat[0][0]); //--- modelTransform 변수에 변환 값 적용하기
//
//		GLuint vertexbuffer;
//		glGenBuffers(1, &vertexbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(facade.g_vertex_buffer_data), facade.g_vertex_buffer_data, GL_STATIC_DRAW);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//		GLuint colorbuffer;
//		glGenBuffers(1, &colorbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(facade.g_color_buffer_data), facade.g_color_buffer_data, GL_STATIC_DRAW);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//		glEnableVertexAttribArray(0);
//		glEnableVertexAttribArray(1);
//		glPolygonMode(GL_FRONT_AND_BACK, Mode);
//		glDrawArrays(GL_TRIANGLES, 0, VIR_NUM * 3 * 12);
//		glDisableVertexAttribArray(0);
//		glDisableVertexAttribArray(1);
//	}
//		break;
//	}
//
//	glm::mat4 transformMat = glm::mat4(1.0f);
//	unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &transformMat[0][0]);
//
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
//	switch (key) {
//	case VK_ESCAPE:
//		exit(0);
//		break;
//	case 'w':
//		if (Mode == GL_LINE)
//			Mode = GL_FILL;
//		else
//			Mode = GL_LINE;
//		break;
//	case 'y':
//		Rotate = !Rotate;
//		break;
//	case 'h':
//		culling = !culling;
//		break;
//	case 'c':
//		shape = RECTANGLE;
//		break;
//	case 'p':
//		shape = TRIANGLE;
//		break;
//	}
//	return;
//}
//
//void TimerFunction(int value)
//{
//	glutPostRedisplay();
//	if (Rotate) {
//		cuboid.rad += 10.0;
//		facade.rad += 10.0;
//	}
//	glutTimerFunc(100, TimerFunction, 1);
//}