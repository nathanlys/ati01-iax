#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* tabRand(int,int*);
void afficheTabInt(int,int*);
int* bulleTri(int,int*);

int main(){
int taille=-1;
time_t t;
//demande taille du tableau
printf( "Entrez la taille du tableau :");
//taille=getchar()-1;
scanf("%d",&taille);
srand((unsigned) time(&t));
int tab[taille];
tabRand(taille,tab);
printf("Le tableau est :\n");
afficheTabInt(taille,tab);
bulleTri(taille,tab);
printf("Après le tri le tableau est :\n");
afficheTabInt(taille,tab);
return 0;
}


int* tabRand(int taille, int* tab){
int i=0;
for (i=0;i<=taille;i++){
	tab[i]=rand()%6587;
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

int* bulleTri(int n,int* tab){
int i,j,ct;
int c=0;
for (j=n-1;j>=0;j--){
	ct=0;
	for (i=0;i<=j;i++){
	if (tab[i]>tab[i+1]){
		c=tab[i];
		tab[i]=tab[i+1];
		tab[i+1]=c;
		ct++;
	}
	if ((i==j)&&(tab[i]>tab[i-1])){
		c=tab[i];
		tab[i]=tab[i-1];
		tab[i-1]=c;
		ct++;
	}
}
	if (ct==0){
		j=-1;
	}

}
return tab;
}

