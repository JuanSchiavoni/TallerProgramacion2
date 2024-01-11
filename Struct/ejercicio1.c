#include <stdio.h>
#include <stdlib.h>


typedef struct tiempo{
int anio, mes, dia, hora, minuto, segundo;
} Tiempo;


typedef struct {
char * nombre;
Tiempo ultima_mod;
} Archivo;

Tiempo t1;
Tiempo t2;
int res;
int i;
int n=10;
Archivo lista[10];

int main(){

DefArchivos();
comparatiempos();



return 0;
}



void DefArchivos(){


for (i=0;i<n;i++){
    printf("Ingrese el nombre del archivo %d: ",i+1);
    char *nombre = malloc(sizeof(char)*20);
    fgets(nombre,20,stdin);
    lista[i].nombre = nombre;
    }

for (i=0;i<n;i++){
    printf("%s",lista[i].nombre);
    }

for (i=0;i<n;i++){
    printf("Ingrese el año del archivo %d: ",i+1);
    scanf("%d",&lista[i].ultima_mod.anio);
    lista[i].ultima_mod.mes = 9;
    lista[i].ultima_mod.dia = 27;
    lista[i].ultima_mod.hora = 9;
    lista[i].ultima_mod.minuto = 44;
    lista[i].ultima_mod.segundo = 35;
}

//printf("\nPRIMER ARCHIVO:\n - Nombre: %s - Ultima Modificacion: %d / %d / %d    %d : %d : %d",lista[0].nombre,lista[0].ultima_mod.dia,lista[0].ultima_mod.mes,lista[0].ultima_mod.anio,lista[0].ultima_mod.hora,lista[0].ultima_mod.minuto,lista[0].ultima_mod.segundo);
//printf("\n\n\nSEGUNDO ARCHIVO:\n - Nombre: %s - Ultima Modificacion: %d / %d / %d    %d : %d : %d",lista[1].nombre,lista[1].ultima_mod.dia,lista[1].ultima_mod.mes,lista[1].ultima_mod.anio,lista[1].ultima_mod.hora,lista[1].ultima_mod.minuto,lista[1].ultima_mod.segundo);
}



void comparatiempos(){


printf("\nPRIMER ARCHIVO:\n - Nombre: %s - Ultima Modificacion: %d / %d / %d    %d : %d : %d",lista[0].nombre,lista[0].ultima_mod.dia,lista[0].ultima_mod.mes,lista[0].ultima_mod.anio,lista[0].ultima_mod.hora,lista[0].ultima_mod.minuto,lista[0].ultima_mod.segundo);
printf("\n\n\nSEGUNDO ARCHIVO:\n - Nombre: %s - Ultima Modificacion: %d / %d / %d    %d : %d : %d",lista[1].nombre,lista[1].ultima_mod.dia,lista[1].ultima_mod.mes,lista[1].ultima_mod.anio,lista[1].ultima_mod.hora,lista[1].ultima_mod.minuto,lista[1].ultima_mod.segundo);



if (lista[0].ultima_mod.anio<lista[1].ultima_mod.anio) {res=1;}
if (lista[0].ultima_mod.anio>lista[1].ultima_mod.anio) {res=-1;}

if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && lista[0].ultima_mod.mes<lista[1].ultima_mod.mes) {res=1;}
if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && lista[0].ultima_mod.mes>t2.mes) {res=-1;}

if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && lista[0].ultima_mod.dia<lista[1].ultima_mod.dia)) {res=1;}
if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && lista[0].ultima_mod.dia>lista[1].ultima_mod.dia)) {res=-1;}

if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && (lista[0].ultima_mod.dia==lista[1].ultima_mod.dia && lista[0].ultima_mod.hora<lista[1].ultima_mod.hora))) {res=1;}
if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && (lista[0].ultima_mod.dia==lista[1].ultima_mod.dia && lista[0].ultima_mod.hora>lista[1].ultima_mod.hora))) {res=-1;}

if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && (lista[0].ultima_mod.dia==lista[1].ultima_mod.dia && (lista[0].ultima_mod.hora==lista[1].ultima_mod.hora && lista[0].ultima_mod.minuto<lista[1].ultima_mod.minuto)))) {res=1;}
if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && (lista[0].ultima_mod.dia==lista[1].ultima_mod.dia && (lista[0].ultima_mod.hora==lista[1].ultima_mod.hora && lista[0].ultima_mod.minuto>lista[1].ultima_mod.minuto)))) {res=-1;}

if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && (lista[0].ultima_mod.dia==lista[1].ultima_mod.dia && (lista[0].ultima_mod.hora==lista[1].ultima_mod.hora && (lista[0].ultima_mod.minuto==lista[1].ultima_mod.minuto && lista[0].ultima_mod.segundo<lista[1].ultima_mod.segundo))))) {res=1;}
if (lista[0].ultima_mod.anio==lista[1].ultima_mod.anio && (lista[0].ultima_mod.mes==lista[1].ultima_mod.mes && (lista[0].ultima_mod.dia==lista[1].ultima_mod.dia && (lista[0].ultima_mod.hora==lista[1].ultima_mod.hora && (lista[0].ultima_mod.minuto==lista[1].ultima_mod.minuto && lista[0].ultima_mod.segundo>lista[1].ultima_mod.segundo))))) {res=-1;}

printf("\n\n%d\n\n",res);
}
