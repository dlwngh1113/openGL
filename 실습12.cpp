//#define VIR_NUM 3
//#define PI 3.141592
//#include <Windows.h>
//#include<iostream>
//#include<time.h>
//#include <stdlib.h> 
//#include <vector>
//#include <math.h>
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
//float Allrad;
//bool allRotate;
//enum Shape {
//	CYLINDER,
//	DISK,
//	CIRCLE,
//	NORMAL
//};
//
//class Cuboid {
//	GLUquadricObj* qobj = gluNewQuadric();
//public:
//	const GLfloat vertex_buffer_data[VIR_NUM * 3 * 12] = {
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
//	GLfloat color_buffer_data[VIR_NUM * 3 * 12] = {
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
//	bool Isrotate = false;
//	Shape shape = NORMAL;
//	void draw() {
//		glm::mat4 MyMatrix = glm::mat4(1.0f);
//		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//		if (allRotate)
//			MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(Allrad), glm::vec3(0, 1, 0));
//		MyMatrix = glm::scale(MyMatrix, glm::vec3(0.3, 0.3, 0.3));
//		MyMatrix = glm::translate(MyMatrix, glm::vec3(-1.5, 0, 0));
//		MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(rad), glm::vec3(1, 0, 0));
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
//
//		switch (shape)
//		{
//		case CYLINDER:
//			gluCylinder(qobj, 1.0, 1.0, 2.0, 8, 8);
//			break;
//		case DISK:
//			gluDisk(qobj, 0.5, 2.0, 20, 3);
//			break;
//		case CIRCLE:
//			gluSphere(qobj, 1.5, 50, 50);
//			break;
//		case NORMAL:
//		{
//			GLuint vertexbuffer;
//			glGenBuffers(1, &vertexbuffer);
//			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
//			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//			GLuint colorbuffer;
//			glGenBuffers(1, &colorbuffer);
//			glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//			glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);
//			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//			glEnableVertexAttribArray(0);
//			glEnableVertexAttribArray(1);
//			glPolygonMode(GL_FRONT, GL_FILL);
//			glDrawArrays(GL_TRIANGLES, 0, VIR_NUM * 3 * 12);
//			glDisableVertexAttribArray(0);
//			glDisableVertexAttribArray(1);
//		}
//			break;
//		}
//	}
//}cuboid;
//
//class Facade {
//	GLUquadricObj* qobj = gluNewQuadric();
//public:
//	const GLfloat vertex_buffer_data[VIR_NUM * 3 * 6] = {
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
//	const GLfloat color_buffer_data[VIR_NUM * 3 * 6] = {
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
//	float rad = 10;
//	bool Isrotate = false;
//	Shape shape = NORMAL;
//	void draw() {
//		glm::mat4 MyMatrix = glm::mat4(1.0f);
//		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//		if (allRotate)
//			MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(Allrad), glm::vec3(0, 1, 0));
//		MyMatrix = glm::scale(MyMatrix, glm::vec3(0.3, 0.3, 0.3));
//		MyMatrix = glm::translate(MyMatrix, glm::vec3(1.5, 0, 0));
//		MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(rad), glm::vec3(0, 1, 0));
//		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
//
//		switch (shape)
//		{
//		case CYLINDER:
//			gluCylinder(qobj, 1.0, 1.0, 2.0, 8, 8);
//			break;
//		case DISK:
//			gluDisk(qobj, 0.5, 2.0, 20, 3);
//			break;
//		case CIRCLE:
//			gluSphere(qobj, 1.5, 50, 50);
//			break;
//		case NORMAL:
//		{
//			GLuint vertexbuffer;
//			glGenBuffers(1, &vertexbuffer);
//			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
//			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//			GLuint colorbuffer;
//			glGenBuffers(1, &colorbuffer);
//			glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//			glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);
//			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//			glEnableVertexAttribArray(0);
//			glEnableVertexAttribArray(1);
//			glPolygonMode(GL_FRONT, GL_FILL);
//			glDrawArrays(GL_TRIANGLES, 0, VIR_NUM * 3 * 6);
//			glDisableVertexAttribArray(0);
//			glDisableVertexAttribArray(1);
//		}
//			break;
//		}
//	}
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
//	glEnable(GL_CULL_FACE);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glUseProgram(program);
//
//	//그리는 코드	
//	//glm::mat4 RotateMat = glm::mat4(1.0f);
//	unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//	//RotateMat = glm::rotate(RotateMat, (GLfloat)glm::radians(Allrad), glm::vec3(0, 1, 0));
//	//glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &RotateMat[0][0]);
//	facade.draw();
//	cuboid.draw();
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
//	case VK_ESCAPE:
//		exit(0);
//		break;
//	case 'x':
//		cuboid.Isrotate = true;
//		break;
//	case 'y':
//		facade.Isrotate = true;
//		break;
//	case 's':
//		cuboid.Isrotate = false;
//		facade.Isrotate = false;
//		allRotate = false;
//		break;
//	case 'b':
//		allRotate = true;
//		break;
//	case 'c':
//		cuboid.shape = (enum Shape)(rand() % NORMAL);
//		facade.shape = (enum Shape)(rand() % NORMAL);
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
//	if (cuboid.Isrotate)
//		cuboid.rad += 5.0f;
//	if (facade.Isrotate)
//		facade.rad += 5.0f;
//	if (allRotate)
//		Allrad += 5.0;
//	glutTimerFunc(100, TimerFunction, 1);
//}