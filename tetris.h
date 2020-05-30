#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viderLeBuffer();
int saisir(char * maChaine, int longueur);
int changeToInt();
void menu(char* filename);

struct block {
  int * x;
  int * y;
  int taille;
};typedef struct block block_t;


  
