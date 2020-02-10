#include <stdio.h>

int longueurChaine(char*);
int palin(char*);

int main(){
char message[255]="Je suis un palindrome emordnilap nu sius eJ";
int palintest=palin(message);
printf("Le message est : \n%s \n",message);
if (palintest) {
printf("Ce n'est pas un palindrome\n");
}
else {
printf("c'est un palimdrome\n");
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

//Exercice 6
int palin(char* message){
int a=longueurChaine(message)-1;
int i=0, j=0;
int k=0;
for (i=a-1;i>=0;i=i-1){
if (message[i]==message[j]){
k=1;
}
else {
k=0;
}
j++;
}
return k;
}

