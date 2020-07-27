#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"
#define MAXCHAR 1000

Nodo *primero=NULL; //se define un nodo global que representara el primer nodo de la lista (head)
Nodo *ultimo=NULL; //se define un nodo global que representara el ultimo nodo de la lista (tail)

static int cantidadNodos=0; //variable global estatica que contarta

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
 * @brief        : imprime la data de los nodos de la lista enlazada, es decir, imprime el "number" de cada uno de los nodos, desde el nodo head hasta el tail
 * @param head: recibe el nodo head de la lista doblemente enlazada
 * @return       : corresponde a void, por lo que retorna vacio
 */
void printList(Nodo* head);

int main(/*int argc, char *argv[]*/) {
    generarArchivo(150);
    /*if (argc!=2){
        fprintf(stderr,"ejecutar: %s data.txt", argv[0]);
        exit(EXIT_FAILURE);
    }*/
    FILE* fileList=fopen("data.txt"/*argc[1]*/,"r");
    operacionesArchivo(fileList);
    primero=buildMaxHeap(primero);
    printList(primero);
    return 0;
}

void generarArchivo(int data){
    int num=0;
    int cont=0;
    char buffer [50];
    FILE *fp;
    fp = fopen ("data.txt", "w"); //se abre el archivo
    for(int i = 0; i<=150000; i++){
        num = rand() % 1000001; //numeros random hasta el millon
        if (((num>=0)&&(num<=1000000))){ //numeros entre el 0 y el millon
            cont++;
            snprintf(buffer,50,"%d",num);
            //se escribe en un archivo
            fprintf(fp,"%s,", buffer);
        }
        if (cont==data){
            fclose(fp); //se cierra el archivo
            break;
        }
    }
}

void operacionesArchivo(FILE* fp){
    char str[MAXCHAR];
    int num;
    if(fp==NULL){ //si el archivo en NULL entonces entrega el mensaje
        printf("no se encontro el archivo %s",fp);
    }
    while(fgets(str,MAXCHAR,(FILE*)fp) !=NULL){
        char *token;
        token=strtok(str,",");
        while(token != NULL){
            num = atoi(token); //la funcion atoi convierte el char en entero
            insertarNodo(num); //se inserta el num en la lista doblemente enlazada
            token = strtok(NULL,",");
        }
    }
}

Nodo * insertarNodo(int A){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); //se crea un nodo nuevo
    nuevo->number=A; //se copia la informacion de number nuevo->notas
    //si el primero es null, quiere decir que aun no tiene nada, por lo tanto se le ingresa data
    if (primero==NULL){
        primero = nuevo; //primero es igual al nodo nuevo
        primero->next=NULL; //next en null debido a que el nodo ingresado es el head
        primero->previous=NULL; //el previus en null debido a que el nodo que ingresamos corresponde al head
        ultimo=primero; //el ultimo es el primero que ingresa
    } else{ //este caso sucede cuando ya hay un nodo ingresado, es decir, cuando primero!=NULL
        ultimo->next = nuevo; //el ultimo apunta a next y este es igual a nuevo, nodo que creamos dentro de esta funcion
        nuevo->next=NULL; //el next de nuevo corresponde a null ya que no hay ningun nodo adelante de el
        nuevo->previous=ultimo; //dejamos a previus como el nodo ultimo
        ultimo = nuevo; //igualamos el ultimo a nuevo
    }
    cantidadNodos++; //sumamos la cantidad de nodos
    return nuevo; //retorna el nodo nuevo
}

void printList(Nodo* head){
    while (head !=NULL){ //si el head tiene contenido entonces se recorre la lista enlazada
        printf("%d\n",head->number);//printa el number en el head
        head = head->next; //head apunta al siguiente
    }
}