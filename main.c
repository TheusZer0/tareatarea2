#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"
#define MAXCHAR 1000

Nodo *primero=NULL; //se define un nodo global que representara el primer nodo de la lista
Nodo *ultimo=NULL; //se define un nodo global que representara el ultimo nodo de la lista
static int cantidadNodos=0; //variable global estatica que contarta

void generarArchivo(); //genera el archivo data.txt con numeros
void operacionesArchivo(FILE* fp); //recibe el archivo data.txt y opera sobre el
Nodo * insertarNodo(int A);
Nodo* sortedInsert(Nodo* head_ref, Nodo* newNode);
void printList(Nodo* head);

int main(/*int argc, char *argv[]*/) {
    generarArchivo();
    /*if (argc!=2){
        fprintf(stderr,"ejecutar: %s data.txt", argv[0]);
        exit(EXIT_FAILURE);
    }*/
    FILE* fileList=fopen("data.txt"/*argc[1]*/,"r");
    operacionesArchivo(fileList);
//    insertionSort(primero);
    maxHeapify(primero,2);
    printList(primero);
    return 0;
}

void generarArchivo(){
    int num=0;
    int cont=0;
    char buffer [50];
    FILE *fp;
    fp = fopen ("data.txt", "w");
    for(int i = 0; i<=150000; i++){
        num = rand() % 1000001;
        if (((num>=0)&&(num<=1000000))){
            cont++;
            snprintf(buffer,50,"%d",num);
            fprintf(fp,"%s,", buffer);
        }
        if (cont==150){
            fclose(fp);
            break;
        }
    }
}
void operacionesArchivo(FILE* fp){
    char str[MAXCHAR];
    int num;
    if(fp==NULL){
        printf("no se encontro el archivo %s",fp);
    }
    while(fgets(str,MAXCHAR,(FILE*)fp) !=NULL){
        char *token;
        token=strtok(str,",");
        while(token != NULL){
            num = atoi(token);//cambiar tiene errores creo 409 y 125
            insertarNodo(num);
            token = strtok(NULL,",");
        }
    }
}
Nodo * insertarNodo(int A){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); //se crea un nodo nuevo
    nuevo->number=A; //se copia la informacion de number nuevo->notas
    if (primero==NULL){
        primero = nuevo; //primero es igual al nodo nuevo
        primero->next=NULL;
        primero->previous=NULL;
        ultimo=primero; //el ultimo es el primero que ingresa
    } else{
        ultimo->next = nuevo;
        nuevo->next=NULL;
        nuevo->previous=ultimo;
        ultimo = nuevo;
    }
    cantidadNodos++;
    return nuevo;
}
void printList(Nodo* head){
    while (head !=NULL){
        printf("%d\n",head->number);
        head = head->next;
    }
}