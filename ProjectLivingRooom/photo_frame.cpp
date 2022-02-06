#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "photo_frame.h"

void PhotoFrame::drawPhotoFrame(GLuint frameTexture) {

	glRotatef(90, 0, 0, 1);
	glPushMatrix();

	//glBindTexture(GL_TEXTURE_2D, imgTexture);
	glBindTexture(GL_TEXTURE_2D, frameTexture);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	glBegin(GL_QUADS);

	//Front
	//
	//glColor3f(.6, .2, 0);
    //texture
	glVertex3f(-4.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, 2.0f);

	//Back
	//;
	glVertex3f(-4.0f, -0.2f, -2.0f);
	glVertex3f(-4.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//Right
	//
	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);


	//Left
	;
	glVertex3f(-4.0f, -0.2f, -2.0f);
	glVertex3f(-4.0f, -0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, 2.0f);
	glVertex3f(-4.0f, 0.2f, -2.0f);

	//top
	//
	glTexCoord2f(0, 0);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glTexCoord2f(0, 1);
	glVertex3f(-4.0f, 0.2f, 2.0f);
	glTexCoord2f(1, 1);
	glVertex3f(-4.0f, 0.2f, -2.0f);
	glTexCoord2f(1, 0);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;
	glTexCoord2f(0, 0);
		glVertex3f(2.0f, -0.2f, 2.0f);
	glTexCoord2f(0, 1);
		glVertex3f(-4.0f, -0.2f, 2.0f);
	glTexCoord2f(1, 1);
		glVertex3f(-4.0f, -0.2f, -2.0f);
	glTexCoord2f(1, 0);
		glVertex3f(2.0f, -0.2f, -2.0f);

	glEnd();

	glPopMatrix();

}