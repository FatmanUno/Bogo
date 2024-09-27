#!/bin/bash

# Resolver problemas pendientes con dpkg
echo "Verificando el estado de dpkg..."
sudo dpkg --configure -a

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
if command -v glxinfo > /dev/null 2>&1; then
    glxinfo | grep "OpenGL"
else
    echo "glxinfo no está instalado o no se encuentra en el PATH"
fi

# Instalar GLFW (opcional)
echo "Instalando GLFW (opcional)..."
sudo apt install -y libglfw3-dev

echo "Instalación completada."
