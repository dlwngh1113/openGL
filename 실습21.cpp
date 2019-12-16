#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#define VIR_NUM 3
#define PI 3.141592
#include<iostream>
#include<time.h>
#include<vector>
#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/ext.hpp>
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<gl/freeglut_ext.h>
#include"Shader_Loader.h"
#include"Quadric.h"
#include"stb_image.h"

using namespace Core;

GLvoid drawScene(GLvoid);
void TimerFunction(int);
void Init();
void Mouse(int, int, int, int);
void Reshape(int, int);
void Keyboard(unsigned char key, int x, int y);
void special(int, int, int);
void DrawLine();
double GetRad(int);
bool load_obj(
	const char* path,
	std::vector < glm::vec3 >& out_vertices,
	std::vector < glm::vec2 >& out_uvs,
	std::vector < glm::vec3 >& out_normals);
GLuint loadBMP_custom(const char* imagepath);
void draw_obj();
glm::mat4 GetCameraMat();

GLuint program;
int winWidth, winHeight;
std::vector< glm::vec3 > vertices;
std::vector< glm::vec2 > uvs;
std::vector< glm::vec3 > normals; // 지금은 안쓸거에요.
bool res = load_obj("cube.obj", vertices, uvs, normals);
GLuint texture = loadBMP_custom("grass_block_top.bmp");
float Allrad;
bool allRotate;
float ypos = 1;
float zpos = 1;

int main(int argc, char** argv)
{
	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Example2");
	glewInit();
	Init();

	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(special);
	glutDisplayFunc(drawScene);
	glutTimerFunc(100, TimerFunction, 1);
	glutMouseFunc(Mouse);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

void Init()
{
	glDepthFunc(GL_LESS);

	//load and compile shaders 
	Core::Shader_Loader shaderLoader;
	program = shaderLoader.CreateProgram((char*)"Vertex_Shader21.vs", (char*)"Fragment_Shader21.fs");

	winWidth = 1000;
	winHeight = 700;
}

void draw_obj()
{
	GLuint vertex_buffer;
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glDisableVertexAttribArray(0);
	glDeleteBuffers(1, &vertex_buffer);

	GLuint uv_buffer;
	glGenBuffers(1, &uv_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
	glBufferData(GL_ARRAY_BUFFER, texture, &texture, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDisableVertexAttribArray(1);
	glDeleteBuffers(1, &uv_buffer);

	GLuint normal_buffer;
	glGenBuffers(1, &normal_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, normal_buffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDisableVertexAttribArray(2);
	glDeleteBuffers(1, &normal_buffer);
}

GLvoid drawScene()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glUseProgram(program);

	//그리는 코드
	unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
	unsigned int projLocation = glGetUniformLocation(program, "projTransform");

	int lightPosLocation = glGetUniformLocation(program, "lightPos"); //--- lightPos 값 전달
	glUniform3f(lightPosLocation, 0, ypos, zpos);
	int lightColorLocation = glGetUniformLocation(program, "lightColor"); //--- lightColor 값 전달
	glUniform3f(lightColorLocation, 1.0, 1.0, 1.0);
	int objColorLocation = glGetUniformLocation(program, "objectColor"); //--- object Color값 전달
	glUniform3f(objColorLocation, 0.5, 0.0, 0.5);
	int viewLocation = glGetUniformLocation(program, "viewPos"); //--- view location값 전달
	glUniform3f(viewLocation, 4, 3, 3);

	glm::mat4 cameraMat = GetCameraMat();
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, &cameraMat[0][0]);
	glm::mat4 transformMat = glm::mat4(1.f);
	transformMat = glm::scale(transformMat, glm::vec3(0.5, 0.3, 0.5));
	transformMat = glm::translate(transformMat, glm::vec3(0, 0, 0));
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &transformMat[0][0]);

	draw_obj();

	glm::mat4 LineMat = glm::mat4(1.f);
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &LineMat[0][0]);
	DrawLine();
	glutSwapBuffers();
}

glm::mat4 GetCameraMat()
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)winWidth / (float)winHeight, 0.1f, 100.0f);
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 3), // 카메라는 (4,3,3) 에 있다. 월드 좌표에서
		glm::vec3(0, 0, 0), // 그리고 카메라가 원점을 본다
		glm::vec3(0, 1, 0)  // 머리가 위쪽이다 (0,-1,0 으로 해보면, 뒤집어 볼것이다)
	);

	return Projection * View;
}

void Reshape(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = 1.0 * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	winWidth = glutGet(GLUT_WINDOW_WIDTH);
	winHeight = glutGet(GLUT_WINDOW_HEIGHT);

	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

bool load_obj(const char *path, std::vector < glm::vec3 >& out_vertices, std::vector < glm::vec2 >& out_uvs, std::vector < glm::vec3 >& out_normals)
{
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;

	FILE* file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return false;
	}
	while (1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
			for (unsigned int i = 0; i < vertexIndices.size(); ++i) {
				unsigned int vertexIndex = vertexIndices[i];
				glm::vec3 vertex = temp_vertices[vertexIndex - 1];
				out_vertices.push_back(vertex);
			}
			for (unsigned int i = 0; i < uvIndices.size(); ++i) {
				unsigned int uvIndex = uvIndices[i];
				glm::vec2 uv = temp_uvs[uvIndex - 1];
				out_uvs.push_back(uv);
			}
			for (unsigned int i = 0; i < normalIndices.size(); ++i) {
				unsigned int normalIndex = normalIndices[i];
				glm::vec3 normal = temp_normals[normalIndex - 1];
				out_normals.push_back(normal);
			}
		}
	}
	fclose(file);
	return true;
}

GLuint loadBMP_custom(const char* imagepath)
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char* data;
	FILE* file = fopen(imagepath, "rb");
	if (!file) {
		printf("Image could not be opened\n");
		return 0;
	}
	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}
	// 바이트 배열에서 int 변수를 읽습니다. 
	dataPos = *(int*) & (header[0x0A]);
	imageSize = *(int*) & (header[0x22]);
	width = *(int*) & (header[0x12]); 
	height = *(int*) & (header[0x16]);
	if (imageSize == 0)    
		imageSize = width * height * 3;
	if (dataPos == 0)      
		dataPos = 54;

	data = new unsigned char[imageSize];

	// 파일에서 버퍼로 실제 데이터 넣기. 
	fread(data, 1, imageSize, file);

	//이제 모두 메모리 안에 있으니까, 파일을 닫습니다. 
	//Everything is in memory now, the file can be closed
	fclose(file);

	GLuint textureID;
	glGenTextures(1, &textureID);

	// 새 텍스처에 "Bind" 합니다 : 이제 모든 텍스처 함수들은 이 텍스처를 수정합니다. 
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// OpenGL에게 이미지를 넘겨줍니다. 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return textureID;
}

class Cuboid {
	GLUquadricObj* qobj = gluNewQuadric();
public:
	const GLfloat vertex_buffer_data[VIR_NUM * 3 * 12] = {
	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, // triangle 1 : end

	1.0f, 1.0f,-1.0f, // triangle 2 : begin
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f, // triangle 2 : end

	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,

	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,

	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,

	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,

	-1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,

	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,

	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,

	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,

	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,

	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f
	};
	GLfloat color_buffer_data[VIR_NUM * 3 * 12] = {
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//1

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//2

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//3

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//4

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//5

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//6

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//7

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//8

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//9

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//10

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//11

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f//12
	};
	float rad = 30.0;
	bool Isrotate = false;
	void draw() {
		glm::mat4 MyMatrix = glm::mat4(1.0f);
		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
		if (allRotate)
			MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(Allrad), glm::vec3(0, 1, 0));
		MyMatrix = glm::scale(MyMatrix, glm::vec3(0.3, 0.3, 0.3));
		MyMatrix = glm::translate(MyMatrix, glm::vec3(-1.5, 0, 0));
		MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(rad), glm::vec3(1, 0, 0));
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
	}
}cuboid;

class Facade {
	GLUquadricObj* qobj = gluNewQuadric();
public:
	const GLfloat vertex_buffer_data[VIR_NUM * 3 * 6] = {
		0.0f, 1.0f, 0.0f,// { Front }
		-1.0f,-1.0f, 1.0f, // { Front }
		1.0f,-1.0f, 1.0f,// { Front }

		0.0f, 1.0f, 0.0f,// { Right }
		1.0f,-1.0f, 1.0f,// { Right }
		1.0f,-1.0f,-1.0f,// { Right }

		0.0f, 1.0f, 0.0f,// { Back }
		1.0f,-1.0f,-1.0f,// { Back }
		-1.0f,-1.0f,-1.0f, // { Back }

		0.0f, 1.0f, 0.0f,// { Left }
		-1.0f,-1.0f,-1.0f, // { Left }
		-1.0f,-1.0f, 1.0f, // { Left }

		-1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f, //{ bottom }

		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f//{ bottom }
	};
	const GLfloat color_buffer_data[VIR_NUM * 3 * 6] = {
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//1

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//2

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//3

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//4

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//5

		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,
		rand() % 100 * 0.01f,rand() % 100 * 0.01f,rand() % 100 * 0.01f,//6
	};
	float rad = 10;
	bool Isrotate = false;
	void draw() {
		glm::mat4 MyMatrix = glm::mat4(1.0f);
		unsigned int modelLocation = glGetUniformLocation(program, "modelTransform");
		if (allRotate)
			MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(Allrad), glm::vec3(0, 1, 0));
		MyMatrix = glm::scale(MyMatrix, glm::vec3(0.3, 0.3, 0.3));
		MyMatrix = glm::translate(MyMatrix, glm::vec3(1.5, 0, 0));
		MyMatrix = glm::rotate(MyMatrix, (GLfloat)glm::radians(rad), glm::vec3(0, 1, 0));
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &MyMatrix[0][0]);
	}
}facade;

double GetRad(int i)
{
	return (double)(i * PI / 180);
}

void Mouse(int button, int state, int x, int y)
{
}

void DrawLine()
{
	//x축
	int objColorLocation = glGetUniformLocation(program, "objectColor"); //--- object Color값 전달
	glUniform3f(objColorLocation, 1.0, 0.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(5.0f, 0.0f, 0.0f);
	glVertex3f(-5.0f, 0.0f, 0.0f);
	glEnd();

	////y축
	glUniform3f(objColorLocation, 0.0, 1.0, 0.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0f, 5.0f, 0.0f);
	glVertex3f(0.0f, -5.0f, 0.0f);
	glEnd();

	//z축
	glUniform3f(objColorLocation, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0f, 0.0f, 5.0f);
	glVertex3f(0.0f, 0.0f, -5.0f);
	glEnd();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case VK_ESCAPE:
		exit(0);
		break;
	case 'x':
		cuboid.Isrotate = true;
		break;
	case 'y':
		facade.Isrotate = true;
		break;
	case 's':
		cuboid.Isrotate = false;
		facade.Isrotate = false;
		allRotate = false;
		break;
	case 'b':
		allRotate = true;
		break;
	}
}

void special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		ypos += 1;
		break;
	case GLUT_KEY_LEFT:
		zpos += 1;
		break;
	case GLUT_KEY_RIGHT:
		zpos -= 1;
		break;
	case GLUT_KEY_DOWN:
		ypos -= 1;
		break;
	}
}

void TimerFunction(int value)
{
	glutPostRedisplay();
	if (cuboid.Isrotate)
		cuboid.rad += 5.0f;
	if (facade.Isrotate)
		facade.rad += 5.0f;
	if (allRotate)
		Allrad += 5.0;
	glutTimerFunc(100, TimerFunction, 1);
}