#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c, f, i, j;
int **Matriz1;
int **Matriz2;
int **SumaMats;

int main() {

    creaMat1();
    creaMat2();
    mat1();
    printf("\n");
    mat2();
    printf("\n");
    creaSum();
    sumats();

    return 0;
}

void creaMat1() {
    printf("Ingrese el tamaño de las matrices a sumar: ");
    scanf("%d", &f);
    c=f;

    Matriz1=malloc(sizeof(int*)*f);
    for(i=0; i<f; i++) {
        Matriz1[i]=malloc(sizeof(int)*c);
    }

}

void creaMat2() {
    Matriz2=malloc(sizeof(int*)*f);
    for(i=0; i<f; i++) {
        Matriz2[i]=malloc(sizeof(int)*c);
    }
}

void mat1() {

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            Matriz1[i][j]= rand()%50;
        }
    }

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            printf("%d\t", Matriz1[i][j]);
        }
        printf("\n");
    }

}

void mat2() {

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            Matriz2[i][j]= rand()%50;
        }
    }

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            printf("%d\t", Matriz2[i][j]);
        }
        printf("\n");
    }
}

void creaSum() {

    SumaMats=malloc(sizeof(int*)*f);
    for(i=0; i<f; i++) {
        SumaMats[i]=malloc(sizeof(int)*c);
    }

}

void sumats() {

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            SumaMats[i][j]= Matriz1[i][j]+Matriz2[i][j];
        }
    }

    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            printf("%d\t", SumaMats[i][j]);
        }
        printf("\n");
    }
}
