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

Nodo* getNode(int data);
void sortedInsert(Nodo* head_ref, Nodo* newNode);
void insertionSort(Nodo* head_ref);
void printList(Nodo* head);

#endif //TAREATAREA2_MYSORTALG_H
