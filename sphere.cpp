#include <GL/glut.h>
#include <math.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glutWireSphere(0.5, 20, 20);
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glViewport(0, 0, 300, 200);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 200);
    glutCreateWindow("Wireframe Sphere");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
