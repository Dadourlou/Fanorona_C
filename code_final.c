#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAUTEUR 5
#define LARGEUR 9
#define BLEU 1
#define ROUGE 2
#define VIDE 6
#define USE 7
#define ROUGE_BOUGE 13
#define BLEU_BOUGE 14

void afficher_solution(int plateau[HAUTEUR][LARGEUR]){
  int i,j,x,n,z;
printf("    ");
    if (LARGEUR<10){
      for ( j=0 ; j < LARGEUR ; j++)
      printf(" %d  ", j);
    }else if (LARGEUR>=10 && LARGEUR <100){
      for ( j=0 ; j < 10 ; j++)
      printf(" %d  ", j);
      for ( j=10 ; j < LARGEUR ; j++)
      printf(" %d ", j);
    }
  printf("\n");
  printf("  ");
    for ( j=0 ; j < LARGEUR ; j++){
      printf("----");
    }
    printf("--\n");
for(x=0; x < ((HAUTEUR * 2)-1); x++)
if(x%2 ==  0){
    i = x/2;
  if (HAUTEUR<10){
    printf("%d  |", i);
  }else if (HAUTEUR>=10 && HAUTEUR <100){
    if (i < 10)
    printf("%d  |", i);
    if (i >= 10)
    printf("%d |", i);

  }
    for (j=0; j < LARGEUR; j++ ){
      if (plateau[i][j] == VIDE && j != LARGEUR -1){
        printf(" . -");
      }else if (plateau[i][j] == BLEU && j != LARGEUR-1){
        printf ("\033[34;01m B \033[00m");
        printf("-");
      }else if (plateau[i][j] == ROUGE && j != LARGEUR-1){
        printf ("\033[31;01m R \033[00m");
        printf("-");
      }else if (plateau[i][j] == VIDE&& j == LARGEUR-1){
        printf(" . ");
      }else if (plateau[i][j] == BLEU && j == LARGEUR-1){
        printf ("\033[34;01m B \033[00m");
      }else if (plateau[i][j] == ROUGE && j == LARGEUR-1){
        printf ("\033[31;01m R \033[00m");
      }else if (plateau[i][j] == USE && j != LARGEUR-1){
        printf (" o -");
      }else if (plateau[i][j] == USE && j == LARGEUR-1){
        printf (" o ");
      }else if (plateau[i][j] == ROUGE_BOUGE && j != LARGEUR-1){
        printf (" R -");
      }else if (plateau[i][j] == ROUGE_BOUGE && j == LARGEUR-1){
        printf (" R ");
    }else if (plateau[i][j] == BLEU_BOUGE && j != LARGEUR-1){
      printf (" B -");
    }else if (plateau[i][j] == BLEU_BOUGE && j == LARGEUR-1){
      printf (" B ");
    }
  }
    printf("|\n");
 } else {
    for(n=0; n<(HAUTEUR); n++){
    if (x == 4*n+1){
        for (z=-1; z < (LARGEUR+1); z++ ){
        if (z==-1){
            printf("   |");
        } else if (z != LARGEUR && z != (LARGEUR-2) && z != (LARGEUR-1)){
            printf(" | \\ | ");
            printf("/");
            z++;
        } else if (z== (LARGEUR-2)){
            printf(" | / |");
        } else if (z== LARGEUR-1){
            printf(" |");
        }
        }
        if (LARGEUR%2 == 0){
        printf("\n");
        } else {
        printf(" |\n");
        }
    } else if ( x == 4*n+3){
        for (z=-1; z < (LARGEUR+1); z++ ){
        if (z==-1){
            printf("   |");
        } else if (z != LARGEUR && z != (LARGEUR-2) && z != (LARGEUR-1)){
            printf(" | / | ");
            printf("\\");
            z++;
        } else if (z== (LARGEUR-2)){
            printf(" | \\ |");
        } else if (z== LARGEUR-1){
            printf(" |");
        }
        }
        if (LARGEUR%2 == 0){
        printf("\n");
        } else {
	  printf(" |\n");
        }
    }
    }
 }

 printf("  ");
 for ( j=0 ; j < LARGEUR ; j++){
     printf("----");
 }
 printf("--\n");
}

void initialiser(int plateau[HAUTEUR][LARGEUR]){
    int i , j ;
    for (i=0 ; i < HAUTEUR ; i++){
      for (j=0; j < LARGEUR ; j++ ){
        plateau[i][j] = VIDE;
      }
    }
}

void placer_pion(int plateau[HAUTEUR][LARGEUR]){
    int i,j;

    for (i = 0; i < (HAUTEUR / 2) ; i++){
      for (j = 0 ; j < LARGEUR ; j++){
        plateau[i][j] = ROUGE;
      }
    }
    for (i = (HAUTEUR / 2) + 1 ; i < HAUTEUR; i++){
      for (j=0 ; j < LARGEUR ; j++){
        plateau[i][j] = BLEU;
      }
    }

    for (j = 0; j < LARGEUR-1 ; j++)
    plateau[HAUTEUR/2][j] = (j % 2 == 0) ? ROUGE : BLEU;
    for (j = LARGEUR /2; j < LARGEUR ; j++)
    plateau[HAUTEUR/2][j] = (j % 2 == 0) ? BLEU : ROUGE;
    plateau[HAUTEUR/2][(LARGEUR - 1)/2]=VIDE;

}

void placer_pion_un_sur_deux(int plateau[HAUTEUR][LARGEUR]){
    int i,j;

    for (i = 0; i < (HAUTEUR / 2) ; i=i+2){
      for (j = 0 ; j < LARGEUR ; j++){
        plateau[i][j] = ROUGE;
      }
    }
    for (i = (HAUTEUR-1); i > (HAUTEUR / 2); i=i-2){
      for (j=0 ; j < LARGEUR ; j++){
        plateau[i][j] = BLEU;
      }
    }

    for (j = 0; j < LARGEUR-1 ; j++)
    plateau[HAUTEUR/2][j] = (j % 2 == 0) ? ROUGE : BLEU;
    for (j = LARGEUR /2; j < LARGEUR ; j++)
    plateau[HAUTEUR/2][j] = (j % 2 == 0) ? BLEU : ROUGE;
    plateau[HAUTEUR/2][(LARGEUR - 1)/2]=VIDE;

}

void placer_pion_deux_sur_un(int plateau[HAUTEUR][LARGEUR]){
    int i,j;

    for (i = 0; i < (HAUTEUR / 2) ; i++){
      for (j = 0 ; j < LARGEUR ; j=j+2){
        if(i%2==0){
        plateau[i][j] = ROUGE;
      } else {
        if(j==0){
          j++;
        }
        plateau[i][j] = ROUGE;
      }
      }
    }
    for (i = (HAUTEUR-1); i > (HAUTEUR / 2); i--){
      for (j=0 ; j < LARGEUR ; j=j+2){
        if(i%2==0){
        plateau[i][j] = BLEU;
      } else {
        if(j==0){
          j++;
        }
      plateau[i][j] = BLEU;
      }
      }
    }
    for (j = 0; j < LARGEUR-1 ; j++)
plateau[HAUTEUR/2][j] = (j % 2 == 0) ? ROUGE : BLEU;
for (j = LARGEUR /2; j < LARGEUR ; j++)
plateau[HAUTEUR/2][j] = (j % 2 == 0) ? BLEU : ROUGE;
plateau[HAUTEUR/2][(LARGEUR - 1)/2]=VIDE;

}


int jouable(int plateau[HAUTEUR][LARGEUR],int i , int j){
    // check si dans le plateau
    if((j < 0)||(j >= LARGEUR)||(i < 0)||(i >= HAUTEUR)) return 0;
    if (plateau[i][j] == VIDE ) return 3;

    // check si un espace libre dans la voisinage
    //D'abor checker si pair ou impair pour faciliter les check

    if((plateau[i+1][j]==VIDE && (j >= 0) && (j <= LARGEUR)&&(i >= 0) && (i <= HAUTEUR))) return 1;
    if((plateau[i-1][j]==VIDE && (j >= 0) && (j <= LARGEUR)&&(i >= 0) && (i <= HAUTEUR))) return 1;
    if((plateau[i][j+1]==VIDE && (j >= 0) && (j <= LARGEUR)&&(i >= 0) && (i <= HAUTEUR))) return 1;
    if((plateau[i][j-1]==VIDE && (j >= 0) && (j <= LARGEUR)&&(i >= 0) && (i <= HAUTEUR))) return 1;

    if ((j%2 == 0 && i%2 == 0 ) || (j%2 != 0 && i%2 != 0 )){
    	if((plateau[i+1][j+1]==VIDE && (j >= 0) && (j <= LARGEUR) && (i >= 0) && (i <= HAUTEUR))) return 1;
	if((plateau[i-1][j-1]==VIDE && (j >= 0) && (j <= LARGEUR) && (i >= 0) && (i <= HAUTEUR))) return 1;
	if((plateau[i+1][j-1]==VIDE && (j >= 0) && (j <= LARGEUR) && (i >= 0) && (i <= HAUTEUR))) return 1;
	if((plateau[i-1][j+1]==VIDE && (j >= 0) && (j <= LARGEUR) && (i >= 0) && (i <= HAUTEUR))) return 1;
    	return 2;
    }
	// DONC return 1 = ca marche , return 2 = ca marche pas et return 0 = t'es con c'est hors plateau
	// return 3 = tu veux jouer une acse deja vide boloss
    return 666;
}

int coord_area(int a,int b,int c,int d) { // check si les coord a,b sont quelque part autour des coord i,j
    if( (a > c+1) || (a < c-1) || (b > d+1) || (b < d-1) ) return 0;
    else if((a > HAUTEUR) || (a < 0) || (b > LARGEUR) || (b < 0)) return 0;
    else return 1;
}

int mangeable (int plateau[HAUTEUR][LARGEUR], int i, int j){
  if (plateau[i][j]==ROUGE){
    if ((j%2 == 0 && i%2 == 0 ) || (j%2 != 0 && i%2 != 0 )){
      if ((plateau[i-2][j]==BLEU) && (plateau[i-1][j]==VIDE)) return 1;
      else if ((plateau[i][j-2]==BLEU) && (plateau[i][j-1]==VIDE)) return 1;
      else if ((plateau[i-2][j+2]==BLEU) && (plateau[i-1][j+1]==VIDE)) return 1;
      else if ((plateau[i+2][j-2]==BLEU) && (plateau[i+1][j-1]==VIDE)) return 1;
      else if ((plateau[i][j+2]==BLEU) && (plateau[i][j+1]==VIDE)) return 1;
      else if ((plateau[i+2][j]==BLEU) && (plateau[i+1][j]==VIDE)) return 1;
      else if ((plateau[i-2][j-2]==BLEU) && (plateau[i-1][j-1]==VIDE)) return 1;
      else if ((plateau[i+2][j+2]==BLEU) && (plateau[i+1][j+1]==VIDE)) return 1;

      if ((plateau[i-1][j]==VIDE) && (plateau[i+1][j]==BLEU)) return 1;
      else if ((plateau[i][j-1]==VIDE) && (plateau[i][j+1]==BLEU)) return 1;
      else if ((plateau[i-1][j+1]==VIDE) && (plateau[i+1][j-1]==BLEU)) return 1;
      else if ((plateau[i+1][j-1]==VIDE) && (plateau[i-1][j+1]==BLEU)) return 1;
      else if ((plateau[i][j+1]==VIDE) && (plateau[i][j-1]==BLEU)) return 1;
      else if ((plateau[i+1][j]==VIDE) && (plateau[i-1][j]==BLEU)) return 1;
      else if ((plateau[i-1][j-1]==VIDE) && (plateau[i+1][j+1]==BLEU)) return 1;
      else if ((plateau[i+1][j+1]==VIDE) && (plateau[i-1][j-1]==BLEU)) return 1;
      return 2;
    }else{
      if ((plateau[i+2][j]==BLEU) && (plateau[i+1][j]==VIDE)) return 1;
      else if ((plateau[i-2][j]==BLEU) && (plateau[i-1][j]==VIDE)) return 1;
      else if ((plateau[i][j-2]==BLEU) && (plateau[i][j-1]==VIDE)) return 1;
      else if ((plateau[i][j+2]==BLEU) && (plateau[i][j+1]==VIDE)) return 1;

      if ((plateau[i+1][j]==VIDE) && (plateau[i-1][j]==BLEU)) return 1;
      else if ((plateau[i-1][j]==VIDE) && (plateau[i+1][j]==BLEU)) return 1;
      else if ((plateau[i][j-1]==VIDE) && (plateau[i][j+1]==BLEU)) return 1;
      else if ((plateau[i][j+1]==VIDE) && (plateau[i][j-1]==BLEU)) return 1;
      return 2;
    }
  }else if (plateau[i][j]==BLEU){
    if ((j%2 == 0 && i%2 == 0 ) || (j%2 != 0 && i%2 != 0 )){
      if ((plateau[i-2][j]==ROUGE) && (plateau[i-1][j]==VIDE)) return 1;
      else if ((plateau[i][j-2]==ROUGE) && (plateau[i][j-1]==VIDE)) return 1;
      else if ((plateau[i-2][j+2]==ROUGE) && (plateau[i-1][j+1]==VIDE)) return 1;
      else if ((plateau[i+2][j-2]==ROUGE) && (plateau[i+1][j-1]==VIDE)) return 1;
      else if ((plateau[i][j+2]==ROUGE) && (plateau[i][j+1]==VIDE)) return 1;
      else if ((plateau[i+2][j]==ROUGE) && (plateau[i+1][j]==VIDE)) return 1;
      else if ((plateau[i-2][j-2]==ROUGE) && (plateau[i-1][j-1]==VIDE)) return 1;
      else if ((plateau[i+2][j+2]==ROUGE) && (plateau[i+1][j+1]==VIDE)) return 1;

      if ((plateau[i-1][j]==VIDE) && (plateau[i+1][j]==ROUGE)) return 1;
      else if ((plateau[i][j-1]==VIDE) && (plateau[i][j+1]==ROUGE)) return 1;
      else if ((plateau[i-1][j+1]==VIDE) && (plateau[i+1][j-1]==ROUGE)) return 1;
      else if ((plateau[i+1][j-1]==VIDE) && (plateau[i-1][j+1]==ROUGE)) return 1;
      else if ((plateau[i][j+1]==VIDE) && (plateau[i][j-1]==ROUGE)) return 1;
      else if ((plateau[i+1][j]==VIDE) && (plateau[i-1][j]==ROUGE)) return 1;
      else if ((plateau[i-1][j-1]==VIDE) && (plateau[i+1][j+1]==ROUGE)) return 1;
      else if ((plateau[i+1][j+1]==VIDE) && (plateau[i-1][j-1]==ROUGE)) return 1;
      return 2;
    }else{
      if ((plateau[i+2][j]==ROUGE) && (plateau[i+1][j]==VIDE)) return 1;
      else if ((plateau[i-2][j]==ROUGE) && (plateau[i-1][j]==VIDE)) return 1;
      else if ((plateau[i][j-2]==ROUGE) && (plateau[i][j-1]==VIDE)) return 1;
      else if ((plateau[i][j+2]==ROUGE) && (plateau[i][j+1]==VIDE)) return 1;

      if ((plateau[i+1][j]==VIDE) && (plateau[i-1][j]==ROUGE)) return 1;
      else if ((plateau[i-1][j]==VIDE) && (plateau[i+1][j]==ROUGE)) return 1;
      else if ((plateau[i][j-1]==VIDE) && (plateau[i][j+1]==ROUGE)) return 1;
      else if ((plateau[i][j+1]==VIDE) && (plateau[i][j-1]==ROUGE)) return 1;
      return 2;
    }
    return 0;
  }
  return 0;
  // là on a le cas si oui ou non il y a des pions mangeable
  // faut encore faire le check du deplacement force
}

int demande(int plateau[HAUTEUR][LARGEUR], int i, int j,int a, int b){
  int demandation;
  plateau[i][j] = USE;
  if(plateau[a][b] == ROUGE) plateau[a][b] = ROUGE_BOUGE;
  if(plateau[a][b] == BLEU) plateau[a][b] = BLEU_BOUGE;
  afficher_solution(plateau);
  if(plateau[a][b] == ROUGE_BOUGE) plateau[a][b] = ROUGE;
  if(plateau[a][b] == BLEU_BOUGE) plateau[a][b] = BLEU;
  printf("Devant = 1, Derrière = -1\n");
  scanf("%d",&demandation);
  return demandation;
}

void mangeation (int plateau[HAUTEUR][LARGEUR],int joueur, int i, int j,int a, int b){
  int vert, hori,vert1,hori1,dev_ou_der=0;
  vert = a-i;
  hori = b-j;
  vert1=vert;
  hori1=hori;


    if (joueur%2==0){
      if (plateau[a+vert][b+hori] == ROUGE && plateau[i-vert][j-hori] == ROUGE){
        dev_ou_der = demande(plateau,i,j,a,b);
      }
      if(plateau[a+vert][b+hori] == ROUGE && dev_ou_der == 0){
        while(plateau[a+vert][b+hori] == ROUGE && (b+hori) < LARGEUR && (a+vert) < HAUTEUR && (b+hori) >= 0 && (a+vert) >= 0){
          plateau[a+vert][b+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;

        }
      }
      else if(plateau[i-vert][j-hori] == ROUGE && dev_ou_der == 0){
        vert=-vert;
        hori=-hori;
        vert1=-vert1;
        hori1=-hori1;
        while(plateau[i+vert][j+hori] == ROUGE && (j+hori) < LARGEUR && (i+vert) < HAUTEUR && (j+hori) >= 0 && (i+vert) >= 0){
          plateau[i+vert][j+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;

        }
      }

      if(plateau[a+vert][b+hori] == ROUGE && dev_ou_der == 1){
        while(plateau[a+vert][b+hori] == ROUGE && (b+hori) < LARGEUR && (a+vert) < HAUTEUR && (b+hori) >= 0 && (a+vert) >= 0){
          plateau[a+vert][b+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;

        }
      }
      else if(plateau[i-vert][j-hori] == ROUGE && dev_ou_der == -1){
        vert=-vert;
        hori=-hori;
        vert1=-vert1;
        hori1=-hori1;
        while(plateau[i+vert][j+hori] == ROUGE && (j+hori) < LARGEUR && (i+vert) < HAUTEUR && (j+hori) >= 0 && (i+vert) >= 0){
          plateau[i+vert][j+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;
        }
      }

    } else {

      if (plateau[a+vert][b+hori] == BLEU && plateau[i-vert][j-hori] == BLEU){
        dev_ou_der = demande(plateau,i,j,a,b);
      }
      if(plateau[a+vert][b+hori] == BLEU && dev_ou_der == 0){
        while(plateau[a+vert][b+hori] == BLEU && (b+hori) < LARGEUR && (a+vert) < HAUTEUR && (b+hori) >= 0 && (a+vert) >= 0){
          plateau[a+vert][b+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;
        }
      }
      else if(plateau[i-vert][j-hori] == BLEU && dev_ou_der == 0){
        vert=-vert;
        hori=-hori;
        vert1=-vert1;
        hori1=-hori1;
        while(plateau[i+vert][j+hori] == BLEU && (j+hori) < LARGEUR && (i+vert) < HAUTEUR && (j+hori) >= 0 && (i+vert) >= 0){
          plateau[i+vert][j+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;
        }
      }
      if(plateau[a+vert][b+hori] == BLEU && dev_ou_der == 1){
        while(plateau[a+vert][b+hori] == BLEU && (b+hori) < LARGEUR && (a+vert) < HAUTEUR && (b+hori) >= 0 && (a+vert) >= 0){
          plateau[a+vert][b+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;
        }
      }
      else if(plateau[i-vert][j-hori] == BLEU && dev_ou_der == -1){
        vert=-vert;
        hori=-hori;
        vert1=-vert1;
        hori1=-hori1;
        while(plateau[i+vert][j+hori] == BLEU && (j+hori) < LARGEUR && (i+vert) < HAUTEUR && (j+hori) >= 0 && (i+vert) >= 0){
          plateau[i+vert][j+hori]=VIDE;
          vert=vert+vert1;
          hori=hori+hori1;
        }
      }
}

}




int diagonal(int i, int j,int a,int b){
  if ( ( (i%2 != 0) && (j%2 != 0) ) || ( (i%2 == 0) && (j%2 == 0) ) ) return 0;
  else{
    if((a == i+1) && (b == j+1)) return 1;
    else if ((a == i-1) && (b == j+1))return 1;
    else if ((a == i+1) && (b == j-1))return 1;
    else if ((a == i-1) && (b == j-1)) return 1;
  }
  return 2;
}

int deplacement(int plateau[HAUTEUR][LARGEUR],int joueur, int i, int j, int a, int b){
  int test=0,dpl=0,mgb=0,x=0,y=0;
  if((joueur%2 == 0)&&(plateau[i][j] == ROUGE)) return 0;
  if((joueur%2 != 0)&&(plateau[i][j] == BLEU)) return 0;
  dpl=jouable(plateau,i,j);
  if(dpl == 0){
     return 1;
  }
  if(dpl == 2){
     return 2;
  }
  if(dpl == 3){
     return 3;
  }
  if(mgb == 2){ //Si le pion selec n'est pas jouable qu'en est il des autres ?
    for(x=0;x<HAUTEUR;x++){
      for(y=0;y<LARGEUR;y++){
	mgb=mangeable(plateau,x,y);
	if((plateau[i][j] == BLEU) && (joueur%2 == 0)){
	    if(mgb == 1){
	      printf("Vous devez/pouvez jouer un autre pion car au moins un autre peut eliminer un pion adverse\n");
	      return 6; // Il faut rejouer avec un autre pion
	    }
	  }
	if((plateau[i][j] == ROUGE ) && (joueur%2 != 0)){
	      if(mgb == 1){
	        printf("Vous devez/pouvez jouer un autre pion car au moins un autre peut eliminer un pion adverse\n");
		return 6;
	      }
	}
      }
    }
  }
// Checker qure les pions de la couleur du joueur
  test = coord_area(a,b,i,j);
  if(test == 1){
    if(plateau[a][b] == VIDE){
      plateau[i][j] = VIDE;
      if(joueur%2 == 0){
      plateau[a][b] = BLEU;

      //mangeable
      mangeation(plateau,joueur,i,j,a,b);

      return 42;
      }else{
	plateau[a][b] = ROUGE;

      //mangeable
      mangeation(plateau,joueur,i,j,a,b);

	return 42;
      }
    }else return 4;
  }else return 5;

  if (plateau[a][b] == USE){
    return 6;


  }
  return 99;
}


int check_vie_BLEU(int plateau[HAUTEUR][LARGEUR]){
  int i=0,j=0,vie=0;
  for(i=0;i<HAUTEUR;i++){
    for(j=0;j<LARGEUR;j++){
      if(plateau[i][j] == BLEU) vie ++;
    }
  }
  return vie;
}
int check_vie_ROUGE(int plateau[HAUTEUR][LARGEUR]){
  int i=0,j=0,vie=0;
  for(i=0;i<HAUTEUR;i++){
    for(j=0;j<LARGEUR;j++){
      if(plateau[i][j] == ROUGE) vie ++;
    }
  }
  return vie;
}

char fin_tour(){
  char tour;
  printf("Voulez vous finir votre tour ? Si oui = o, Non = n\n");
  scanf("%s", &tour);
  printf("\n");
  return tour;
}

int doit_manger(int plateau[HAUTEUR][LARGEUR],int joueur,int i, int j,int x,int y){
  int a1=i-1,a=i,a2=i+1,b1=j-1,b=j,b2=j+1;
  if(joueur%2 == 0){
    if( ((i%2 == 0) && (j%2 == 0)) || ((i%2 != 0) && (j%2 != 0))){
      // manger en avant
      if((plateau[a1][b]==VIDE) && (plateau[a1-1][b] == ROUGE)){// haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b]==VIDE) && (plateau[a2+1][b] == ROUGE)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b2+1] == ROUGE)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b1-1] == ROUGE)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }
      if((plateau[a][b]==VIDE) && (plateau[a-1][b+1] == ROUGE)){ // haut/droite
	if((x==a) && (y==b))
	  return 1;
      }
      if((plateau[a2][b1]==VIDE) && (plateau[a2+1][b1-1] == ROUGE)){ // bas/gauche
	if((x==a2) && (y==b1))
	  return 1;
      }
      if((plateau[a2][b2]==VIDE) && (plateau[a2+1][b2+1] == ROUGE)){ // bas/droite
	if((x==a2) && (y==b2))
	  return 1;
      }
      if((plateau[a1][b1]==VIDE) && (plateau[a1-1][b1-1] == ROUGE)){ // haut/gauche
	if((x==a1) && (y==b1))
	  return 1;
      }
      // manger en arriere

      if((plateau[a1][b]==VIDE) && (plateau[a2][b] == ROUGE)){ // haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b]==VIDE) && (plateau[a1][b] == ROUGE)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b1] == ROUGE)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b2] == ROUGE)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }
      if((plateau[a1][b2]==VIDE) && (plateau[a2][b1] == ROUGE)){ // haut/droite
	if((x==a1) && (y==b2))
	  return 1;
      }
      if((plateau[a2][b1]==VIDE) && (plateau[a1][b2] == ROUGE)){ // bas/gauche
	if((x==a2) && (y==b1))
	  return 1;
      }
      if((plateau[a2][b2]==VIDE) && (plateau[a1][b1] == ROUGE)){ // bas/droite
	if((x==a2) && (y==b2))
	  return 1;
      }
      if((plateau[a1][b1]==VIDE) && (plateau[a2][b2] == ROUGE)){ // haut/gauche
	if((x==a1) && (y==b1))
	  return 1;
      }

    }
    else{
      // en avant
      if((plateau[a1][b]==VIDE) && (plateau[a1-1][b] == ROUGE)){ // haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b]==VIDE) && (plateau[a2+1][b] == ROUGE)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b2+1] == ROUGE)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b1-1] == ROUGE)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }

      // en arriere

      if((plateau[a1][b]==VIDE) && (plateau[a2][b] == ROUGE)){ // haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b]==VIDE) && (plateau[a1][b] == ROUGE)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b1] == ROUGE)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b2] == ROUGE)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }
    }
  }

  if(joueur%2 != 0){
    if( ((i%2 == 0) && (j%2 == 0)) || ((i%2 != 0) && (j%2 != 0))){
      // en avant
      if((plateau[a1][b] == VIDE) && (plateau[a1-1][b] == BLEU)){ // haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b] == VIDE) && (plateau[a2+1][b] == BLEU)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b2+1] == BLEU)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b1-1] == BLEU)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }
      if((plateau[a1][b2]==VIDE) && (plateau[a1-1][b2+1] == BLEU)){ // haut/droite
	if((x==a1) && (y==b2))
	  return 1;
      }
      if((plateau[a2][b1]==VIDE) && (plateau[a2+1][b1-1] == BLEU)){ // bas/gauche
	if((x==a2) && (y==b1))
	  return 1;
      }
      if((plateau[a2][b2]==VIDE) && (plateau[a2+1][b2+1] == BLEU)){ // bas/droite
	if((x==a2) && (y==b2))
	  return 1;
      }
      if((plateau[a1][b1]==VIDE) && (plateau[a1-1][b1-1] == BLEU)){ // haut/gauche
	if((x==a1) && (y==b1))
	  return 1;
      }

      // en arriere

      if((plateau[a1][b] == VIDE) && (plateau[a2][b] == BLEU)){ // haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b] == VIDE) && (plateau[a1][b] == BLEU)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b1] == BLEU)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b2] == BLEU)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }
      if((plateau[a1][b2]==VIDE) && (plateau[a2][b1] == BLEU)){ // haut/droite
	if((x==a1) && (y==b2))
	  return 1;
      }
      if((plateau[a2][b1]==VIDE) && (plateau[a1][b2] == BLEU)){ // bas/gauche
	if((x==a2) && (y==b1))
	  return 1;
      }
      if((plateau[a2][b2]==VIDE) && (plateau[a1][b1] == BLEU)){ // bas/droite
	if((x==a2) && (y==b2))
	  return 1;
      }
      if((plateau[a1][b1]==VIDE) && (plateau[a2][b2] == BLEU)){ // haut/gauche
	if((x==a1) && (y==b1))
	  return 1;
      }

    }

    else{
      // en arriere
      if((plateau[a1][b]==VIDE) && (plateau[a2][b] == BLEU)){ // haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b]==VIDE) && (plateau[a1][b] == BLEU)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b1] == BLEU)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b2] == BLEU)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }

      // en avant

    if((plateau[a1][b]==VIDE) && (plateau[a1-1][b] == BLEU)){ // haut
	if((x==a1) && (y==b))
	  return 1;
      }
      if((plateau[a2][b]==VIDE) && (plateau[a2+1][b] == BLEU)){ // bas
	if((x==a2) && (y==b))
	  return 1;
      }
      if((plateau[a][b2]==VIDE) && (plateau[a][b2+1] == BLEU)){ // droite
	if((x==a) && (y==b2))
	  return 1;
      }
      if((plateau[a][b1]==VIDE) && (plateau[a][b1-1] == BLEU)){ // gauche
	if((x==a) && (y==b1))
	  return 1;
      }
    }
  }
  return 666; // quand on va au bord du plateau alors qu'on peut manger
}

int devant_devant(int i,int j,int a,int b,int compteur){
  int N=1,S=2,E=3,W=4,NE=5,SE=6,NW=7,SW=8;

  if((a == i-1) && (b == j)){// vers le haut
    if(compteur == N) return 0;
    else{
      compteur = N;
      return compteur;
    }
  }
  if((a == i+1) && (b == j)){// vers le bas
    if(compteur == S) return 0;
    else{
      compteur = S;
      return compteur;
    }
  }
  if((a == i) && (b == j+1)){// vers la droite
    if(compteur == E) return 0;
    else{
      compteur = E;
      return compteur;
    }
  }
  if((a == i) && (b == j-1)){// vers la gauche
    if(compteur == W) return 0;
    else{
      compteur = W;
      return compteur;
    }
  }
  if((a == i-1) && (b == j+1)){// vers NE
    if(compteur == NE) return 0;
    else{
      compteur = NE;
      return compteur;
    }
  }
  if((a == i+1) && (b == j+1)){// vers SE
    if(compteur == SE) return 0;
    else{
      compteur = SE;
      return compteur;
    }
  }
  if((a == i+1) && (b == j-1)){// vers NW
    if(compteur == NW) return 0;
    else{
      compteur = NW;
      return compteur;
    }
  }
  if((a == i-1) && (b == j-1)){// vers SW
    if(compteur == SW) return 0;
    else{
      compteur = SW;
      return compteur;
    }
  }
  return 155;
}

void mouvement (int plateau[HAUTEUR][LARGEUR],int joueur, int i, int j,int a, int b){
  int jeu =0;
  int mgb,miam,compteur_devant;
  char tour;
  int vert, hori,vert1,hori1;
  while (tour != 'o'){
    vert = a-i;
    hori = b-j;
    tour = fin_tour();
    printf("Ou voulez vous deplacer ce pion ?\n");
    scanf("%d,%d",&a,&b);
    vert1 = a-i;
    hori1 = b-j;

    mgb=mangeable(plateau,i,j);
    if(mgb == 1){
      miam=doit_manger(plateau,joueur,i,j,a,b);
      compteur_devant=devant_devant(i,j,a,b,compteur_devant);
      //printf("devant_devant : %d\n",compteur_devant);
      if(compteur_devant == 0){
        printf("vous ne pouvez pas jouer deux fois dans la meme direction\n");
      }

      //printf("%d,%d\n",joueur,miam);
      if(miam != 1){
	printf("Vous pouvez et donc devez faire un deplacement impliquant l'elimination d'un pion adverse\n");
	continue;
      }
    }

    if(mgb != 1){
      tour='o';
      continue;
    }



    system("clear");

    jeu=deplacement(plateau,joueur,i,j,a,b);

    if (vert == vert1 && hori == hori1){
      afficher_solution(plateau);
      printf("Vous ne pouvez pas vous déplacez deux fois dans la même direction\n");continue;}

    if(jeu == 0){ afficher_solution(plateau);
                  printf("Vous ne pouvez jouer ce pion : il ne vous appartient pas\n");continue;}
    if(jeu == 1){ afficher_solution(plateau);
                  printf("Vous essayez de sélectionner un pion hors du plateau\n");continue;}
    if(jeu == 2){ afficher_solution(plateau);
                  printf("Ce pion n'est actuellement pas jouable : aucune case libre adjacente\n");continue;}
    if(jeu == 3){ afficher_solution(plateau);
                  printf("Il n'y a pas de pions sur cette case ... \n");continue;}
    if(jeu == 4){ afficher_solution(plateau);
                  printf("Cette case est deja occupee\n");continue;}
    if(jeu == 5){ afficher_solution(plateau);
                  printf("ces coordonnes ne sont pas accessibles pour ce pion\n");continue;}
    if(jeu == 6){ afficher_solution(plateau);
                  printf("Cases déjà occupé précédemment\n");continue;}

    if(jeu == 42)plateau[i][j] = USE;
    if(jeu == 42 && plateau[a][b] == ROUGE) plateau[a][b] = ROUGE_BOUGE;
    if(jeu == 42 && plateau[a][b] == BLEU) plateau[a][b] = BLEU_BOUGE;
    afficher_solution(plateau);
    if(jeu == 42 && plateau[a][b] == ROUGE_BOUGE) plateau[a][b] = ROUGE;
    if(jeu == 42 && plateau[a][b] == BLEU_BOUGE) plateau[a][b] = BLEU;
    mgb=mangeable(plateau,a,b);
    i=a;
    j=b;


  }
  compteur_devant = 0;

}

void reinit_USE(int plateau[HAUTEUR][LARGEUR]){
int n, z;
  for(n=0; n<(HAUTEUR); n++){
    for (z=-1; z < (LARGEUR+1); z++ ){
      if (plateau[n][z] == USE)
        plateau[n][z] = VIDE;
    }
  }
}

void victoire (int vie_BLEU){
  system("clear");
  FILE* fichier = NULL;
  fichier = fopen("sauv1.txt", "w");
  fclose(fichier);

  int fin;
  if (vie_BLEU == 0){
    printf("Victoire des Rouges, Bravo\n");
  } else {
    printf("Victoire des BLEUS, Bravo\n");
  }
  printf("Pour quittez, tapez 1\n");
  scanf("%d",&fin);
  if (fin == 1){
    exit(EXIT_FAILURE);
  }
}

void sauvegarde(int plateau[HAUTEUR][LARGEUR], int joueur){
int n,y;
FILE* fichier = NULL;
fichier = fopen("sauv1.txt", "w");
  for(n=0; n < (HAUTEUR); n++){
    for (y=0; y < (LARGEUR); y++ ){
      if (plateau[n][y] == ROUGE){
        fprintf(fichier, "2");
      } else if (plateau[n][y] == BLEU){
        fprintf(fichier, "1");
      }else if (plateau[n][y] == VIDE){
        fprintf(fichier, "6");
      }
    }
  }
  fprintf(fichier, "%d" , joueur);
  fclose(fichier);
}

int load_sauvegarde(int plateau[HAUTEUR][LARGEUR], int joueur){
  FILE* sauv = NULL;
  int x;
  int y;
  char z;
  int i;

  sauv = fopen("sauv1.txt", "r");

for(i = 0 ; i < (HAUTEUR*LARGEUR)+1 ; i++){
  for(x=0; x < (HAUTEUR); x++){
    for (y=0; y < (LARGEUR); y++ ){
      z = fgetc(sauv);
      if (z == '2'){
        plateau[x][y] = ROUGE;
      } else if ( z== '6'){
        plateau[x][y] = VIDE;
      } else if ( z== '1'){
        plateau[x][y] = BLEU;
      }
    }
  }
  if (i == (HAUTEUR*LARGEUR)){
    fseek(sauv, -1, SEEK_END);
  z = fgetc(sauv);

  joueur = z - '0';
}
}
fclose(sauv);
return joueur;
}

int check_sauvegarde(int plateau[HAUTEUR][LARGEUR], int joueur){
  int pr=0;
  FILE* fichier;
  int size;
  fichier = fopen("sauv1.txt", "r");

  fseek(fichier,0,SEEK_END);
  size = ftell(fichier);
  fclose(fichier);
  if(size != ((HAUTEUR*LARGEUR)+1)){
    printf("Le plateau sauvegarder n'est pas de la taille du plateau sur lequel vous voulez jouez.\n");
    printf("Si vous voulez quittez tapez 1\n");
    printf("Si vous voulez jouez sans sauvegarde tapez 2\n");
    scanf("%d",&pr);
    if (pr == 1){
      exit(EXIT_FAILURE);
      return 0;
    } else if (pr == 2){
      return 1;
    }
  } else {
    return 2;
  }
  return 777;
}

int menu(int plateau[HAUTEUR][LARGEUR], int joueur){
  int num_menu,check;
  system("clear");
  printf("Bonjour et bienvenue dans ce jeu : FANORONA\n\n");

  printf("                         /-                        \n");
  printf("                        -m+.                       \n");
  printf("                       `dNs/`                      \n");
  printf("                       ymdm+:                      \n");
  printf("                      +mdhNh/-                     \n");
  printf("                     :mhh:/No:.                    \n");
  printf("                    .dhho  sNo/`                   \n");
  printf("                   `hmys`  `hm//                   \n");
  printf("                   sNdh.    .dh/-                  \n");
  printf("                  +Nmh-      /ms:.                 \n");
  printf("                 :mmdo        om+:`                \n");
  printf("                .mmdy`        `ym+:`               \n");
  printf("               `hNmd.          .dd/:               \n");
  printf("               oNmm:            :my/-              \n");
  printf("              /Nmm+              +ms+.             \n");
  printf("             :mdds`               sm+-`            \n");
  printf("           `+mdmd.                `dd/.``          \n");
  printf("  `-`````.+hdddm:                  -mmyo+.    ``-` \n");
  printf("   yyo/:+oshhdm+                    +mms-````./so  \n");
  printf("   :Nmh++/sddds                      smmd+.`-oyy-  \n");
  printf("   -NNNNdhmddh`                      `hmNNdoysso.  \n");
  printf("   +MMNNNmNmm:                        -mNmmmdho/.  \n");
  printf("   hdmNMMNmmm                          mNNmNNmdy/  \n");
  printf("     `-omNNhh.                        -mmNNdo-`    \n");
  printf("  ``    `+dmh+`      `        `      -hmmh/`    .. \n");
  printf("    ..     .+yo-`   `o: .+:. :+`   .+dy+.    `--`  \n");
  printf("      ..`     `-::-.    `/:     .-:/-`    `.--     \n");
  printf("        `--.        ```  .   ```       .:/:`       \n");
  printf("           .::::.`````-:od-.````..-/+++:.          \n");
  printf("               `-/+osyhdmmdhyysso+/-`              \n");

  printf("\n");
  printf("Si vous voulez jouer, tapez 1\n");
  printf("Si vous voulez changez la disposition des pions en 1 lignes sur deux, tapez 2\n");
  printf("Si vous voulez changez la disposition des pions en 1 colonnes sur deux, tapez 3\n");
  printf("Si vous voulez récupérez une sauvegarde, tapez 4\n");
  printf("Si vous voulez quittez, tapez 9\n");
  scanf("%d", &num_menu);

  if (num_menu == 1){
    system("clear");
    initialiser(plateau);
    placer_pion(plateau);
    afficher_solution(plateau);
    return 3;
  }
  else if (num_menu == 9){
    exit(EXIT_FAILURE);
    return 777;
  } else if (num_menu == 2){
    system("clear");
    initialiser(plateau);
    placer_pion_un_sur_deux(plateau);
    afficher_solution(plateau);
    return 3;
  } else if ( num_menu == 4){
    system("clear");
    initialiser(plateau);
    check = check_sauvegarde(plateau,joueur);
    if (check == 2){
    joueur = load_sauvegarde(plateau,joueur);
    afficher_solution(plateau);
    return joueur;
  } else if (check ==1){
    placer_pion(plateau);
    afficher_solution(plateau);
    return joueur;
  }

  } else if (num_menu == 3){
    system("clear");
    initialiser(plateau);
    placer_pion_deux_sur_un(plateau);
    afficher_solution(plateau);
  }
  return 777;
}

void jeu_sans_ia(int plateau[HAUTEUR][LARGEUR]){
  int joueur=3; // joueur%2 != 0  pour les ROUGEs, = 0 pour les BLEUZ
  int i=0,j=0,vie_BLEU=0,vie_ROUGE,jeu=0,miam,x=0,y=0,compteur=0;
  int a,b,mgb,diag=0;
  joueur = menu(plateau,joueur);

  vie_BLEU=check_vie_BLEU(plateau);
  vie_ROUGE=check_vie_ROUGE(plateau);
  while((vie_BLEU > 0) && (vie_ROUGE > 0)){
    compteur=0;

    if(joueur%2 == 0 ) printf("Aux BLEUS de jouer \n");
    else printf("Aux ROUGES de jouer\n");

    vie_BLEU=check_vie_BLEU(plateau);
    vie_ROUGE=check_vie_ROUGE(plateau);

    if(vie_BLEU == 0 || vie_ROUGE == 0){
      victoire(vie_BLEU);
    }

    printf("Quel pion voulez vous jouer ?\nOu voulez vous deplacer ce pion ?\n(Si vous voulez abandonner, tapez 666,666)\n");
    scanf("%d,%d",&i,&j);
    if (i == 666 && j == 666){
      if(joueur%2 == 0 ) {
	vie_BLEU=0;
	victoire(vie_BLEU);
      }else {
	victoire(vie_BLEU);
      }
    }
    scanf("%d,%d",&a,&b);

    mgb=mangeable(plateau,i,j);
    if(mgb == 1){
      miam=doit_manger(plateau,joueur,i,j,a,b);
      //printf("%d,%d\n",joueur,miam);
      if(miam != 1){
  	printf("Vous pouvez et donc devez faire un deplacement impliquant l'elimination d'un pion adverse\n");
  	continue;
      }
    }
    if(mgb == 2){ //Si le pion selec n'est pas jouable qu'en est il des autres ?
      for(x=0;x<HAUTEUR;x++){
  	for(y=0;y<LARGEUR;y++){
  	  mgb=mangeable(plateau,x,y);
  	  if((plateau[i][j] == BLEU) && (joueur%2 == 0)){
  	    if(mgb == 1){
  	      //printf("%d,%d\n",x,y);
  	      compteur++;
  	      break;
  	    }
  	  }
  	  if((plateau[i][j] == ROUGE ) && (joueur%2 != 0)){
  	    if(mgb == 1){
  	      //printf("%d,%d",x,y);
  	      compteur++;
  	      break;
  	    }
  	  }
  	}
      }
    }

    if(compteur > 0){printf("Vous devez/pouvez jouer un autre pion car au moins un autre peut eliminer un pion adverse\n");afficher_solution(plateau);continue;}


    //fprintf(fichier, "%d,%d %d,%d",i,j,a,b);
    //fclose(fichier);
    system("clear");
    diag = diagonal(i,j,a,b);
    if(diag == 1 ) {
      printf("ce pion ne peut pas se deplacer en diagonal\n");
      afficher_solution(plateau);
      continue;
    }

    jeu=deplacement(plateau,joueur,i,j,a,b);
    if(jeu == 0){ afficher_solution(plateau);
      printf("Vous ne pouvez jouer ce pion : il ne vous appartient pas\n");continue;}
    if(jeu == 1){ afficher_solution(plateau);
      printf("Vous essayez de sélectionner un pion hors du plateau\n");continue;}
    if(jeu == 2){ afficher_solution(plateau);
      printf("Ce pion n'est actuellement pas jouable : aucune case libre adjacente\n");continue;}
    if(jeu == 3){ afficher_solution(plateau);
      printf("Il n'y a pas de pions sur cette case ... \n");continue;}
    if(jeu == 4){ afficher_solution(plateau);
      printf("Cette case est deja occupee\n");continue;}
    if(jeu == 5){ afficher_solution(plateau);
      printf("ces coordonnes ne sont pas accessibles pour ce pion\n");continue;}
    if(jeu == 42)plateau[i][j] = USE;
    if(jeu == 42 && plateau[a][b] == ROUGE) plateau[a][b] = ROUGE_BOUGE;
    if(jeu == 42 && plateau[a][b] == BLEU) plateau[a][b] = BLEU_BOUGE;
    afficher_solution(plateau);
    if(jeu == 42 && plateau[a][b] == ROUGE_BOUGE) plateau[a][b] = ROUGE;
    if(jeu == 42 && plateau[a][b] == BLEU_BOUGE) plateau[a][b] = BLEU;
    mgb=mangeable(plateau,a,b);
    if((jeu == 42) && (mgb != 1) ){
      joueur++;
      reinit_USE(plateau);
      afficher_solution(plateau);
      sauvegarde(plateau,joueur);
      continue;
    }
    mouvement(plateau,joueur,a,b,i,j);
    reinit_USE(plateau);
    afficher_solution(plateau);
    sauvegarde(plateau,joueur);
    if(jeu == 42)joueur++;
  }
}






int diagonale_ia(int i, int j){
  if(((i%2 == 0) && (j%2 == 0))||((i%2 != 0) && (j%2 != 0))) return 1;
  else return 2;
}

int score_dpl(int plateau[HAUTEUR][LARGEUR], int i, int j , int a , int b , int joueur){
  int score=0,x,y;
  // test du non deplacement
  if((a==0) && (b == 0)) return 0;
  // test adversaire devant
  if(joueur%2 == 0){
    if((a == -1) && (b == -1)){// HAUT GAUCHE
      if((plateau[i-1][j-1] == VIDE) && (plateau[i-2][j-2] == ROUGE)){
	x=i-2;
	y=i-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    return 666;
	    score ++;
	  } else return score;
	  x--;
	  y--;
	}
	return score;
      }
    }
    if((a == -1) && (b ==  0)){
      if((plateau[i-1][j] == VIDE) && (plateau[i-2][j] == ROUGE)){
	x=i-2;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }

    if((a == -1) && (b ==  1)){
      if((plateau[i-1][j+1] == VIDE) && (plateau[i-2][j+2] == ROUGE)){
	x=i-2;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  x--;
	  y++;
	}
	return score;
      }
    }
    if((a ==  0) && (b == -1)){
      if((plateau[i][j-1] == VIDE) && (plateau[i][j-2] == ROUGE)){
	x=i;
	y=j-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  y--;
	}
	return score;
      }
    }
    if((a ==  0) && (b ==  1)){
      if((plateau[i][j+1] == VIDE) && (plateau[i][j+2] == ROUGE)){
	x=i;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  y++;
	}
	return score;
      }
    }
    if((a ==  1) && (b == -1)){
      if((plateau[i+1][j-1] == VIDE) && (plateau[i+2][j-2] == ROUGE)){
	x=i+2;
	y=j-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  x++;
	  y--;
	}
	return score;
      }
    }
    if((a ==  1) && (b ==  0)){
      if((plateau[i+1][j] == VIDE) && (plateau[i+2][j] == ROUGE)){
	x=i+2;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a ==  1) && (b ==  1)){
      if((plateau[i+1][j+1] == VIDE) && (plateau[i+2][j+2] == ROUGE)){
	x=i+2;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  x++;
	  y++;
	}
	return score;
      }
    }
    ////////////  // test adversaire derriere////////////////////////////////////////////////////////////////

    if((a == 1) && (b == 1)){// HAUT GAUCHE
      if((plateau[i+1][j+1] == VIDE) && (plateau[i-1][j-1] == ROUGE)){
	x=i-1;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    x--;
	    y--;
	  }
	  return score;
	}
      }
      if((a == 1) && (b ==  0)){
	if((plateau[i+1][j] == VIDE) && (plateau[i-1][j] == ROUGE)){
	  x=i-1;
	  y=j;
	  score=0;
	  while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	    if(plateau[x][y] == ROUGE){
	      score ++;
	    } else return score;
	    x--;
	  }
	  return score;
	}
      }
      if((a == 1) && (b ==  -1)){
	if((plateau[i+1][j-1] == VIDE) && (plateau[i-1][j+1] == ROUGE)){
	x=i-1;
	y=j+1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    x--;
	    y++;
	  }
	  return score;
	}
      }
      if((a ==  0) && (b == 1)){
	if((plateau[i][j+1] == VIDE) && (plateau[i][j-1] == ROUGE)){
	x=i;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    y--;
	  }
	  return score;
	}
      }
      if((a ==  0) && (b ==  -1)){
	if((plateau[i][j-1] == VIDE) && (plateau[i][j+1] == ROUGE)){
	x=i;
	y=j+1;
	  score=0;
	  while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	    if(plateau[x][y] == ROUGE){
	      score ++;
	    } else return score;
	    y++;
	  }
	  return score;
	}
      }
      if((a ==  -1) && (b == 1)){
	if((plateau[i-1][j+1] == VIDE) && (plateau[i+1][j-1] == ROUGE)){
	x=i+1;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    x++;
	    y--;
	  }
	  return score;
	}
      }
      if((a ==  -1) && (b ==  0)){
	if((plateau[i-1][j] == VIDE) && (plateau[i+1][j] == ROUGE)){
	x=i+1;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    x--;
	  }
	  return score;
	}
      }
      if((a ==  -1) && (b ==  -1)){
	if((plateau[i-1][j-1] == VIDE) && (plateau[i+1][j+1] == ROUGE)){
	x=i+1;
	y=j+1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    x++;
	    y++;
	  }
	  return score;
	}
      }
  }
  //////////////////////////////AUTRE COULEUR////////////////////////////
  if(joueur%2 != 0){
    if((a == -1) && (b == -1)){// HAUT GAUCHE
      if((plateau[i-1][j-1] == VIDE) && (plateau[i-2][j-2] == BLEU)){
	x=i-2;
	y=j-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	  y--;
	}
	return score;
      }
    }
    if((a == -1) && (b ==  0)){
      if((plateau[i-1][j] == VIDE) && (plateau[i-2][j] == BLEU)){
	x=i-2;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a == -1) && (b ==  1)){
      if((plateau[i-1][j+1] == VIDE) && (plateau[i-2][j+2] == BLEU)){
	x=i-2;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	  y++;
	}
	return score;
      }
    }
    if((a ==  0) && (b == -1)){
      if((plateau[i][j-1] == VIDE) && (plateau[i][j-2] == BLEU)){
	x=i;
	y=j-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  y--;
	}
	return score;
      }
    }
    if((a ==  0) && (b ==  1)){
      if((plateau[i][j+1] == VIDE) && (plateau[i][j+2] == BLEU)){
	x=i;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  y++;
	}
	return score;
      }
    }
    if((a ==  1) && (b == -1)){
      if((plateau[i+1][j-1] == VIDE) && (plateau[i+2][j-2] == BLEU)){
	x=i+2;
	y=j-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x++;
	  y--;
	}
	return score;
      }
    }
    if((a ==  1) && (b ==  0)){
      if((plateau[i-1][j] == VIDE) && (plateau[i-2][j] == BLEU)){
	x=i-2;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a ==  1) && (b ==  1)){
      if((plateau[i+1][j+1] == VIDE) && (plateau[i+2][j+2] == BLEU)){
	x=i+2;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x++;
	  y++;
	}
	return score;
      }
    }
  ////////////  // test adversaire derriere////////////////////////////////////////////////////////////////

    if((a == 1) && (b == 1)){// HAUT GAUCHE
      if((plateau[i+1][j+1] == VIDE) && (plateau[i-1][j-1] == BLEU)){
	x=i-1;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	  y--;
	}
	return score;
      }
    }
    if((a == 1) && (b ==  0)){
      if((plateau[i+1][j] == VIDE) && (plateau[i-1][j] == BLEU)){
	x=i-1;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a == 1) && (b == -1)){
      if((plateau[i+1][j-1] == VIDE) && (plateau[i-1][j+1] == BLEU)){
	x=i-1;
	y=j+1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	  y++;
	}
	return score;
      }
    }
    if((a ==  0) && (b == 1)){
      if((plateau[i][j+1] == VIDE) && (plateau[i][j-1] == BLEU)){
	x=i;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  y--;
	}
	return score;
      }
    }
    if((a ==  0) && (b ==  -1)){
      if((plateau[i][j-1] == VIDE) && (plateau[i][j+1] == BLEU)){
	x=i;
	y=j+1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  y++;
	}
	return score;
      }
    }
    if((a ==  -1) && (b == 1)){
      if((plateau[i-1][j+1] == VIDE) && (plateau[i+1][j-1] == BLEU)){
	x=i+1;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x++;
	  y--;
	}
	return score;
      }
    }
    if((a ==  -1) && (b ==  0)){
      if((plateau[i-1][j] == VIDE) && (plateau[i+1][j] == BLEU)){
	x=i+1;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a ==  -1) && (b ==  -1)){
      if((plateau[i-1][j-1] == VIDE) && (plateau[i+1][j+1] == BLEU)){
	x=i+1;
	y=j+1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x++;
	  y++;
	}
	return score;
      }
    }
  }
  return 0;
}


int score4(int plateau[HAUTEUR][LARGEUR], int i, int j, int a, int b, int joueur){
  int x,y,score=0;
  if(joueur%2 == 0){
    if((a == -1) && (b == 0)){
      if((plateau[i-1][j] == VIDE) && (plateau[i-2][j] == ROUGE)){
	x=i-2;
	y=i;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    return 666;
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a == +1) && (b ==  0)){
      if((plateau[i+1][j] == VIDE) && (plateau[i+2][j] == ROUGE)){
	x=i+2;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  x++;
	}
	return score;
      }
    }

    if((a == 0) && (b ==  1)){
      if((plateau[i][j+1] == VIDE) && (plateau[i][j+2] == ROUGE)){
	x=i;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  y++;
	}
	return score;
      }
    }
    if((a ==  0) && (b == -1)){
      if((plateau[i][j-1] == VIDE) && (plateau[i][j-2] == ROUGE)){
	x=i;
	y=j-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	  y--;
	}
	return score;
      }
    }
    ///////////////////////EN ARRIERE//////////////////////////:

    if((a == 0) && (b == 1)){// HAUT GAUCHE
      if((plateau[i][j+1] == VIDE) && (plateau[i][j-1] == ROUGE)){
	x=i;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    y--;
	  }
	  return score;
	}
      }
      if((a == 0) && (b ==  -1)){
	if((plateau[i][j-1] == VIDE) && (plateau[i][j+1] == ROUGE)){
	  x=i;
	  y=j+1;
	  score=0;
	  while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	    if(plateau[x][y] == ROUGE){
	      score ++;
	    } else return score;
	    y++;
	  }
	  return score;
	}
      }
      if((a == 1) && (b ==  0)){
	if((plateau[i+1][j] == VIDE) && (plateau[i-1][j] == ROUGE)){
	x=i-1;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    x--;
	  }
	  return score;
	}
      }
      if((a ==  -1) && (b == 0)){
	if((plateau[i-1][j] == VIDE) && (plateau[i+1][j] == ROUGE)){
	x=i+1;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == ROUGE){
	    score ++;
	  } else return score;
	    x++;
	  }
	  return score;
	}
      }
      /////////////////////////////////CHANGEMENT COULEUR////////////////////////////
  } if(joueur%2 != 0){
    if((a == -1) && (b == 0)){// HAUT GAUCHE
      if((plateau[i-1][j] == VIDE) && (plateau[i-2][j] == BLEU)){
	x=i-2;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a == 1) && (b ==  0)){
      if((plateau[i+1][j] == VIDE) && (plateau[i+2][j] == BLEU)){
	x=i+2;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x++;
	}
	return score;
      }
    }
    if((a == 0) && (b ==  +1)){
      if((plateau[i][j+1] == VIDE) && (plateau[i][j+2] == BLEU)){
	x=i;
	y=j+2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  y++;
	}
	return score;
      }
    }
    if((a ==  0) && (b == -1)){
      if((plateau[i][j-1] == VIDE) && (plateau[i][j-2] == BLEU)){
	x=i;
	y=j-2;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  y--;
	}
	return score;
      }
    }

    ////////////////////////////EN ARRIERE///////////////////////////////////
   if((a == -1) && (b == 0)){// HAUT GAUCHE
      if((plateau[i-1][j] == VIDE) && (plateau[i+1][j] == BLEU)){
	x=i+1;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x++;
	}
	return score;
      }
    }
    if((a == 1) && (b ==  0)){
      if((plateau[i+1][j] == VIDE) && (plateau[i-1][j] == BLEU)){
	x=i-1;
	y=j;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	}
	return score;
      }
    }
    if((a == 1) && (b == -1)){
      if((plateau[i+1][j-1] == VIDE) && (plateau[i-1][j+1] == BLEU)){
	x=i-1;
	y=j+1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  x--;
	  y++;
	}
	return score;
      }
    }
    if((a ==  0) && (b == 1)){
      if((plateau[i][j+1] == VIDE) && (plateau[i][j-1] == BLEU)){
	x=i;
	y=j-1;
	score=0;
	while((x > 0) && (x <= HAUTEUR) && (y > 0) && (y <= LARGEUR)){
	  if(plateau[x][y] == BLEU){
	    score ++;
	  } else return score;
	  y--;
	}
	return score;
      }
    }
  }
  return 0;
}






void mouvement_random(int plateau[HAUTEUR][LARGEUR],int joueur){
  int i,j;
  if(joueur%2 == 0){
    for(i=0;i<HAUTEUR;i++){
      for(j=0;j<LARGEUR;j++){
	if(plateau[i][j] == BLEU){
	  if(((i%2 == 0) && (j%2 == 0))||((i%2 != 0) && (j%2 != 0))){
	    if(plateau[i-1][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j-1] = BLEU;
	    }
	    if(plateau[i-1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j] = BLEU;
	    }
	    if(plateau[i-1][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j+1] = BLEU;
	    }
	    if(plateau[i][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j-1] = BLEU;
	    }
	    if(plateau[i][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j+1] = BLEU;
	    }
	    if(plateau[i+1][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j-1] = BLEU;
	    }
	    if(plateau[i+1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j] = BLEU;
	    }
	    if(plateau[i+1][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j+1] = BLEU;
	    }
	  }else{
	    if(plateau[i+1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j] = BLEU;
	    }
	    if(plateau[i][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j+1] = BLEU;
	    }
	    if(plateau[i-1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j] = BLEU;
	    }
	    if(plateau[i][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j-1] = BLEU;
	    }
	  }
	}
      }
    }
  }else{
    for(i=0;i<HAUTEUR;i++){
      for(j=0;j<LARGEUR;j++){
	if(plateau[i][j] == ROUGE){
	  if(((i%2 == 0) && (j%2 == 0))||((i%2 != 0) && (j%2 != 0))){
	    if(plateau[i-1][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j-1] = ROUGE;
	    }
	    if(plateau[i-1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j] = ROUGE;
	    }
	    if(plateau[i-1][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j+1] = ROUGE;
	    }
	    if(plateau[i][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j-1] = ROUGE;
	    }
	    if(plateau[i][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j+1] = ROUGE;
	    }
	    if(plateau[i+1][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j-1] = ROUGE;
	    }
	    if(plateau[i+1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j] = ROUGE;
	    }
	    if(plateau[i+1][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j+1] = ROUGE;
	    }
	  }else{
	    if(plateau[i+1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i+1][j] = ROUGE;
	    }
	    if(plateau[i][j+1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j+1] = ROUGE;
	    }
	    if(plateau[i-1][j] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i-1][j] = ROUGE;
	    }
	    if(plateau[i][j-1] == VIDE){
	      plateau[i][j] = VIDE;
	      plateau[i][j-1] = ROUGE;
	    }
	  }
	}
      }
    }
  }
}







void deplacement_IA(int plateau[HAUTEUR][LARGEUR], int joueur, int i, int j, int a, int b){
  int jeu,mgb,U=1;
  while(U==1){
    jeu=deplacement(plateau,joueur,i,j,a,b);
    printf(" jeu IA : %d \n",jeu);
    if(jeu == 42)plateau[i][j] = USE;
    if(jeu == 42 && plateau[a][b] == ROUGE) plateau[a][b] = ROUGE_BOUGE;
    if(jeu == 42 && plateau[a][b] == BLEU) plateau[a][b] = BLEU_BOUGE;
    afficher_solution(plateau);
    if(jeu == 42 && plateau[a][b] == ROUGE_BOUGE) plateau[a][b] = ROUGE;
    if(jeu == 42 && plateau[a][b] == BLEU_BOUGE) plateau[a][b] = BLEU;
    mgb=mangeable(plateau,a,b);
    if((jeu == 42) && (mgb != 1) ){
      printf("carrot\n");
      reinit_USE(plateau);
      afficher_solution(plateau);
      sauvegarde(plateau,joueur);
      break;
    }
    printf("coucou\n");
    reinit_USE(plateau);
    afficher_solution(plateau);
    sauvegarde(plateau,joueur);
    break;
  }

}

void jeu_ia_debile(int plateau [HAUTEUR][LARGEUR],int joueur){
  int x=0,y=0;
  int a,b,mgb,diag=0,cont=0;
  int score=0,score_max=0,a_max,b_max,mange=0,x_max=0,y_max=0;
  afficher_solution(plateau);
  printf("A l'IA de jouer \n");
  while(cont==0){
    for(x=0;x<HAUTEUR;x++){
      for(y=0;y<LARGEUR;y++){
	mgb=mangeable(plateau,x,y);
	if(joueur%2==0){ // Si joue les bleus
	  if((mgb == 1) && (plateau[x][y] == BLEU)){
	    mange++;
	    diag=diagonale_ia(x,y);
	    if(diag == 1){
	      for(a=-1;a<2;a++){
		for(b=-1;b<2;b++){
		  score=0;
		  score=score_dpl(plateau,x,y,a,b,joueur);
		  if(score>score_max){
		    score_max=score;
		    x_max=x;
		    y_max=y;
		    a_max=a;
		    b_max=b;
		  }
		}
	      }
	    }if(diag != 1){
	      for(a=-1;a<2;a++){
		for(b=-1;b<2;b++){
		  score=score4(plateau, x, y, a, b, joueur);
		  if(score>score_max){
		    score_max=score;
		    x_max=x;
		    y_max=y;
		    a_max=a;
		    b_max=b;
		  }
		}
	      }
	    }
	  }

	}else{ // Donc joue les rouge
	   if((mgb == 1) && (plateau[x][y] == ROUGE)){
	    mange++;
	    diag=diagonale_ia(x,y);
	    if(diag == 1){
	      for(a=-1;a<2;a++){
		for(b=-1;b<2;b++){
		  score=0;
		  score=score_dpl(plateau,x,y,a,b,joueur);
		  if(score>score_max){
		    score_max=score;
		    x_max=x;
		    y_max=y;
		    a_max=a;
		    b_max=b;
		  }
		}
	      }
	    }if(diag != 1){
	      for(a=-1;a<2;a++){
		for(b=-1;b<2;b++){
		  score=score4(plateau, x, y, a, b, joueur);
		  if(score>score_max){
		    score_max=score;
		    x_max=x;
		    y_max=y;
		    a_max=a;
		    b_max=b;
		  }
		}
	      }
	    }
	   }
      }
    }
  }
  cont++;
}

  if(mange==0){
    mouvement_random(plateau,joueur);
    cont++;
  }
  deplacement_IA(plateau,joueur,x_max,y_max,x_max+a_max,y_max+b_max);
}




void jeu_joueur(int plateau[HAUTEUR][LARGEUR],int joueur){
  int i=0,j=0,jeu=0,miam,x=0,y=0,compteur=0;
  int a,b,mgb,diag=0,cont=0;
  printf("Au joueur de jouer \n");
  while(cont==0){
    afficher_solution(plateau);
    compteur=0;
    if(joueur%2 == 0)printf("Vous etes les  BLEUS\n");
    else printf("Vous etes les ROUGES\n");
    printf("Quel pion voulez vous jouer ?\nOu voulez vous deplacer ce pion ?\n(Si vous voulez abandonner, tapez 666,666)\n");
    scanf("%d,%d",&i,&j);
    scanf("%d,%d",&a,&b);

    mgb=mangeable(plateau,i,j);
    if(mgb == 1){
      miam=doit_manger(plateau,joueur,i,j,a,b);
      //printf("%d,%d\n",joueur,miam);
      if(miam != 1){
	printf("Vous pouvez et donc devez faire un deplacement impliquant l'elimination d'un pion adverse\n");
	continue;
      }
    }
    if(mgb == 2){ //Si le pion selec n'est pas jouable qu'en est il des autres ?
      for(x=0;x<HAUTEUR;x++){
	for(y=0;y<LARGEUR;y++){
	  mgb=mangeable(plateau,x,y);
	  if((plateau[i][j] == BLEU) && (joueur%2 == 0)){
	    if(mgb == 1){
	      //printf("%d,%d\n",x,y);
	      compteur++;
	      break;
	    }
	  }
	  if((plateau[i][j] == ROUGE ) && (joueur%2 != 0)){
	    if(mgb == 1){
	      //printf("%d,%d",x,y);
	      compteur++;
	      break;
	    }
	  }
	}
      }

    }

    if(compteur > 0){printf("Vous devez/pouvez jouer un autre pion car au moins un autre peut eliminer un pion adverse\n");afficher_solution(plateau);continue;}

    system("clear");
    diag = diagonal(i,j,a,b);
    if(diag == 1 ) {
      printf("ce pion ne peut pas se deplacer en diagonal\n");
      afficher_solution(plateau);
      continue;
    }

    jeu=deplacement(plateau,joueur,i,j,a,b);
    if(jeu == 0){ afficher_solution(plateau);
      printf("Vous ne pouvez jouer ce pion : il ne vous appartient pas\n");continue;}
    if(jeu == 1){ afficher_solution(plateau);
      printf("Vous essayez de sélectionner un pion hors du plateau\n");continue;}
    if(jeu == 2){ afficher_solution(plateau);
      printf("Ce pion n'est actuellement pas jouable : aucune case libre adjacente\n");continue;}
    if(jeu == 3){ afficher_solution(plateau);
      printf("Il n'y a pas de pions sur cette case ... \n");continue;}
    if(jeu == 4){ afficher_solution(plateau);
      printf("Cette case est deja occupee\n");continue;}
    if(jeu == 5){ afficher_solution(plateau);
      printf("ces coordonnes ne sont pas accessibles pour ce pion\n");continue;}
    if(jeu == 42)plateau[i][j] = USE;
    if(jeu == 42 && plateau[a][b] == ROUGE) plateau[a][b] = ROUGE_BOUGE;
    if(jeu == 42 && plateau[a][b] == BLEU) plateau[a][b] = BLEU_BOUGE;
    afficher_solution(plateau);
    if(jeu == 42 && plateau[a][b] == ROUGE_BOUGE) plateau[a][b] = ROUGE;
    if(jeu == 42 && plateau[a][b] == BLEU_BOUGE) plateau[a][b] = BLEU;
    mgb=mangeable(plateau,a,b);
    if((jeu == 42) && (mgb != 1) ){
      reinit_USE(plateau);
      afficher_solution(plateau);
      sauvegarde(plateau,joueur);
      break;
    }
    mouvement(plateau,joueur,a,b,i,j);
    reinit_USE(plateau);
    // afficher_solution(plateau);
    sauvegarde(plateau,joueur);
    break;
  }
}



void jeu_avec_ia(int plateau[HAUTEUR][LARGEUR]){
  int choix,joueur=3;
  int vie_BLEU,vie_ROUGE;
  vie_BLEU=check_vie_BLEU(plateau);
  vie_ROUGE=check_vie_ROUGE(plateau);
  printf("Les ROUGES commencent, voulez jouer en premier ?\n 0 : Oui\n 1: Non\n");
  scanf("%d",&choix);
  while((vie_BLEU > 0) && (vie_ROUGE > 0)){
    if(choix == 0){
      if(joueur%2 != 0){
	jeu_joueur(plateau,joueur);
	joueur++;
      }else{
	jeu_ia_debile(plateau,joueur);
	joueur++;
      }
    }else{
      if(joueur%2 != 0){
	jeu_ia_debile(plateau,joueur);
	joueur++;
      }else{
	jeu_joueur(plateau,joueur);
	joueur++;
      }
    }
  }
}



int main (){
  int choix_IA;
  int joueur=3;
  int plateau[HAUTEUR][LARGEUR];
  menu(plateau,joueur);
  printf("voulez vous jouer avec une IA ?\n 0 : OUI\n 1 : NON\n");
  scanf("%d",&choix_IA);
  if(choix_IA == 1){
    jeu_sans_ia(plateau);
  }else{
    jeu_avec_ia(plateau);

  }
    return 0;
}
