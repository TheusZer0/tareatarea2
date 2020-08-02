/*
 * @file    : mySortAlg.h
 * @author	: Robert Parra
 * @date	: 01/08/2020
 * @brief   : Tarea N2 estructura de datos y algoritmos
 */

#ifndef TAREATAREA2_MYSORTALG_H
#define TAREATAREA2_MYSORTALG_H

// estructura de los nodos de la listas
typedef struct nd {
    int number;
    struct nd *previous;
    struct nd *next;
}Nodo;

/**
 * Links usados:
 * https://www.geeksforgeeks.org/create-doubly-linked-list-using-double-pointer-inserting-nodes-list-remains-ascending-order/ //InsertionSort
 * https://www.geeksforgeeks.org/insertion-sort-doubly-linked-list/ //InsertionSort
 * https://gist.github.com/badboy/2630183 //swap de nodos
 */

/**
 * @brief        : realiza un sorted y un swap simple
 * @param head_ref: recibe el nodo head_ref, que correspondera al primer nodo de las listas enlazadas.
 * @param newNode: newNode corresponde a un nodo que puede apuntar a un nodo vacio o a uno especifico de la lista enlazada.
 * @return       : retorna un Nodo.
 */
Nodo* sortedInsert(Nodo* head_ref, Nodo* newNode);

/**
 * @brief        : ejecuta el algoritmo de ordenamiento de tipo insertSort sobre la lista
 * @param head_ref: corresponde a la lista doblemente enlazada sobre la que se hara el ordenamiento
 * @return       : retorna la lista enlazada ordenada
 */
Nodo* insertionSort(Nodo* head_ref);

/**
 * @brief        : entrega un entero que corresponde a la posicion del nodo dentro de la lista
 * @param head_ref: parametro que corresponde al nodo head de la lista (usado para recorrerla dentro de la misma funcion)
 * @param elect: el nodo que sera buscado dentro de la lista doblemente enlazada
 * @return       : retorna un entero que corresponde a la posicion del nodo 'elect' dentro de la lista doblemente enlazada
 */
int posicionNodo(Nodo* head_ref, Nodo* elect);

/**
 * @brief        : funcion que cuenta la cantidad total de nodos de la lista doblemente enlazada
 * @param head: recibe un head (primer nodo) para recorrerlo y asi sacar el total de la lista
 * @return       : retorna un entero que sera la cantida total de nodos
 */
int countNodos(Nodo* head);

/**
 * @brief        : entrega el nodo hijo izquierdo de un nodo padre
 * @param pNodo: la posicion del nodo dentro de la lista
 * @return       : retorna un entero que corresponde al indice de la posicion del nodo izquiero (posicion entera del nodo)
 */
int leftChild(int pNodo);

/**
 * @brief        : entrega la posicion entera del nodo derecho del nodo padre
 * @param pNodo: la posicion del nodo dentro de la lista
 * @return       : retorna un entero que corresponde al indice de la posicion del nodo derecho (posicion entera del nodo)
 */
int rightChild(int pNodo);

/**
 * @brief      : retorna índice (o puntero) del nodo padre
 * @param pNodo: corresponde al indice del nodo
 * @return     : retorna un entero que corresponde al indice del nodo padre
 */
int parent(int pNodo);

/**
 * @brief        : mantiene la propiedad base de un max-heap
 * @param head   : recibe el nodo head de la lista, es decir, el primer nodo
 * @param posicion: recibe un entero que corresponde a la posicion del indice del nodo dentro de la lista enlazada, sera en este donde se haran los swap para mantener la propiedad base de un max-heap
 * @param heapzise: el largo del heap, cant de datos o nodos (que luego se van restando o sacando)
 * @return       : no retorna nada
 */
void maxHeapify(Nodo** head, int posicion, int heapzise);

/**
 * @brief        : funcion que retorna un nodo en base a su posicion
 * @param head: recibe el primer nodo, de esta forma, dentro de la funcion puede recorrer la lista
 * @param pNodo: recibe un entero que corresponde a la posicion del nodo que se quiere retornar
 * @return       : retorna el nodo que se esta buscando, en base a su posicion dentro de la lista
 */
Nodo* returnNodo(Nodo* head, int pNodo);

/**
 * @brief        : realiza un swap entre nodos, es decir, cambia la posicion de 2 nodos.
 * @param one: Nodo a que sera intercambiado con un nodo b, es decir, seran intercambiados de posicion en la lista enlazada
 * @param two: Nodo b que sera intercambiado con un nodo a, es decir, seran intercambiados de posicion en la lista enlazada
 * @return       : no retorna ningun nodo
 */
void swap(Nodo** headRef,Nodo* nodo1, Nodo* nodo2);

/**
 * @brief      : funcion que realiza un max_heap, es decir, convierte la lista en un max-heap
 * @param head : recibe el nodo head de la lista doblemente enlazada
 * @return     : no retorna nada
 */
Nodo* buildMaxHeap(Nodo* head);

/**
 * @brief      : ejecuta el algortimo de ordenamiento heapSort sobre la lista doblemente enlazada
 * @param head_ref : recibe el nodo head de la lista doblemente enlazada
 * @return     : retorna el nodo ordenado por el metodo heapSort
 */
Nodo* heapsort(Nodo* head_ref);

#endif //TAREATAREA2_MYSORTALG_H
