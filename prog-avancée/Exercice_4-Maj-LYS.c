#include <stdio.h>
#include <stdlib.h>
int longueurChaine(char*);
char* low2up(char*);

int main(int argc,char* argv[255]){
if (argc>=2){
        printf("Le message est: \n%s\n",argv[1]);
        low2up(argv[1]);
        printf("Le message en majuscule uniquement est: \n%s\n",argv[1]);
}
else {
	char message[255]="ReNtREz lE TEXtE eN ArgUEmEnT";
	printf("Le message est: \n%s\n",message);
	low2up(message);
        printf("Le message en majuscule uniquement est: \n%s\n",message);
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

//Exercice 4
char* low2up(char* message){
        char* msg=malloc(255);
        if (!msg) {
                return NULL; 
        }
	int a=longueurChaine(message);
	int i=0;
	for (i=0;i<=a;i++){
		if ((message[i]<='z')&&(message[i]>='a')){
			message[i]=message[i]+'A'-'a';
		}
	}
	message[i]='\0';
	free(msg);
return message;
}
