#ifndef TAGCLOUD_H_INCLUDED
#define TAGCLOUD_H_INCLUDED
#include <stdio.h>
extern void read_words(FILE*, char*);
extern void process_file(char***);
extern void store_duplicate(char*);

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
#endif