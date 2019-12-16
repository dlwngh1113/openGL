//#define VIR_NUM 3
//#define PI 3.141592
//#include<iostream>
//#include<time.h>
//#include<vector>
//#include<glm/glm/glm.hpp>
//#include<glm/glm/gtc/matrix_transform.hpp>
//#include<glm/glm/ext.hpp>
//#include<GL/glew.h>
//#include<GL/freeglut.h>
//#include<gl/freeglut_ext.h>
//#include"Shader_Loader.h"
//#include"Quadric.h"
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
//void DrawCrane();
//glm::mat4 GetModelMat();
//glm::mat4 GetCameraMat(glm::mat4 model);
//
//GLuint program;
//int winWidth, winHeight;
//bool y_rotate;
//bool z_rotate;
//bool x_rotate;
//float y_rad;
//float z_rad;
//float x_rad;
//float z_distance = 3;
//float x_distance = 3;
//float y_distance = 3;
//float view_angle = 0;
//float t;
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
//	GLfloat color_buffer[VIR_NUM * 3 * 12] = {
//		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2],
//		color_buffer[0],color_buffer[1],color_buffer[2]
//	};
//	void draw() {
//		GLuint vertexbuffer;
//		glGenBuffers(1, &vertexbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//		GLuint colorbuffer;
//		glGenBuffers(1, &colorbuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer), color_buffer, GL_STATIC_DRAW);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//		glEnableVertexAttribArray(0);
//		glEnableVertexAttribArray(1);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		glDrawArrays(GL_TRIANGLES, 0, VIR_NUM * 12);
//		glDisableVertexAttribArray(0);
//		glDisableVertexAttribArray(1);
//	}
//	float rad = 0.0;
//}cuboid[3];
//
//enum Direction {
//	LEFT,
//	RIGHT
//}dir;
//
//Direction Adir, Bdir;
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
//	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
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
//
//	DrawCrane();
//
//	glm::mat4 LineMat = glm::mat4(1.0f);
//	LineMat = GetCameraMat(LineMat);
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &LineMat[0][0]);
//	DrawLine();
//	glutSwapBuffers();
//}
//
//glm::mat4 GetModelMat()
//{
//	glm::mat4 MyMatrix = glm::mat4(1.0f);
//	MyMatrix = glm::scale(MyMatrix, glm::vec3(0.4, 0.4, 0.4));
//	switch (dir)
//	{
//	case LEFT:
//		t -= 0.05;
//		MyMatrix = glm::translate(MyMatrix, glm::vec3(t, 0, 0));
//		if (t < -5.0)
//			dir = RIGHT;
//		break;
//	case RIGHT:
//		t += 0.05;
//		MyMatrix = glm::translate(MyMatrix, glm::vec3(t, 0, 0));
//		if (t > 5.0)
//			dir = LEFT;
//		break;
//	}
//
//	return MyMatrix;
//}
//
//glm::mat4 GetCameraMat(glm::mat4 model)
//{
//	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)winWidth / (float)winHeight, 0.1f, 100.0f);
//	glm::mat4 View = glm::lookAt(
//		glm::vec3(y_distance * sin(view_angle) + x_distance, 3.f, y_distance * cos(view_angle) + z_distance), // 카메라는 (4,3,3) 에 있다. 월드 좌표에서
//		glm::vec3(0, 0, 0), // 그리고 카메라가 원점을 본다
//		glm::vec3(0, 1.f, 0)  // 머리가 위쪽이다 (0,-1,0 으로 해보면, 뒤집어 볼것이다)
//	);
//	View = glm::rotate(View, glm::radians(y_distance), glm::vec3(0, 1, 0));
//
//	return Projection * View * model;
//}
//
//void DrawCrane()
//{
//	unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//
//	glm::mat4 MyMatrix = GetModelMat();
//	if(y_rotate)
//		MyMatrix = glm::rotate(MyMatrix, glm::radians(y_rad), glm::vec3(0, 1, 0));
//	MyMatrix = GetCameraMat(MyMatrix);
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
//	cuboid[0].draw();
//	MyMatrix = GetModelMat();
//	if (y_rotate)
//		MyMatrix = glm::rotate(MyMatrix, glm::radians(y_rad), glm::vec3(0, 1, 0));
//
//	MyMatrix = glm::scale(MyMatrix, glm::vec3(0.7, 0.5, 0.7));
//	MyMatrix = glm::translate(MyMatrix, glm::vec3(0, 2.5, 0.0));
//	if (x_rotate) {
//		switch (Adir)
//		{
//		case LEFT:
//			x_rad -= 10;
//			MyMatrix = glm::rotate(MyMatrix, (float)glm::radians(x_rad), glm::vec3(1, 0, 0));
//			if (x_rad < -90)
//				Adir = RIGHT;
//			break;
//		case RIGHT:
//			x_rad += 10;
//			MyMatrix = glm::rotate(MyMatrix, (float)glm::radians(x_rad), glm::vec3(1, 0, 0));
//			if (x_rad > 90)
//				Adir = LEFT;
//			break;
//		}
//	}
//	MyMatrix = GetCameraMat(MyMatrix);
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
//	cuboid[1].draw();
//	MyMatrix = GetModelMat();
//	MyMatrix = GetModelMat();
//	if (y_rotate)
//		MyMatrix = glm::rotate(MyMatrix, glm::radians(y_rad), glm::vec3(0, 1, 0));
//
//	MyMatrix = glm::scale(MyMatrix, glm::vec3(0.7, 0.5, 0.7));
//	MyMatrix = glm::translate(MyMatrix, glm::vec3(0, 2.5, 0.0));
//	if (x_rotate) {
//		switch (Adir)
//		{
//		case LEFT:
//			x_rad -= 10;
//			MyMatrix = glm::rotate(MyMatrix, (float)glm::radians(x_rad), glm::vec3(1, 0, 0));
//			if (x_rad < -90)
//				Adir = RIGHT;
//			break;
//		case RIGHT:
//			x_rad += 10;
//			MyMatrix = glm::rotate(MyMatrix, (float)glm::radians(x_rad), glm::vec3(1, 0, 0));
//			if (x_rad > 90)
//				Adir = LEFT;
//			break;
//		}
//	}
//
//	MyMatrix = glm::scale(MyMatrix, glm::vec3(0.5, 1, 0.5));
//	MyMatrix = glm::translate(MyMatrix, glm::vec3(0, 2.5, 0.0));
//	if (z_rotate) {
//		switch (Bdir)
//		{
//		case LEFT:
//			z_rad -= 10;
//			MyMatrix = glm::rotate(MyMatrix, (float)glm::radians(z_rad), glm::vec3(0, 0, 1));
//			if (z_rad < -90)
//				Bdir = RIGHT;
//			break;
//		case RIGHT:
//			z_rad += 10;
//			MyMatrix = glm::rotate(MyMatrix, (float)glm::radians(z_rad), glm::vec3(0, 0, 1));
//			if (z_rad > 90)
//				Bdir = LEFT;
//			break;
//		}
//	}
//	MyMatrix = GetCameraMat(MyMatrix);
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
//	cuboid[2].draw();
//}
//
//void DrawLine()
//{
//	glBegin(GL_LINE_STRIP);
//	glVertex3f(3, 0, 3);
//	glVertex3f(3, 0, -3);
//	glVertex3f(-3, 0, -3);
//	glVertex3f(-3, 0, 3);
//	glVertex3f(3, 0, 3);
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
//	winWidth = glutGet(GLUT_WINDOW_WIDTH);
//	winHeight = glutGet(GLUT_WINDOW_HEIGHT);
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
//	case 'q':
//		exit(0);
//		break;
//	case 'm':
//		x_rotate = true;
//		break;
//	case 't':
//		z_rotate = true;
//		break;
//	case 'b':
//		y_rotate = true;
//		break;
//	case 's':
//		y_rotate = false;
//		z_rotate = false;
//		x_rotate = false;
//		break;
//	case 'c':
//		x_rad = y_rad = z_rad = 0;
//		break;
//	case 'z':
//		z_distance += 1.0;
//		break;
//	case 'Z':
//		z_distance -= 1.0;
//		break;
//	case 'x':
//		x_distance -= 1.0;
//		break;
//	case 'X':
//		x_distance += 1.0;
//		break;
//	case 'r':
//		if (++view_angle > 360);
//		break;
//	}
//}
//
//void special(int key, int x, int y)
//{
//	switch (key)
//	{
//	}
//}
//
//void TimerFunction(int value)
//{
//	glutPostRedisplay();
//	if (y_rotate)
//		y_rad += 10;
//	if (z_rotate)
//		z_rotate += 10;
//	if (x_rotate)
//		x_rotate += 10;
//	glutTimerFunc(100, TimerFunction, 1);
//}