#include <stdio.h>
#include <GL/glut.h>

int main(int argc, char** argv) {
    printf("Test program started\n");
    fflush(stdout);
    
    printf("About to call glutInit\n");
    fflush(stdout);
    
    glutInit(&argc, argv);
    
    printf("glutInit completed successfully\n");
    fflush(stdout);
    
    return 0;
}
