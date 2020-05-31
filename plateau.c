#include"tetris.h"
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
}

void pose(int * tab, int x, int y, block_t block){
	int i =0;
	for(i=0;i<block.taille;i++){
		tab[(block->x[i]+x)+(block->y[i]+y)*block.taille];
	}
}

void affplateau(int * tab, int taille){
	printf("   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27\n");
	printf("   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n\n");
	int x=0, y=0;
	for(y=0;y<taille;y++){
			printf(" %d ",y);
		for(x=0;x<taille-1;x++){
			if(tab[x+y*taille] == 1){
				printf("#");
			}else if(tab[x+y*taille] == 2){
				printf("*");
			}else{
				printf("•");
			}
			printf(" ");
		}
		if(tab[x+y*taille] == 1){
			printf("#\n");
		}else if(tab[x+y*taille] == 2){
			printf("*\n");
		}else{
			printf("•\n");
		}
		printf(" \n");
	}
}

void remplir(int * tab, int taille){
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
}

void liberer(int * tab, int taille, int * score){
	int x=0, y=0;
	int buffer[1024];
	int i = 0;
	for(y=0;y<taille;y++){
		for(x=0;x<taille;x++){
			if(tab[x+y*taille] = 1){
				buffer[i++]=(x+y*taille);
			}
		}
	}

}

