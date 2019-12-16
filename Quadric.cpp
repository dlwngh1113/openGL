#include "Quadric.h"

Quadric::Quadric()
{
	qobj = gluNewQuadric(); // 객체 생성하기
	row = width = height = 2.0;
}

Quadric::Quadric(float x, float y, float h)
{
	qobj = gluNewQuadric(); // 객체 생성하기
	row = x;
	width = y;
	height = h;
}

void Quadric::draw()
{
	gluQuadricDrawStyle(qobj, GLU_LINE); // 도형 스타일
	//gluQuadricOrientation(qobj, GLU_OUTSIDE); // 생략 가능
	gluCylinder(qobj, row, width, height, 4, 1);
}

Quadric::~Quadric()
{
}
