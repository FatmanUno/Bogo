#include <GL/glut.h>
#include "funciones.h"
#include <time.h>  // Para la función time


int main(int argc, char **argv) {
    srand(time(NULL)); // Inicializa el generador de números aleatorios

    iniciarVentana(argc, argv);  // Inicializa la ventana
    glutDisplayFunc(display);    // Registra la función de renderizado
    glutMainLoop();              // Inicia el bucle principal de GLUT

    return 0;
}
