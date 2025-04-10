# Nome do executável
EXECUTABLE = main.out

# Compilador
CXX = g++

# Arquivos fonte (pega todos os .cpp)
SOURCES = $(wildcard src/*.cpp) main.cpp

# Diretórios de inclusão
INCLUDES = -I./include/

# Bibliotecas
LIBRARIES = -lSDL2 -lSDL2_ttf

# Flags padrão
CXXFLAGS = -Wall -std=c++17

# Flags de DEBUG (define a macro DEBUG e inclui símbolos)
DEBUG_FLAGS = -g -O0 -DDEBUG

# Flags de RELEASE (otimizações)
RELEASE_FLAGS = -O3

# --- REGRAS PRINCIPAIS ---

# Padrão: compila em modo release
all: release

# Compilação em modo release (otimizado)
release: CXXFLAGS += $(RELEASE_FLAGS)
release:
	@echo "--------------------------------------"
	@echo "Compilando simuBox em modo RELEASE"
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES) $(INCLUDES) $(LIBRARIES)


# Compilação em modo debug (com símbolos e macros DEBUG)
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug:
	@echo "--------------------------------------"
	@echo "Compilando simuBox em modo DEBUG"
	@echo "--------------------------------------"
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES) $(INCLUDES) $(LIBRARIES)

# Execução em modo release
run: release
	@echo "--------------------------------------"
	@echo "Iniciando $(EXECUTABLE) em modo RELEASE"
	@echo "--------------------------------------"
	./$(EXECUTABLE)

# Execução em modo debug (compila + roda com debug)
debug-run: debug
	@echo "--------------------------------------"
	@echo "Iniciando simuBox em modo DEBUG"
	@echo "Executavel: $(EXECUTABLE)"
	@echo "Arquivos fonte:"
	@ls -l main.cpp src/*.cpp
	@echo "--------------------------------------"
	@./$(EXECUTABLE)

# Limpa o executável
clean:
	@echo "Limpando arquivos gerados..."
	rm -f $(EXECUTABLE)
	@echo "Limpeza concluída!"

# Ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make all        - Compila em modo release (padrão)"
	@echo "  make debug      - Compila em modo debug"
	@echo "  make run        - Compila (release) e executa"
	@echo "  make debug-run  - Compila (debug) e executa"
	@echo "  make clean      - Remove o executável"
	@echo "  make help       - Mostra esta ajuda"

.PHONY: all release debug run debug-run clean help

