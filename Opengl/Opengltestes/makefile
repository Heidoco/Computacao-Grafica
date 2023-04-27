.PRECIOUS: glad/glad.c

CC = g++
CFLAGS = -fdiagnostics-color=always -g -Wall
LIBS = -lGL -lglfw -lstb 

SRCS = Main.cpp glad/glad.c EBO.cpp shaderClass.cpp VAO.cpp VBO.cpp Texture.cpp camera.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = teste

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

