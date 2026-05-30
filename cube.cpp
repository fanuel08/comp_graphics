#include <GL/glut.h>
#include <math.h>

float rotationX = 0.0f;
float rotationY = 0.0f;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Position camera
    gluLookAt(0.0, 0.0, 2.0,   // camera position
              0.0, 0.0, 0.0,   // look at point
              0.0, 1.0, 0.0);  // up vector
    
    // Apply rotations
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
    
    // Draw wireframe cube
    glColor3f(0.0, 1.0, 1.0);  // cyan color
    glutWireCube(1.0);
    
    glFlush();
    glutSwapBuffers();
    
    // Update rotations for animation
    rotationX += 0.5f;
    rotationY += 0.7f;
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // black background
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void idle(void) {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Cube");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
