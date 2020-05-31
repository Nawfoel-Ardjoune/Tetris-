//#include"tetris.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<string.h>

int * make_place(int taille){
	printf("make start\n");
	int * plateau =NULL;
	plateau = malloc((taille*taille)*sizeof(char));
	assert(plateau);
	return plateau;
	printf("end make\n");
}

static void drawLine(int * tab, int taille, int x0, int y0, int x1, int y1, int value) {
	float y = 0.0f, pente;
	int u = x1 - x0, v = y1 - y0, pas, depassement;
  if(abs(u) > abs(v)) { // 1er octan
  	pente = v / (float)abs(u);
  	pas = u < 0 ? -1 : 1;
  	depassement = u + pas;
  	for (int x = 0; x != depassement; x += pas) {
  		int nx = x + x0;
  		int ny = ((int)y) + y0;
  		if(nx >= 0 && nx < taille && ny >= 0 && ny < taille)
  			tab[ny * taille + nx] = value;
  		y += pente;
  	}
  } else { // 2eme octan
  	pente = u / (float)abs(v);
  	pas = v < 0 ? -1 : 1;
  	depassement = v + pas;
  	for (int x = 0; x != depassement; x += pas) {
  		int nx = ((int)y) + x0;
  		int ny = x + y0;
  		if(nx >= 0 && nx < taille && ny >= 0 && ny < taille)
  			tab[ny * taille + nx] = value;
  		y += pente;
  	}
  }
}

static void drawCircle(int * tab, int taille) {
	printf("drawstart");
	int x, r2 = ((taille/2) * (taille/2));
	float y, finx = ((int)ceil((double)(taille/2-1) * M_SQRT1_2)) + 1;
	for(x = 0; x < finx; ++x) {
		y = sqrt(r2 - x * x) + 0.1f;
		tab[taille*(((int)y)+taille/2)+(x+taille/2)] = 1;
		tab[taille*(((int)y)+taille/2)+(-x+taille/2)] = 1;
		tab[taille*(-((int)y)+taille/2)+(x+taille/2)] = 1;
		tab[taille*(-((int)y)+taille/2)+(-x+taille/2)] = 1;
		tab[taille*(((int)x)+taille/2)+(((int)y)+taille/2)] = 1;
		tab[taille*(-((int)x)+taille/2)+(((int)y)+taille/2)] = 1;
		tab[taille*(((int)x)+taille/2)+(-((int)y)+taille/2)] = 1;
		tab[taille*(-((int)x)+taille/2)+(-((int)y)+taille/2)] = 1;
	}
	printf("fin draw\n");
}
static void drawTriangle(int * tab, int taille){
	int x=0;
	float y=0;
	for(x=0,y=taille/2;x<taille;x++){
		tab[(int)y*taille+x] = 1;
	}
	for(x=0,y=taille/2;y>=0;y--,x++){
		tab[(int)y*taille+x] = 1;
		tab[(int)y*taille+(taille-x)] =1 ;
	}
}
void testAndPut(int * champ, int x, int y,int taille,int type){
  if(type == 1){ /*ICI POUR LE CERCLE*/
	if(champ[x+y*taille]==0)
	{
		printf("IN IF\n");
		champ[x+y*taille] = 2;
	}
}

printf("out IF\n");
  // else if(type == 2){	/*ICI POUR LE TRIANGLE*/

  // }
  // else if(type == 3){	/*ICI POUR LE LOSANGE*/

  // }
}

void affplateau(int * tab, int taille){
	printf("start aff\n");
	int x=0, y=0;
	for(y=0;y<taille;y++){
		for(x=0;x<taille-1;x++){
			if(tab[x+y*taille] == 1){
				printf("#");
			}else if(tab[x+y*taille] == 2){
				printf("*");
			}else{
				printf(" ");
			}
		}
		if(tab[x+y*taille] == 1){
			printf("#\n");
		}else if(tab[x+y*taille] == 2){
			printf("*\n");
		}else{
			printf(" \n");
		}
	}
	printf("fin aff\n");
}

void remplir(int * tab, int taille){
	printf("start arp\n");
	int x=0, y=0;
	for(y=0;y<taille;y++){
		for(x=0;x<taille;x++){
			if(tab[x+y*taille] != 1){
				tab[x+y*taille] = 0 ;
			}
		}
		if(tab[x+y*taille] != 1){
			tab[x+y*taille] = 0 ;
		}
	}
	printf("fin arp\n");
}

int main(void){
	printf("Start");
	int * test = make_place(21) ;
	//drawCircle(test, 21);
	drawTriangle(test,21);
	remplir(test,21);
	testAndPut(test, 21/2,21/2,21,1);
	affplateau(test, 21);
	printf("Over");
	free(test);
	return 0;
}
