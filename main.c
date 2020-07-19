#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mySortAlg.h"
#define MAXCHAR 1000

Nodo *primero=NULL;
Nodo *ultimo=NULL;

void generarArchivo();
void operacionesArchivo();
Nodo * insertarNodo();

//void desplegarListaPU();

int main(int argc, char *argv[]) {
    generarArchivo();
    if (argc!=2){
        fprintf(stderr,"ejecutar: %s <name.txt>", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* fileList=fopen(argv[1],"r");
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
        if (cont==149){
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
            num = atoi(token);
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
    return nuevo;
}

/*void desplegarListaPU(){
    Nodo* actual= (Nodo*)malloc(sizeof(Nodo));
    actual=primero;
    if(primero!=NULL){
        while (actual!=NULL){
            printf("\n %d",actual->number);
            actual= actual->next;
        }
    } else{
        printf("\n la lista se encuentra vacia\n");
    }
}*/