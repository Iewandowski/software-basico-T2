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

void process_file(char ** lines[200]) {
  int i;
  FILE *file_handle = fopen ("lorem-ipsum.txt", "r");

  for (i =0; i < 200; ++i) {
    lines[i] = malloc (128); /* allocate a memory slot of 128 chars */
    fscanf (file_handle, "%127s", lines[i]);
  }
  for (i =0; i < 200; ++i)
    free (lines[i]); /* remember to deallocated the memory allocated */
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
  int i = 0, j = 0, n = 0, count = 1;
  int dup[200];
  for(i = 0; i < 200; i++) {
    scanf("%d", &lines[1]);
    dup[i] = -1;
  }
  for(i = 0; i < 200; i++) {
    count = 1;
    for(j = i + 1; j < 200; j++) {
    if(lines[i] == lines[j]) 
    {
      count++;
      dup[j] = 0;
    }      
    }
    if(dup[i] != 0) 
    {
      dup[i] = count;
    }
  }
  
  printf("Duplicate Elements:");
  for(i = 0; i < 200; i++) {
    if(dup[i] > 1) {
      printf("%d", lines[i]);
    }
  }
}

int
main (int argc, char **argv)
{
  int i = 0;
  char * lines[200];
  int n; 
  process_file(lines);
  //for (i =0; i < 200; ++i)
  //  printf ("%s\n", lines[i]);
  //find_duplicate(lines, &n);
  store_duplicate(lines);

  int optc = 0;
  FILE *in_file;
  char * vet = NULL;
  char word[50];
  char words[50];
return 0;
while (true)
{
  switch (optc) {
    case 'r':

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