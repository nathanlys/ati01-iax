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
int** tab;
tab=malloc(4*sizeof(int*));
for (int i=0; i<4;i++){
tab[i]=malloc(3*sizeof(int));
}
*/

void afficheMat(int**,int,int);
int** createMat(int,int);
void delMat(int**,int,int);
void remplirMatAlea(int**,int,int);
void multMat(int**,int,int,int**,int,int,int**,int,int);
void remplirMat(int**,int,int);
void remplirMatZero(int**,int,int);
void addMat(int**,int,int,int**,int,int,int**,int,int);
int traceMat(int**,int,int);
int detMat(int **,int,int);




int main(){
    int** tab1;
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
    printf("On affiche le tableau\n");
    afficheMat(tab1,lgtab1,coltab1);
    printf("On remplis le tableau\n");
    remplirMatAlea(tab1,lgtab1,coltab1);
    printf("On affiche le tableau random\n");
    afficheMat(tab1,lgtab1,coltab1);
    //remplirMat(tab1,lgtab1,coltab1);
    //afficheMat(tab1,lgtab1,coltab1);
    printf("On crée le tableau 2");
    int ** tab2;
    int lgtab2, coltab2;
    printf("Entrer le nombre de ligne du tableau 2\n");
    scanf("%d",&lgtab2);
    printf("Entrer le nombre de colone du tableau 2\n");
    scanf("%d",&coltab2);
    tab2=createMat(lgtab2,coltab2);
    remplirMatAlea(tab2,lgtab2,coltab2);
    afficheMat(tab2,lgtab2,coltab2);
    int** tab3;
    int lgtab3,coltab3;
    printf("Entrer le nombre de ligne du tableau 2\n");
    scanf("%d",&lgtab3);
    printf("Entrer le nombre de colone du tableau 2\n");
    scanf("%d",&coltab3);
    tab3=createMat(lgtab3,coltab3);
    addMat(tab1,lgtab1,coltab1,tab2,lgtab2,coltab2,tab3,lgtab3,coltab3);
    afficheMat(tab3,lgtab3,coltab3);
    multMat(tab1,lgtab1,coltab1,tab2,lgtab2,coltab2,tab3,lgtab3,coltab3);
    afficheMat(tab3,lgtab3,coltab3);

    printf("La trace de la matrice 1 vaut %d \n",traceMat(tab1,lgtab1,coltab1));



    printf("On détruit le tableau\n");
    delMat(tab1,lgtab1,coltab1);
    delMat(tab2,lgtab2,coltab2);
    delMat(tab3,lgtab3,coltab3);
}

int** createMat(int i, int j){
    int** tab;
    tab=malloc(i*sizeof(int*));
    for (int k=0;k<i;k++){
        tab[k]=malloc(j*sizeof(int));
    }
return tab;
}

void afficheMat(int** tab, int i, int j){
int ii, jj;
    for (ii=0;ii<i;ii++){
        for (jj=0;jj<j;jj++){
            printf("%d ",tab[ii][jj]);
        }
        printf("\n");
    }
}

void delMat(int** tab, int i, int j){
for (int k=0; k<i;k++){
    free(tab[k]);
}
free(tab);
}


void remplirMatAlea(int** tab, int i, int j){
int ii, jj;
for (ii=0;ii<i;ii++){
for (jj=0;jj<j;jj++){
    tab[ii][jj]=rand()%99;
}
}
}
void remplirMatZero(int** tab, int i, int j){
int ii, jj;
for (ii=0;ii<i;ii++){
for (jj=0;jj<j;jj++){
    tab[ii][jj]=0;
}
}
}


void remplirMat(int** tab, int i, int j){
int ii, jj;
int val=0;
for (ii=0;ii<i;ii++){
for (jj=0;jj<j;jj++){
    printf("Entrer la valeur de la case %d %d \n",ii,jj);
    scanf("%d",&val);
    tab[ii][jj]=val;
}
}
}

void addMat(int** tab1,int lgtab1,int coltab1,int** tab2,int lgtab2, int coltab2,int** tabres,int lgtabres,int coltabres){
    if ((lgtab1==lgtab2)&&(coltab1==coltab2)){
        for (int ii=0;ii<lgtab1;ii++){
            for (int jj=0;jj<coltab1;jj++){
                tabres[ii][jj]=tab1[ii][jj]+tab2[ii][jj];
            }
        }
    }
}





void multMat(int** tab1,int lgtab1,int coltab1,int** tab2,int lgtab2, int coltab2,int** tabres,int lgtabres,int coltabres){
int ia,ii,jj;
int somme=0;
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

int traceMat(int** tab,int lg,int col){
int trace=0;
    if (lg==col){
        for (int i=0; i<lg;i++){
            trace=trace+tab[i][i];
        }
    }
return trace;








}



int detMat(int** tab, int lg, int col){
int det=0;
int tab2[lg-1][col-1];
    if (lg==col){
        if (lg==2){
          det=tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
          return det;  
        }
        else {
            



















        }










    }
}













