/*  tagcloud -- tag cloud generator
    Copyright (C) 2021-2022 Carol Lewandowski & Leticia Flores

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include <getopt.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define PROGRAM_NAME "tagcloud"

#define AUTHORS \
  proper_name ("Carol Lewandowski"), \
  proper_name ("Leticia Flores")


void
usage ()
{
    printf("Texto usage\n\
            - Op l -  O tag cloud generator gera nuvem de palavras a partir de um aquivo txt.\n\
            - Op i -  Realiza a leitura de palavras em um arquivo txt. Informar nome do arquivo. \n\
            - Op t -  Exibe o resultado em arquivo txt. Palavras e frequencia. \n\
            - Op g -  Exibe o resultado no navegador como Tag Cloud.\n\
            - Op s -  Encerra o programa. \n");

}
/* Chamada da função de leitura */
void read_words(FILE* in_file, char* text) {
  char in_name[80];
  printf("Enter file name:\n");
    scanf("%s", in_name);

    in_file = fopen(in_name, "r");

    if (in_file == NULL)
        printf("Can't open %s for reading.\n", in_name);
    else
    {
        while (fscanf(in_file, "%s", text) != EOF)
        {
            printf("%s\n", text);
        }
        fclose(in_file);
    }
}

void process_file(FILE* in_file) {
   char ch, *line;  
    size_t len = 0, read;  
    char words[1000][1000], word[20];  
    int i = 0, j, k, maxCount = 0, count;  
  char in_name[80];
  printf("Enter file name:\n");
    scanf("%s", in_name);
    in_file = fopen(in_name, "r");

    if (in_file == NULL)
        printf("Can't open %s for reading.\n", in_name);
    else {
      while ((read = getline(&line, &len, in_file)) != -1) {  
          
        for(k=0; line[k]!='\0'; k++){  
            //Here, i represents row and j represents column of two-dimensional array words   
            if(line[k] != ' ' && line[k] != '\n' && line[k] != ',' && line[k] != '.' ){  
                words[i][j++] = tolower(line[k]);  
            }  
            else{  
                words[i][j] = '\0';  
                //Increment row count to store new word  
                i++;  
                //Set column count to 0  
                j = 0;  
            }  
        }  
    }  

    }
}
/*
void find_duplicate() {
  for (int i = 0; i < size; i++) 
  {
    for(j=i+1; j<size; j++)
      {
        if(arr[i] == arr[j])
          {
            count++;
            break;
          }
      }
  }
}*/
/* Chamada da função principal */
/*
void 
tcg()
{ 
} 
*/

int
main (int argc, char **argv)
{
  int optc = 0;
  FILE *in_file;
  char word[50];
  int size = 0;
  //read_words(in_file, &word);
  process_file(in_file);
  printf("%s\n", word[0]);

while (true)
{
  switch (optc) {
    case 'r':
    process_file(in_file);
    printf("%s\n", word[0]);
    break;
  }
}
     /* Opção do usuário */
    char q;

    do{
        printf("\n\nTAG Cloud:\
        \nu -> para acessar o usage; \
        \ni -> para abrir e ler arquivo;\
        \nl -> para executar a funcao principal;\
        \nt -> para visulizar saida em texto;\
        \ng -> para visaulizar saida grafica no navegador\
        \ns -> para sair \n:");

        fflush(stdin);	     
        scanf("%c", &q);     /* Le a opcao do usuario */
        fflush(stdin);       

  switch(q) {
            case 'u': case 'U':		/* Exibe o usage */
                usage(); 
                break;

            case 'i': case 'I':		/* Abertura e leitura do arquivo */
                lerArquivo();
            	break;   

            case 'l': case 'L':		/* função principal do programa */
                tcg();
                break;    

            case 't': case 'T':		/* função para saida em txt */
               
                break;    

            case 'g': case 'G':		/* função para saida no navegador */
               
                break;                  

            case 's': case 'S':		/* Sair do programa */
            	break;

            default:
            	printf("\n Opcao invalida");
        }
    } while ((q != 's') && (q != 'S') );

    return 0;
}