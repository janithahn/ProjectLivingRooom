#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "lamp.h"

GLUquadricObj* quadratic;

void Lamp::drawTableLamp(GLuint texture) {

	quadratic = gluNewQuadric(); 

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glRotatef(-90, 1.0, 0.0, 0.0);
    glTexCoord3d(0, 0, 0);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.7, 0.4, 0.9, 10, 1); /* draw a cone */
	glutSolidCone(0.15, 1, 100, 1 ); /* holding bar */
    
    glPushMatrix();
    glTranslatef(0, 0, -1.95);
    gluQuadricDrawStyle(quadratic, GLU_FILL);
    gluCylinder(quadratic, 0.07, 0.07, 2.7, 10, 1); /* draw a cone */
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -2.1);
    gluQuadricDrawStyle(quadratic, GLU_FILL);
    gluCylinder(quadratic, 0.8, 0.07, 0.2, 10, 1); /* draw a cone */
    glPopMatrix();
}

void Lamp::drawWallLamp(GLuint texture) {

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

    // lighting plate
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

    //glColor3f(1.0f, 1.0f, 0.0f);     // Yellow

    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out

    glVertex3f(1.0f, 1.0f, -0.05f);
    glVertex3f(-1.0f, 1.0f, -0.05f);
    glVertex3f(-1.0f, 1.0f, 0.05f);
    glVertex3f(1.0f, 1.0f, 0.05f);

    // Bottom face (y = -1.0f)
    glVertex3f(1.0f, -1.0f, 0.05f);
        glTexCoord3f(1.0f, -1.0f, 0.05f);
    glVertex3f(-1.0f, -1.0f, 0.05f);
        glTexCoord3f(-1.0f, -1.0f, 0.05f);
    glVertex3f(-1.0f, -1.0f, -0.05f);
        glTexCoord3f(-1.0f, -1.0f, -0.05f);
    glVertex3f(1.0f, -1.0f, -0.05f);
        glVertex3f(1.0f, -1.0f, -0.05f);

    // Front face  (z = 1.0f)
    glVertex3f(1.0f, 1.0f, 0.05f);
        glTexCoord3f(1.0f, 1.0f, 0.05f);
    glVertex3f(-1.0f, 1.0f, 0.05f);
        glTexCoord3f(-1.0f, 1.0f, 0.05f);
    glVertex3f(-1.0f, -1.0f, 0.05f);
        glTexCoord3f(-1.0f, -1.0f, 0.05f);
    glVertex3f(1.0f, -1.0f, 0.05f);
        glTexCoord3f(1.0f, -1.0f, 0.05f);

    // Back face (z = -1.0f)
    glVertex3f(1.0f, -1.0f, -0.05f);
        glTexCoord3f(1.0f, -1.0f, -0.05f);
    glVertex3f(-1.0f, -1.0f, -0.05f);
        glTexCoord3f(-1.0f, -1.0f, -0.05f);
    glVertex3f(-1.0f, 1.0f, -0.05f);
        glTexCoord3f(-1.0f, 1.0f, -0.05f);
    glVertex3f(1.0f, 1.0f, -0.05f);
        glTexCoord3f(1.0f, 1.0f, -0.05f);

    // Left face (x = -1.0f)
    glVertex3f(-1.0f, 1.0f, 0.05f);
        glTexCoord3f(-1.0f, 1.0f, 0.05f);
    glVertex3f(-1.0f, 1.0f, -0.05f);
        glTexCoord3f(-1.0f, 1.0f, -0.05f);
    glVertex3f(-1.0f, -1.0f, -0.05f);
        glTexCoord3f(-1.0f, -1.0f, -0.05f);
    glVertex3f(-1.0f, -1.0f, 0.05f);
        glTexCoord3f(-1.0f, -1.0f, 0.05f);

    // Right face (x = 1.0f)
    glVertex3f(1.0f, 1.0f, -0.05f);
        glTexCoord3f(1.0f, 1.0f, -0.05f);
    glVertex3f(1.0f, 1.0f, 0.05f);
        glTexCoord3f(1.0f, 1.0f, 0.05f);
    glVertex3f(1.0f, -1.0f, 0.05f);
        glTexCoord3f(1.0f, -1.0f, 0.05f);
    glVertex3f(1.0f, -1.0f, -0.05f);
        glTexCoord3f(1.0f, -1.0f, -0.05f);

    glEnd();  // End of drawing color-cube

    // plate holder
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

    //glColor3f(1.0f, 1.0f, 0.0f);     // Yellow

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