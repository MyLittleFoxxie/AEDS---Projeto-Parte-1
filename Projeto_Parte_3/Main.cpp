/****************
LAED1 - Projeto Parte 2
Alunos(as): Vitor Brandão Raposo e Gabriel Bernalle
Data: 26/03/21

****************/
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

//Estamos buscando a sequência “1 3 1 3 1 3 1 3 1 3 1 3 1" nessa ordem
bool procurarPadrao(int* elementosLista, int qtdItens)
{
    int padrao = 0, resultado = 0;

    for (int i = 0; i < qtdItens; i++)
    {
        if (padrao == 12)
            resultado = 1;
        
        switch (padrao)
        {
        case 0:
            if (elementosLista[i] == 1)
                padrao++;

            else
                padrao = 0;

            break;
        
        default:
            if (elementosLista[i] == 1 && elementosLista[i - 1] == 3)
                padrao++;

            else if (elementosLista[i] == 3 && elementosLista[i - 1] == 1)
                padrao++;

            else
                padrao = 0;

            break;
        }
    }
    
    if (resultado == 1){
    	printf("Resultado: Pista com faixa de pedestres\n");
		return true;
	}
    else{
		return false;
	}      
}


bool mapeiaPadrao(int* elementosLista, int qtdItens)
{
	int listaFinal[qtdItens];

	for(int i = 0; i < qtdItens; i++){
		if(elementosLista[i] == 0) listaFinal[i] = 1; 
		if(elementosLista[i] == 128) listaFinal[i] = 2; 
		if(elementosLista[i] == 255) listaFinal[i] = 3; 
	}

	bool padrao = procurarPadrao(listaFinal, qtdItens);
	if (padrao == true) return true;
	else return false;
}


bool reduzPadrao(int* elementosLista, int qtdItens)
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

	bool padrao = mapeiaPadrao(auxList, qtdItens);

	if(padrao == true) return true;
	else return false;
}


int main () 
{
//	struct timeval t;

    FILE *arquivo;
    char nomeArquivo[100];
    int qtdlinhas;
	int qtdItens;

	printf("Digite o nome do arquivo: ");
	  scanf("%s", nomeArquivo);
	  arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL){
        printf("\nERROR: IMPOSSIBLE TO OPEN THE FILE");
        exit(1);
    }

	bool padrao;
    //Escaneia a quantidade de itens
	fscanf(arquivo, "%d", &qtdlinhas);

	for(int i = 0; i < qtdlinhas; i++){
		// Escaneia a quantidade de Linhas
    	fscanf(arquivo, "%d", &qtdItens);
		int elementosLista[qtdItens];

    	//Escaneia cada elemento e insere no vetor
	  	for (int j = 0; j < qtdItens; j++) fscanf(arquivo, "%d", &elementosLista[j]);

	  		padrao = reduzPadrao(elementosLista,qtdItens);
		if(padrao == true) break;
	}
	if(padrao == false) printf("Resultado: Pista sem faixa de pedestres\n");

    fclose(arquivo);
	
	return(0);
}