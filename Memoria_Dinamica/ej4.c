#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, f, c;
int **Matriz;
int **MatrizTrans;

int main() {

    reservMat();
    matrand();
    reservMatRan();
    matRandom();

    return 0;
}
void reservMat() {

    printf("Ingrese la cantidad de filas de su matriz: ");
    scanf("%d", &f);
    printf("Ingrese la cantidad de columnas de su matriz: ");
    scanf("%d", &c);

    Matriz=malloc(sizeof(int*)*f);
    for(i=0; i<f; i++) {
        Matriz[i]=malloc(sizeof(int)*c);
    }
}

void matrand() {

    printf("\nMATRIZ ORIGINAL\n");
    srand(time(NULL));

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            Matriz[i][j]= rand()%50;
        }
    }

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            printf("%d\t", Matriz[i][j]);
        }
        printf("\n");
    }
}

void reservMatRan () {

    MatrizTrans=malloc(sizeof(int*)*f);
    for(i=0; i<f; i++) {
        MatrizTrans[i]=malloc(sizeof(int)*c);
    }
}

void matRandom () {

    printf("\nMATRIZ TRANSPUESTA\n");
    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            MatrizTrans[i][j]=Matriz[i][j];
        }
    }

    for(i=0; i<c; i++) {
        for(j=0; j<f; j++) {
            printf("%d\t", MatrizTrans[j][i]);
        }
        printf("\n");
    }
}
