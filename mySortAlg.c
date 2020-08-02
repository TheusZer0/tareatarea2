/*
 * @file    : mySortAlg.c
 * @author	: Robert Parra
 * @date	: 01/08/2020
 * @brief   : Tarea N2 Estructura de datos y algoritmos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"

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
        //localiza el nodo
        while ((current->next != NULL) && (((current->next)->number) < newNode->number)){
            current= current->next; //avanza al next
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
        if(indice->number == pNodo->number){ //si el numero es igual al numero que estamos buscando (encontramos el numero)
            return posicion; //se retorna la posicion
        } else{
            posicion++; //si no, se suma 1 en la posicion
            indice=indice->next; //se avanza en la lista doblemente enlazada
        }
    }
}

int leftChild(int pNodo){
    int tmp = 2*pNodo; //sacado de las ppt de clases
    return tmp;
}

int rightChild(int pNodo){
    int tmp = ((2*pNodo)+1); //sacado de las ppt de clases
    return tmp;
}

int parent(int pNodo){
    int nodoPadre=0;
    nodoPadre=(pNodo/2); //sacado de las ppt de clases
    return nodoPadre;
}

void swap(Nodo** headRef,Nodo* numNode_One, Nodo* numNode_Two) {
    /*
     * en el codigo original cuando intercambias head con b, b se conviertia en una nueva head.  por lo que ocurria ese error y fue arreglado
     * otro error era que cuando intercambias a con ultimo nodo, a se convierte en un nuevo ultimo nodo, tambien fue arreglado
     */
    if(numNode_One!=*headRef && numNode_Two != *headRef){
        if (numNode_One == numNode_Two)
            return;

        if (numNode_One->next == numNode_Two) { // right next to each other
            numNode_One->next = numNode_Two->next;
            numNode_Two->previous = numNode_One->previous;

            if (numNode_One->next != NULL)
                numNode_One->next->previous = numNode_One;

            if (numNode_Two->previous != NULL)
                numNode_Two->previous->next = numNode_Two;


            numNode_Two->next = numNode_One;
            numNode_One->previous = numNode_Two;
        } else {
            Nodo* prev = numNode_Two->previous;
            Nodo* n = numNode_Two->next;

            numNode_Two->previous = numNode_One->previous;
            numNode_Two->next = numNode_One->next;

            numNode_One->previous = prev;
            numNode_One->next = n;

            if (numNode_Two->next != NULL)
                numNode_Two->next->previous = numNode_Two;
            if (numNode_Two->previous != NULL)
                numNode_Two->previous->next = numNode_Two;

            if (numNode_One->next != NULL)
                numNode_One->next->previous = numNode_One;
            if (numNode_One->previous != NULL)
                numNode_One->previous->next = numNode_One;
        }
    }
    else{
        if (numNode_One == numNode_Two)
            return;

        if (numNode_One->next == numNode_Two) { // right next to each other
            numNode_One->next = numNode_Two->next;
            numNode_Two->previous = numNode_One->previous;

            if (numNode_One->next != NULL)
                numNode_One->next->previous = numNode_One;

            if (numNode_Two->previous != NULL)
                numNode_Two->previous->next = numNode_Two;


            numNode_Two->next = numNode_One;
            numNode_One->previous = numNode_Two;
        } else {
            Nodo* prev = numNode_Two->previous;
            Nodo* n = numNode_Two->next;

            numNode_Two->previous = numNode_One->previous;
            numNode_Two->next = numNode_One->next;

            numNode_One->previous = prev;
            numNode_One->next = n;

            if (numNode_Two->next != NULL)
                numNode_Two->next->previous = numNode_Two;
            if (numNode_Two->previous != NULL)
                numNode_Two->previous->next = numNode_Two;

            if (numNode_One->next != NULL)
                numNode_One->next->previous = numNode_One;
            if (numNode_One->previous != NULL)
                numNode_One->previous->next = numNode_One;
        }
        if(numNode_One->previous == NULL){
            *headRef = numNode_One;
        }
        else{
            *headRef = numNode_Two;
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
        swap(head,returnNodo(*head, posicion), ((returnNodo(*head, largest))));
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
        swap(&tmp,returnNodo(tmp,1),returnNodo(tmp,i));
        heapzise--;
        maxHeapify(&tmp,1,heapzise);
    }
    return tmp;
}