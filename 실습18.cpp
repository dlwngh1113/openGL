//#include <iostream>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include <GL/freeglut_ext.h>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <glm/glm/glm.hpp>
//#include <glm/glm/ext.hpp>
//#include <glm/glm/ext/matrix_transform.hpp>
//using namespace std;
//
//int movekey = 0, jumpkey = 0, wallmove = 0;
//
//float accelation = 0.0;
//
//float robotmove_x = 0.0, robotmove_z = 0.0;
//float robotangle = 0.0;
//float robotjump_y = 0.0;
//float wallmove_y = 0.0;
//float right_foot = 0.0, left_foot = 0.0;
//int foot_dir = 0;
//
//GLenum n = GL_FILL;
//GLvoid drawScene(GLvoid);
//void Mouse(int, int, int, int);
//void Keyboard(unsigned char, int, int);
//void Special(int, int, int);
//GLuint LoadShaders(const char*, const char*);
//void TimerFunction(int);
//
//GLuint programID;
//GLUquadricObj* qobj;
//
//struct Color {
//   float r, g, b;
//
//   Color() {
//	   r = rand() % 1000 * 0.0001;
//	   g = rand() % 1000 * 0.0001;
//	   b = rand() % 1000 * 0.0001;
//   }
//
//   Color(float x, float y, float z) {
//      r = x;
//      g = y;
//      b = z;
//   }
//
//   Color& operator=(Color a) {
//      r = a.r;
//      g = a.g;
//      b = a.b;
//      return *this;
//    }
//
//};
//
//Color color[13];
//
//class Cube {
//public:
//   const GLfloat g_vertex_buffer_data[3 * 3 * 12] = {
//   -0.1f,   -0.1f,   -0.1f, // triangle 1 : begin
//   -0.1f,   -0.1f,    0.1f,
//   -0.1f,    0.1f,    0.1f, // triangle 1 : end
//   0.1f,    0.1f,   -0.1f, // triangle 2 : begin
//   -0.1f,   -0.1f,   -0.1f,
//   -0.1f,    0.1f,   -0.1f, // triangle 2 : end
//   0.1f,   -0.1f,    0.1f,//3
//   -0.1f,   -0.1f,   -0.1f,
//   0.1f,   -0.1f,   -0.1f,//3
//   0.1f,    0.1f,   -0.1f,//4
//   0.1f,   -0.1f,   -0.1f,
//   -0.1f,   -0.1f,   -0.1f,//4
//   -0.1f,   -0.1f,   -0.1f,//5
//   -0.1f,    0.1f,    0.1f,
//   -0.1f,    0.1f,   -0.1f,//5
//   0.1f,   -0.1f,    0.1f,//6
//   -0.1f,   -0.1f,    0.1f,
//   -0.1f,   -0.1f,   -0.1f,//6
//   -0.1f,    0.1f,    0.1f,//7
//   -0.1f,   -0.1f,    0.1f,
//   0.1f,   -0.1f,    0.1f,//7
//   0.1f,    0.1f,    0.1f,//8
//   0.1f,   -0.1f,   -0.1f,
//   0.1f,    0.1f,   -0.1f,//8
//   0.1f,   -0.1f,   -0.1f,//9
//   0.1f,    0.1f,    0.1f,
//   0.1f,   -0.1f,    0.1f,//9
//   0.1f,    0.1f,    0.1f,//10
//   0.1f,    0.1f,   -0.1f,
//   -0.1f,    0.1f,   -0.1f,//10
//   0.1f,    0.1f,    0.1f,//11
//   -0.1f,    0.1f,   -0.1f,
//   -0.1f,    0.1f,    0.1f,//11
//   0.1f,    0.1f,    0.1f,//12
//   -0.1f,    0.1f,    0.1f,
//   0.1f,   -0.1f,    0.1f//12
//   };
//   GLfloat g_fragment_buffer_data[3 * 3 * 12] = {
//      color[0].r,  color[0].g,  color[0].b,
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2],
//      g_fragment_buffer_data[0],  g_fragment_buffer_data[1],  g_fragment_buffer_data[2]
//   };
//
//   Cube() {}
//   ~Cube() {}
//   
//   Cube (Color rgb) {
//      const GLfloat tmp[3 * 3 * 12] = {
//      rgb.r, rgb.g, rgb.b,
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2],
//      tmp[0], tmp[1],  tmp[2]
//      };
//      for (int i = 0; i < 3 * 3 * 12; ++i)
//         g_fragment_buffer_data[i] = tmp[i];
//   }
//
//   Cube& operator=(Cube a) {
//      for (int i = 0; i < 3 * 3 * 12; ++i)
//         g_fragment_buffer_data[i] = a.g_fragment_buffer_data[i];
//      return *this;
//   }
//
//   void draw() {
//      GLuint vertexbuffer;
//      glGenBuffers(1, &vertexbuffer);
//      glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//      glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//      GLuint vertexcolor;
//      glGenBuffers(1, &vertexcolor);
//      glBindBuffer(GL_ARRAY_BUFFER, vertexcolor);
//      glBufferData(GL_ARRAY_BUFFER, sizeof(g_fragment_buffer_data), g_fragment_buffer_data, GL_STATIC_DRAW);
//      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//      glEnableVertexAttribArray(0);
//      glEnableVertexAttribArray(1);
//      glPolygonMode(GL_FRONT_AND_BACK, n);
//      glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
//      glDisableVertexAttribArray(0);
//      glDisableVertexAttribArray(1);
//   }
//}cubes[13];
//
//int main(int argc, char** argv) // 윈도우 출력하고 콜백함수 설정 
//{
//	srand((unsigned)time(NULL));
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
//   glutInitWindowPosition(0, 0);
//   glutInitWindowSize(800, 600);
//   glutCreateWindow("Example1");
//
//   glewExperimental = GL_TRUE;
//   if (glewInit() != GLEW_OK)
//   {
//      std::cerr << "Unable to initialize GLE" << std::endl;
//      exit(EXIT_FAILURE);
//   }
//   else
//      std::cout << "GLEW Initialized\n";
//
//   for (int i = 0; i < 13; ++i) {
//      cubes[i] = Cube{color[i]};
//   }
//
//   programID = LoadShaders("vertex_jaewon.glvs", "fragment_jaewon.glfs");
//
//   glutTimerFunc(100, TimerFunction, 1);
//   glutKeyboardFunc(Keyboard);
//   glutSpecialFunc(Special);
//   glutMouseFunc(Mouse);
//   glutDisplayFunc(drawScene);
//   glutMainLoop();
//}
//
//void Special(int key, int x, int y)
//{
//
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//   switch (key)
//   {
//   case 'n':
//      if (n == GL_FILL)
//         n = GL_LINE;
//      else
//         n = GL_FILL;
//      break;
//
//
//   case 'w':
//      if (robotmove_z > -0.6)
//         robotmove_z -= 0.02;
//      robotangle = 180.0;
//      break;
//   case 's':
//      if (robotmove_z < 1.2)
//         robotmove_z += 0.02;
//      robotangle = 0.0;
//      break;
//   case 'a':
//      if (robotmove_x > -0.8)
//         robotmove_x -= 0.02;
//      robotangle = -90.0;
//      break;
//   case 'd':
//      if (robotmove_x < 1.0)
//         robotmove_x += 0.02;
//      robotangle = 90.0;
//      break;
//
//   case 'i':
//      if (robotjump_y == 0.0)
//         jumpkey = key;
//      break;
//
//   case 'o':
//      wallmove = key;
//      break;
//
//   case 'j':
//      movekey = 0, jumpkey = 0, wallmove = 0;
//      robotmove_x = 0.0, robotmove_z = 0.0;
//      robotangle = 0.0;
//      robotjump_y = 0.0;
//      wallmove_y = 0.0;
//      break;
//
//   case 'q':
//      exit(0);
//      break;
//   }
//}
//
//void Mouse(int button, int state, int x, int y)
//{
//   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//   {
//
//   }
//}
//
//void TimerFunction(int value)
//{
//   glutPostRedisplay(); // 화면재출력
//   robotjump_y += accelation;
//
//   if (jumpkey == 'i') {
//      accelation += 0.02;
//      if (robotjump_y > 0.1) {
//         jumpkey = 0;
//      }
//   }
//   else {
//      accelation -= 0.02;
//      if (robotjump_y < 0.0) {
//         robotjump_y = 0.0;
//         accelation = 0.0;
//      }
//   }
//
//   if (foot_dir == 0){
//      right_foot += 5.0;
//      left_foot -= 5.0;
//      if (right_foot > 45.0)
//         foot_dir = 1;
//   }
//   else {
//      right_foot -= 5.0;
//      left_foot += 5.0;
//      if (right_foot < -45.0)
//         foot_dir = 0;
//   }
//
//   if (wallmove == 'o')
//      wallmove_y += 0.1;
//      
//   glutTimerFunc(100, TimerFunction, 1);
//}
//
//GLvoid drawScene()
//{
//   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//
//   glClearColor(1.0, 1.0, 1.0, 1.0);
//   glUseProgram(programID);
//   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//   glMatrixMode(GL_MODELVIEW);
//
//   glEnable(GL_DEPTH_TEST);
//   glFrontFace(GL_CCW);
//   glCullFace(GL_BACK);
//
//
//   glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)800.0 / (float)600.0, 0.1f, 100.0f);
//
//   glm::vec3 cameraPos = glm::vec3(1.0f, 3.0f, 5.0f);
//   glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f);
//   glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//   glm::mat4 view = glm::mat4(1.0f);
//
//   view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
//   view = Projection * view;
//
//   unsigned int viewLocation = glGetUniformLocation(programID, "viewTransform");
//   glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
//
//   glLoadIdentity();
//
//   glm::mat4 SRTMatrix = glm::mat4(0.1f);
//   unsigned int trasformLocation = glGetUniformLocation(programID, "SRTMatrix");
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   
//
//   // 그리기 시작
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.0, -0.2, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(12.0, 0.02, 12.0));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[0].draw();               // 바닥
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(robotmove_x, robotjump_y, robotmove_z));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(robotangle), glm::vec3(0.0, 1.0, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.05, 0.08, 0.0));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(left_foot), glm::vec3(1.0, 0.0, 0.0));
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(-0.05, -0.08, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(-0.05, 0.0, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.2, 0.8, 0.2));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[1].draw();               // 왼쪽 다리
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(robotmove_x, robotjump_y, robotmove_z));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(robotangle), glm::vec3(0.0, 1.0, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(-0.05, 0.08, 0.0));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(right_foot), glm::vec3(1.0, 0.0, 0.0));
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.05, - 0.08, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.05, 0.0, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.2, 0.8, 0.2));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[2].draw();               // 오른쪽 다리
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(robotmove_x, robotjump_y, robotmove_z));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(robotangle), glm::vec3(0.0, 1.0, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.0, 0.16, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.8, 0.8, 0.8));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[3].draw();               // 몸통
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(robotmove_x, robotjump_y, robotmove_z));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(robotangle), glm::vec3(0.0, 1.0, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.1, 0.16 + 0.08, 0.0));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(right_foot), glm::vec3(1.0, 0.0, 0.0));
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(-0.1, - 0.16 - 0.08, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(-0.1, 0.16, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.2, 0.8, 0.2));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[4].draw();               // 왼쪽 팔
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(robotmove_x, robotjump_y, robotmove_z));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(robotangle), glm::vec3(0.0, 1.0, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(-0.1, 0.16 + 0.08, 0.0));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(left_foot), glm::vec3(1.0, 0.0, 0.0));
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.1, -0.16 - 0.08, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.1, 0.16, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.2, 0.8, 0.2));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[5].draw();               // 오른쪽 팔
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(robotmove_x, robotjump_y, robotmove_z));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(robotangle), glm::vec3(0.0, 1.0, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.0, 0.28, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.4, 0.4, 0.4));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[6].draw();               // 대가리
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(robotmove_x, robotjump_y, robotmove_z));
//   SRTMatrix = glm::rotate(SRTMatrix, glm::radians(robotangle), glm::vec3(0.0, 1.0, 0.0));
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.0, 0.28, 0.06));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.2, 0.2, 0.2));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[7].draw();               // 코
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(1.2, 1.0, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.02, 12.0, 12.0));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[8].draw();               // 오른쪽 벽
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(-1.2, 1.0, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(0.02, 12.0, 12.0));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[9].draw();               // 왼쪽 벽
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.0, 1.0, -1.2));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(12.0, 12.0, 0.02));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[10].draw();               // 뒤쪽 벽
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.0, 2.2, 0.0));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(12.0, 0.02, 12.0));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[11].draw();               // 위쪽 벽
//
//   SRTMatrix = glm::mat4(0.1f);      // 초기화
//
//   SRTMatrix = glm::translate(SRTMatrix, glm::vec3(0.0, 1.0 + wallmove_y, 1.2));
//   SRTMatrix = glm::scale(SRTMatrix, glm::vec3(12.0, 12.0, 0.02));
//
//   glUniformMatrix4fv(trasformLocation, 1, GL_FALSE, glm::value_ptr(SRTMatrix));
//   cubes[12].draw();               // 위쪽 벽
//
//
//
//   glutSwapBuffers();
//}
//
//
//GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path) {
//
//   // 쉐이더들 생성
//   GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
//   GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
//
//   // 버텍스 쉐이더 코드를 파일에서 읽기
//   std::string VertexShaderCode;
//   std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
//   if (VertexShaderStream.is_open()) {
//      std::stringstream sstr;
//      sstr << VertexShaderStream.rdbuf();
//      VertexShaderCode = sstr.str();
//      VertexShaderStream.close();
//   }
//   else {
//      printf("파일 %s 를 읽을 수 없음. 정확한 디렉토리를 사용 중입니까 ? FAQ 를 우선 읽어보는 걸 잊지 마세요!\n", vertex_file_path);
//      getchar();
//      return 0;
//   }
//
//   // 프래그먼트 쉐이더 코드를 파일에서 읽기
//   std::string FragmentShaderCode;
//   std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
//   if (FragmentShaderStream.is_open()) {
//      std::stringstream sstr;
//      sstr << FragmentShaderStream.rdbuf();
//      FragmentShaderCode = sstr.str();
//      FragmentShaderStream.close();
//   }
//
//   GLint Result = GL_FALSE;
//   int InfoLogLength;
//
//
//   // 버텍스 쉐이더를 컴파일
//   printf("Compiling shader : %s\n", vertex_file_path);
//   char const* VertexSourcePointer = VertexShaderCode.c_str();
//   glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
//   glCompileShader(VertexShaderID);
//
//   // 버텍스 쉐이더를 검사
//   glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
//   glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
//   if (InfoLogLength > 0) {
//      std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
//      glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
//      printf("%s\n", &VertexShaderErrorMessage[0]);
//   }
//
//
//
//   // 프래그먼트 쉐이더를 컴파일
//   printf("Compiling shader : %s\n", fragment_file_path);
//   char const* FragmentSourcePointer = FragmentShaderCode.c_str();
//   glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
//   glCompileShader(FragmentShaderID);
//
//   // 프래그먼트 쉐이더를 검사
//   glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
//   glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
//   if (InfoLogLength > 0) {
//      std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
//      glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
//      printf("%s\n", &FragmentShaderErrorMessage[0]);
//   }
//
//
//
//   // 프로그램에 링크
//   printf("Linking program\n");
//   GLuint ProgramID = glCreateProgram();
//   glAttachShader(ProgramID, VertexShaderID);
//   glAttachShader(ProgramID, FragmentShaderID);
//   glLinkProgram(ProgramID);
//
//   // 프로그램 검사
//   glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
//   glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
//   if (InfoLogLength > 0) {
//      std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
//      glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
//      printf("%s\n", &ProgramErrorMessage[0]);
//   }
//
//
//   glDetachShader(ProgramID, VertexShaderID);
//   glDetachShader(ProgramID, FragmentShaderID);
//
//   glDeleteShader(VertexShaderID);
//   glDeleteShader(FragmentShaderID);
//
//   return ProgramID;
//}