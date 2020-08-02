/*
 * @file    : mySearchAlg.h
 * @author	: Robert Parra
 * @date	: 01/08/2020
 * @brief   : Tarea N2 estructura de datos y algoritmos
 */

#ifndef TAREATAREA2_MYSEARCHALG_H
#define TAREATAREA2_MYSEARCHALG_H

#include "mySortAlg.h"

/**
 * @brief        : realiza la busqueda binaria a una lista enlazada
 * @param head_ref: corresponde al head de la lista enlazada
 * @param numero: sera el numero que sera buscado en la lsita
 * @param pInicio: correponde a la posicion del nodo inicio
 * @param pFinal: correponde a la posicion del nodo final
 * @return       :
 */
int binarySearch(Nodo* head_ref,int numero,int pInicio, int pFinal);

/**
 * @brief        : retorna el promedio de 100 mediciones tiempo para el binarysearch
 * @param head_ref: la posicion del nodo dentro de la lista
 * @return       : retorna un entero que corresponde al indice de la posicion del nodo izquiero (posicion entera del nodo)
 */
float timeBinarySearch(Nodo* head_ref);

#endif //TAREATAREA2_MYSEARCHALG_H
