//
// Created by TheusZero on 7/27/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"

int binarySearch(Nodo* head_ref,int numero,int pInicio, int pFinal){
    Nodo* tmp=head_ref;
    Nodo* nMedio = NULL;
    int pMedio = 0;
    if (pInicio==pFinal){
        return pInicio;
    } else{
        pMedio= (pInicio+pFinal)/2;
        nMedio = returnNodo(head_ref,pMedio);
        if (numero <= nMedio->number){
            binarySearch(tmp,numero,pInicio,pMedio);
        } else {
            binarySearch(tmp,numero,pMedio+1,pFinal);
        }
    }
}

void recuperarNumAleatorio(Nodo* head_ref){
    Nodo* tmp =head_ref;
    int cantNodos=countNodos(head_ref);
    int num = 0;
    int pNodo =0;
    for (int i = 1; i <= 100 ; ++i) {
        num= rand() % cantNodos+1;
        pNodo=binarySearch(head_ref,returnNodo(head_ref,num)->number,1,cantNodos);
        printf("la posicion del nodo en el la lista ordenada es: %d y el nodo contiene la data: %d \n",pNodo,returnNodo(head_ref,pNodo)->number);
    }
}
