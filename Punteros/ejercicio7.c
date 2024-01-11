#include <stdio.h>

int main () {
    int x, i, V[100], j;
    int *punt;
    printf("Cuantos reales desea ingresar? (entre 1 y 100): ");
    scanf("%d", &x);

    if(x>0 && x<101) {
        for(i=0; i<x; i++) {
            printf("Ingrese su #%d elemento: ", i+1);
            scanf("%d", &V[i]);
        }
    }else {
        printf("¡FUERA DE RANGO! Reingresar");
        return -1;
    }

    printf("\nOrden original\n");
    for(i=0; i<x; i++) {
            printf("%d ", V[i]);
    }

    printf("\nOrden inverso\n");

    punt=&V[x-1];
    for(j=0; j<x; j++) {
        printf("%d ", *punt);
        punt=punt-1;
    }
    return 0;
}
