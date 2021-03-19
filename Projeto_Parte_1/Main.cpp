/****************
LAED1 - Projeto Parte 1
Alunos(as): Vitor Brandão Raposo e Gabriel Bernalle
Data:19/03/21
****************/
#include <stdlib.h>
#include <stdio.h>

//Estamos buscando a sequência 1 3 2 3 1 em um arquivo texto
void procurarPadrao(int* elementosLista, int qtdItens)
{
    int padrao = 0, resultado = 0;

    for (int i = 0; i < qtdItens; i++)
    {
        //Um case para cada etapa do padrão
        switch (padrao)
        {
            //Procura o primeiro item do padrao: 1
            case 0:
                switch (elementosLista[i])
                {
                    case 1:
                        padrao = 1;
                        break;

                    default:
                        padrao = 0;
                        break;
                }
                break;

            //Procura o segundo item do padrao: 3
            case 1:
                switch (elementosLista[i])
                {
                    case 3:
                        padrao = 2;
                        break;

                    case 1:
                        padrao = 1;
                        break;

                    default:
                        padrao = 0;
                        break;
                }
                break;

            //Procura o terceiro item do padrao: 2
            case 2:
                switch (elementosLista[i])
                {
                    case 2:
                        padrao = 3;
                        break;

                    case 1:
                        padrao = 1;
                        break;

                    default:
                        padrao = 0;
                        break;
                }
                break;

            //Procura o quarto item do padrao: 3
            case 3:
                switch (elementosLista[i])
                {
                    case 3:
                        padrao = 4;
                        break;

                    case 1:
                        padrao = 1;
                        break;

                    default:
                        padrao = 0;
                        break;
                }
                break;

            //Procura o quinto item do padrao: 1
            case 4:
                switch (elementosLista[i])
                {
                    case 1:
                        padrao = 5;
                        resultado = 1;
                        break;

                    default:
                        padrao = 0;
                        break;
                }
                break; 

            default:
                padrao = 0;
                break;
        } 
    }   
    
    if (resultado == 1)
    {
        printf("Resultado: Padrao encontrado.\n");
    } 
    else
    {
        printf("Resultado: Padrao nao encontrado.\n");
    }
}


void mapeiaPadrao(int* elementosLista, int qtdItens)
{
	int listaFinal[qtdItens];

	for(int i = 0; i < qtdItens; i++){
		if(elementosLista[i] == 0) listaFinal[i] = 1; 
		if(elementosLista[i] == 128) listaFinal[i] = 2; 
		if(elementosLista[i] == 255) listaFinal[i] = 3; 
	}

	procurarPadrao(listaFinal, qtdItens);
}


void reduzPadrao(int* elementosLista, int qtdItens)
{
	int *auxList;
	auxList = (int*) malloc(qtdItens * sizeof (int));
	auxList[0] = elementosLista[0];
	int aux = elementosLista[0];
	int j = 0;

	for(int i = 0; i < qtdItens; i++){
		if(elementosLista[i] != aux){
			j++;
			auxList[j] = elementosLista[i];
			aux = elementosLista[i];
		}
	}

    qtdItens = j + 1;

	mapeiaPadrao(auxList, qtdItens);
}


int main () 
{
    FILE *arquivo;
    char nomeArquivo[100];
    int qtdItens;

	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArquivo);
	arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL){
        printf("\nERROR: IMPOSSIBLE TO OPEN THE FILE");
        exit(1);
    }

    //Escaneia a quantidade de itens
	fscanf(arquivo, "%d", &qtdItens);

    int elementosLista[qtdItens];

    //Escaneia cada elemento e insere no vetor
	for (int i = 0; i < qtdItens; i++)
    {    
        fscanf(arquivo, "%d", &elementosLista[i]);
    }

	reduzPadrao(elementosLista,qtdItens);

    fclose(arquivo);
}
