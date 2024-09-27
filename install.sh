#!/bin/bash

# Actualizar repositorios
echo "Actualizando repositorios..."
sudo apt update && sudo apt upgrade -y

# Instalar Mesa-utils (OpenGL básico)
echo "Instalando Mesa-utils (herramientas básicas de OpenGL)..."
sudo apt install -y mesa-utils

# Instalar FreeGLUT y GLEW
echo "Instalando FreeGLUT y GLEW..."
sudo apt install -y freeglut3-dev libglew-dev

# Verificar instalación de OpenGL
echo "Verificando la instalación de OpenGL..."
glxinfo | grep "OpenGL"

# Instalar GLFW (opcional)
echo "Instalando GLFW (opcional)..."
sudo apt install -y libglfw3-dev

echo "Instalación completada."
