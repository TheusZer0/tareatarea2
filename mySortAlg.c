//
// Created by theuszero on 18-07-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"

Nodo * sortedInsert(Nodo* head_ref, Nodo* newNode){
    //recibe como parametro el nodo head_ref que es el head de la lista y el newNode para el insertSort
    Nodo* current; //se crea un nodo current
    if (head_ref==NULL){
        head_ref=newNode;
    } else if (head_ref->number >= newNode->number){
        newNode->next=head_ref;
        (newNode->next)->previous=newNode;
        head_ref=newNode;
    } else {
        current = head_ref;
        while ((current->next != NULL) && (((current->next)->number) < newNode->number)){
            current= current->next;
        }
        (newNode->next)=(current->next);
        if (current->next != NULL){
            (newNode->next)->previous=newNode;
        }
        current->next= newNode;
        newNode->previous= current;
    }
    return head_ref;
}
Nodo* insertionSort(Nodo* head_ref){
    Nodo* sorted = NULL;
    Nodo* current = head_ref;
    /*Nodo* sorted= NULL
    Nodo* current = head_ref;*/
    while (current!=NULL){
        Nodo* next = current->next;
        current->previous = current->next=NULL;
        sorted = sortedInsert(sorted,current);
        current=next;
    }
    head_ref = sorted;
    return head_ref;
}

//heapsort

int countNodos(Nodo* head){
    int numNodos = 0;
    while (head !=NULL){
        numNodos++;
        head = head->next;
    }
    return numNodos;
} // cuenta la cantidad de nodos del sistema
int posicionNodo(Nodo* Lista, Nodo* pNodo){
    //Lista = primer nodo de la lista y pNodo = nodo elejido
    Nodo* indice = NULL;
    //cuenta la cantidad de nodos
    int posicion=0;
    indice=Lista;
    while (indice !=NULL){
        indice=indice->next;
        if(indice->number == pNodo->number){
            return posicion;
        } else{
            posicion++;
        }
    }
}
int leftChild(int pNodo){
    int tmp = 2*pNodo;
    return tmp;
}
int rightChild(int pNodo){
    int tmp = ((2*pNodo)+1);
    return tmp;
}
int parent(int pNodo){
    int nodoPadre=0;
    nodoPadre=(pNodo/2);
    return nodoPadre;
}

