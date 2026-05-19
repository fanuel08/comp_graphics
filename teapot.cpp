#include <GL/glut.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);   // clear screen to black
    glColor3f(1.0, 0.0, 1.0);       // magenta colour
    glutWireTeapot(0.7);            // draw wireframe teapot
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  // keeps proportions correct
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(577, 314);   // matches the given graphic
    glutCreateWindow("Wireframe Teapot");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
