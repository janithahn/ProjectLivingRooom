#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "lamp.h"

GLUquadricObj* quadratic;

void Lamp::drawTableLamp() {

	quadratic = gluNewQuadric(); 
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.7, 0.4, 0.9, 10, 1); /* draw a cone */
	glTranslatef(0, 0, -0.2);
	glutSolidCone(0.15, 1, 100, 1 ); /* holder bar */

}