#include <stdio.h>
#include <stdlib.h>
//Définition de la structure pile_s
struct pile_s{
char tab[19999];
int pointeur;
int taille;
};

//Pré-définition des fonctions
char* tabRandChar(int,char*);
void afficheTabChar(int,char*);
char pop(struct pile_s *);
void push(struct pile_s *,char);
int isvide(struct pile_s *);
char peek(struct pile_s *);
void efface(struct pile_s *);
void duplique(struct pile_s *);
void swap(struct pile_s *);

//Main
int main(){
struct pile_s test;
char car,car2;
FILE* fp;
fp=fopen("Exercice_14-equilibrageParenthese-LYS.c","r");
if (fp==NULL){
	printf("Fichier non trouvé ou autre erreurs\n");
	return 1;
}
test.pointeur=0;
while ((car=fgetc(fp))!=EOF) {
switch (car) {
case '{' :push(&test,car);
	break;

case '(' :push(&test,car);
	break;

case ')' :car2=peek(&test);
	if (car2=='('){
		car2=pop(&test);
	}
	break;
case '}' : car2=peek(&test);
	if (car2=='{'){
		car2=pop(&test);
		}
	break;
default: break;
}

}
if (isvide(&test)){
	printf("Toutes les parenthèses sont fermées\n");
}
else{
printf("Parmis les caractères pas fermés on a :");
afficheTabChar(test.pointeur,test.tab);
}
return 0;
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
