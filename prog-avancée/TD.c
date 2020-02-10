#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//définition des structures
typedef struct{
	int degre;
	float* coeffs;
}poly_s;

//prédéfinition des fonctions
poly_s* polyNul(int);
float valPoly(poly_s*,float);
void affichePoly( poly_s*);
void polyDeriv(poly_s*);

// définition du main
int main(){
poly_s* test;
test=polyNul(8);
test->coeffs[3]=5;
test->coeffs[1]=3;
test->coeffs[0]=-3;

affichePoly(test);
float truc=valPoly(test,8);
printf("%f Est la valeurs de f(8) \n",truc);

polyDeriv(test);
affichePoly(test);

return 0;
}


//Définition des fonctions
poly_s* polyNul(int deg){
	int i=0;
	poly_s* tmp;
	tmp=(poly_s*)malloc(sizeof(poly_s));
	tmp->degre=deg;
	tmp->coeffs=(float*)malloc((deg+1)*sizeof(float));
	for (i=0;i<=tmp->degre;i++){
		tmp->coeffs[i]=0;
	}
return tmp;
}

//question 2
float valPoly(poly_s* poy,float x){
	int i=0;
	float valeurs=0;
	float val2=0;
	for (i=0;i<poy->degre;i++){
		val2=powf(x,i);
		val2=poy->coeffs[i]*val2;
		valeurs=valeurs+val2;
	}
return valeurs;
}


//question 3
void affichePoly(poly_s* poy){
int i=0;
printf("f: x ->");
for (i=poy->degre;i>=0;i--){
	if (poy->coeffs[i]<0){
		printf("%fx^%d",poy->coeffs[i],i);
	}
	else {
		printf("+%fx^%d",poy->coeffs[i],i);
	}
}
printf("\n");

}

//question 4
void polyDeriv(poly_s* poy){
int i=0;

for (i=0;i<poy->degre;i++){
	poy->coeffs[i]=(i+1)*poy->coeffs[i+1];
	}
poy->degre--;
}



//Question 5
void sommePoly(poly_s* poy,poly_s* pay){



}
