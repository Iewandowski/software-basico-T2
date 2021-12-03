#ifndef TAGCLOUD_H_INCLUDED
#define TAGCLOUD_H_INCLUDED
#include <stdio.h>
extern  void read_words(FILE*, char*);
extern  void process_file(char***);
extern  void store_duplicate(char*);
#endif