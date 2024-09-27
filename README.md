# BogoStream

Un simple programa en C que mostraría cómo se resuelven iteraciones de un algoritmo de búsqueda Bogosort ordenando una serie de números, esto con el propósito de ser stremeado vía Twitch, simplemente porque Bogo es mi algoritmo de búsqueda favorito debido a lo cómicamente ineficiente que es.

## Herramientas y Dependencias
- **Lenguaje**: C
- **Compilador**: GCC (o cualquier compilador compatible con C)
- **Bibliotecas**:
  - OpenGL (para la visualización gráfica)
  - GLFW 
  - GLAD 
- **Plataforma**: Linux mediante wsl


## Historial de Cambios

### [0.0.1] - 26-09-2024
- Se creó el repositorio
- Se agregó el script de instalación `install.sh` con los comandos para instalar las dependencias necesarias.


### [0.1.1] - 26-09-2024

- Prototipo del programa, una ventana basica que muestra un texto (todavia no se usar opengl xd) 

- Se añadio un Makefile para poder crear carpetas y compilar.


### [0.2.1] - 26-09-2024

- El programa muestra un bogosort en la ventana

### [0.2.2] - 26-09-2024

- Agregue comandos en el install.sh para evitar errores al montar el proyecto

### [0.3.2] - 26-09-2024

- se agregaron barras para visualizar mejor el orden de cada iteracion, por ahora estan crudas pero la idea es que se vean mejor despues

### [0.3.3] - 26-09-2024

- se arreglo la estetica de las barras
- se solucionaron errores del compilador por declaraciones implicitas de funciones.

# Proximos cambios

- Mostrar un reloj contando el tiempo que lleva el algoritmo.
- Mostrar un contador de veces que el algoritmo estubo cerca de ordenar los numeros.
- una pantalla final mostrando el numero de iteracion en que se completo el algoritmo y el tiempo que se demoro.
- mejorar la estetica delas barras. <listo>
  




chmod +x install.sh

