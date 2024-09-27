#include <GL/glut.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include <unistd.h>

int numeros[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};  // Inicialmente desordenado
int iteracion = 0;

void iniciarVentana(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("BogoSort Visualization");
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

// Función para verificar si el array está ordenado
bool estaOrdenado(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Función para barajar el array
void mezclar(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Algoritmo BogoSort
void bogoSort(int arr[], int size) {
    iteracion++;
    if (!estaOrdenado(arr, size)) {
        mezclar(arr, size);
        glutPostRedisplay();  // Solicita que se vuelva a dibujar la pantalla
        //usleep(20000);
    }
}

// Función que convierte el array de números a texto para dibujarlo en pantalla
void convertirNumerosATexto(char *buffer, int arr[], int size) {
    int offset = 0;
    for (int i = 0; i < size; i++) {
        offset += sprintf(buffer + offset, "%d ", arr[i]);
    }
}

// Función de renderizado
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la ventana

    char texto[50];
    convertirNumerosATexto(texto, numeros, 9); // Convierte el array a texto
    dibujarTexto(texto, 200, 250);  // Dibuja el array en el centro de la pantalla
    dibujarBarras(numeros, 9);
    // Dibuja la iteración actual
    char iteracionTexto[50];
    sprintf(iteracionTexto, "Iteracion: %d", iteracion);
    dibujarTexto(iteracionTexto, 200, 200);

    glFlush();  // Asegura que se dibuje en pantalla
    bogoSort(numeros, 9);  // Ejecuta otra iteración de BogoSort
}

void dibujarBarras(int arr[], int size) {
    float anchoBarra = 500.0 / size;
    for (int i = 0; i < size; i++) {
        float altura = arr[i] * 50;  // Ajusta la altura según los valores del array
        glBegin(GL_QUADS);
        glVertex2f(i * anchoBarra, 0);              // Esquina inferior izquierda
        glVertex2f((i + 1) * anchoBarra, 0);        // Esquina inferior derecha
        glVertex2f((i + 1) * anchoBarra, altura);   // Esquina superior derecha
        glVertex2f(i * anchoBarra, altura);         // Esquina superior izquierda
        glEnd();
    }
}
