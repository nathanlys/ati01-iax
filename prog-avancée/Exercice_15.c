#include <stdio.h>

//On définie un type matrice:
struct matrice_s{
int tab[255][255];
};
//Pré-définition
void afficheMat(struct matrice_s*,int);
int remplirMat(struct matrice_s*,int);
void dijkstra(struct matrice_s*,int,int);


int main(){
	struct matrice_s test;
	int taille;
	printf("Combien de point vous avez:");
	scanf("%d",&taille);
	afficheMat(&test,taille);
	int drt=remplirMat(&test,taille);
	afficheMat(&test,taille);
	dijkstra(&test,taille,drt);
return 0;
}

void afficheTabInt(int taille,int* tab){
int i=0;
for (i=0;i<=taille;i++){
printf("%d,",tab[i]);
}
printf("\n");
}


//Affiche la matrice 
void afficheMat(struct matrice_s* mat,int max){
	int i=0,j=0;
	int val=0;
	int val2=0;
	printf("  |");
	for (i=0;i<max;i++){
		if (i+'a'>'z'){
			val=i%('z'-'a'+1);
			val2=i/('z'-'a'+1);
			printf("%c%c",val2+'a'-1,'a'+val);
		}
		else{
			printf(" %c",'a'+i);
		}
		printf("|");
	}
	printf("\n");
	for (i=0;i<max;i++){
              	if (i+'a'>'z'){
              		val=i%('z'-'a'+1);
              		val2=i/('z'-'a'+1);
              		printf("%c%c",val2+'a'-1,'a'+val);
              	}
		else{
                      printf(" %c",'a'+i);
               	}
		printf("|");
		for (j=0;j<max;j++){
			printf("%d",mat->tab[i][j]);
			printf("|");
		}
	printf("\n");
	}
}

int remplirMat(struct matrice_s* mat,int taille){
	int i,j;
	int tempo;
	int dir=0;
	printf("entrer 0 si c'est un tableau avec direction, sinon entré 1");
	scanf("%d",&dir);
	if (dir){
	printf("Merci de rentrer la case du tableau demandé puis entrer, si on a pas de lien entre les 2 points on  met -1:\n");
	for (i=0;i<taille;i++){
		for (j=i;j<taille;j++){
			printf("Rentrer la case %d,%d: ",i,j);
			scanf("%d",&tempo);
				if (tempo==-1)
					tempo=9999999;
			mat->tab[i][j]=tempo;
			mat->tab[j][i]=tempo;
		}
	}
	}
	else{
        printf("Merci de rentrer la case du tableau demandé puis entrer, si on a pas de lien entre les 2 points on met -1:\n");
        for (i=0;i<taille;i++){
                for (j=0;j<taille;j++){
                        printf("Rentrer la case %d,%d: ",i,j);
                        scanf("%d",&tempo);
			if (tempo==-1)
				tempo=9999999;
                        mat->tab[i][j]=tempo;
                }
        }
        }
return dir;
}


void dijkstra(struct matrice_s* mat, int taille,int dir){
	int ptsVerif[taille];
	int tabFinal[taille][taille];
	int bas=0;
	int droite=0;
	int distmin=9999999;
//	ptsVerif[0]=1;
	int i=0;
	int deb=0;
	printf("Quel est le point de départ (entre 1 et %d) ?",taille);
	scanf("%d",&deb);
	int fin=0;
        printf("Quel est le point de fin (entre 1 et %d) ?",taille);
        scanf("%d",&fin);
	deb--;
	fin--;
printf("\nLe tableau des valeurs fini est\n");
for (i=0;i<taille;i++){
	ptsVerif[i]=0;
        for (bas=0;bas<taille;bas++){
//                printf("%d ,",tabFinal[i][bas]);
		tabFinal[i][bas]=0;
                printf("%d ,",tabFinal[i][bas]);

        }
printf("\n\n");
}

        if (deb==fin){
                for (bas=0;bas<taille;bas++){
                        ptsVerif[bas]=1;
                }
                printf("Le début est la fin\n");
        }


	ptsVerif[deb]=1;
	int placeFin=0;
for (bas=0;bas<taille;bas++){
	distmin=9999999;


	for (droite=0;droite<taille;droite++){
		distmin=9999999;
		printf("On commence le 2eme FOR avec DROITE= %d\n",droite);
		if (bas==0){
			if (droite==deb){
				printf("On met tabFinal[%d][%d] à 0\n",bas,droite);
				tabFinal[bas][droite]=0;
			}
			else {
                                printf("On met tabFinal[%d][%d] à 999999\n",bas,droite);
				tabFinal[bas][droite]=9999999;
			}
		}
		if ((bas!=0)&&(ptsVerif[droite]==1)){
                        printf("On met tabFinal[%d][%d] à la valeur d'avant\n",bas,droite);
			tabFinal[bas][droite]=tabFinal[bas-1][droite];
			droite++;
		}
		for (i=0;i<taille;i++){

			printf("\n On rentre dans le for avec i=%d si %d <= %d et et ptsVerif[%d]==%d \n\n ",i,mat->tab[i][droite]+tabFinal[bas-1][i],tabFinal[bas-1][droite],i,ptsVerif[i]);


			if ((bas!=0)&&((mat->tab[i][droite]+tabFinal[bas-1][i]<=tabFinal[bas-1][droite])||(tabFinal[bas-1][droite]==9999999))&&(ptsVerif[i]==0)){
                                printf("On met tabFinal[%d][%d] à %d\n",bas,droite,mat->tab[i][droite]+tabFinal[bas-1][i]);
				tabFinal[bas][droite]=mat->tab[i][droite]+tabFinal[bas-1][i];
				printf("\n\n on compare %d et %d \n\n",tabFinal[bas][droite],distmin);
				if (tabFinal[bas][droite]<distmin){
					printf("On met distmin à %d\n",tabFinal[bas][droite]);
					distmin=tabFinal[bas][droite];
					printf("On a vérifier le points %d \n\n\n",i);
					ptsVerif[i]=1;
				}
				printf("On vérifie si distmin=%d == tabFinal[bas][fin]=%d \n",distmin,tabFinal[bas][fin]);
				if (distmin==tabFinal[bas][fin]){
					printf("C'est la fin\n");
					placeFin=bas;
					printf("On définit placeFIN=%d \n",placeFin);
				}
			}
		}
	}
}
printf("Le tableau des valeurs fini est\n");
for (i=0;i<taille;i++){
	for (bas=0;bas<taille;bas++){
		printf("%d ,",tabFinal[i][bas]);
	}
printf("\n");
}
}
