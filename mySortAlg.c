//
// Created by theuszero on 18-07-20.
//

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
//heapSort
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
void swap(Nodo* a, Nodo* b) {
    if (a == b)
        return;

    if (a->next == b) { // right next to each other
        a->next = b->next;
        b->previous = a->previous;

        if (a->next != NULL)
            a->next->previous = a;

        if (b->previous != NULL)
            b->previous->next = b;


        b->next = a;
        a->previous = b;
    } else {
        Nodo* p = b->previous;
        Nodo* n = b->next;

        b->previous = a->previous;
        b->next = a->next;

        a->previous = p;
        a->next = n;

        if (b->next != NULL)
            b->next->previous = b;
        if (b->previous != NULL)
            b->previous->next = b;

        if (a->next != NULL)
            a->next->previous = a;
        if (a->previous != NULL)
            a->previous->next = a;
    }
}
Nodo* returnNodo(Nodo* head, int pNodo){
    int tmp=0;
    Nodo* indice=NULL;
    indice=head;
    int cantNodo=countNodos(head);
    if (pNodo>cantNodo){
        return head;
    };
    while (indice !=NULL){
        tmp++;
        if (tmp==pNodo){
            return indice;
        }
        indice= indice->next;
    }
}
void maxHeapify(Nodo* head, int posicion){
    int l = leftChild(posicion);
    int r = rightChild(posicion);
    int cantNodos=0;
    cantNodos=countNodos(head);
    int largest;
    if ((l<=cantNodos)&&((returnNodo(head, l)->number) > (returnNodo(head, posicion))->number)){
        largest = l;
    } else{
        largest=posicion;
    }
    if ((r<=(countNodos(head))) && ((returnNodo(head, r)->number) > (returnNodo(head, largest)->number))){
        largest=r;
    }
    if (largest!=posicion){
        swap((returnNodo(head, posicion)),(returnNodo(head, largest)));
        maxHeapify(head, largest);
    }
}