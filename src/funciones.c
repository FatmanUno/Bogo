#include <GL/glut.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  
#include "funciones.h"  


extern clock_t tiempoInicio, tiempoFin; 
extern double tiempoTotal;


int numeros[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};  
int iteracion = 0;
int windowWidth = 500;
int windowHeight = 500;

void iniciarVentana(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("BogoSort Visualization");
    glClearColor(0.0, 0.0, 0.0, 1.0);  
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// Función para manejar el "responsive" de la ventana

void reshape(int width, int height) {
    
    glViewport(0, 0, width, height);

 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);  

    
    windowWidth = width;
    windowHeight = height;

   
    glutPostRedisplay();
}

void dibujarTexto(const char *texto, float x, float y) {
    glRasterPos2f(x, y);  
    while (*texto) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto);  
        texto++;
    }
}

bool estaOrdenado(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void mezclar(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bogoSort(int arr[], int size) {
    iteracion++;
    if (!estaOrdenado(arr, size)) {
        mezclar(arr, size);
        glutPostRedisplay();  
        usleep(10000);  
    }
}


void dibujarBarras(int arr[], int size) {
    float anchoBarra = (float)windowWidth / size;  
    for (int i = 0; i < size; i++) {
        float altura = arr[i] * (windowHeight / 9.0);  /

        
        glColor4f(0.0f, 0.5f, 1.0f, 0.5f);  
        
        glBegin(GL_QUADS);
        glVertex2f(i * anchoBarra, 0);             
        glVertex2f((i + 1) * anchoBarra, 0);      
        glVertex2f((i + 1) * anchoBarra, altura);  
        glVertex2f(i * anchoBarra, altura);         
        glEnd();
    }
}


void convertirNumerosATexto(char *buffer, int arr[], int size) {
    int offset = 0;
    for (int i = 0; i < size; i++) {
        offset += sprintf(buffer + offset, "%d ", arr[i]);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 

  
    dibujarBarras(numeros, 9);

   
    char texto[50];
    convertirNumerosATexto(texto, numeros, 9);  
    dibujarTexto(texto, 200, 250);  
    // Dibuja la iteración actual
    char iteracionTexto[50];
    sprintf(iteracionTexto, "Iteracion: %d", iteracion);
    dibujarTexto(iteracionTexto, 200, 200);

    
    if (estaOrdenado(numeros, 9)) {
        char tiempoTexto[50];
        sprintf(tiempoTexto, "Tiempo: %.2f segundos", tiempoTotal);
        dibujarTexto(tiempoTexto, 200, 150);  
    }

    glFlush(); 
    bogoSort(numeros, 9);  
}

