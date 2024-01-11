#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct proceso{

int procesador;
int id_proceso;
int prioridad;
char estado[10];
int n;  // estado en numero: 0(Nuevo) ; 1(Listo) ; 2(Corriendo) ; 3(Terminado) ; 4(es usado para que la funcion mostrarScheduler no lo imprima).

} Proceso;


static int id = 0;
int i,j,k,r;


void asignaEstado();
void ingresaProceso();
void recorreCola();
void mostrarScheduler();
void terminaProceso();


Proceso *scheduling[10];


int main(){
    asignaestado();
    mostrarScheduler();
    ingresaProceso();

    for(k=0;k<11;k++){
        recorreCola();
        terminaProceso();
        mostrarScheduler();
    }

    terminaProceso();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void asignaestado(Proceso* l){                     //Asigna los estados a los procesos
    int orden = 0;
    for(i=0;i<10;i++){
    scheduling[i] = malloc(10*(sizeof(Proceso)));
    scheduling[i]->procesador = 0;
    do {scheduling[i]->id_proceso = 1 + rand() %90;} while (scheduling[i]->id_proceso<10);
    scheduling[i]->prioridad = orden + i + 1;
    strcpy (scheduling[i]->estado,"Nuevo");
    scheduling[i]->n = 0;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ingresaProceso(){                     //Ingresa el proceso en el primer espacio libre que encuentre
    int en_proceso = 0;
    for(i=0;i<10;i++){
        en_proceso = en_proceso + 1;
        j = j + 1;
        if(en_proceso<=2){
        scheduling[i]->procesador = 0 + j;
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void terminaProceso(){                     // Quita el proceso de la cola liberando espacio
    int en_proceso = 0;

    for(i=0;i<10;i++){
        en_proceso = en_proceso + 1;
        if(en_proceso<3){
            if(scheduling[i]->n==2 && k==1){
                strcpy (scheduling[i]->estado,"Terminado");
                scheduling[i]->n = 3;
            }
        }
    }

    en_proceso = 0;
    for(i=0;i<10;i++){
        if (en_proceso<3){
                if(scheduling[i]->n==2 && k==3){
                    strcpy (scheduling[i]->estado,"Terminado");
                    scheduling[i]->n = 3;
                }
                if(scheduling[i]->n==2 && k==5){
                    strcpy (scheduling[i]->estado,"Terminado");
                    scheduling[i]->n = 3;
                    }
            }
    }

    en_proceso = 0;
    for(i=0;i<10;i++){
        if(en_proceso<2){
            if(en_proceso<1){
                if(scheduling[i]->n==2 && k==7){
                    strcpy (scheduling[i]->estado,"Terminado");
                    scheduling[i]->n = 3;
                }

                if(scheduling[i]->n==2 && k==9){
                    strcpy (scheduling[i]->estado,"Terminado");
                    scheduling[i]->n = 3;
                }
            }
        }

        if(scheduling[i]->n==3 && k==2){
            scheduling[i]->n=4;
        }

        if(scheduling[i]->n==3 && k==4){
            scheduling[i]->n=4;
        }

        if(scheduling[i]->n==3 && k==6){
            scheduling[i]->n=4;
        }

        if(scheduling[i]->n==3 && k==8){
            scheduling[i]->n=4;
        }

        if(scheduling[i]->n==3 && k==10){
            scheduling[i]->n=4;
        }
    }
}


// -----------------------------------------------------------------------------------------  //


void recorreCola(){                     // Recorrera todos los procesos de la cola, haciendo el cambio del estado de los mismos
    int en_proceso = 0;
    printf("\n\nRecorriendo la cola...\n");

    for(i=0;i<10;i++){
        en_proceso = en_proceso + 1;
        if(en_proceso>2){
            if(scheduling[i]->n==0){
                strcpy(scheduling[i]->estado,"Listo");
                scheduling[i]->n = 1;
            }
        }

        if(en_proceso<3){
            if(scheduling[i]->n==0 && k==0){
                strcpy (scheduling[i]->estado,"Corriendo");
                scheduling[i]->n = 2;
            }
        }
        j=0;
    }

    en_proceso = 0;
    for(i=0;i<10;i++){
        if(en_proceso<2){
            if(scheduling[i]->n==1 && k==2){
                en_proceso = en_proceso + 1;
                strcpy(scheduling[i]->estado,"Corriendo");
                scheduling[i]->n = 2;
                scheduling[i]->procesador= i-1;
            }

            if(scheduling[i]->n==1 && k==4){
                en_proceso = en_proceso + 1;
                strcpy (scheduling[i]->estado,"Corriendo");
                scheduling[i]->n = 2;
                scheduling[i]->procesador= i-3;
            }
        }
    }

    en_proceso = 0;
    for(i=0;i<10;i++){
        if(en_proceso<2){
            if(scheduling[i]->n==1 && k==6){
                en_proceso = en_proceso + 1;
                strcpy (scheduling[i]->estado,"Corriendo");
                scheduling[i]->n = 2;
                scheduling[i]->procesador= i-5;
            }
            if(scheduling[i]->n==1 && k==8){
                en_proceso = en_proceso + 1;
                strcpy(scheduling[i]->estado,"Corriendo");
                scheduling[i]->n = 2;
                scheduling[i]->procesador= i-7;
            }
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mostrarScheduler(){                     // Lista los procesos de la cola
for(i=0;i<10;i++){
        printf("[%d]",i);
    if (scheduling[i]->n!=4){
        printf("-> { %d;%d;%d; '%s'}\n",scheduling[i]->procesador, scheduling[i]->id_proceso , scheduling[i]->prioridad,scheduling[i]->estado);
        }
    else printf("\n");
    }
}

