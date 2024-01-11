#include <stdio.h>

#define N 5

int main() {
    int i, j, MI[N][N];

    printf("Matriz identidad: \n");

    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            MI[i][j]=(i==j);
        }
    }

    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            printf("%d\t", MI[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
