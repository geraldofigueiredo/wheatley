# wheatley

**Aluno**: Geraldo Figueiredo.

**Matrícula**: 11513834

**Linguagem utilizada**: C++14.

## Entregavel 1: Planejamento de Caminho do Turtlebot

Implementar o algoritmo de mapa de rotas probabilisticas (PRM) para planejamento de caminhos.

### Dependências

    sudo apt install git build-essential cmake

### Instalação e Execução

    git clone https://github.com/geraldofigueiredo/wheatley.git
    cd wheatley
    cmake .
    make
    ./wheatley
    
### Demonstração

https://www.youtube.com/watch?v=yO6YPUWzBw8&ab

- Mapa
  
![Entrada](resources/map.png?raw=true "Entrada")
- Nós gerados aleatoriamente

![Entrada](resources/1-nodes.png?raw=true "Entrada")
- Conexões entre os nós

![Entrada](resources/2-nodesConnection.png?raw=true "Entrada")
- Rota gerada a partir do caminho mínimo do grafo gerado

![Saida](resources/3-route.png?raw=true "Saída")
