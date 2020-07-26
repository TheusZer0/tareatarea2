#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"
#define MAXCHAR 1000

Nodo *primero=NULL;
//se define un nodo global que representara el primer nodo de la lista (head)
Nodo *ultimo=NULL;
//se define un nodo global que representara el ultimo nodo de la lista (tail)
static int cantidadNodos=0;
//variable global estatica que contarta

/**
 * @brief        : generar una base de datos con números enteros aleatorios con valores entre 0 y 1.000.000 y los escribe en un archivo "data.txt" separados cada numeros por una coma
 * @param        : no recibe parametros
 * @return       : no retorna nada
 */
void generarArchivo();

/**
 * @brief        : realiza la lista doblemente enlazada llamando a diferetes funciones, realiza la conversion de los numeros del archivo a int y los ingresa a la lista doblemente enlazada
 * @param FILE* fp: recibe un archivo, por defecto debe ser el "data.txt" ya que es este archivo el que tiene los numeros
 * @return       : no retorna nada
 */
void operacionesArchivo(FILE* fp); //recibe el archivo data.txt y opera sobre el

/**
 * @brief        : inserta nodos, los enlaza para crear la lista doblemente enlazada y cada nodo nuevo entra siendo un tail, es decir, cada nodo que se agrega se agrega al final
 * @param int A  : recibe como parametro un numero entero que sera ingresado a al nodo que se crea
 * @return       : retorna el Nodo con el data (number) ingresado como parametro
 */
Nodo * insertarNodo(int A);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
Nodo* sortedInsert(Nodo* head_ref, Nodo* newNode);

/**
 * @brief        :
 * @param headRef:
 * @return       :
 */
void printList(Nodo* head);

int main(/*int argc, char *argv[]*/) {
    generarArchivo();
    /*if (argc!=2){
        fprintf(stderr,"ejecutar: %s data.txt", argv[0]);
        exit(EXIT_FAILURE);
    }*/
    FILE* fileList=fopen("data.txt"/*argc[1]*/,"r");
    operacionesArchivo(fileList);
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