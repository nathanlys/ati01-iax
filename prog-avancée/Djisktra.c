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
	int tabPetit[taille];
//	ptsVerif[0]=1;
	int nbrVerif=0;
	int i=0;
	int deb=0;
	int placeDistmin=0;
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
			tabFinal[i][bas]=0;
        	        printf("%d ,",tabFinal[i][bas]);
	        }
	printf("\n\n");
	}
        if (deb==fin){
                for (bas=0;bas<taille;bas++){
                        ptsVerif[bas]=1;
			nbrVerif++;
                }
                printf("Le début est la fin\n");
        }
	ptsVerif[deb]=1;
	int placeFin=0;
	for (i=0;i<taille;i++){
		if (i==deb)
			tabFinal[0][i]=0;
		else
			tabFinal[0][i]=9999999;
	}
	while (nbrVerif!=taille){
		distmin=9999999;
		bas=nbrVerif;
		//On cherche le plus petit
		for (bas=0;bas<taille;bas++){
			if (ptsVerif[bas]==1){
				tabPetit[bas]=9999999;
				}
			else{
				tabPetit[bas]=0;
			}
		}
		for (bas=0;bas<taille;bas++){
			for (droite=0;droite<taille;droite++){
				printf("On compare mat->tab[%d][%d]+tabFinal[bas]:%d et %d\n",bas,droite,mat->tab[bas][droite]+tabFinal[bas],distmin);
				//Si on a une valeur a l'intersection de notre matrice alors on récupère la valeur et si le points BAS a était vérifier mais pts droitepas verif
				if ((mat->tab[bas][droite]!=9999999)&&(ptsVerif[bas]==1)&&(ptsVerif[droite]==0)){
					if (mat->tab[bas][droite]+tabFinal[bas]<=distmin){
						distmin=mat->tab[bas][droite]+tabFinal[bas];
						placeDistmin=droite;
						tabPetit[droite]=distmin;
						printf("Bite numero 1\n");
					}
					else {
						if (tabPetit[droite]>mat->tab[bas][droite]+tabFinal[bas]){
							tabPetit[droite]=mat->tab[bas][droite]+tabFinal[bas];
							printf("Bite 2\n");
						}
					}
				}
				else {
					printf("TON PerE l a grenousse des bois de écris qsiudyqskkqfsd\n");
					if (droite>1){
						tabPetit[droite]=tabFinal[bas-1][droite];
						printf("HEAAAAAAAAAAAAAAAAAAAAAYYYYYYYYYYYAH\n");
					}
				}
			}
		}
		ptsVerif[placeDistmin]=1;
		printf("On vérifie %d qui a un poids de %d\n",placeDistmin,tabPetit[placeDistmin]);
		if (placeDistmin==placeFin){
			printf("SAFINILOL\n");
		}
		distmin=9999999;
		for (droite=0;droite<taille;droite++){
			tabFinal[nbrVerif][droite]=tabPetit[droite];
		}
		nbrVerif++;
	}

	printf("Le tableau des valeurs fini est\n");
	for (i=0;i<taille;i++){
		for (bas=0;bas<taille;bas++){
			printf("%d ,",tabFinal[i][bas]);
		}
	printf("\n");
	}
}
