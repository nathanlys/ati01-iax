#include <stdio.h>
int longueurChaine(char*);
void concat(char*,char*,char*);

int main(){
	char total[255];
	char message[255]="Bonjour ";
	char message2[255]="je viens de me faire concatener";
	concat(total,message,message2);
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

//Exercice 4
void concat(char* msg,char* ch1,char* ch2){
int a=longueurChaine(ch1),b=longueurChaine(ch2);
int i=0;
for (i=0;i<=a+b;i++){
if (i>=a){
msg[i]=ch2[i-a];
}
else {
msg[i]=ch1[i];
}
}
printf("Le message concaténé est:\n%s\n",msg);

}
