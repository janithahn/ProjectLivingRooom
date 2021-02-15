#include <GL/glut.h>  
#include <math.h>

// vertices for the cube
GLfloat x = 5.0f;
GLfloat y = 5.0f;
GLfloat z = 5.0f;

// variables to move outermost Object Frame (to move all the rendered environment)
GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
GLfloat moveZ = 0.0f;

// variables to rotate outermost Object Frame (to move all the rendered environment)
GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;

//variables to move the camera
GLfloat camY = 0.0f;
GLfloat camX = 0.0f;
GLfloat camZ = 0.0f;

//light
GLfloat   lightPosition[] = { 1, 3, 0, 1 };
GLfloat   lightDirection[] = { 0, 0, 10, 0 };
GLfloat   diffuseLight[] = { 0, 1, 0, 1 };
GLfloat   ambientLight[] = { 0.2, 0.2, 0.2, 1 };

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    //enable lighing
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);

}
/*
Use this function to identify the transformations(translation/ rotation/ scaling) if needed
(call this function at the place you need to determine the orientation of the axes)
*/

//init light
void initLight() {
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 128);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
}

void drawAxes() {

    glBegin(GL_LINES);

    glLineWidth(1.5);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-20, 0, 0);
    glVertex3f(20, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -20, 0);
    glVertex3f(0, 20, 0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -20);
    glVertex3f(0, 0, 20);

    glEnd();
}
void DrawGrid() {
    GLfloat ext = 20.0f;
    GLfloat step = 1.0f;
    GLfloat yGrid = -0.4f;
    GLint line;

    glBegin(GL_LINES);
    for (line = -ext; line <= ext; line += step) {
        glVertex3f(line, yGrid, ext);
        glVertex3f(line, yGrid, -ext);

        glVertex3f(ext, yGrid, line);
        glVertex3f(-ext, yGrid, line);
    }
    glEnd();
}

void drawWalls() {
    // glTranslatef(0.0, 1.6, 0.0);
    // BACK
    glBegin(GL_QUADS);
    glColor3f(.224, .255, .255);
    glVertex3f(x, y, z);
    glVertex3f(x, -y, z);
    glVertex3f(-x, -y, z);
    glVertex3f(-x, y, z);
    glEnd();

    // FRONT
    glBegin(GL_QUADS);
    glColor3f(.224, .255, .255);
    glVertex3f(x, y, -z);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(x, -y, -z);
    glEnd();

    // LEFT
    glBegin(GL_QUADS);
    glColor3f(.224, .255, .255);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, -y, z);
    glEnd();

    //Right
    glBegin(GL_QUADS);
    glColor3f(.224, .255, .255);
    glVertex3f(x, y, z);
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);
    glVertex3f(x, y, -z);
    glEnd();

    //Top
    glBegin(GL_QUADS);
    glColor3f(.188, .143, .143);
    glVertex3f(x, y, -z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, y, -z);
    glEnd();

    //Bottom
    glBegin(GL_QUADS);
    glColor3f(.160, .82, .45);
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, -y, z);
    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();

    // camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    gluLookAt(0.0 + camX, 2.0 + camY, 5.0 + camZ, 0, 0, 0, 0, 1.0, 0);
    initLight();

    // move the object frame using keyboard keys
    glTranslatef(moveX, moveY, moveZ);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);


    glColor3f(1.0, 1.0, 1.0);

    DrawGrid();

    //walls, floor and ceiling
    glPushMatrix();
    glTranslatef(0.0, 4.6, 0.0);

    drawWalls();

    glPopMatrix();

    drawAxes();
    glPopMatrix();

    glutSwapBuffers();

}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        moveZ += 1;

    if (key == GLUT_KEY_DOWN)
        moveZ -= 1;

    if (key == GLUT_KEY_LEFT)
        rotY -= 5.0;

    if (key == GLUT_KEY_RIGHT)
        rotY += 1.0;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w')
        camY += 0.5;
    if (key == 's')
        camY -= 0.5;

    if (key == 'c')
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if (key == 'C')
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glutPostRedisplay();

}

void Timer(int x) {
    //animateRotation += animateRotation >= 360.0 ? -animateRotation : 5;
    glutPostRedisplay();

    glutTimerFunc(60, Timer, 1);
}

void changeSize(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Define the Perspective projection frustum 
    // (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
    gluPerspective(120.0, aspect_ratio, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("OpenGL Setup Test");
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);

    // keyboard function activation
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);

    //glutTimerFunc(60.0, Timer, 1);
    init();
    glutMainLoop();


    return 0;
}