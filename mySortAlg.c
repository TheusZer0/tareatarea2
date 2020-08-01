/*
 * @file    : mySortAlg.c
 * @author	: Robert Parra
 * @date	: 01/08/2020
 * @brief   : Tarea N2 estructura de datos y algoritmos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"

// insertionSort
Nodo * sortedInsert(Nodo* head_ref, Nodo* newNode){ //recibe como parametro el nodo head_ref que es el head de la lista y el newNode para el insertSort
    Nodo* current; //se crea un nodo current, correspondiente a un nodo tmp
    if (head_ref==NULL){ //si el head es null
        head_ref=newNode; //el head apunta al newNode
    } else if (head_ref->number >= newNode->number){
        //si el number en el nodo head es mayor o igual al number del newNodo entonces el nodo sera  al principio de la lista
        newNode->next=head_ref;
        (newNode->next)->previous=newNode;
        head_ref=newNode;
    } else {
        current = head_ref; //el nodo current apunta al head_ref
        //localiza el nodo despues de
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
    while (current!=NULL){
        Nodo* next = current->next;
        current->previous = current->next=NULL;
        sorted = sortedInsert(sorted,current);
        current=next;
    }
    head_ref = sorted;
    return head_ref;
}

//heapSort

int countNodos(Nodo* head){
    int numNodos = 0;
    while (head !=NULL){ //recorre la lista doblemente enlazada
        numNodos++; //suma 1 a numNodos
        head = head->next; //avanza al nodo siguiente
    }
    return numNodos; //retorna la cant de nodos como entero
}

int posicionNodo(Nodo* Lista, Nodo* pNodo){
    Nodo* indice = NULL;
    int posicion=1;
    indice=Lista;
    while (indice !=NULL){ //recorre la lista
        if(indice->number == pNodo->number){
            return posicion;
        } else{
            posicion++;
            indice=indice->next; //ind
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

void swamp(Nodo** headRef,Nodo* nodo1, Nodo* nodo2) {
    if(nodo1!=*headRef && nodo2!=*headRef){
        if (nodo1 == nodo2)
            return;

        if (nodo1->next == nodo2) { // right next to each other
            nodo1->next = nodo2->next;
            nodo2->previous = nodo1->previous;

            if (nodo1->next != NULL)
                nodo1->next->previous = nodo1;

            if (nodo2->previous != NULL)
                nodo2->previous->next = nodo2;


            nodo2->next = nodo1;
            nodo1->previous = nodo2;
        } else {
            Nodo* prev = nodo2->previous;
            Nodo* n = nodo2->next;

            nodo2->previous = nodo1->previous;
            nodo2->next = nodo1->next;

            nodo1->previous = prev;
            nodo1->next = n;

            if (nodo2->next != NULL)
                nodo2->next->previous = nodo2;
            if (nodo2->previous != NULL)
                nodo2->previous->next = nodo2;

            if (nodo1->next != NULL)
                nodo1->next->previous = nodo1;
            if (nodo1->previous != NULL)
                nodo1->previous->next = nodo1;
        }
    }
    else{
        if (nodo1 == nodo2)
            return;

        if (nodo1->next == nodo2) { // right next to each other
            nodo1->next = nodo2->next;
            nodo2->previous = nodo1->previous;

            if (nodo1->next != NULL)
                nodo1->next->previous = nodo1;

            if (nodo2->previous != NULL)
                nodo2->previous->next = nodo2;


            nodo2->next = nodo1;
            nodo1->previous = nodo2;
        } else {
            Nodo* prev = nodo2->previous;
            Nodo* n = nodo2->next;

            nodo2->previous = nodo1->previous;
            nodo2->next = nodo1->next;

            nodo1->previous = prev;
            nodo1->next = n;

            if (nodo2->next != NULL)
                nodo2->next->previous = nodo2;
            if (nodo2->previous != NULL)
                nodo2->previous->next = nodo2;

            if (nodo1->next != NULL)
                nodo1->next->previous = nodo1;
            if (nodo1->previous != NULL)
                nodo1->previous->next = nodo1;
        }
        if(nodo1->previous == NULL){
            *headRef = nodo1;
        }
        else{
            *headRef = nodo2;
        }
    }
}

Nodo* returnNodo(Nodo* head, int pNodo){
    int tmp=0;
    Nodo* indice=NULL;
    indice=head;
    int cantNodo=countNodos(head);
    if (pNodo>cantNodo){
        return head;
    }
    while (indice !=NULL){
        tmp++;
        if (tmp==pNodo){
            return indice;
        }
        indice= indice->next;
    }
}

void maxHeapify(Nodo** head, int posicion, int heapzise){
    int l = leftChild(posicion);
    int r = rightChild(posicion);
    int cantNodos=0;
    cantNodos=countNodos(*head);
    int largest;
    if ((l<=heapzise)&&((returnNodo(*head, l)->number) > (returnNodo(*head, posicion))->number)){
        largest = l;
    } else{
        largest=posicion;
    }
    if ((r<=heapzise) && (returnNodo(*head, r)->number > (returnNodo(*head, largest)->number))){
        largest=r;
    }
    if (largest!=posicion){
        swamp(head,returnNodo(*head, posicion), ((returnNodo(*head, largest))));
        maxHeapify(head, largest,heapzise);
    }
}

Nodo* buildMaxHeap(Nodo* headRef){
    int aLargo=countNodos(headRef);
    int i = (aLargo/2);
    for (int j = i; j > 0; --j) {
        maxHeapify(&headRef,j,aLargo);
    }
    return headRef;
}

Nodo* heapsort(Nodo* head_ref){
    Nodo* tmp = head_ref;
    tmp=buildMaxHeap(tmp);
    int heapzise = countNodos(tmp);
    for (int i = countNodos(tmp); i>=2 ; i--) {
        swamp(&tmp,returnNodo(tmp,1),returnNodo(tmp,i));
        heapzise--;
        maxHeapify(&tmp,1,heapzise);
    }
    return tmp;
}