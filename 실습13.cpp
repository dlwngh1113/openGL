//#define PI 3.141592
//#include<iostream>
//#include<time.h>
//#include <math.h>
//#include<glm/glm/glm.hpp>
//#include<glm/glm/gtc/matrix_transform.hpp>
//#include<glm/glm/ext.hpp>
//#include<GL/glew.h>
//#include<GL/freeglut.h>
//#include<gl/freeglut_ext.h>
//#include"Shader_Loader.h"
//#include"Sphere.h"
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
//Sphere spheres[7];
//GLUquadricObj* line;
//float allrad;
//bool all_rotate;
//float first_angle = 45, second_angle = 45;
//float moon_angle = 0;
//GLenum Mode;
//float z_distance = 3;
//float y_distance;
//float x_distance;
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
//	program = shaderLoader.CreateProgram((char*)"Vertex_Shader1.vs", (char*)"Fragment_Shader1.fs");
//
//	Mode = GL_LINE;
//	line = gluNewQuadric();
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
//	gluQuadricDrawStyle(line, GLU_LINE);
//
//	//그리는 코드	
//	unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
//	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)winWidth / (float)winHeight, 0.1f, 100.0f);
//	glm::mat4 View = glm::lookAt(
//				glm::vec3(4, 3, z_distance), // 카메라는 (4,3,3) 에 있다. 월드 좌표에서
//				glm::vec3(x_distance, y_distance, 0), // 그리고 카메라가 원점을 본다
//				glm::vec3(0, 1.f, 0)  // 머리가 위쪽이다 (0,-1,0 으로 해보면, 뒤집어 볼것이다)
//			);
//	glm::mat4 tmp = glm::mat4(1.f);
//	glm::mat4 MyMatrix = glm::mat4(1.0f);
//	glm::mat4 secondMat = glm::mat4(1.0f);
//	glm::mat4 thirdMat = glm::mat4(1.0f);
//	glm::mat4 rotateMat = glm::mat4(1.f);
//	rotateMat = glm::rotate(rotateMat, glm::radians(90.f), glm::vec3(1, 0, 0));
//
//
//	if(all_rotate)
//		MyMatrix = glm::rotate(MyMatrix, glm::radians(allrad), glm::vec3(0, 1, 0));
//	MyMatrix = glm::scale(MyMatrix, glm::vec3(0.5, 0.5, 0.5));
//	tmp = Projection * View * MyMatrix;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	spheres[0].draw(Mode);	//태양
//
//	tmp = Projection * View * rotateMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	gluDisk(line, 2.6, 2.7, 20, 1);
//
//	rotateMat = glm::rotate(rotateMat, glm::radians(45.f), glm::vec3(1, 1, 0));
//	tmp = Projection * View * rotateMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	gluDisk(line, 2.6, 2.7, 20, 1);
//
//	rotateMat = glm::rotate(rotateMat, glm::radians(90.f), glm::vec3(1, 1, 0));
//	tmp = Projection * View * rotateMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	gluDisk(line, 2.6, 2.7, 20, 1);
//
//	MyMatrix = glm::rotate(MyMatrix, glm::radians(allrad), glm::vec3(0, 1, 0));
//	MyMatrix = glm::translate(MyMatrix, glm::vec3(5.0, 0, 0));
//	tmp = Projection * View * MyMatrix;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	spheres[1].draw(Mode);	//직선
//
//	tmp = Projection * View * MyMatrix * rotateMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	gluDisk(line, 1.0, 1.1, 20, 1);
//
//	MyMatrix = glm::rotate(MyMatrix, glm::radians(moon_angle), glm::vec3(0, 1, 0));
//	MyMatrix = glm::translate(MyMatrix, glm::vec3(1.0, 0, 0));
//	MyMatrix = glm::scale(MyMatrix, glm::vec3(0.5, 0.5, 0.5));
//	tmp = Projection * View * MyMatrix;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	spheres[2].draw(Mode);	//직선 달
//
//	if (all_rotate)
//		secondMat = glm::rotate(secondMat, glm::radians(45.f), glm::vec3(1, 1, 0));
//	secondMat = glm::rotate(secondMat, glm::radians(allrad), glm::vec3(1, 1, 0));
//	secondMat = glm::scale(secondMat, glm::vec3(0.5, 0.5, 0.5));
//	secondMat = glm::translate(secondMat, glm::vec3(-5.0, 5.0, 0));
//	tmp = Projection * View * secondMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	spheres[3].draw(Mode);	//2사분면
//
//	tmp = Projection * View * secondMat * rotateMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	gluDisk(line, 1.0, 1.1, 20, 1);
//
//	secondMat = glm::rotate(secondMat, glm::radians(moon_angle), glm::vec3(0, 1, 0));
//	secondMat = glm::translate(secondMat, glm::vec3(1.0, 0.0, 0.0));
//	secondMat = glm::scale(secondMat, glm::vec3(0.5, 0.5, 0.5));
//	tmp = Projection * View * secondMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	spheres[4].draw(Mode);	//2사분면 달
//
//	if (all_rotate)
//		thirdMat = glm::rotate(thirdMat, glm::radians(45.f), glm::vec3(-1, 1, 0));
//	thirdMat = glm::rotate(thirdMat, glm::radians(allrad), glm::vec3(1, -1, 0));
//	thirdMat = glm::scale(thirdMat, glm::vec3(0.5, 0.5, 0.5));
//	thirdMat = glm::translate(thirdMat, glm::vec3(-5.0, -5.0, 0));
//	tmp = Projection * View * thirdMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	spheres[5].draw(Mode);	//1사분면
//
//	tmp = Projection * View * thirdMat * rotateMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	gluDisk(line, 1.0, 1.1, 20, 1);
//
//	thirdMat = glm::rotate(thirdMat, glm::radians(moon_angle), glm::vec3(0, 1, 0));
//	thirdMat = glm::translate(thirdMat, glm::vec3(1.0, 0.0, 0.0));
//	thirdMat = glm::scale(thirdMat, glm::vec3(0.5, 0.5, 0.5));
//	tmp = Projection * View * thirdMat;
//	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &tmp[0][0]);
//	spheres[6].draw(Mode);	//1사분면 달
//	DrawLine();
//
//	glutSwapBuffers();
//}
//
//void DrawLine()
//{
//	glBegin(GL_LINE_STRIP);
//	for (int i = 0; i < 360; ++i) {
//		glVertex3f(cos(i), 0, sin(i));
//	}
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
//	case 'y':
//		all_rotate = !all_rotate;
//		break;
//	case 'q':
//		exit(0);
//		break;
//	case 'm':
//		if (Mode == GLU_LINE)
//			Mode = GLU_FILL;
//		else
//			Mode = GLU_LINE;
//		break;
//	case'z':
//		z_distance -= 1.f;
//		break;
//	case 'x':
//		z_distance += 1.f;
//		break;
//	case 'w':
//		y_distance -= 1.f;
//		break;
//	case 's':
//		y_distance += 1.f;
//		break;
//	case 'a':
//		x_distance -= 1.f;
//		break;
//	case 'd':
//		x_distance += 1.f;
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
//	if (all_rotate) {
//		if (allrad > 360)
//			allrad -= 360;
//		else
//			allrad += 5;
//	}
//	++moon_angle;
//	glutTimerFunc(100, TimerFunction, 1);
//}