//// ComputerGraphics.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//#include<time.h>
//#include<GL/glew.h>
//#include<GL/freeglut.h>
//#include<gl/freeglut_ext.h>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//void Keyboard(unsigned char key, int x, int y);
//void TimerFunction(int value);
//
//float red, green, blue;
//BOOL input;
//
//int main(int argc, char** argv) // 윈도우 출력하고 콜백함수 설정 
//{
//	srand((unsigned)time(NULL));
//	glutInit(&argc, argv); 
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Example1");
//
//	glewExperimental = GL_TRUE;
//	if (glewInit() != GLEW_OK)
//	{
//		std::cerr << "Unable to initialize GLE" << std::endl;
//		exit(EXIT_FAILURE);
//	}
//	else
//		std::cout << "GLEW Initialized\n";
//
//	glutKeyboardFunc(Keyboard);
//	glutReshapeFunc(Reshape);
//	glutDisplayFunc(drawScene);
//	glutTimerFunc(100, TimerFunction, 1);
//	glutMainLoop();
//}
//
//void TimerFunction(int value)
//{
//	if (input) {
//		red = rand() % 100;
//		green = rand() % 100;
//		blue = rand() % 100;
//	}
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}
//	
//GLvoid drawScene()
//{ 
//	glClearColor( red * 0.01 , green * 0.01 , blue * 0.01, 1.0 ); //r,g,b,1.0f1
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	glutSwapBuffers();
//}
//
//GLvoid Reshape(int w, int h) // 콜백 함수: 다시 그리기
//{
//	glViewport(0, 0, w, h);
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'r':
//	case 'R':
//		red = 100;
//		green = 0;
//		blue = 0;
//		break;
//	case 'g':
//	case 'G':
//		red = 0;
//		green = 100;
//		blue = 0;
//		break;
//	case 'b':
//	case 'B':
//		red = 0;
//		green = 0;
//		blue = 100;
//		break;
//	case 'w':
//	case 'W':
//		red = 100;
//		green = 100;
//		blue = 100;
//		break;
//	case 'k':
//	case 'K':
//		red = 0;
//		green = 0;
//		blue = 0;
//		break;
//	case 'a':
//	case 'A':
//		red = rand() % 100;
//		green = rand() % 100;
//		blue = rand() % 100;
//		break;
//	case 't':
//	case 'T':
//		input = TRUE;
//		break;
//	case 's':
//	case 'S':
//		input = FALSE;
//		break;
//	case 'q':
//	case 'Q':
//		exit(0);
//		break;
//	}
//}