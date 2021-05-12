OBJS = src/main.cpp src/window.cpp src/mesh.cpp src/shader.cpp src/input.cpp src/texture.cpp

CC = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lGL -lglfw -lGLEW

OBJ_NAME = renderer

all : $(OBJS) 
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
