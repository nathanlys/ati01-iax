#include <stdio.h>
#include <stdlib.h>
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

long factorielite(int);
long factorielecu(int,long);


int main(){
	int chaussuredroite=0;
	long chaussuregauche=0;
	
	printf("Merci de rentrer l'entier afin de calculer la factorielle en itératif : \n");
	scanf("%d",&chaussuredroite);
	chaussuregauche=factorielite(chaussuredroite);
	
	printf("La factorielle de %d vaut %ld\n",chaussuredroite,chaussuregauche);

	printf("Merci de rentrer l'entier afin de calculer la factorielle en récursif : \n");
	scanf("%d",&chaussuredroite);
	chaussuregauche=factorielecu(chaussuredroite,1);
	printf("La factorielle de %d vaut %ld\n",chaussuredroite,chaussuregauche);
}

long factorielite(int a){
	long fact=1;
	int i=0;
	if (a==0){
		return 1;
	}
	for (i=1; i<=a;i++){
		fact=fact*i;
	}
	return fact;
}

long factorielecu(int a,long fact){
	if (a==0){
		return fact;
	}
	return factorielecu(a-1,fact*a);
}






