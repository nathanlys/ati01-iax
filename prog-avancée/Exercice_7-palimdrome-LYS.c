#include <stdio.h>

int longueurChaine(char*);
void codeCesar(char*,int);
void decodeCesar(char*,int);

int main(){
char message[255]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char message2[255]="DEFGHIJKLMNOPQRSTUVWXYZABCdefghijklmnopqrstuvwxyzabc";
printf("Le message est : \n%s\n",message);
codeCesar(message,3);
decodeCesar(message2,3);
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

//Exercice 7.1
void codeCesar(char* msg,int dec){
int i=0,a=longueurChaine(msg);
dec=dec%26;
for (i=0;i<a;i++){
if (msg[i]<='Z'){
if ((msg[i]+dec>'Z')&&(msg[i]+dec<'a')){
msg[i]=msg[i]+dec-1-'Z'+'A';
} 
else {
msg[i]=msg[i]+dec;
}
}
else {
if (msg[i]+dec>'z'){
msg[i]=msg[i]+dec-1-'z'+'a';
}
else {
msg[i]=msg[i]+dec;
}
}
}
printf("le message codé est :\n%s\n",msg);
}

//Exercice 7.2
void decodeCesar(char* msg,int dec){
int i=0,a=longueurChaine(msg);
dec=dec%26;
for (i=0;i<a;i++){
if (msg[i]<='Z'){
if ((msg[i]-dec<'A')){
msg[i]=msg[i]-dec+1+'Z'-'A';
} 
else {
msg[i]=msg[i]-dec;
}
}
else {
if (msg[i]-dec<'a'){
msg[i]=msg[i]-dec+1+'z'-'a';
}
else {
msg[i]=msg[i]-dec;
}
}
}
printf("le message décodé est :\n%s\n",msg);
}
