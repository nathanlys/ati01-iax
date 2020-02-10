#include <stdio.h>
double factoriel(int);

int main(){
	int a=39;
	double fact=factoriel(a);
	printf("la factoriel de %d est %f .\n",a,fact);
	return 0;
}

double factoriel(int a){
	double fact=1;
	int i=0;
	if (a==0){
		return 1;
	}
	for (i=1; i<=a;i++){
		fact=fact*i;
	}
	return fact;
}
