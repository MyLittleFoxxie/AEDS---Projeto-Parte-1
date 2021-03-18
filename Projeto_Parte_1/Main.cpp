/****************

LAED1 - Projeto Parte 1

Alunos(as): Vitor Brandão Raposo e Gabriel Bernalle

Data:19/03/21

****************/
#include <stdlib.h>
#include <stdio.h>

void reduzPadrao(int* elementosLista, int tamanho);
void procurarPadrao(int* elementosLista, int tamanho);

void mapeiaPadrao(int* elementosLista, int tamanho){
	int listaFinal[tamanho];

	for(int i = 0; i < tamanho; i++){
		if(elementosLista[i] == 0) listaFinal[i] = 1; 
		if(elementosLista[i] == 128) listaFinal[i] = 2; 
		if(elementosLista[i] == 255) listaFinal[i] = 3; 
	}

	procurarPadrao(listaFinal, tamanho);
}

void reduzPadrao(int* elementosLista, int tamanho){
	int *auxList;
	auxList = (int*) malloc(tamanho * sizeof (int));
	auxList[0] = elementosLista[0];
	int aux = elementosLista[0];
	int j = 0;

	for(int i = 0; i < tamanho; i++){
		if(elementosLista[i] != aux){
			j++;
			auxList[j] = elementosLista[i];
			aux = elementosLista[i];
			printf("%d ",auxList[j]); //-- Funfando --
		}
	}

	mapeiaPadrao(auxList, j+1);
}

void procurarPadrao(int* elementosLista, int tamanho)
{
	printf("\n");
	for(int i = 0; i < tamanho; i++) printf("%d ",elementosLista[i]);
	printf("\n%d", tamanho);// -- Tá chegando os números certos --

    int padrao = 0;
    int resultado = 0;

    for (int i = 0; i < tamanho; i++)
    {
        //Um case para cada etapa do padrão
        switch (padrao)
        {
            //Procura o primeiro item do padrao: 1
            case 0:
                switch (elementosLista[i])
                {
                case 1:
                    padrao++;
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
                    padrao++;
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
                    padrao++;
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
                    padrao++;
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
                    padrao++;
                    resultado++;
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
    
   // if (resultado >= 1) printf("Resultado: Padrao encontrado.\n");
	//else printf("Resultado: Padrao nao encontrado.\n");
}


//Estamos buscando a sequência 1 3 2 3 1 em um arquivo texto
int main () 
{
    FILE *arquivo;
    char nomeArquivo[100];
    int qtdItens;
    int elementosLista[qtdItens];

	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArquivo);
	arquivo = fopen(nomeArquivo, "r");

    //Escaneia a quantidade de itens
	fscanf(arquivo, "%d", &qtdItens);

    //Escaneia cada elemento e insere no vetor
	for (int i = 0; i < qtdItens; i++) fscanf(arquivo, "%d", &elementosLista[i]);

	reduzPadrao(elementosLista,qtdItens);
   // procurarPadrao(elementosLista, qtdItens);
}
