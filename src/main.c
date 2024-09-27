#include <GL/glut.h>
#include "funciones.h"

int main(int argc, char **argv) {
    iniciarVentana(argc, argv);
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0;
}
