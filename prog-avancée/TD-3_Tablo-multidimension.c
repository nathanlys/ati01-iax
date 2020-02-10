tableaux 1D, 2D et plus...

statiques
déclaration:
int tablo[42];
	   L-> taille connue a la compilation

tablo -> int* (Address first cell);

int tab[42][43];
// rester cohérent sur l'appellation osef de ligne/colonne
720Ko -> mémoire/processus = tas


dynamiques

int* tab;
tab=(int*)malloc(42*sizeof(int));

=> malloc alloue dans la ram pas le tas
=> faut libérer la mémoire
free(tab);


//malloc sur tablo a 2D
//TABLEAUX DE POINTEUR
int ** => contient adresse du tableaux d'étoile (int *) qui lui contient la position de la premiere dimension

int** tablo2;
tablo2=(int**)malloc(17*sizeof(int*));
	//1ERE INDICE
for (int i=0;i<17;i++){
	tablo2[i]=(int*)malloc(42*sizeof(int));
		//2ND INDICE
}

//malloc sur un tableau a 3D

int ***tablo3;
tablo3=(int***)malloc(69*sizeof(int**));
//1er indice
for(int i=0;i<69;i++){
	tablo3[i]=(int**)malloc(17*sizeof(int));
	//2eme indice
	for (int j=0;j<17;j++){
		tablo3[j]=(int*)malloc(42*sizeof(int));
		//3eme indice
	}

}


//FREE en 2D
for (int i=0;i<17;i++){
	free(tablo2[i]);
}
free(tablo2);








//Fonction identité
struct matrice_t{
	float** tab;
	float* tab;
};


matrice_t identité(int N){
	matrice_t matric;
	//float** tab;
	matric->tab=(float**)malloc(N*sizeof(float*));
        //1ERE INDICE
	for (int i=0;i<N;i++){
        	matric->tab[i]=(float*)malloc(42*sizeof(float));
   	            	//2ND INDICE
		}

for (i=0;i<N;i++){
	for (int j=0;j<N;j++){
		if (i==j)
			matric->tab[i][i]=1;
		else
			matric->tab[i][j]=0;
	}
}
return matric;
}
