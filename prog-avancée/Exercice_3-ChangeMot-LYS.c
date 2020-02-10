#include <stdio.h>
#include <stdlib.h>

int longueurChaine(char*);
char* copieChaine(char*,char*);
char* changeCarac(char*,char*,char*);

// En arguement on donne le message (entre double quote), la chaine a remplacé et celle qui la remplace, les 2 chaines doivent avoir la même longueur.
int main(int argc,char* argv[]){
char message[255];
if (argc==4){
int chaineL1=longueurChaine(argv[2]);
int chaineL2=longueurChaine(argv[3]);
if (chaineL1==chaineL2){
copieChaine(message,argv[1]);
changeCarac(message,argv[2],argv[3]);
printf("Le message vaut:\n%s\n",message);

}
else{
printf("Les arguments 2 et 3 doivent avoir la même longueur\n");
}
}
else{
//char* message[255]="Bonjour je suis le jour";
char mess[255]="Bonjour je suis le jour";
char ch1[255]="jour";
char ch2[255]="soir";
printf("Vous n'avez pas rentré d'argument, veuillez rentrer le message, la chaine a changer et celle qui va la remplacer\nPar defaut le message est: %s\n on va changer %s par %s\n",mess,ch1,ch2);


int chaineL1=longueurChaine(ch1);
int chaineL2=longueurChaine(ch2);
if (chaineL1==chaineL2){
changeCarac(mess,ch1,ch2);
printf("Le message vaut:\n%s\n",mess);

}
else{
printf("Les arguments 2 et 3 doivent avoir la même longueur\n");
}
}
return 0;
}

//Exercice 1
int longueurChaine(char* message){
int i=0;
int longueur=0;

for (i=0;message[i]!='\0';i++){
	longueur++;
}
return longueur;
}

//Fonction qui copie un tableau dans un autre.
char* copieChaine(char* ch1,char* ch2){
char* msg=malloc(255);
if (!msg) {
return NULL;
}
int a=longueurChaine(ch2);
for (int i=0;i<=a;i++){
ch1[i]=ch2[i];
}
free(msg);
return ch1;
}

//Exercice 3
char* changeCarac(char* message,char* ch1,char* ch2){
char* messag=malloc(255);
if (!messag){
return NULL;
}
int i=0,j=0,k=0;
int a=longueurChaine(message);
int b=longueurChaine(ch1);
for (i=0;i<a;i++){
k=0;
	for (j=0;j<b;j++){
		if (message[j+i]==ch1[j]){
			k=1;
		}
		else {
		k=0;
		j=b+1;
		}
	}
	if (k==1){
		for (j=0;j<b;j++){
		message[i+j]=ch2[j];
		}
	i=i+b-1;
	}
}
free(messag);
return message;
}
