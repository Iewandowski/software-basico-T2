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
}

void read_words(FILE *in_file, char *text) {
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

int
main (int argc, char **argv)
{
  int optc = 0;
  FILE *in_file;
  char word[50];


while (true)
{
  switch (optc) {
    case 'r':
    read_words(in_file, &word);
    printf("%s\n", word[0]);
    break;
  }
}
  return 0;
}