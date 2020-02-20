#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// pour malloc
//*nom var pointeur=new val
//Tab a 1 dim
// tab=malloc(763213*sizeof(int)
//free(tab)
// faire 4 tab1 de taille 3
// faire 1 tab2 de taille 4 qui retient l'adresse des autre tab
// faire une var3 qui prend la valeur du pointeur du tab2
// soit
/*
double** tab;
tab=malloc(4*sizeof(int*));
for (int i=0; i<4;i++){
tab[i]=malloc(3*sizeof(int));
}
*/

void afficheMat(double**,int,int);
double** createMat(int,int);
void delMat(double**,int,int);
void remplirMatAlea(double**,int,int);
void multMat(double**,int,int,double**,int,int,double**,int,int);
void remplirMat(double**,int,int);
void remplirMatZero(double**,int,int);
void addMat(double**,int,int,double**,int,int,double**,int,int);
double traceMat(double**,int,int);
double detMat(double**,int,int);




int main(){
    double** tab1;
    int lgtab1=0, coltab1=0;
    time_t t;
    srand((unsigned) time(&t));
    printf("Entrer le nombre de ligne du tableau 1\n");
    scanf("%d",&lgtab1);
    printf("Entrer le nombre de colone du tableau 1\n");
    scanf("%d",&coltab1);
    printf("On va créer le tableau\n");
    tab1=createMat(lgtab1,coltab1);
    remplirMatZero(tab1,lgtab1,coltab1);
    //printf("On affiche le tableau\n");
    //afficheMat(tab1,lgtab1,coltab1);
    //printf("On remplis le tableau\n");
    remplirMatAlea(tab1,lgtab1,coltab1);
    printf("On affiche le tableau random\n");
    afficheMat(tab1,lgtab1,coltab1);
    //remplirMat(tab1,lgtab1,coltab1);
    //afficheMat(tab1,lgtab1,coltab1);
    printf("On crée le tableau 2\n");
    double** tab2;
    int lgtab2, coltab2;
    printf("Entrer le nombre de ligne du tableau 2\n");
    scanf("%d",&lgtab2);
    printf("Entrer le nombre de colone du tableau 2\n");
    scanf("%d",&coltab2);
    tab2=createMat(lgtab2,coltab2);
    remplirMatAlea(tab2,lgtab2,coltab2);
    afficheMat(tab2,lgtab2,coltab2);
    double** tab3;
    int lgtab3,coltab3;
    printf("Entrer le nombre de ligne du tableau 3\n");
    scanf("%d",&lgtab3);
    printf("Entrer le nombre de colone du tableau 3\n");
    scanf("%d",&coltab3);
    tab3=createMat(lgtab3,coltab3);
    addMat(tab1,lgtab1,coltab1,tab2,lgtab2,coltab2,tab3,lgtab3,coltab3);
    printf("Voici le tableau1 et 2 ajouter : \n");
    afficheMat(tab3,lgtab3,coltab3);
    printf("Voici le tableau 1 et 2 multiplier : \n");
    multMat(tab1,lgtab1,coltab1,tab2,lgtab2,coltab2,tab3,lgtab3,coltab3);
    afficheMat(tab3,lgtab3,coltab3);

    printf("La trace de la matrice 1 vaut %f \n",traceMat(tab1,lgtab1,coltab1));

    printf("Le déterminant de la matrice vaut %f \n",detMat(tab1,lgtab1,coltab1));

    printf("On détruit les tableaux\n");
    delMat(tab1,lgtab1,coltab1);
    delMat(tab2,lgtab2,coltab2);
    delMat(tab3,lgtab3,coltab3);
}

double** createMat(int i, int j){
    double** tab;
    tab=malloc(i*sizeof(double*));
    for (int k=0;k<i;k++){
        tab[k]=malloc(j*sizeof(double));
    }
return tab;
}

void afficheMat(double** tab, int i, int j){
int ii, jj;
    for (ii=0;ii<i;ii++){
        for (jj=0;jj<j;jj++){
            printf("%f ",tab[ii][jj]);
        }
        printf("\n");
    }
}

void delMat(double** tab, int i, int j){
for (int k=0; k<i;k++){
    free(tab[k]);
}
free(tab);
}


void remplirMatAlea(double** tab, int i, int j){
int ii, jj;
for (ii=0;ii<i;ii++){
for (jj=0;jj<j;jj++){
    tab[ii][jj]=rand()%9;
}
}
}
void remplirMatZero(double** tab, int i, int j){
int ii, jj;
for (ii=0;ii<i;ii++){
for (jj=0;jj<j;jj++){
    tab[ii][jj]=0;
}
}
}


void remplirMat(double** tab, int i, int j){
int ii, jj;
double val=0;
for (ii=0;ii<i;ii++){
for (jj=0;jj<j;jj++){
    printf("Entrer la valeur de la case %d %d \n",ii,jj);
    scanf("%lf",&val);
    tab[ii][jj]=val;
}
}
}

void addMat(double** tab1,int lgtab1,int coltab1,double** tab2,int lgtab2, int coltab2,double** tabres,int lgtabres,int coltabres){
    if ((lgtab1==lgtab2)&&(coltab1==coltab2)){
        for (int ii=0;ii<lgtab1;ii++){
            for (int jj=0;jj<coltab1;jj++){
                tabres[ii][jj]=tab1[ii][jj]+tab2[ii][jj];
            }
        }
    }
}





void multMat(double** tab1,int lgtab1,int coltab1,double** tab2,int lgtab2, int coltab2,double** tabres,int lgtabres,int coltabres){
int ia,ii,jj;
double somme=0;
    if (coltab1==lgtab2){
        for (ii=0;ii<lgtab2;ii++){
            for (jj=0;jj<lgtab2;jj++){
                for (ia=0;ia<lgtab2;ia++){
                    somme=somme+tab1[ii][ia]*tab2[ia][jj];
                }
            tabres[ii][jj]=somme;
            somme=0;



        }
     }
}


}

double traceMat(double** tab,int lg,int col){
double trace=0;
    if (lg==col){
        for (int i=0; i<lg;i++){
            trace=trace+tab[i][i];
        }
    }
return trace;








}



double detMat(double** tab, int lg, int col){
double det=0;
int taboule,pantalon,serviette;
int tshirt=0,pizza=0;
int mouton=0;
double** tab2=createMat(lg-1,col-1);
    if (lg==col){
        if (lg==2){ // SI ON A UN TABLEAU DE 2 CASES SUR 2, ON FAIT CA
	  //printf("Blabla tab 2x2\n");
	  det=tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
	  delMat(tab2,lg-1,col-1);
          return det;  
        }
        else { // SINON ON FAIT CA
		for (taboule=0;taboule<lg;taboule++){
			for (serviette=0;serviette<lg;serviette++){
				if (serviette!=taboule){
					
				
				for (pantalon=1;pantalon<lg;pantalon++){
					
					tab2[tshirt][pizza]=tab[serviette][pantalon];
				pizza++;
				}
				pizza=0;
				tshirt++;
				}
			}
		tshirt=0;
		
		mouton=taboule+1;
		mouton=mouton%2;
		if (mouton==0){
			mouton=mouton-1;
		}
		det=detMat(tab2,lg-1,col-1)*tab[taboule][0]*mouton+det;
		
		}
	}		
        }	  
    delMat(tab2,lg-1,col-1);

return det;
}













