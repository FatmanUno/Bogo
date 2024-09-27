#include <GL/glut.h>
#include "funciones.h"

void iniciarVentana(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("peopotoplaceholder");
    glClearColor(0.0, 0.0, 0.0, 1.0); // Fondo negro
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void dibujarTexto(const char *texto, float x, float y) {
    glRasterPos2f(x, y); // Posiciona el texto en la ventana
    while (*texto) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto); // Dibuja cada caracter
        texto++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la ventana
    dibujarTexto("Hola Mundo", 200, 250); // Dibuja el texto en el centro
    glFlush(); // Asegura que se dibuje en pantalla
}
