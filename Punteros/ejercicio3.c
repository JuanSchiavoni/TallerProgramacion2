#include <stdio.h>

int main () {
    int i, j, n, A[10][10], B[10][10], S[10][10];

    printf("Ingrese el tamaño de la matriz (maximo 10x10): ");
    scanf("%d", &n);

    printf("\nMatriz A:\n");

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            int x=0;
            printf("Fila: %d  Columna: %d Valor: ", i+1, j+1);
            scanf("%d", &x);
            A[i][j]=x;
        }
    }

    printf("\nMatriz A:");
     for(i=0; i<n; i++) {
        printf("\n");
        for(j=0; j<n; j++) {
            printf("%d ", A[i][j]);
        }
    }

    printf("\n");
    printf("\nMatriz B:\n");

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            int x=0;
            printf("Fila: %d  Columna: %d Valor: ", i+1, j+1);
            scanf("%d", &x);
            B[i][j]=x;
        }
    }

    printf("\nMatriz B:\n");
     for(i=0; i<n; i++) {
        printf("\n");
        for(j=0; j<n; j++) {
            printf("%d ", B[i][j]);
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\n\nMatriz SUMA\n");

    for(i=0; i<n; i++) {
        printf("\n");
        for(j=0; j<n; j++) {
            printf("%d ", S[i][j]);
        }
    }
return 0;
}
