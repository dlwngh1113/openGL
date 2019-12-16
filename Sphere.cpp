#include "Sphere.h"

Sphere::Sphere()
{
	qobj = gluNewQuadric();
}

Sphere::~Sphere()
{
}

void Sphere::draw(GLenum Mode)
{
	gluQuadricDrawStyle(qobj, Mode);
	gluQuadricNormals(qobj, GLU_SMOOTH); // 생략 가능
	gluQuadricOrientation(qobj, GLU_OUTSIDE); // 생략 가능
	gluSphere(qobj, 1.0, 20, 20);
}