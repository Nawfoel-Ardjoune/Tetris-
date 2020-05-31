#include "tetris.h"

void viderLeBuffer(){
	int c =0;
	while(c != '\n' && c != EOF){
		c= getchar();
	}
}

int saisir(char * maChaine, int longueur){
	char * laSaisie = NULL;

	if(fgets(maChaine, longueur, stdin) != NULL){

		laSaisie = strchr(maChaine, '\n');
		if (maChaine != NULL)
		{
			*laSaisie = '\0';
		}
		else{
			viderLeBuffer();
		}
		return 1;
	}

	else{
		viderLeBuffer();
		return 0;
	}
}

int changeToInt(){
	char maChaine[10];
	if(saisir(maChaine,10)){
		return atoi(maChaine);
	}else{
		return 0;
	}
}

void menu(char* filename){
	char c;
	FILE * fp;
	fp = fopen(filename,"r");
	c = fgetc(fp);
	if(fp == NULL){
		printf("Une erreur du fopen est survenu\n");
		exit(1);
	}
	while(c != EOF){
		printf("%c",c);
		c = fgetc(fp);
	}
	fclose(fp);
}

int main(int argc, char const *argv[])
{
	int test = 0;
	int suite = 0;
	int compteur = 0;
	menu("start.txt");
	
	do{/* ##ICI LE SWITCH POUR LE MENU##  */
		printf("Saisissez : 1 pour Jouer, 2 pour voir les règles\n"); 
		int choix = changeToInt();
		switch(choix){
			case 0:
				return 0;
				break;
			case 1:
				/* ## LANCE LE JEU ICI ## */
				test = 0;
				break;
			case 2:
				menu("rules.txt");
				test = 0;
				break;
			default: 
				printf("Erreur ! ");
				test = 1;
		}
	}while(test);
	
	do{
		/*code du jeu*/
		do{/* ##ICI SWITCH POUR CERCLE TRIANGLE LOSANGE OU QUITTER## */
			printf("Cercle: 1, Triangle: 2, Losange: 3 OR Press 0 to quit\n");
			int type =0;
			int choix2 = changeToInt();//
			switch(choix2){
				case 1:
					printf("cercle\n");
					suite = 0; //TODO A MODIFIER UNE FOIS LES BOUCLES FAITES 
					test = 0;
					type =1;
				break;
				case 2:
					printf("triangle\n");
					suite = 0; //TODO A MODIFIER UNE FOIS LES BOUCLES FAITES 
					test = 0;
					type = 2;
				break;
				case 3:
					printf("Losange\n");
					suite = 0;
					type = 3;
					test = 0;
				case 0:
					return 0;
				// suite = 0; //TODO A MODIFIER UNE FOIS LES BOUCLES FAITES 
				// test = 0;
				// break;
				default: 
					printf("Erreur !\n");
					suite = 1; //TODO A MODIFIER UNE FOIS LES BOUCLES FAITES 
					test = 1;
			}
		}while(test);
	}while(suite);
	
	return 0;
}