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




