#include <stdio.h>

int main () {

    int i=5, j[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char x='a', pal[]="texto en c";
    int *pi;
    char *pc;

    //ap1 dir de i y su valor
    printf("Por Variable i: #Valor: %d   #Direccion: %p \n", i, &i);
    printf("\n");
    //ap2 Mostrar los mismos valores a traves del puntero *pi
    pi= &i;
    printf("Por puntero pi: #Valor: %d   #Direccion: %p \n", *pi, pi);
    printf("\n");

    //ap3 Recorrer j, para cada elemento valor y direccion
    for(int i=0; i<10; i++) {
        printf("Por Variable j[]: #Valor: %d   #Direccion: %p \n", j[i], &j[i]);
    }
    printf("\n");

    //ap4 Recorrer j accediendo a traves de *pi y usando algebra de punteros
    for(int i=0; i<10; i++) {
        pi=(&j[0])+i;
        printf("Por Puntero j[]: #Valor: %d   #Direccion: %p \n", *pi, pi);
    }
    printf("\n");

    //ap5 lo mismo con el char, el string y el puntero *pc
    printf("Por Variable x: #Valor: %c   #Direccion: %p \n", x, &x);
    printf("\n");

    pc= &x;
    printf("Por puntero pc: #Valor: %c   #Direccion: %p \n", *pc, pc);
    printf("\n");

    for(int i=0; i<10; i++) {
        printf("Por Variable pal[]: #Valor: %c   #Direccion: %p \n", pal[i], &pal[i]);
    }
    printf("\n");

    for(int i=0; i<10; i++) {
        pc=(&pal[0])+i;
        printf("Por Puntero pal[]: #Valor: %c   #Direccion: %p \n", *pc, pc);
    }
    printf("\n");

    //Muestre la direccion de *pi y de *pc
    printf("#Direccion de pi: %p   #Direccion de pc:%p \n", &pi, &pc);

    return 0;
}
