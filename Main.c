#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	menu("start.txt");
	int test = 0;
	do{
		int choix = changeToInt();
		switch(choix){
			case 1:
			printf("Test 1 OK !\n");
			test = 0;
			break;
			case 2:
			menu("rules.txt");
			test = 0;
			break;
			default: 
			printf("Erreur saisissez : 1 pour Jouer, 2 pour voir les règles !\n");
			test = 1;
		}
	}while(test);
	return 0;
}