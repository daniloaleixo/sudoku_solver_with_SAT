# Sudoku solver with SAT

## Introdução
Esse programa é um exercício da disciplina de Métodos Formais em Programação, presidida pelo Prof. Dr. Marcelo Finger, do curso de Bacharelado em Ciência da Computação do Instituto de Matemática e Estatística da Universidade de São Paulo (IME-USP).

## OBJETIVO
O programa final deve receber um arquivo de entrada que represente a situação inicial de um jogo de sudoku e, à partir dele, gerar uma fórmula (no formato adequado) para servir de entrada ao programa "zchaff", resolvedor SAT, que responderá se a fórmula for satisfazível e retornará uma possível solução.

## COMPILAÇÃO
Para compilar o programa basta usar o comando 'make' no diretório onde se encontra- um arquivo Makefile 
```sh
make
```

## ENTRADA
A entrada é um arquivo simples que contém todos os números presentes na grade do sudoku e os espaços em branco preenchidos com 0

## LÓGICA
O principal desafio desse exercício-programa foi construir uma fórmula que modelasse devidamente o problema do sudoku. Sabemos das regras do jogo e casos que precisamos isolar para garantir que a variável foi colocada no lugar certo, por exemplo, não podemos ter nenhuma variável igual em uma mesma linha, coluna ou quadrado.
Primeiramente pensamos em um caso onde 3 variáveis só poderiam ter uma validação satisfazível, que seria onde somente uma das variáveis fosse verdade. Pela tabela da verdade chegamos em uma fórmula que em seguida foi expandida para 9 variáveis, desse jeito para 9 variáveis tinhamos uma fórmula que só era verdade quando somente uma das variáveis era verdade.
Com esta formula precisamos verificar que dentro de um espaço da matriz gerado pelo sudoku, só existe uma variavel de 1 a 9 valida. Alem disso precisamos verificar para as linhas se só existe uma variavel d que satisfaça esta linha, ou seja verificar que d nao é repetida, sendo d entre 1 e 9, assim verificamos para todas as variáveis de 1 a 9 para as linhas, assim como para as colunas e quadrados.
Por fim como os numeros que vêm da entrada implicam em atomos que serão sempre verdade, adicionamos a essa fórmula essas clausulas que sempre serão verdade.

