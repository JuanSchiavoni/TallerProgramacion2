#include <stdio.h>
#include <stdlib.h>


int i,j,f,c;
int **Matriz;
int **Escalar;
int **MatFinal;


int main(){

CreaMatriz();
RanMatriz();
CreaEscalar();
MatMezcla();

return 0;
}

void CreaMatriz(){
printf("\nIngrese una cantidad de filas: ");
scanf("%d",&f);
printf("\nIngrese una cantidad de columnas: ");
scanf("%d",&c);
Matriz = malloc (sizeof(int*)*f);
    for (i=0;i<f;i++){
    Matriz[i] = malloc (sizeof(int)*c);
    }
}



void RanMatriz(){
    for(i=0;i<f;i++){
        for (j=0;j<c;j++){
        Matriz[i][j] = 1 + rand () %90;
        }
    }


    for(i=0;i<f;i++){
        for (j=0;j<c;j++){
        printf(" %d ",Matriz[i][j]);
        }
        printf("\n");
    }
}


void CreaEscalar(){
int esc;
printf("\nIngrese un numero: ");
scanf("%d",&esc);
Escalar = malloc (sizeof(int*)*f);
    for (i=0;i<f;i++){
    Escalar [i] = malloc (sizeof(int)*c);
    }

    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
        Escalar [i][j] = esc;
        }
    }


    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
        printf(" %d ",Escalar[i][j]);
        }
        printf("\n");
    }
}



void MatMezcla(){
MatFinal = malloc (sizeof(int*)*f);
    for (i=0;i<f;i++){
    MatFinal[i] = malloc (sizeof(int)*c);
    }

    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
        MatFinal [i][j] = Matriz[i][j]*Escalar[i][j];
        }
        printf("\n");
    }


    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
        printf(" %d ",MatFinal[i][j]);
        }
        printf("\n");
    }
}
