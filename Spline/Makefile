# Variáveis de compilação
CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17
LDFLAGS := -lSDL2

# Caminho para os arquivos de código-fonte
VPATH := src

# Nome do binário final
TARGET := SDL_teste

# Lista de arquivos de código-fonte
SRC := janela.cpp ponto.cpp SDL_teste.cpp

# Lista de arquivos objeto
OBJ := $(SRC:.cpp=.o)

# Receita para gerar o binário final
$(TARGET): $(OBJ)
	$(CXX)  -o $@ $^ $(LDFLAGS)

# Receita para gerar os arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Receita para limpar os arquivos temporários
clean:
	$(RM) $(OBJ) $(TARGET)
