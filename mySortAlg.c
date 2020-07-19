//
// Created by theuszero on 18-07-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"

Nodo* getNode(int data){
    Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
    newNode->number=data;
    newNode->previous = newNode->next=NULL;
    return newNode;
}

void sortedInsert(Nodo* head_ref, Nodo* newNode){
    Nodo* current;
    if (head_ref==NULL){
        head_ref= newNode;
    } else if (head_ref->number >= newNode->number){
        newNode->next=head_ref;
        newNode->next->previous=newNode;
        head_ref=newNode;
    } else {
        current = head_ref;
        while ((current->next != NULL) && ((current->next->number) < newNode->number)){
            current= current->next;
        }
        newNode->next=current->next;
        if (current->next != NULL){
            newNode->next->previous=newNode;
        }
        current->next= newNode;
        newNode->previous= current;
    }
}

void insertionSort(Nodo* head_ref){
    Nodo* sorted = (Nodo*)malloc(sizeof(Nodo));
    sorted=NULL;
    Nodo* current = (Nodo*)malloc(sizeof(Nodo));
    current = head_ref;
    /*Nodo* sorted= NULL
    Nodo* current = head_ref;*/
    while (current!=NULL){
        Nodo* next = current->next;
        current->previous = current->next=NULL;
        sortedInsert(sorted,current);
        current=next;
    }
    head_ref = sorted;
}

void printList(Nodo* head){
    while (head !=NULL){
        printf("%d\n",head->number);
        head = head->next;
    }
}

