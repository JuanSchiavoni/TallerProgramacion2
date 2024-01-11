#include <stdio.h>
#include <stdlib.h>

int deter_Matriz(int tam, int **Matriz);

int main() {

    int i, j, tam, tam1;
    int **Matriz;
    int deter;

    //pide tamaño
    printf("Ingrese el tamaño de su matriz (NxN): ");
    scanf("%d", &tam);
    tam1 = tam;

    //reserva espacio
    Matriz= malloc(sizeof(int*)*tam);
    for(i=0; i<tam; i++) {
        Matriz[i]= malloc(sizeof(int)*tam1);
    }

    //ingresa por teclado los coeficientes
    for(i=0; i<tam1; i++) {
        for(j=0; j<tam1; j++) {
            printf("Ingrese el valor #%d, #%d: ", i+1, j+1);
            scanf("%d", &Matriz[i][j]);
        }
    }

    //muestra matriz original
    printf("\nMatriz original\n");
    for(i=0; i<tam1; i++) {
        for(j=0; j<tam1; j++) {
            printf("%d\t", Matriz[i][j]);
        }
        printf("\n");
    }

    //funcion que calcula determinante
    deter=deter_Matriz(tam, Matriz);

    //muestro el determinante por pantalla
    printf("El valor del determinante es: %d", deter);

    return 0;
}


int deter_Matriz(int tam, int **Matriz) {

    int x, y, k, aux, pivote, pivote1, determ=1;

    for(x=0; x<tam; x++) {
        pivote=Matriz[x][x];
        for(y=0; y<tam; y++) {
            pivote1=Matriz[y][x];
            aux=pivote1/pivote;

            for(k=0; k<tam; k++) {
                Matriz[y][k]=Matriz[y][k]-aux*Matriz[x][k];
            }
        }
    }

    for(x=0; x<tam; x++) {
        determ=determ*Matriz[x][x];
    }
    return determ;
}
