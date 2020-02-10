#include <stdio.h>
#include <stdlib.h>
int longueurChaine(char*);
char* changeEspace(char*);

int main(){
char mssage[255]="Je fais 9";
changeEspace(mssage);
printf("Le message avec les espaces remplacé est:\n%s\n",mssage);
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

//Exercice 2
char* changeEspace(char* message){
char* msg=malloc(255);
int i=0;
int longueur=longueurChaine(message);
for (i=0; i<longueur; i++){
if (message[i]==' '){
message[i]='_';
}
}
free(msg);
return message;
}
