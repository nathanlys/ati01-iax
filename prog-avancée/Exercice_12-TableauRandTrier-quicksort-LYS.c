#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* tabRand(int,int*);
void afficheTabInt(int,int*);
int* triRapide(int*,int,int);
int partition(int*,int,int);

int main(){
int taille=-1;
time_t t;
//demande taille du tableau
printf( "Entrez la taille du tableau :");
//taille=getchar()-1-'0';
scanf("%d",&taille);
srand((unsigned) time(&t));
int tab[taille];
tabRand(taille,tab);
printf("Le tableau est :\n");
afficheTabInt(taille,tab);
triRapide(tab,0,taille);
printf("Après le tri le tableau est :\n");
afficheTabInt(taille,tab);
return 0;
}


int* tabRand(int taille, int* tab){
int i=0;
for (i=0;i<=taille;i++){
	tab[i]=rand()%99999;
	}
return tab;
}


void afficheTabInt(int taille,int* tab){
int i=0;
for (i=0;i<=taille;i++){
printf("%d,",tab[i]);
}
printf("\n");
}

int* triRapide(int* tab,int deb,int fin){
	int pivot;
	if ( deb==fin){
		return tab;
	}
	pivot=partition(tab,deb,fin);
//	printf("Le pivot vaut %d\n",pivot);
//if (pivot>0){
	triRapide(tab,deb,pivot-1);
//	}
//if (pivot<fin){
	triRapide(tab,pivot+1,fin);
//	}
//	printf("FIn du TRI RAPIDE\n");
	return tab;
}

int partition(int* tab,int deb,int fin){
	int test;
	int test2;
	int debT=deb;
if ((deb<0)||(fin<0)){
	return 0;
}
if (deb>fin){
	test=deb;
	deb=fin;
	fin=test;
	return -1;
}
	if (deb!=fin){
//	printf("on commence une partition debut=%d fin=%d\n",deb,fin);
	for (int i=deb;i<fin;i++){
//		printf("On a compare %d <= %d\n",tab[i],tab[fin]);
		if (tab[i]<=tab[fin]){
//		        printf("on est dans le if\n");
//			printf("On échange %d et %d \n",tab[i],tab[debT]);
			test=tab[i];
			test2=tab[debT];
			tab[i]=test2;
			tab[debT]=test;
			debT++;
//		printf("Le tableau vaut \n");
//		afficheTabInt(8,tab);
		}

//	afficheTabInt(4,tab);
	}
	test=tab[fin];
	test2=tab[debT];
	tab[fin]=test2;
	tab[debT]=test;
//	printf("A la fin d'une partition on a :");
//        afficheTabInt(8,tab);
//	printf("\n\n\n");
}
return debT;
}

