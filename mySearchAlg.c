//
// Created by TheusZero on 7/27/2020.
//
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"

float numbTotal[100];

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

float timeBinarySearch(Nodo* head_ref){
    struct timeval start , end ;
    Nodo* tmp =head_ref;
    int cantNodos=countNodos(head_ref);
    int num = 0;
    float pNodo = 0;
    for (int i = 1; i <= 100 ; ++i) {
        num= rand() % cantNodos+1;
        gettimeofday(&start, NULL);
        binarySearch(head_ref,returnNodo(head_ref,num)->number,1,cantNodos);
        gettimeofday(&end, NULL);
        float tiempo;
        tiempo = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000.0;
        numbTotal[i-1]=tiempo;
//        pNodo=binarySearch(head_ref,returnNodo(head_ref,num)->number,1,cantNodos);
//        printf("la posicion del nodo en el la lista ordenada es: %d y el nodo contiene la data: %d \n",pNodo,returnNodo(head_ref,pNodo)->number);
    }
    for (int j = 0; j < 100 ; ++j) {
        pNodo = pNodo+numbTotal[j];
    }
    pNodo=pNodo/100;
    return pNodo;
}
