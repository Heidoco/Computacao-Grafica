.PHONY: clean doxygen

CXX=g++
RM=rm

# receita para gerar o binário final 
SDL_teste: janela.o ponto.o SDL_teste.o
	$(CXX) SDL_teste.o janela.o ponto.o  -o SDL_teste -lSDL2

# receita para gerar o (arquivo objeto) janela.o
janela.o: janela.cpp janela.h
	$(CXX) -o janela.o -c janela.cpp -lSDL2

# receita para gerar o (arquivo objeto) ponto.o
ponto.o: ponto.cpp ponto.h
	$(CXX) -o ponto.o -c ponto.cpp -lSDL2

# receita para gerar o (arquivo objeto) main.o
SDL_teste.o: SDL_teste.cpp janela.h ponto.h
	$(CXX) -o SDL_teste.o -c SDL_teste.cpp -lSDL2

# receita para apagar arquivos (geralmente são arquivos gerados
# no processo de desenvolvimento)
clean:
	$(RM) -f SDL_teste
	$(RM) -f ponto.o
	$(RM) -f janela.o
	$(RM) -f SDL_teste.o

# receita para gerar a documentação, o arquivo Doxyfile está
# configurado para gerar um diretório chamado docs
doc:
	doxygen

# receita para apagar o conteúdo do diretório de documentação
cleandoc:
	$(RM) -fR docs

run:
	./SDL_teste
