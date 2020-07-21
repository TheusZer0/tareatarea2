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

Nodo* sortedInsert(Nodo* head_ref, Nodo* newNode);
Nodo* insertionSort(Nodo* head_ref);

int posicionNodo(Nodo* head_ref, Nodo* elect);
int countNodos(Nodo* head);
int leftChild(int pNodo);
int rightChild(int pNodo);
int parent(int pNodo);
#endif //TAREATAREA2_MYSORTALG_H
