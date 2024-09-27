# Variables
CC = gcc
CFLAGS = -Wall -I./src
LDFLAGS = -lGL -lGLU -lglut # Si necesitas más librerías las añades aquí
SRCDIR = src
OBJDIR = incs
BUILDDIR = build
TARGET = $(BUILDDIR)/programa

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Comandos
all: folders $(TARGET)

folders:
	mkdir -p $(SRCDIR) $(OBJDIR) $(BUILDDIR)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(OBJDIR)/*.o $(BUILDDIR)/programa
