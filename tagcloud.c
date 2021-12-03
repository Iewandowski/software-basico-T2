/*  tagcloud -- tag cloud generator
    Copyright (C) 2021-2022 Carol Lewandowski & Leticia Flores

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include <getopt.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tagcloud.h"


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
/*lê arquivo e armazena palavras em string*/
void process_file(char ** lines[200]) {
  int i;      //variavel para for
  FILE *file_handle = fopen ("lorem-ipsum.txt", "r");

  for (i =0; i < 200; ++i) {
    lines[i] = malloc (128);
    fscanf (file_handle, "%127s", lines[i]);
  }
  for (i =0; i < 200; ++i)
    free (lines[i]);
}

char print_file() {

}

void find_duplicate(char lines[200], int * res) {
  int j = 0;
  int count = 0;
  for (int i = 0; i < 200; i++) 
  {
    for(j=i+1; j<200; j++)
      {
        if(lines[i] == lines[j])
          {
            count++;
            break;
          }
      }
  }
  *res = count;
  printf("%d", count);
}

void store_duplicate(char lines[200]) {
//pra facilitar o mecanismo de busca
//implementar bubble sort
//resultado do bubble sort: actualWord[x], nextWord[x]
//char aux[arraySize], int arrrayInt[arraySize];
//char aux[0] = actualWord[0];
//for i = 0; i < arraySize, i++ 
//if actualWord[i] = nextWord[i + 1]
//      arrrayInt[j] += 1;
// else 
//       j++;
//       aux 
}

int
main (int argc, char **argv)
{
  char * lines[200];
  process_file(lines);
  //for (i =0; i < 200; ++i)
  //  printf ("%s\n", lines[i]);

  FILE *in_file;
     
/* Opção do usuário */
    char q;

    while(true){
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
    }

    return 0;
}