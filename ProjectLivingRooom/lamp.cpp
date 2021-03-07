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
	glutSolidCone(0.15, 1, 100, 1 ); /* holding bar */

}

void Lamp::drawWallLamp() {

    // lighting plate
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow

    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out

    glVertex3f(1.0f, 1.0f, -0.05f);
    glVertex3f(-1.0f, 1.0f, -0.05f);
    glVertex3f(-1.0f, 1.0f, 0.05f);
    glVertex3f(1.0f, 1.0f, 0.05f);

    // Bottom face (y = -1.0f)
    glVertex3f(1.0f, -1.0f, 0.05f);
    glVertex3f(-1.0f, -1.0f, 0.05f);
    glVertex3f(-1.0f, -1.0f, -0.05f);
    glVertex3f(1.0f, -1.0f, -0.05f);

    // Front face  (z = 1.0f)
    glVertex3f(1.0f, 1.0f, 0.05f);
    glVertex3f(-1.0f, 1.0f, 0.05f);
    glVertex3f(-1.0f, -1.0f, 0.05f);
    glVertex3f(1.0f, -1.0f, 0.05f);

    // Back face (z = -1.0f)
    glVertex3f(1.0f, -1.0f, -0.05f);
    glVertex3f(-1.0f, -1.0f, -0.05f);
    glVertex3f(-1.0f, 1.0f, -0.05f);
    glVertex3f(1.0f, 1.0f, -0.05f);

    // Left face (x = -1.0f)
    glVertex3f(-1.0f, 1.0f, 0.05f);
    glVertex3f(-1.0f, 1.0f, -0.05f);
    glVertex3f(-1.0f, -1.0f, -0.05f);
    glVertex3f(-1.0f, -1.0f, 0.05f);

    // Right face (x = 1.0f)
    glVertex3f(1.0f, 1.0f, -0.05f);
    glVertex3f(1.0f, 1.0f, 0.05f);
    glVertex3f(1.0f, -1.0f, 0.05f);
    glVertex3f(1.0f, -1.0f, -0.05f);

    glEnd();  // End of drawing color-cube

    // plate holder
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow

    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out

    glVertex3f(0.4f, 0.4f, -0.5f);
    glVertex3f(-0.4f, 0.4f, -0.5f);
    glVertex3f(-0.4f, 0.4f, 0.05f);
    glVertex3f(0.4f, 0.4f, 0.05f);

    // Bottom face (y = -1.0f)
    glVertex3f(0.4f, -0.4f, 0.05f);
    glVertex3f(-0.4f, -0.4f, 0.05f);
    glVertex3f(-0.4f, -0.4f, -0.5f);
    glVertex3f(0.4f, -0.4f, -0.5f);

    // Front face  (z = 1.0f)
    glVertex3f(0.4f, 0.4f, 0.05f);
    glVertex3f(-0.4f, 0.4f, 0.05f);
    glVertex3f(-0.4f, -0.4f, 0.05f);
    glVertex3f(0.4f, -0.4f, 0.05f);

    // Back face (z = -1.0f)
    glVertex3f(0.4f, -0.4f, -0.5f);
    glVertex3f(-0.4f, -0.4f, -0.5f);
    glVertex3f(-0.4f, 0.4f, -0.5f);
    glVertex3f(0.4f, 0.4f, -0.5f);

    // Left face (x = -1.0f)
    glVertex3f(-0.4f, 0.4f, 0.05f);
    glVertex3f(-0.4f, 0.4f, -0.5f);
    glVertex3f(-0.4f, -0.4f, -0.5f);
    glVertex3f(-0.4f, -0.4f, 0.05f);

    // Right face (x = 1.0f)
    glVertex3f(0.4f, 0.4f, -0.5f);
    glVertex3f(0.4f, 0.4f, 0.05f);
    glVertex3f(0.4f, -0.4f, 0.05f);
    glVertex3f(0.4f, -0.4f, -0.5f);

    glEnd();  // End of drawing color-cube

}