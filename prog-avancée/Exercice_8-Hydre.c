#include <stdio.h>
//prédifinition des fonctions
int hydre(int,int);

//Main
int main(int argc,char* argv[255]){
int coup=0;
if (argc==2){

	char* c=argv[1];
	char c2=c[0];
	int tete=c2-'0';
	coup=hydre(tete,0);
}
else {
	printf("Vous pouvez rentrer le nombre de tetes initial en arguement(entre 0 et 9, par defaut c'est 6 \n");
	coup=hydre(6,0);
}
printf("le nombre total de coups est: %d\n",coup);

return 0;
}

//fonction
//Exercice 1 
//Exercice 8 hydre de Lerne
int hydre(int tete,int coup){

while (tete!=0){
if (tete%2==0){
tete=tete/2;
}
else{
tete=tete+1;
tete=tete/2;
}
if (tete==1){
tete=0;
coup++;
}
else {
if (tete%2!=0){
tete=tete*3;
tete++;
}
}

coup++;
}
return coup;
}
