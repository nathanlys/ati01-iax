#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* tabRand(int,char*);


struct pile_s {
int taille;
char tab[];
int li;
int fo;
}


int main(){
time_t t;
srand((unsigned) time(&t));
struct pile_s test;
test.taille=5;
tabRand(test.taille,test.tab);
}

char* tabRandChar(int taille, char*tab){
char* msg=malloc(255);
int i=0;
for (i=0;i<=taille;i++){
	tab[i]=rand()'a'%'z';
	}
free(msg);
return tab;
}

