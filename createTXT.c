
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    char palavra[50];
    int frequencia;
}Palavras;


/* 
criei essa função de gerar uma saída em TXT,
assim que tiver funcionando o restante deve ser modificada

*/

void createTXT(Palavras palavras[], int numPalavras){ //no momento para funcionar deve receber um vetor de struct com palavra e frequencia


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



createTXT(palavras, 10);


}