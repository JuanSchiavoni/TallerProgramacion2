#include <stdio.h>

int main () {
    int f, c, i, j, matriz[10][10];

    printf("Ingrese la cantidad de filas de su matriz(maximo 10): ");
    scanf("%d", &f);

    printf("\nIngrese la cantidad de columnas de su matriz(maximo 10): ");
    scanf("%d", &c);

    printf("\nIngrese los elementos de su matriz (confirme con ENTER): \n");
    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Matriz\n");
    for(i=0; i<f; i++) {
        for(j=0; j<c; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Transpuesta\n");
    for(i=0; i<c; i++) {
        for(j=0; j<f; j++) {
            printf("%d\t", matriz[j][i]);
        }
        printf("\n");
    }
    return 0;
}
