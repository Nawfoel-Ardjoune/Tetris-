#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct block {
  int * x;
  int * y;
  int taille;
};typedef struct block block_t;

void afficheBlock(block_t block);
int * make_place(int taille);
void testAndPut(int * champ, int x, int y,int taille,int type);
void pose(int * tab, int x, int y, block_t block);
void liberer(int * tab, int taille, int * score);
void remplir(int * tab, int taille);
void affplateau(int * tab, int taille);
void viderLeBuffer();
int saisir(char * maChaine, int longueur);
int changeToInt();
void menu(char* filename);
int * plateau(int taille);
void affplateau();

