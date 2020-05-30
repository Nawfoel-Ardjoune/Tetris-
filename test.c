#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])

{
  int taille;
  
  	free(tab.main.array);
	aff tab(taille);
	
	/* code */
	FILE *fp;
	fp = fopen("rules.txt","r");
	if(fp==NULL){
		printf("Erreur");
		exit(1);
	}
	char c = fgetc(fp);
	while(c != EOF){
		printf("%c",c);
		c = fgetc(fp);
	}
	fclose(fp); 

	return 0;

}
