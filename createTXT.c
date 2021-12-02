
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    char palavra[50];
    int frequencia;
}Palavras;

// protótipo
void createTXT(Palavras palavras[], int numPalavras);
void createTXTordenado(Palavras palavras[], int numPalavras);
int compare(Palavras *, Palavras *);




/* 
criei essa função de gerar uma saída em TXT,
assim que tiver funcionando o restante deve ser modificada

*/


void createTXTordenado(Palavras palavras[], int numPalavras){ 
   
   qsort(palavras, numPalavras, sizeof(Palavras), compare);


    for (int i = 0; i < 10; i++){
        printf("\n%s - %d", palavras[i].palavra, palavras[i].frequencia);

    }

}

int compare(Palavras *x, Palavras *y){
    if (x->frequencia == y->frequencia){
        return 0;
    }
    else if (x->frequencia > y->frequencia){
        return -1;
    }
    else {
        return 1;
    }
}

void createTXT(Palavras palavras[], int numPalavras){ 

//gravar arquivo texto
    FILE *arq = fopen("saida.txt", "w"); //criar arquivo
    if (arq == NULL)                      // 0, FALSE
    {
        printf("Erro ao abrir o aqruivo de saída \n");
        exit(1);
    }
    //gerando txt
    fseek(arq,0,SEEK_END);// posiciona ponteiro ao final do arquivo
    for (int i = 0; i< numPalavras; i++){
        fprintf(arq, "\n%s - %d", palavras[i].palavra, palavras[i].frequencia);
    } 
 

    fclose(arq);

}


int
main (int argc, char **argv)
{

Palavras palavras[] = {{"Java", 2}, {"C", 1}, {"C#", 3}, {"JavaScript", 4}, {"Python", 5}, {"Dart", 1}, {"C++", 3}, {"Go", 2}, {"Ruby", 4}, {"PHP", 5}};



//createTXT(palavras, 10);
createTXTordenado(palavras, 10);
createTXT(palavras, 10);

}