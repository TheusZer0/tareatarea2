#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000

typedef struct nd {
    int number;
    struct nd *previous;
    struct nd *next;
}Nodo;

Nodo *primero=NULL;
Nodo *ultimo=NULL;

void generarArchivo();
void operacionesArchivo();
Nodo * insertarNodo();

int main(int argc, char *argv[]) {
    generarArchivo();
    if (argc != 2 ) {
        fprintf (stderr, "Ejecutar: %s <data.txt>", argv[0]);
        exit (EXIT_FAILURE);
    }
    FILE* filelist = fopen(argv[1],"r");
    operacionesArchivo(filelist);
    return 0;
}

void generarArchivo(){
    int num=0;
    int cont=0;
    char buffer [50];
    FILE *fp;
    fp = fopen ("data.txt", "w");
    for(int i = 0; i<=15000; i++){
        num = rand();
        if ((num>=0)&&(num<=1000000)){
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
    printf("wordks");
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
    return nuevo;
}