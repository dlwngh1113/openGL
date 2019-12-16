//#include <Windows.h>
//#include<iostream>
//#include<time.h>
//#include<GL/glew.h>
//#include<GL/freeglut.h>
//#include<gl/freeglut_ext.h>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//void TimerFunction(int value);
//void changeSize(int w, int h);
//void Mouse(int button, int state, int x, int y);
//
//float Bred = 0, Bgreen = 0, Bblue = 100, Rred = 100, Rgreen = 0, Rblue = 0;
//RECT rt;
//
//int main(int argc, char** argv) // 윈도우 출력하고 콜백함수 설정 
//{
//	srand((unsigned)time(NULL));
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Example2");
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
//	glutReshapeFunc(Reshape);
//	glutDisplayFunc(drawScene);
//	glutTimerFunc(100, TimerFunction, 1);
//	glutMouseFunc(Mouse);
//	glutReshapeFunc(changeSize);
//	glutMainLoop();
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		if (PtInRect(&rt, { x,y })) {
//			Rred = rand() % 100;
//			Rgreen = rand() % 100;
//			Rblue = rand() % 100;
//		}
//		else {
//			Bred = rand() % 100;
//			Bgreen = rand() % 100;
//			Bblue = rand() % 100;
//		}
//	}
//}
//
//void changeSize(int w, int h)
//{
//	if (h == 0)
//		h = 1;
//	float ratio = 1.0 * w / h;
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	glViewport(0, 0, w, h);
//	SetRect(&rt, (w / 2) + (-0.5 * (w / 2)), (h / 2) + (-0.5 * (h / 2)), (w / 2) + (0.5 * (w / 2)), (h / 2) + (0.5 * (h / 2)));
//}
//
//void TimerFunction(int value)
//{
//	glutPostRedisplay();
//	glutTimerFunc(100, TimerFunction, 1);
//}
//
//GLvoid drawScene()
//{
//	glClearColor(Bred * 0.01, Bgreen * 0.01, Bblue * 0.01, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor4f(Rred * 0.01 , Rgreen * 0.01 , Rblue * 0.01,1.0);
//	glRectf(-0.5, -0.5, 0.5, 0.5);
//	glutSwapBuffers();
//}
//
//GLvoid Reshape(int w, int h) // 콜백 함수: 다시 그리기
//{
//	glViewport(0, 0, w, h);
//}