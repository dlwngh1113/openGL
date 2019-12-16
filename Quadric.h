#pragma once
#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/ext.hpp>
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<gl/freeglut_ext.h>

class Quadric {
	GLUquadricObj* qobj;
	float row, width, height;
public:
	Quadric();
	Quadric(float x, float y, float h);
	void draw();
	~Quadric();
};