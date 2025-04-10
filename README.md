# simuBox 🚀

Simulador gráfico interativo usando SDL2

## 📦 Dependências

Certifique-se de ter instalado:

```bash
# Ubuntu/Debian
$ sudo apt-get install libsdl2-dev libsdl2-ttf-dev
```

## **🛠 Compilação e Execução**

| **Comando** | **Descrição** |
| --- | --- |
| `make` | Compila em modo release (otimizado) |
| `make debug` | Compila com símbolos de depuração |
| `make run` | Compila (release) e executa |
| `make debug-run` | Compila (debug) e executa com logs ativos |
| `make clean` | Remove arquivos gerados |

## 🎨 Estrutura do Projeto


simuBox/
├── include/    # Cabeçalhos (.h)
├── src/        # Código fonte (.cpp)
├── main.cpp    # Ponto de entrada
└── Makefile    # Sistema de build


## 🔍 Debug Avançado
Para depuração com gdb:

``` bash
$ make debug
$ gdb ./main.out
```