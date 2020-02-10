#include <stdio.h>
double factoriel(int,double);

int main(){
	int a=3;
	double fact=factoriel(a,1);
	printf("la factoriel de %d est %f .\n",a,fact);
	return 0;
}


double factoriel(int a,double fact){
	if (a==0){
		return fact;
	}
	return factoriel(a-1,fact*a);
}
