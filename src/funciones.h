#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdbool.h>

void iniciarVentana(int argc, char **argv);

void reshape(int width, int height);  // Añadir esta línea

void dibujarTexto(const char *texto, float x, float y);

bool estaOrdenado(int arr[], int size);

void mezclar(int arr[], int size);

void bogoSort(int arr[], int size);

void dibujarBarras(int arr[], int size);

void convertirNumerosATexto(char *buffer, int arr[], int size);




void display();

#endif
