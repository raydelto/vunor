UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS = -lGL -lGLEW -lglfw -ldl
	INCLUDES=-I ./includes -I ./third-party-code
endif
ifeq ($(UNAME_S),Darwin)
FRAMEWORKS=-framework OpenGL

LIBS= -L/System/Library/Frameworks \
	  -lglfw
INCLUDES=-I./include -I ./third-party-code
SRC=third-party-code/glad.c
OBJ=bin/glad.o
endif

SRC += src/core/glfw/Window.cpp \
	   src/core/Node.cpp \
	   src/core/Scene.cpp \
	   src/core/Shader.cpp \
	   src/core/Triangle.cpp 

OBJ += bin/Window.o \
	   bin/Node.o \
	   bin/Scene.o \
	   bin/Shader.o \
	   bin/Triangle.o

WARNINGS=-w

FLAGS=-std=c++14 -D _DEBUG

all:
	g++ -c -g $(SRC) $(INCLUDES) $(WARNINGS) $(FLAGS)
	#ls bin>/dev/null||mkdir bin
	#mv *.o ./bin
	g++ -g $(OBJ) src/main.cpp $(FRAMEWORKS) $(LIBS) $(INCLUDES) -o bin/main $(WARNINGS) $(FLAGS)
