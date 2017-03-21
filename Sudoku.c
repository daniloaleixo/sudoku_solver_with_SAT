/*********************************************/ 
/*					      
	EP1 de Metodos Formais
	Prof: Marcelo Finger 

	Alunos:
	Danilo Aleixo Gomes de Souza
	7972370

	Carlos Augusto Motta de Lima
	791228
					      */
/*********************************************/


#include <stdlib.h>
#include <stdio.h>


/* declaracoes de funcoes */
FILE *abreEntrada (char *nomeArquivo);
int *criaVetor(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9);
int contaBits(int n);
void imprimeClausulas(int v[9]);


/* variaveis globais */
int p[9][9][9], nomeVariaveis[9][9][9];
FILE *entrada, *saida;




int main(int argc, char *argv[])
{

    int num, i, j, k;
    int x = 1;
    int nVariaveisEntrada = 162972;





    entrada = abreEntrada(argv[1]);
    saida = fopen("saida", "w");


    /* coloca 0 em todos os elementos da matriz p e coloca */
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            for(k = 0; k < 9; k++)
            {
                p[i][j][k] = 0;
                nomeVariaveis[i][j][k] = x++;
            }
        }
    }

    /*coloca os numeros da entrada na matriz*/
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            fscanf(entrada, "%d", &num);
            if(num != 0)
            {
               p[i][j][k] = 1;
               nVariaveisEntrada++;
            }
        }
    }

    fprintf(saida, "p cnf 729 %d \n", nVariaveisEntrada);


    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            for(k = 0; k < 9; k++)
            {
                if(p[i][j][k] == 1) fprintf(saida, "%d 0 \n", nomeVariaveis[i][j][k] );
            }
        }
    }


    /* Clausulas para os digitos do sudoku */
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            imprimeClausulas(nomeVariaveis[i][j]);
        }
    }

    /* Clausulas para as linhas */
    for (i = 0; i < 9; i++)
    {
        for(k = 0; k < 9; k++)
        {
            imprimeClausulas(criaVetor(nomeVariaveis[i][1][k], nomeVariaveis[i][2][k],
                                       nomeVariaveis[i][3][k], nomeVariaveis[i][4][k],
                                       nomeVariaveis[i][5][k], nomeVariaveis[i][6][k],
                                       nomeVariaveis[i][7][k], nomeVariaveis[i][8][k],
                                       nomeVariaveis[i][0][k] ));
        }
    }

    /* */
    for (j = 0; j < 9; j++)
    {
        for(k = 0; k < 9; k++)
        {
            imprimeClausulas(criaVetor(nomeVariaveis[1][j][k], nomeVariaveis[2][j][k],
                                       nomeVariaveis[3][j][k], nomeVariaveis[4][j][k],
                                       nomeVariaveis[5][j][k], nomeVariaveis[6][j][k],
                                       nomeVariaveis[7][j][k], nomeVariaveis[8][j][k],
                                       nomeVariaveis[0][j][k] ));
        }
    }

    /* Clausulas para os quadrados */
    for(i = 0; i < 9; i+= 3)
    {
        for(j = 0; j < 9; j+= 3)
        {
            for(k = 0; k < 9; k++)
            {
                imprimeClausulas(criaVetor(nomeVariaveis[i][j][k], nomeVariaveis[i][j+1][k],
                                       nomeVariaveis[i][j+2][k], nomeVariaveis[i+1][j][k],
                                       nomeVariaveis[i+1][j+1][k], nomeVariaveis[i+1][j+2][k],
                                       nomeVariaveis[i+2][j][k], nomeVariaveis[i+2][j+1][k],
                                       nomeVariaveis[i+2][j+2][k] ));
            }
        }
    }


    return 0;
}

/* abre o arquivo de entrada, dando erro se o arquivo nao existir e se existir retorna seu file handle */
FILE *abreEntrada (char *nomeArquivo)
{
    FILE *entrada;
    entrada = fopen(nomeArquivo, "r");
    if (entrada == NULL)
    {
        fprintf(stderr, "ERRO!! Nao consegui abrir o arquivo %s\n", nomeArquivo);
        exit(-1);
    }

    return entrada;
}

/* cria um vetor que sera usado na impressao das clausulas */
int *criaVetor(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9)
{
    int i;
    int vetor[] = {x1, x2, x3, x4, x5, x6, x7, x8, x9};
    int *vet = malloc(9*sizeof(int));
    for (i = 0; i < 9; i++)
    {
        vet[i] = vetor[i];
    }
    return vet;
}


/*  Conta o numero de bits com valor 1 no numero n */
int contaBits(int n)
{
    int r = 0;
    while (n != 0)
    {
        r += n % 2;
        n /= 2;
    }
    return r;
}

/*  imprime um conjunto de clausulas no formato CNF com as
    variaveis cujos nomes sao os elementos do vetor 'v'.
    A valoracao desse conjunto de clausulas so e' verdadeira
    quando apenas uma das variaveis tem valoracao verdadeira */
void imprimeClausulas(int v[9])
{
    int i, j, n = (1 << 9) - 1, bit, x;

    for(i = 0; i <= n; i ++)
    {
        if(contaBits(i) == 1) continue;
        x = i;
        for(j = 0; j < 9; j ++)
        {
            bit = x % 2;
            x /= 2;
            if(bit) {
                fprintf(saida, "-%d ", v[j]);
            }
            else
            {
                 fprintf(saida, "%d ", v[j]);
            }

        }
        fprintf(saida, "0\n");
    }
}






