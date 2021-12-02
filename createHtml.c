
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    char palavra[50];
    int frequencia;
}Palavras;

// protótipo
void createHTML(Palavras palavras[], int numPalavras);



/* 
criei essa função de gerar o HTML separado só para teste,
assim que tiver funcionando o restante deve ser modificada

*/


void createHTML(Palavras palavras[], int numPalavras){ 


//gravar arquivo texto
    FILE *arq = fopen("index.html", "w"); //criar arquivo: w 
    if (arq == NULL)                      // 0, FALSE
    {
        printf("Erro ao abrir o aqruivo de saída \n");
        exit(1);
    }
    //gerando html
    fprintf(arq, "<html>\n");
    fprintf(arq, "<title>Word Cloud");
    fprintf(arq, "</title>\n");   
    fprintf(arq, "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n");
    fprintf(arq,"</head>\n");
    fprintf(arq, "<body>\n");
    fprintf(arq, "<div class=\"para\">\n");
    
    for (int i = 0; i< numPalavras; i++){
        if (palavras[i].frequencia == 1){
            fprintf(arq, "<span class=\"text1\">");
            fprintf(arq, palavras[i].palavra);
            fprintf(arq, "</span>\n");
        }
        else if (palavras[i].frequencia == 2 ){
            fprintf(arq, "<span class=\"text2\">");
            fprintf(arq, palavras[i].palavra);
            fprintf(arq, "</span>\n");

        }
        else if (palavras[i].frequencia== 3){
            fprintf(arq, "<span class=\"text3\">");
            fprintf(arq, palavras[i].palavra);
            fprintf(arq, "</span>\n");

        }
        else if (palavras[i].frequencia == 4){
            fprintf(arq, "<span class=\"text4\">");
            fprintf(arq, palavras[i].palavra);
            fprintf(arq, "</span>\n");

        }
        else if (palavras[i].frequencia >= 5){
            fprintf(arq, "<span class=\"text5\">");
            fprintf(arq, palavras[i].palavra);
            fprintf(arq, "</span>\n");

        }

    }

    fprintf(arq, "</div>\n");
    fprintf(arq, "</body>\n");
    fprintf(arq, "</html>\n");

    fclose(arq);

}


int
main (int argc, char **argv)
{

Palavras palavras[] = {{"Java", 2}, {"C", 1}, {"C#", 3}, {"JavaScript", 4}, {"Python", 5}, {"Dart", 1}, {"C++", 3}, {"Go", 2}, {"Ruby", 4}, {"PHP", 5}};



createHTML(palavras, 10);


}