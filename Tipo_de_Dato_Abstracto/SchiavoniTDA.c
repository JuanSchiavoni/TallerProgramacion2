#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct legislador{
    char nombre[10];
    struct legislador *sig;
}nodo;

//Prototipado
int esMiembro();
void inserta(char nombres[10],nodo** lista);
int esMiembro(char nombre[10], nodo* lista);
void mostrar(nodo* lista);
void suprime(char nombre[10], nodo** lista);


int main() {

    nodo *chicos_buenos;
    nodo *chicos_malos;
    char c, nombre[10];

   do{
        printf("Ingrese un comando\n 'F': Voto favorable\n 'D': Voto desfavorable\n 'E': Salir\n\n 'L': Listar votos\n\n->");
        scanf("%c", &c);
        getchar();
        switch(c){
            case 'D':   printf("Ingrese el nombre del votante\n->");
                        scanf("%s", &nombre);
                        getchar();
                        inserta(nombre, &chicos_malos);
                        suprime(nombre, &chicos_buenos);
                        system("clear");
                        printf("Voto registrado\n");
                        break;
            case 'F':   printf("Ingrese el nombre del votante\n->");
                        scanf("%s", &nombre);
                        getchar();
                        inserta(nombre, &chicos_buenos);
                        suprime(nombre, &chicos_malos);
                        system("clear");
                        printf("Voto registrado\n");
                        break;
            case 'E':   break;
            case 'L':   printf("Chicos buenos:\n");
                        mostrar(chicos_buenos);
                        printf("\nChicos malos:\n");
                        mostrar(chicos_malos);
                        printf("\nPresione ENTER para continuar\n");
                        getchar();
                        system("clear");
                        break;
            default:    system("clear");
                        printf("Ingrese un comando valido\n");
                        break;

        }
    }   while(c!='E');
    return 0;
}

//Recibe nombre y agraga a la lista correspondiente
void inserta(char nombres[10],nodo** lista){
    int n;

    if(*lista==NULL){
        //el primero
        printf("Inserto a %s en la lista \n\n", nombres);
        *lista=(nodo*)malloc(sizeof(nodo));
        strcpy((*lista)->nombre, nombres);
    }else {
        n=esMiembro(nombres, *lista);
        if(n==1){
            //los siguientes
            printf("Inserto a %s en la lista\n\n", nombres);
            nodo* nuevo=(nodo*)malloc(sizeof(nodo));
            strcpy(nuevo->nombre, nombres);
            nuevo->sig= *lista;
            *lista = nuevo;
        }else if(n==0){
            printf("%s ya esta en la lista\n\n", nombres);
        }else {
            inserta(nombres, &(*lista)->sig);
        }
    }
}

//Corrobora que el nombre este en la lista
int esMiembro(char nombre[10], nodo* lista){
    nodo *aux = lista;
    while(aux!=NULL){
        if(strcmp((aux)->nombre, nombre)==0) {
            return 0;
        }else {
            aux = aux->sig;
        }
    }
    return 1;
}

//Muestra las listas
void mostrar(nodo* lista){

    if(lista != NULL){
        printf("Legislador: %s\n", lista->nombre);
        mostrar(lista->sig);
    }
}

//Elimina de la lista
void suprime(char nombre[10], nodo** lista){

    if(*lista==NULL){
        //printf("No existe el nombre a eliminar en la lista");
    }else {
        if(strcmp(nombre, (*lista)->nombre)==0){ //elimina el primero
            printf("Elimina a %s\n", nombre);
            nodo* aux= (*lista);
            (*lista) = (*lista)->sig;
            free(aux);
        }else if((*lista)->sig !=NULL && strcmp(nombre, (*lista)->nombre)==0){ //elimina el siguiente
            printf("Elimina a %s\n", nombre);
            nodo* aux= (*lista)->sig;
            (*lista)->sig = (*lista)->sig->sig;
            free(aux);
        }else {
            suprime(nombre, &(*lista)->sig);
        }
    }
}
