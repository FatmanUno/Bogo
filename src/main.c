#include <GL/glut.h>
#include "funciones.h"
#include <time.h>       

clock_t tiempoInicio, tiempoFin;
double tiempoTotal = 0;

int main(int argc, char **argv) {
    srand(time(NULL)); 

    // funcion pal tiempo
    tiempoInicio = clock(); 

    // inicia las openglcosas
    iniciarVentana(argc, argv);  
    glutDisplayFunc(display);    
    glutMainLoop();              

    return 0;
}
