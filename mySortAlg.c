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
        if (current->next != NULL){  //si el next es distinto de null,  es decir, se encuentra dentro de la lista enlazada
            (newNode->next)->previous=newNode; //se cambia el previus del newNode
        }
        current->next= newNode; //el next de current es newNode
        newNode->previous= current;
    }
    return head_ref;//retorna el sorted
}

Nodo* insertionSort(Nodo* head_ref){
    Nodo* sorted = NULL; //Nodo nulo
    Nodo* current = head_ref; //nodo current apunta al nodo head de la lista
    while (current!=NULL){ //mientras current no sea null, es decir, recorre el current
        Nodo* next = current->next;//avanza e iguala a un nodo next (nodo next = al nodo siguiente)
        current->previous = current->next=NULL;
        sorted = sortedInsert(sorted,current);  // se realiza el sorted
        current=next;
    }
    head_ref = sorted;
    return head_ref; //se retorna la lista enlazada ordenada
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
    //mientras el nodo uno sea diferente del puntero al nodo head y el nodo dos cumpla con lo mismo se ejecuta el swap
    if(numNode_One!=*headRef && numNode_Two != *headRef){
        if (numNode_One == numNode_Two) //si el nodo uno y dos son iguales se retorna 0,ya que cambiarlos seria lo mismo que no cambiarlos
            return;

        if (numNode_One->next == numNode_Two) {
            /*si el next del nodo uno es igual al nodo dos entonces el next de nodo uno sera igual al next del nodo dos
             *de esta forma, el nodo anterior a dos sera igual al nodo anterior de nodo uno
             * */
            numNode_One->next = numNode_Two->next;
            numNode_Two->previous = numNode_One->previous;

            if (numNode_One->next != NULL) // el next del nodo uno es diferente de null (el nodo uno no es el ultimo nodo)
                numNode_One->next->previous = numNode_One;

            if (numNode_Two->previous != NULL) // el next del nodo dos es diferente de null (el nodo uno no es el ultimo nodo)
                numNode_Two->previous->next = numNode_Two; //el puntero next del nodo anterior sera igual el nodo 2

            numNode_Two->next = numNode_One; //el nodo siquiente al nodo 2 sera igual nodo 1
            numNode_One->previous = numNode_Two; //el puntero previus del nodo uno sera igual al nodo 2
        } else {
            Nodo* prev = numNode_Two->previous; //creacion de un nodo prev que gaurdara el nodo previous del nodo 2
            Nodo* n = numNode_Two->next; //creacion de un nodo n que sera el nodo siguiente al nodo 2

            numNode_Two->previous = numNode_One->previous;//el puntero anterior del nodo 2 sera igual al puntero anterior del nodo uno
            numNode_Two->next = numNode_One->next; //el puntero siguiente del nodo 2 sera igual al puntero siguiente del nodo 1

            numNode_One->previous = prev; //el pnodo anterior al nodo uno actual sera igual a prev
            numNode_One->next = n;//el nodo siguiente al nodo uno actual sera igual a n

            if (numNode_Two->next != NULL)//si el siguiente nodo del nodo 2 es diferente de null (si el nodo 2 no es el ultimo)
                numNode_Two->next->previous = numNode_Two; //el puntero previous del nodo anterior sera igual el nodo 2
            if (numNode_Two->previous != NULL)//si el anterior nodo del nodo 2 es diferente de null (si el nodo 2 no es el ultimo)
                numNode_Two->previous->next = numNode_Two;//el puntero next del nodo anterior sera igual el nodo 2
            if (numNode_One->next != NULL)//si el siguiente nodo del nodo 1 es diferente de null (si el nodo 1 no es el ultimo)
                numNode_One->next->previous = numNode_One;//el puntero previous del nodo anterior sera igual el nodo 1
            if (numNode_One->previous != NULL)//si el anterior nodo del nodo 1 es diferente de null (si el nodo 1 no es el ultimo)
                numNode_One->previous->next = numNode_One;//el puntero next del nodo anterior sera igual el nodo 1
        }
    }
    else{
        if (numNode_One == numNode_Two) //si el nodo uno y dos son iguales se retorna 0,ya que cambiarlos seria lo mismo que no cambiarlos
            return;

        if (numNode_One->next == numNode_Two) {
            /*si el next del nodo uno es igual al nodo dos entonces el next de nodo uno sera igual al next del nodo dos
            *de esta forma, el nodo anterior a dos sera igual al nodo anterior de nodo uno
            */
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

Nodo* rNodo(Nodo* head, int pNodo){
    int tmp=0;
    Nodo* indice=NULL;
    indice=head;
    int cantNodo=countNodos(head); //cuenta la cantidadde nodos de la lista enlazada
    if (pNodo>cantNodo){
        return head; //retorna el head
    }
    while (indice !=NULL){
        tmp++;
        if (tmp==pNodo){
            return indice;//retorna el indice(nodo)
        }
        indice= indice->next;//avanza
    }
}

void maxHeapify(Nodo** head, int posicion, int heapzise){
    int l = leftChild(posicion);//nodo izquierdo
    int r = rightChild(posicion);//nodo derecho
    int cantNodos=0;
    cantNodos=countNodos(*head); //cantidad de nodos
    int largest;
    if ((l<=heapzise)&&((rNodo(*head, l)->number) > (rNodo(*head, posicion))->number)){
        largest = l;
    } else{
        largest=posicion;
    }
    if ((r<=heapzise) && (rNodo(*head, r)->number > (rNodo(*head, largest)->number))){
        largest=r;
    }
    if (largest!=posicion){
        swap(head, rNodo(*head, posicion), ((rNodo(*head, largest))));
        maxHeapify(head, largest,heapzise);
    }
}

Nodo* buildMaxHeap(Nodo* headRef){
    int aLargo=countNodos(headRef);
    int i = (aLargo/2);
    for (int j = i; j > 0; --j) {
        maxHeapify(&headRef,j,aLargo);//realiza el max heapify
    }
    return headRef;
}

Nodo* heapsort(Nodo* head_ref){
    Nodo* tmp = head_ref;
    tmp=buildMaxHeap(tmp);
    int heapzise = countNodos(tmp);
    for (int i = countNodos(tmp); i>=2 ; i--) {
        swap(&tmp, rNodo(tmp, 1), rNodo(tmp, i)); //realiza el swap del primer nodo con el ultimo
        heapzise--;
        maxHeapify(&tmp,1,heapzise); //realiza el maxHeapify con nodo tmp y la posicion 1, siendo el heap el que cambia o disminuye (se saca)
    }
    return tmp;
}