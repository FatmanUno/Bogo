#include <GL/glut.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  

int numeros[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};  // Inicialmente desordenado
int iteracion = 0;

void iniciarVentana(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("BogoSort Visualization");
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Fondo negro
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
    
    // Activa la mezcla de colores con transparencia
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void dibujarTexto(const char *texto, float x, float y) {
    glRasterPos2f(x, y);  // Posiciona el texto en la ventana
    while (*texto) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto);  // Dibuja cada caracter
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
        glutPostRedisplay();  // Solicita que se vuelva a dibujar la pantalla
        usleep(10000);  // Retardo de 500 ms entre iteraciones
    }
}

// Dibuja las barras de forma transparente
void dibujarBarras(int arr[], int size) {
    float anchoBarra = 500.0 / size;
    for (int i = 0; i < size; i++) {
        float altura = arr[i] * 50;  // Ajusta la altura según los valores del array

        // Configura el color con transparencia (0.5f es el valor alfa)
        glColor4f(0.0f, 0.5f, 1.0f, 0.5f);  // Azul transparente
        
        glBegin(GL_QUADS);
        glVertex2f(i * anchoBarra, 0);              // Esquina inferior izquierda
        glVertex2f((i + 1) * anchoBarra, 0);        // Esquina inferior derecha
        glVertex2f((i + 1) * anchoBarra, altura);   // Esquina superior derecha
        glVertex2f(i * anchoBarra, altura);         // Esquina superior izquierda
        glEnd();
    }
}

// Convierte el array de números a texto para dibujarlo en pantalla
void convertirNumerosATexto(char *buffer, int arr[], int size) {
    int offset = 0;
    for (int i = 0; i < size; i++) {
        offset += sprintf(buffer + offset, "%d ", arr[i]);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpia la ventana

    // Dibuja las barras primero
    dibujarBarras(numeros, 9);

    // Luego dibuja el texto por encima
    char texto[50];
    convertirNumerosATexto(texto, numeros, 9);  // Convierte el array a texto
    glColor3f(1.0, 1.0, 1.0);  // Color blanco para el texto
    dibujarTexto(texto, 200, 250);  // Dibuja el array en el centro de la pantalla

    // Dibuja la iteración actual
    char iteracionTexto[50];
    sprintf(iteracionTexto, "Iteracion: %d", iteracion);
    dibujarTexto(iteracionTexto, 200, 200);

    glFlush();  // Asegura que se dibuje en pantalla
    bogoSort(numeros, 9);  // Ejecuta otra iteración de BogoSort
}

