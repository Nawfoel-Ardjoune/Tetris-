#include "tetris.h"
/*!\
*Attention ici il n'y a que les block de base
*Je pourrai tous les indexe
*Je devrais peu etre les mettre directement dans un header.h
*/

/*Faire leur symetrique*/
block_t block1{
  int x = {0,0,1};
  int y = {0,-1,0};
  int taille = 3; 
}
block_t block2{
  int x = {0,1,1};
  int y = {0,0,-1};
  int taille = 3; 
}
/*Faire les symetrique*/
block_t block3{
  int x = {0,0,1,2};
  int y = {0,-1,0,0};
  int taille = 4; 
}
block_t block4{
  int x = {0,1,1,1};
  int y = {2,0,1,2};
  int taille = 4; 
}
/*faire les symetrique*/
block_t block5{
  int x = {0,0,0,1};
  int y = {0,1,2,1};
  int taille = 4; 
}
block_t block6{
  int x = {0,1,1,2};
  int y = {0,0,1,0};
  int taille = 4; 
}
/*faire les symetrique*/
block_t block7{
  int x = {0,1,1,2};
  int y = {1,1,0,0};
  int taille = 4; 
}
/*Faire les symetrique*/
block_t block8{
  int x = {0,0,1,1};
  int y = {1,2,1,0};
  int taille = 4; 
}
block_t block9{
  int x = {0,0,0,0};
  int y = {0,1,2,3};
  int taille = 4; 
}
block_t block10{
  int x = {0,0,1,1};
  int y = {0,1,0,1};
  int taille = 4; 
}
block_t block11{
  int x = {0};
  int y = {0};
  int taille = 1 ; 
}
block_t block12{
  int x = {0,1,2,3};
  int y = {0,0,0,0};
  int taille =4 ; 
}

int * bchoix(int *tab,int taille){
	int test =1;
	do{/* ##ICI LE SWITCH POUR LE MENU##  */
		printf("Saisissez : le block désiré\n"); 
		int choix = changeToInt();
		switch(choix){
			case 0:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block1);
				test =0;
				break;
			case 1:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block2);
				test =0;
				break;
			case 2:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block3);
				test =0;
				break;
			case 3:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block4);
				test =0;
				break;
			case 4:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block5);
				test =0;
				break;
			case 5:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block6);
				test =0;
				break;
			case 6:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block7);
				test =0;
				break;
			case 7:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block8);
				test =0;
				break;
			case 8:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block9);
				test =0;
				break;
			case 9:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block10);
				test =0;
				break;
			case 10:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block11);
				test =0;
				break;
			case 11:
				int x = changeToInt();
				int y = changeToInt();
				pose(tab,x,y,block12);
				test =0;
				break;
			default: 
				printf("Erreur ! ");
				test = 1;
		}
	}while(test);

} 

void afficheBlock(block_t block){
	int tab [9];
	int y,x;
	for(int i=0;i<block.taille;i++){
		tab[block.x[i]+block.y[i]*9];
	}
	for(y=0;y<3;y++){
		for(x=0;x<3;x++){
			if(tab[y*9+x]==1)
				printf("#");
		}
		printf(" ");
	}

}


