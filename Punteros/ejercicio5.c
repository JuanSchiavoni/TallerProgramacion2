#include <stdio.h>


int main () {
    int i = 8, *pi=&i;
    long long l = 8, *pl=&l;
    float f = 102.8f, *pf=&f;
    double d=678.44, *pd=&d;
    int vec[100];
    vec[0] = 44;
    printf("variable int: #tam.bytes: %d   #dir.&i: %p   #valor: %d\n", sizeof(i), &i, i);

    printf("puntero int: #tam.bytes: %d   #dir.&pi: %p   #valor: %p\n", sizeof(pi), &pi, pi);

    printf("variable long: #tam.bytes: %d   #dir.&l: %p   #valor: %ld\n", sizeof(l), &l, l);

    printf("puntero long: #tam.bytes: %d   #dir.&pl: %p   #valor: %p\n", sizeof(pl), &pl, pl);

    printf("variable float: #tam.bytes: %d   #dir.&f: %p   #valor: %.1f\n" , sizeof(f), &f, f);

    printf("puntero float: #tam.bytes: %d   #dir.&pf: %p   #valor: %p\n", sizeof(pf), &pf, pf);

    printf("variable double: #tam.bytes: %d   #dir.&d: %p   #valor: %.2lf\n", sizeof(d), &d, d);

    printf("puntero double: #tam.bytes: %d   #dir.&pd: %p   #valor: %p\n", sizeof(pd), &pd, pd);

    printf("variable array: #tam.bytes: %d   #dir.&vec[0]: %p   #valor: %d\n", sizeof(vec [0]), &vec[0], vec[0]);

    printf("puntero array: #tam.bytes: %d   #dir.&vec: %p   #valor: %p\n", sizeof(vec), &vec, vec);

    return 0;
}
