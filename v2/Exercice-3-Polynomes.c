#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// pour malloc
//
//*nom var pointeur=new val
//Tab a 1 dim
// tab=malloc(763213*sizeof(int)
//free(tab)
// faire 4 tab1 de taille 3
// faire 1 tab2 de taille 4 qui retient l'adresse des autre tab
// faire une var3 qui prend la valeur du pointeur du tab2
// soit
/*
int** tab;
tab=malloc(4*sizeof(int*));
for (int i=0; i<4;i++){
tab[i]=malloc(3*sizeof(int));
}
*/

struct poly_s{
	double tab[255];
	int taille;
};

void rempPolyAlea(struct poly_s*);
void affichePoly(struct poly_s*);
void rempPolyAlea(struct poly_s*);
void multPoly(struct poly_s*,struct poly_s*,struct poly_s*);
double calcPoly(struct poly_s*,double);
void derivPoly(struct poly_s*,struct poly_s*);
void addPoly(struct poly_s*,struct poly_s*,struct poly_s*);
void rempPolyZero(struct poly_s*);
void divPoly(struct poly_s*,struct poly_s*,struct poly_s*);
void rempPoly(struct poly_s*);
int maxPoly(struct poly_s*);

int main(){
    time_t t;
    srand((unsigned) time(&t));

struct poly_s test;
printf("Quel est l'exposant le plus haut de votre polynomes ? \n");
scanf("%d",&test.taille);
printf("On a donc un tableau de taille %d\n",test.taille);
rempPolyAlea(&test);
affichePoly(&test);
double caramel=0;
printf("A quel point doit-on calculer le machin ?\n");
scanf("%lf",&caramel);
double portejartel=calcPoly(&test,caramel);
printf("Pour le point %f notre polynome vaut %f\n",caramel,portejartel);
struct poly_s yeet;
derivPoly(&test,&yeet);
printf("La dérivé du polynome vaut : \n");
affichePoly(&yeet);
struct poly_s chevre;
addPoly(&test,&yeet,&chevre);
printf("La somme de la dérivé et du polynome vaut : \n");
affichePoly(&chevre);
rempPolyZero(&chevre);
multPoly(&test,&yeet,&chevre);
printf("La multiplication du poly et du dérivé vaut : \n");
affichePoly(&chevre);
struct poly_s a,b,c;

printf("Quel est l'exposant le plus haut de votre polynomes ? \n");
scanf("%d",&a.taille);

printf("Quel est l'exposant le plus haut de votre polynomes ? \n");
scanf("%d",&b.taille);
rempPoly(&a);
rempPoly(&b);

divPoly(&a,&b,&c);

}


void divPoly(struct poly_s* A, struct poly_s* B, struct poly_s* Q){
// On calcule P1
struct poly_s p1,p2,r1,r2,r1prim,r2prim;
p1.taille=A->taille-B->taille;
rempPolyZero(&p1);
p1.tab[p1.taille]=-1*A->tab[A->taille]*B->tab[B->taille];
// On calcule R1
multPoly(B,&p1,&r1prim);
addPoly(&r1prim,A,&r1);
r1.taille=maxPoly(&r1);
// On calcule R2=R1-P2*B
// On calcule P1
p2.taille=r1.taille-B->taille;
rempPolyZero(&p2);
p2.tab[p2.taille]=-1*r1.tab[r1.taille]*B->tab[B->taille];
// On calcule R2
multPoly(B,&p2,&r2prim);
addPoly(&r2prim,&r1,&r2);
r2.taille=maxPoly(&r2);

// ??
printf("p1 vaut : \n");
affichePoly(&p1);
printf("r1 vaut : \n");
affichePoly(&r1);
printf("p2 vaut : \n");
affichePoly(&p2);
printf("r2 vaut : \n");
affichePoly(&r2);

}

int maxPoly(struct poly_s* test){
	for (int i=test->taille;i>=0;i--){
		if (test->tab[i]!=0){
			return i;
		}



	}
return 0;
}






void multPoly(struct poly_s* src,struct poly_s* placard,struct poly_s* dst){
int max=0;
max=src->taille+placard->taille;
dst->taille=max;
int i,j;

for (i=0;i<=src->taille;i++){
	for (j=0;j<=placard->taille;j++){
		dst->tab[i+j]=dst->tab[i+j]+src->tab[i]*placard->tab[j];
	}
}
}









void addPoly(struct poly_s* src,struct poly_s* placard,struct poly_s* dst){
int max=0;
if (src->taille>placard->taille){
	max=src->taille;
}
else {
	max=placard->taille;
	}
dst->taille=max;
for (int i=0;i<=max;i++){
	dst->tab[i]=src->tab[i]+placard->tab[i];
}

}



double calcPoly(struct poly_s* poly,double var){
double huitre=0;
int pikachu=0;
for (pikachu=poly->taille;pikachu>-1;pikachu=pikachu-1){
	huitre=huitre+poly->tab[pikachu]*pow(var,pikachu);
}
return huitre;

}


void affichePoly(struct poly_s* poly){
for (int i=poly->taille;i>-1;i=i-1){
	printf("%f*x^%d+",poly->tab[i],i);
}
printf("\n");
}

void rempPolyAlea(struct poly_s* poly){
for (int i=0;i<=poly->taille;i++){
		poly->tab[i]=rand()%99;
}
}


void rempPoly(struct poly_s* poly){
double truc=0;
	for (int i=0;i<=poly->taille;i++){
                printf("Merci de rentrer le nombre avec l'exposant %d \n",i);
		scanf("%lf",&truc);
		poly->tab[i]=truc;
}
}


void rempPolyZero(struct poly_s* poly){
double truc=0;
        for (int i=0;i<=poly->taille;i++){
                poly->tab[i]=truc;
}
}
void derivPoly(struct poly_s* src,struct poly_s* dst){
	for (int i=src->taille;i>0;i=i-1){
		dst->tab[i-1]=i*src->tab[i];

		}
	dst->taille=src->taille-1;
	}














