.PRECIOUS: glad/glad.c

CC = g++
CFLAGS = -fdiagnostics-color=always -g -Wall
LIBS = -lGL -lglfw

SRCS = Main.cpp glad/glad.c EBO.cpp shaderClass.cpp VAO.cpp VBO.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = teste

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

