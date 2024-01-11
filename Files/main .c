#include <stdio.h>
#include <stdlib.h>


typedef struct _persona {
    char nombre[10];
    char apellido[10];
    int edad;
    char sexo;
    int meses;
    char plan;
    int paga;
} persona;

typedef struct _planes{
    int cuota;
    char tipo;
}planes;


void cuotas(planes** b);
void ingresa_datos(persona** a);
void descuentos(persona** a);
void escritura(persona** a);


struct persona** persona1 = NULL;
struct persona** persona2 = NULL;
struct persona** persona3 = NULL;
struct persona** persona4 = NULL;
struct planes** planA = NULL;
struct planes** planB = NULL;
struct planes** planC = NULL;
float desc;

int cuotaA,cuotaB,cuotaC;

int main(){
persona1= malloc(sizeof(persona));
persona2= malloc(sizeof(persona));
persona3= malloc(sizeof(persona));
persona4= malloc(sizeof(persona));
planA = malloc(sizeof(planes));
planB = malloc(sizeof(planes));
planC = malloc(sizeof(planes));

cuotas(&planA);
cuotas(&planB);
cuotas(&planC);
cuotas(&planA);
printf("\n");

ingresa_datos(&persona1);

return 0;
}


void cuotas(planes** b){
    FILE* sArchivo;
    sArchivo = fopen ("planes.txt","rt");
    if (sArchivo!=NULL){
        if (*b==planA)fscanf(sArchivo,"%c - %d\n",&(*b)->tipo,&cuotaA);

        if (*b==planB){
            fscanf(sArchivo,"%c - %d\n",&(*b)->tipo,&cuotaB);
            fscanf(sArchivo,"%c - %d\n",&(*b)->tipo,&cuotaB);
        }

        if (*b==planC){
            while (!feof(sArchivo)){
            fscanf(sArchivo,"%c - %d\n",&(*b)->tipo,&cuotaC);
            }
        }
        if (fclose(sArchivo)) printf("Error al cerrar el archivo\n");
    }
}


void ingresa_datos(persona** a){
    int i=0;
    FILE* pArchivo;
    pArchivo = fopen("personas.txt","rt");
    if (pArchivo!=NULL){
        fscanf (pArchivo,"%s - %s - %d - %c - %d - %c",&(*a)->nombre,&(*a)->apellido,&(*a)->edad,&(*a)->sexo,&(*a)->meses,&(*a)->plan);
        while (!feof(pArchivo)){
            i = i + 1;
            printf ("%s %s %d %c %d %c",(*a)->nombre,(*a)->apellido,(*a)->edad,(*a)->sexo,(*a)->meses,(*a)->plan);
            descuentos(&(*a));
            escritura(&(*a));
            printf("\n\n\n");
            fscanf (pArchivo,"\r%s - %s - %d - %c - %d - %c",&(*a)->nombre,&(*a)->apellido,&(*a)->edad,&(*a)->sexo,&(*a)->meses,&(*a)->plan);
        }
        if (fclose(pArchivo)) printf ("Error al cerrar el archivo\n");
    }
}

//calcula los descuentos a aplicar
void descuentos(persona** a){
    float desc=0;
    if( (*a)->edad<12 || (*a)->edad>65 ){
        desc = desc + 0.05;
        }
    if( (*a)->meses>=24 ){
        desc = desc + 0.30;}
    printf("\n%s %s tiene un descuento de: %.2f\n",(*a)->nombre,(*a)->apellido,desc);

    if ((*a)->plan=='A') (*a)->paga=cuotaA;
    if ((*a)->plan=='B') (*a)->paga=cuotaB;
    if ((*a)->plan=='C') (*a)->paga=cuotaC;
    (*a)->paga = (*a)->paga - (desc*(*a)->paga);
    printf("%s %s debe pagar %d",(*a)->nombre,(*a)->apellido,(*a)->paga);
}

//escribe en el archivo
void escritura(persona** a){

    FILE* xArchivo;
    xArchivo = fopen("personas.txt","a+");

    if (xArchivo!=NULL){
    fprintf (xArchivo,"%s - %s - %d - %c - %d - %c - $%d\n",(*a)->nombre,(*a)->apellido,(*a)->edad,(*a)->sexo,(*a)->meses,(*a)->plan,(*a)->paga);
    printf("\nLos datos fueron actualizados en el archivo.\n");
    }
}



