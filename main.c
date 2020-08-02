/*
 * @file    : main.c
 * @author	: Robert Parra
 * @date	: 01/08/2020
 * @brief   : Tarea N2 estructura de datos y algoritmos
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mySortAlg.h"
#include "mySearchAlg.h"
#define MAXCHAR 1000

Nodo *primero=NULL; //se define un nodo global que representara el primer nodo de la lista (head)
Nodo *ultimo=NULL; //se define un nodo global que representara el ultimo nodo de la lista (tail)

//array que guarda los tiempos de 3 ejecuciones para una cantidad de datos X en el archivo con el algoritmo de InsertSort
float insertSortArray[3];

//array que guarda los tiempos de 3 ejecuciones para una cantidad de datos X en el archivo con el algoritmo de heapSort
float heapSortArray[3];

//array que guarda los tiempos de 3 ejecuciones para una cantidad de datos X en el archivo con el algoritmo de binarySearch
float binarySearchArray[3];

/**
 * @brief        : generar una base de datos con números enteros aleatorios con valores entre 0 y 1.000.000 y los escribe en un archivo "data.txt" separados cada numeros por una coma
 * @param        : no recibe parametros
 * @return       : no retorna nada
 */
void generarArchivo(int data);

/**
 * @brief        : realiza la lista doblemente enlazada y realiza la conversion de los numeros del archivo a int y los ingresa a la lista doblemente enlazada
 * @param FILE* fp: recibe un archivo, por defecto debe ser el "data.txt" ya que es este archivo el que tiene los numeros
 * @param cantNum : cantidad de numeros que seran ingresados a la lista
 * @return       : no retorna nada
 */
void createList(FILE* fp, int cantNum);

/**
 * @brief        : inserta nodos, los enlaza para crear la lista doblemente enlazada y cada nodo nuevo entra siendo un tail, es decir, cada nodo que se agrega se agrega al final
 * @param int A  : recibe como parametro un numero entero que sera ingresado a al nodo que se crea
 * @return       : retorna el Nodo con el data (number) ingresado como parametro
 */
Nodo * insertarNodo(int A);

/**
 * @brief        : imprime la data de los nodos de la lista enlazada, es decir, imprime el "number" de cada uno de los nodos, desde el nodo head hasta el tail
 * @param head   : recibe el nodo head de la lista doblemente enlazada
 * @return       : corresponde a void, por lo que retorna vacio
 */
void printList(Nodo* head);

/**
 * @brief        : elimina una lista doblemente enlazada gracias al uso de un loop
 * @param headRef  : recibe como parametro el head de una lista doblemente enlazada
 * @return       : retorna el Nodo NULL
 */
Nodo* eliminarLista(Nodo* headRef);

/**
 * @brief        :  realiza el insertSort, el heapSort, el BinarySearch y los promedios los guarda dentro de variables globales
 * @param n  : el N es la cantidad de veces que se guardara un tiempo dentro del arreglo MAX 3
 * @param x  : cantidad de datos con los que se haran las listas enlazadas
 * @return       : no retorna nada
 */
void mainFunction(int n,int x);

int main(/*int argc, char *argv[]*/){
    generarArchivo(15000); //se genera el archivo
    int cantDatosUno=150; //cantidad de nodos con los que se hara la lista enlazada
    for (int i = 0; i <= 2 ; ++i) {
        mainFunction(i,cantDatosUno); //para sacar el promedio lo hacemos 3 veces y guardamos los tiempos en arreglos
    }
    float resultInsertSort = (insertSortArray[0]+insertSortArray[1]+insertSortArray[2])/3; //se resuelve para calcular el promedio
    float resultHeapSort = (heapSortArray[0]+heapSortArray[1]+heapSortArray[2])/3; //se resuelve para calcular el promedio
    float resultBinarySearch = (binarySearchArray[0]+binarySearchArray[1]+binarySearchArray[2])/3; //se resuelve para calcular el promedio
    printf("#############################\n");
    printf("el promedio del insertSort con la cantidad de total de datos 150 es: %f \n",cantDatosUno,resultInsertSort);
    printf("el promedio del heapSort con la cantidad de total de datos 150 es: %f \n",cantDatosUno,resultHeapSort);
    printf("el promedio del binarySearch con la cantidad de total de datos 150 es: %f \n",cantDatosUno,resultBinarySearch);

    cantDatosUno=1500; //cantidad de nodos con los que se hara la lista enlazada
    for (int i = 0; i <= 2 ; ++i) {
        mainFunction(i,cantDatosUno); //para sacar el promedio lo hacemos 3 veces y guardamos los tiempos en arreglos
    }
    resultInsertSort = (insertSortArray[0]+insertSortArray[1]+insertSortArray[2])/3; //se resuelve para calcular el promedio
    resultHeapSort = (heapSortArray[0]+heapSortArray[1]+heapSortArray[2])/3; //se resuelve para calcular el promedio
    resultBinarySearch = (binarySearchArray[0]+binarySearchArray[1]+binarySearchArray[2])/3; //se resuelve para calcular el promedio
    printf("#############################\n");
    printf("el promedio del insertSort con la cantidad de total de datos (%d) es: %f \n",cantDatosUno,resultInsertSort);
    printf("el promedio del heapSort con la cantidad de total de datos (%d) es: %f \n",cantDatosUno,resultHeapSort);
    printf("el promedio del binarySearch con la cantidad de total de datos (%d) es: %f \n",cantDatosUno,resultBinarySearch);

    cantDatosUno=15000; //cantidad de nodos con los que se hara la lista enlazada
    for (int i = 0; i <= 2 ; ++i) {
        mainFunction(i,cantDatosUno); //cantidad de nodos con los que se hara la lista enlazada
    }
    resultInsertSort = (insertSortArray[0]+insertSortArray[1]+insertSortArray[2])/3; //se resuelve para calcular el promedio
    resultHeapSort = (heapSortArray[0]+heapSortArray[1]+heapSortArray[2])/3; //se resuelve para calcular el promedio
    resultBinarySearch = (binarySearchArray[0]+binarySearchArray[1]+binarySearchArray[2])/3; //se resuelve para calcular el promedio
    printf("#############################\n");
    printf("el promedio del insertSort con la cantidad de total de datos (%d) es: %f \n",cantDatosUno,resultInsertSort);
    printf("el promedio del heapSort con la cantidad de total de datos (%d) es: %f \n",cantDatosUno,resultHeapSort);
    printf("el promedio del binarySearch con la cantidad de total de datos (%d) es: %f \n",cantDatosUno,resultBinarySearch);
    printf("\n");

    return 0;
}

void mainFunction(int n,int x){

    struct timeval start , end ; //struct para determinar el tiempo de la ejecucion de los algortimos usados dentro de la funcion
    //creacion de nodos que seran igualados al head (para asi no modificar el head principal, de manera que el head principal siempre estara en desorden)
    Nodo* insertSort = NULL;
    Nodo* heapSortFinal=NULL;
    FILE* fileList=fopen("data.txt","r"); //abrir el archivo
    float tiempoInsertSort,tiempoHeapSort; //variables para el tiempo de ejecucion

    //InsertSort
    createList(fileList,x); //funcion que crea las listas enlazadas, siendo x la cantidad de datos que se leeran del archivo
    insertSort=primero;
    gettimeofday(&start, NULL); //tiempo de la ejecucion del programa
    insertSort=insertionSort(primero); //insertSort es una variable que tiene la lista ordenada por insertSort
    gettimeofday(&end, NULL); //tiempo de la ejecucion del programa
    primero=eliminarLista(primero); //se elimina la lista
    //termina el insertSort y se elimina la lista

    //HeapSort
    createList(fileList,x); //funcion que crea las listas enlazadas, siendo x la cantidad de datos que se leeran del archivo
    heapSortFinal=primero;
    tiempoInsertSort = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000.0; //tiempo InsertSort
    printf("#############################\n");
    printf("El tiempo que demoro el insertSort es: %f \n",tiempoInsertSort);
    gettimeofday(&start, NULL);//tiempo de la ejecucion del programa
    heapSortFinal=heapsort(heapSortFinal); // heapsort
    gettimeofday(&end, NULL); //tiempo de la ejecucion del programa
    tiempoHeapSort = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000.0;
    printf("El tiempo que demoro el heapSort es: %f \n",tiempoHeapSort);

    //BinarySearch
    binarySearchArray[n]=timeBinarySearch(heapSortFinal); //asignacion del tiempo en una variable global que corresponde a un arreglo
    printf("El tiempo que demoro la busqueda binaria es: %f \n",binarySearchArray[n]);
    insertSortArray[n] = tiempoInsertSort; //asignacion del tiempo en una variable global que corresponde a un arreglo
    heapSortArray[n] = tiempoHeapSort; //asignacion del tiempo en una variable global que corresponde a un arreglo
    primero=eliminarLista(primero); //elimina la lista
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
            fprintf(fp,"%s\n", buffer);
        }
        if (cont==data){
            fclose(fp); //se cierra el archivo
            break;
        }
    }
}

void createList(FILE* fp, int cantNum){
    int numero; //variable que tendra o sera igualada al numero del archivo
    for(int i=0; i < cantNum; i++){
        fscanf(fp,"%d",&numero); //lee por linea y convierte el dato en int
        insertarNodo(numero); //insertar en lista enlazada
    }
    rewind(fp);
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
    return nuevo; //retorna el nodo nuevo
}

void printList(Nodo* head){
    while (head !=NULL){ //si el head tiene contenido entonces se recorre la lista enlazada
        printf("%d\n",head->number);//printa el number en el head
        head = head->next; //head apunta al siguiente
    }
}

Nodo* eliminarLista(Nodo* headRef){
    Nodo* tmp = headRef; //nodo temporal que apunta a headref
    while(headRef!=NULL){ //mientras headref no sea nulo
        tmp = headRef; //variable tmp
        headRef = (headRef)->next ;  //el head pasa al dato siguiente
        free(tmp); //se libera el tmp
    }
    headRef = NULL;  //el head queda NULL
    return headRef; //se retorna el Head
}
