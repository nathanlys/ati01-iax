#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct pile_s{
char tab[10];
int pointeur;
int taille;
};



char* tabRandChar(int,char*);
void afficheTabChar(int,char*);
char pop(struct pile_s *);
void push(struct pile_s *,char);
int isvide(struct pile_s *);
char peek(struct pile_s *);
void efface(struct pile_s *);
void duplique(struct pile_s *);
void swap(struct pile_s *);

int main(){
time_t t;
srand((unsigned) time(&t));
struct pile_s test;
test.pointeur=9;
test.taille=10-1;
tabRandChar(test.taille,test.tab);
printf("Dans le tableau on a:\n");
afficheTabChar(test.pointeur,test.tab);
char a=pop(&test);
printf("Le truc sortis est %c\n",a);
printf("Dans le tableau on a:\n");
afficheTabChar(test.pointeur,test.tab);
push(&test,'x');
printf("Dans le tableau on a:\n");
afficheTabChar(test.pointeur,test.tab);
printf("Le premier bidule de la pile est: %c\n",peek(&test));
efface(&test);
printf("Le tableau vidé donne:");
afficheTabChar(test.pointeur,test.tab);
push(&test,'b');
push(&test,'i');
push(&test,'r');
push(&test,'e');
afficheTabChar(test.pointeur,test.tab);
swap(&test);
afficheTabChar(test.pointeur,test.tab);
duplique(&test);
afficheTabChar(test.pointeur,test.tab);

return 0;
}

//Fonction qui remplit le tableau avec des lettres miniscules aléatoire
char* tabRandChar(int taille, char*tab){
char* msg=malloc(255);
int i=0;
for (i=0;i<=taille;i++){
	tab[i]=rand()% (122-97) + 97;
	}
free(msg);
return tab;
}

//Fonction qui affiche un tableau de caractère.
void afficheTabChar(int taille,char* tab){
int i=0;
for (i=0;i<=taille;i++){
printf("%c,",tab[i]);
}
printf("\n");
}


//Fonction qui empile
void push(struct pile_s * piles, char val){
if (piles->pointeur!=piles->taille){
	piles->pointeur++;
	piles->tab[piles->pointeur]=val;
}
}

//Fonction qui dépile
char pop(struct pile_s * P){
	if (!isvide(P)){
		char value=P->tab[P->pointeur];
		P->pointeur--;
		return value;
	}
return 0;
}


//Fonction qui vérifie si le tableau est vide
int isvide(struct pile_s * piles){
	return !(piles->pointeur);
}


//Retourne l'élément de tète
char peek(struct pile_s * P){
	char top=pop(P);
	push(P,top);
return top;
}

//Vide la pile
void efface(struct pile_s * P){
	char truc;
	while (!isvide(P)){
		truc=pop(P);
	}
        P->pointeur--;
	truc=truc+'r';
}

//Duplique l'élément de tête
void duplique(struct pile_s * P){
	char truc1;
	truc1=pop(P);
	push(P,truc1);
	push(P,truc1);
}

//Echange les 2 premiers éléments
void swap(struct pile_s * P){
	char truc1,truc2;
	truc1=pop(P);
	truc2=pop(P);
	push(P,truc1);
	push(P,truc2);
}
