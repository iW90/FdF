# 42 Cursus - FdF

<img src="https://game.42sp.org.br/static/assets/achievements/fdfm.png" alt="completion-with-bonus-badge" align="left">

FDF é a abreviação de 'Fil de Fer' em francês, que significa 'wireframe model' (modelo de estrutura de arame). Este projeto de `computação gráfica` trata da representação de uma paisagem como um objeto 3D no qual todas as superfícies são contornadas por linhas, permitindo o aprendizado de algumas noções básicas de programação gráfica, especialmente como colocar pontos no espaço, juntá-los e, mais importante, como ver a cena de um ponto de vista específico. Foi utilizada a MiniLibX, uma biblioteca desenvolvida internamente pela 42 que inclui o básico necessário para abrir uma janela, colocar imagens na tela e lidar com eventos de mouse e teclado.

## Bônus <img src="https://img.shields.io/badge/GRADE-115%2F100-green" align="right">

Além de simplesmente exibir na tela uma projeção isométrica de um [arquivo](./maps/42.fdf), foram implementadas algumas funcionalidades:

- **Zoom (teclas <kbd>+</kbd> e <kbd>-</kbd>, ou <kbd>scroll wheel</kbd>)**: Aumenta ou diminui a projeção.
- **Movimentação (setas <kbd>←</kbd>, <kbd>↑</kbd>, <kbd>→</kbd> e <kbd>↓</kbd> do teclado)**: Movimenta para cima, para baixo, para esquerda e para a direita.
- **Rotação (clicando através do menu)**: Rotaciona nos três eixos, **x**, **y** e **z**.
- **Reset (tecla <kbd>backspace</kbd>)**: Retorna a projeção para sua versão inicial.
- **Fechar a janela (tecla <kbd>esc</kbd>)**: Fecha a janela.

## Instalação da MiniLibX

> Necessária para a execução do programa (no Linux).

- Passo a Passo, no terminal:

1. `git clone https://github.com/42Paris/minilibx-linux`
2. `cd minilibx-linux`
3. `sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev`
4. `sudo mv ./man/man1 /usr/local/man/`
5. `sudo mv ./mlx.h /usr/local/include/`
6. `make`
7. `sudo mv ./libmlx.a /usr/local/lib/`

- Exemplo de compilação:

`cc -Wall -Wextra -Werror main.c -lbsd -lmlx lXext -lX11`

## Mapas

Geradas a partir de arquivos com extensão `.fdf`, as imagens apresentadas na tela possuem 3 dimensões, e são inclinadas de acordo com a projeção isométrica.

> Uma visão isométrica de um objeto pode ser obtida escolhendo-se a direção de visualização de modo que os ângulos entre as projeções dos eixos x, y e z sejam todos iguais, ou 120°. Por exemplo, com um cubo, isso é feito primeiro olhando diretamente para uma face. Em seguida, o cubo é girado ±45° em torno do eixo vertical, seguido por uma rotação de aproximadamente 35,264° (precisamente arcsin 1⁄√3 ou arctan 1⁄√2, que está relacionado ao ângulo mágico) sobre o eixo horizontal.

Estes arquivos .fdf estão em 2 dimensões, como o modelo abaixo:

```
0 0 0 0 0
0 1 1 1 0
0 1 2 1 0
0 1 1 1 0
0 0 0 0 0
```

- Cada número representa um "ponto" no mapa, e ligando-se um ponto no outro, obtemos a projeção.
- A quantidade de números na horizontal é referente à largura.
- A quantidade de números na horizontal é referente à profundidade.
- O valor representado pelos números é referente à altura (podendo ser positivo ou negativo).

O programa também interpreta mapas coloridos, através da leitura de cores representadas em valores hexadecimais logo em seguida do número onde a cor deve aparecer (separado por vírgula, sem espaço):

```
0 0 0 0 0
0 1 1 1 0
0 1 2,0xf00 1 0
0 1 1 1 0
0 0 0 0 0
```

## Compilação e Execução

### Versão Estática
Para a versão estática (sem funcionalidades do bônus), digite no terminal:

```
make
```

E para executar, alguns mapas estão na pasta [maps](./maps/). É necessário que o arquivo possua a extensão `.fdf`:

```
./fdf maps/42.fdf
```

### Versão com Bônus

Já para a versão completa com o bônus, digite no terminal:

```
make bonus
```

E para executar, funciona da mesma forma que a versão estática, mudando somente o nome do programa:

```
./fdf_bonus maps/42.fdf
```

## Visualização

> *Soon.*
