//
// Created by theuszero on 18-07-20.
//

#ifndef TAREATAREA2_MYSORTALG_H
#define TAREATAREA2_MYSORTALG_H

typedef struct nd {
    int number;
    struct nd *previous;
    struct nd *next;
}Nodo;

/**
 * @brief        :
 * @param head_ref: recibe el nodo head_ref, que correspondera al primer nodo de las listas enlazadas.
 * @param newNode: newNode corresponde a un nodo nuevo, que puede apuntar a un nodo vacio o a uno especifico de la lista enlazada.
 * @return       : retorna un Nodo.
 */
Nodo* sortedInsert(Nodo* head_ref, Nodo* newNode);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
Nodo* insertionSort(Nodo* head_ref);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
int posicionNodo(Nodo* head_ref, Nodo* elect);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
int countNodos(Nodo* head);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
int leftChild(int pNodo);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
int rightChild(int pNodo);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
int parent(int pNodo);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
void maxHeapify(Nodo* head, int posicion);

/**
 * @brief        : funcion que retorna un nodo en base a su posicion
 * @param head: recibe el primer nodo, de esta forma, dentro de la funcion puede recorrer la lista
 * @param pNodo: recibe un entero que corresponde a la posicion del nodo que se quiere retornar
 * @return       : retorna el nodo que se esta buscando, en base a su posicion dentro de la lista
 */
Nodo* returnNodo(Nodo* head, int pNodo);

void swap(Nodo** one, Nodo** two);

void buildMaxHeap(Nodo* head);

#endif //TAREATAREA2_MYSORTALG_H
