# Nome do executável
EXECUTABLE = main.out

# Arquivos fonte
SOURCES = main.cpp src/*.cpp

# Diretórios de inclusão
INCLUDES = -I ./include/

# Bibliotecas a serem linkadas
LIBRARIES = -lSDL2 -lSDL2_ttf

# Flags do compilador
CXXFLAGS = -Wall

# Regra para compilar o programa
compile:
	g++ $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES) $(INCLUDES) $(LIBRARIES)

# Regra para compilar e executar o programa
run: compile
	./$(EXECUTABLE)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(EXECUTABLE)