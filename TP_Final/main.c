#include "kruskal.h"

rama* grafo = NULL;
rama** krusk = NULL;
conjunto_CE conj;
int costo_total = 0;

/* Funcion Kruskal
Llama a inicial para cargar el primer elemento.
Mientras la lista no sea anula con sacar_min libera el espacio de la rama.
Con encuetra devuelve el conjunto al que pertenence.
Si el origen y el destino son distintos, con combina, compara el peso de las aristas y se queda con la de menor costo.
Con inserta, reserva el espaacio para la arista y la pone en la lista
Suma el costo a costo_total para mostrarlo al final*/

void kruskal (rama* graf){
    int aux_origen;
    int aux_dest;
    for (int i=1; i<=VERTICES; i++){
        inicial (i, i, &conj);
    }
    printf("\n");
    while (graf != NULL){
        arista a = graf->a;
        sacar_min(&graf);
        aux_origen = a.u;
        aux_origen = encuentra(aux_origen, &conj);
        aux_dest = a.v;
        aux_dest = encuentra(aux_dest, &conj);
        if (aux_origen != aux_dest){
    	    combina(aux_origen, aux_dest, &conj);
            inserta(a.u, a.v, a.costo, &krusk);
            costo_total = costo_total + a.costo;
        }
    }
}



void inicial (tipo_nombre a, tipo_elemento x, conjunto_CE* conj){
	conj->nombres[x].nombre_conjunto = a;
	conj->nombres[x].siguiente_elemento = 0;
	conj->encabezamientos_conjunto[a].cuenta = 1;
	conj->encabezamientos_conjunto[a].primer_elemento = x;
}



void sacar_min (rama** graf){
    rama* prama = *graf;
    *graf = (*graf)->sig;
    free(prama);
}



tipo_nombre encuentra (int x, conjunto_CE* conj){
	return (*conj).nombres[x].nombre_conjunto;
}


/*
La funcion combina toma los pesos de los caminos y se queda con el de menor costo
*/

void combina (tipo_nombre o, tipo_nombre d, conjunto_CE* conj){
	int i;
	if ( conj->encabezamientos_conjunto[o].cuenta < conj->encabezamientos_conjunto[d].cuenta ){
		i = conj->encabezamientos_conjunto[o].primer_elemento;
        	while ( conj->nombres[i].siguiente_elemento != 0 ) {
        	    conj->nombres[i].nombre_conjunto = d;
        	    i = conj->nombres[i].siguiente_elemento;
       	 }
        conj->nombres[i].nombre_conjunto = d;
		conj->nombres[i].siguiente_elemento = conj->encabezamientos_conjunto[d].primer_elemento;
        conj->encabezamientos_conjunto[d].primer_elemento = conj->encabezamientos_conjunto[o].primer_elemento;
        conj->encabezamientos_conjunto[d].cuenta = conj->encabezamientos_conjunto[d].cuenta + conj->encabezamientos_conjunto[o].cuenta;
		conj->encabezamientos_conjunto[o].primer_elemento = 0;
		conj->encabezamientos_conjunto[o].cuenta = 0;
	}
	else{
		i = conj->encabezamientos_conjunto[d].primer_elemento;
		while ( conj->nombres[i].siguiente_elemento != 0 ){
			conj->nombres[i].nombre_conjunto = o;
			i = conj->nombres[i].siguiente_elemento;
		}
		conj->nombres[i].nombre_conjunto = o;
		conj->nombres[i].siguiente_elemento = conj->encabezamientos_conjunto[o].primer_elemento;
		conj->encabezamientos_conjunto[o].primer_elemento = conj->encabezamientos_conjunto[d].primer_elemento;
		conj->encabezamientos_conjunto[o].cuenta = conj->encabezamientos_conjunto[o].cuenta + conj->encabezamientos_conjunto[d].cuenta;
		conj->encabezamientos_conjunto[d].primer_elemento = 0;
		conj->encabezamientos_conjunto[d].cuenta = 0;
	}
}



void inserta(int i, int j, int peso, rama** graf){
    rama* nuevo = malloc(sizeof(rama));
    nuevo->a.u = i;
    nuevo->a.v = j;
    nuevo->a.costo = peso;
    if (*graf==NULL){
        nuevo->sig = NULL;
        *graf = nuevo;
    }
    else if (*graf!=NULL){
        rama* aux = *graf;
        rama* ant;
        if (peso<=(*graf)->a.costo){
            nuevo->sig = aux;
            *graf = nuevo;
        }
        else{
            while (aux!=NULL && peso>aux->a.costo){
                ant = aux;
                aux = aux->sig;
            }
            nuevo->sig = aux;
            ant->sig = nuevo;
        }
    }
}


//muestra la lista final

void lista (rama* graf){
    if (graf!=NULL){
        rama* prama = graf;
        while (prama != NULL){
            printf ("Arista (%d; %d) con costo %d\n", prama->a.u, prama->a.v, prama->a.costo);
            prama = prama->sig;
        }
    }
    else{
        printf("El grafo está vacio.\n");
    }
}


/*En el main:
-Pido el costo entre las distintas aristas.
-LLamo a kruskal para q haga todas las comparaciones
-Muestro el arbol de costo minimo y el costo total minimo
*/
int main(){
    int M_Costos [VERTICES][VERTICES];
    printf("Ingrese el costo de las aristas, entre los vertices:\n");
    for (int i=1; i<=VERTICES; i++){
        for (int j= i+1; j<=VERTICES; j++){
            printf ("Arista (%d; %d): \n>", i, j);
            scanf ("%d", &M_Costos[i][j]);
            if (M_Costos [i][j] !=0){
                inserta (i, j, M_Costos [i][j], &grafo);
            }
        }
    }
    printf("\n\n");

    kruskal(grafo);

    printf ("El arbol abarcador de costo minimo está formado por las siguientes aristas:\n");
    lista(krusk);
    printf("\nEl costo del arbol abarcador de costo minimo es: %d\n",costo_total);

return 0;
}
