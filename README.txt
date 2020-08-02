Nombres: Robert Antonio
Apellidos: Parra Inostroza
Rol: 201930022-9

Resumen:
 
Muchos de los programas se realizaron gracias a las diapositivas y al pseudocodigo que estas mismas presentaban, de esta manera, se hizo mucho mas llevadero y facil el completar la tarea.
De todas maneras, hubieron algun algoritmos que presentaron una gran complejidad a la hora de implementarse, como lo pudo ser el HeapSort debido al SWAP de nodos que se tuvo que implementar, ya que
este mismo swap no dejaba cambiar los valores interiores, si no, que debia intercambiar los nodos como tal, por lo cual fue muy complejo.
Tambien hubieron problemas con la implemetacion de las 100 busquedas del BinarySearch, ya que fue complejo y complicado generar las 100 busquedas y promediar los tiempos.
Otra cosa a destacar fue que el codigo final, para los 15000 numeros emplea mucho tiempo, se demoro bastante en aragon (no tanto en windows) pero de todas formas, es algo a considerar. (esto del tiempo fue debido a la creacion de listas y el mismo heapSort).
Fue mucho mas dificil manipular listas enlazadas, debido a que estas mismas ocupan diferentes tipos de links, tanto para devolverse como para avanzar (como el head y el tail, next y previous), por lo que esto mismo consume mucho tiempo a la hora e ejecutar el programa.

Complejidad Algoritmica:

Se uso "http://www.cs.us.es/~jalonso/cursos/i1m/temas/tema-28.html" como ayuda a la hora de calcular la complejidad asintotica

``` InsertionSort

Despues del "-" es la complejidad asintótica del algoritmo

Nodo * sortedInsert(Nodo* head_ref, Nodo* newNode){ //recibe como parametro el nodo head_ref que es el head de la lista y el newNode para el insertSort
    Nodo* current; //se crea un nodo current, correspondiente a un nodo tmp - "n"
    if (head_ref==NULL){ //si el head es null - "n"
        head_ref=newNode; //el head apunta al newNode - "n"
    } else if (head_ref->number >= newNode->number){ - "n"
        //si el number en el nodo head es mayor o igual al number del newNodo entonces el nodo sera  al principio de la lista
        newNode->next=head_ref; - "n"
        (newNode->next)->previous=newNode; - "n"
        head_ref=newNode; - "n"
    } else {
        current = head_ref; //el nodo current apunta al head_ref - "n"
        //localiza el nodo
        while ((current->next != NULL) && (((current->next)->number) < newNode->number)){ O(n)
            current= current->next; //avanza al next O(n-1)
        }
        (newNode->next)=(current->next);- "n"
        if (current->next != NULL){  //si el next es distinto de null,  es decir, se encuentra dentro de la lista enlazada - "n"
            (newNode->next)->previous=newNode; //se cambia el previus del newNode - "n"
        }
        current->next= newNode; //el next de current es newNode - "n"
        newNode->previous= current; - "n"
    }
    return head_ref;//retorna el sorted - "n"
}

El sortedInsert corresponde a O(n), ya que es una funcion lineal y en el while corresponde a O(n)

Nodo* insertionSort(Nodo* head_ref){
    Nodo* sorted = NULL; //Nodo nulo - "n"
    Nodo* current = head_ref; //nodo current apunta al nodo head de la lista - "n"
    while (current!=NULL){ //mientras current no sea null, es decir, recorre el current - "O(n)"
        Nodo* next = current->next;//avanza e iguala a un nodo next (nodo next = al nodo siguiente)- "O(n)"
        current->previous = current->next=NULL;- "O(n)"
        sorted = sortedInsert(sorted,current);  // se realiza el sorted- "O(n)"
        current=next;- "O(n-1)"
    }
    head_ref = sorted; - "n"
    return head_ref; //se retorna la lista enlazada ordenada - "n"
}

debido a que el sortedInsert ya presenta una complejidad de O(n) y dentro del insertionSort se ejecuta un while y dentro de este esta el sortedInsert entonces, la complejidad corresponde a: O(n^2)

complejidad asintótica del algoritmo InsertionSort=  O(n^2)

```

```HeapSort

int leftChild(int pNodo){ 
    int tmp = 2*pNodo; //sacado de las ppt de clases - Θ(1)
    return tmp;
}

LeftChild corresponde a - Θ(1)

int rightChild(int pNodo){
    int tmp = ((2*pNodo)+1); //sacado de las ppt de clases - Θ(1)
    return tmp;
}

rightChild corresponde a - Θ(1)

void swap(Nodo** headRef,Nodo* numNode_One, Nodo* numNode_Two):
el SWAP corresponde a - Θ(1) debido a que solo hay condicionales y corresponde a una funcion constante, ya que no existen loops dentro la funcion

Nodo* rNodo(Nodo* head, int pNodo){
    int tmp=0; - "n"
    Nodo* indice=NULL;- "n"
    indice=head;- "n"
    int cantNodo=countNodos(head); //cuenta la cantidadde nodos de la lista enlazada- "n"
    if (pNodo>cantNodo){- "n"
        return head; //retorna el head- "n"
    }
    while (indice !=NULL){ -"O(n)"
        tmp++; -"O(n)"
        if (tmp==pNodo){ -"O(n)"
            return indice;//retorna el indice(nodo) -"O(n)"
        }
        indice= indice->next;//avanza -"O(n)"
    }
}

la Complejidad Algoritmica del rNodo corresponde a "O(n)" ya que el peor caso seria cuando n es el ultimo nodo de la lista, por ende esta funcion recorrera la lista hasta encontrar al O(n).

int countNodos(Nodo* head){
    int numNodos = 0;- "n"
    while (head !=NULL){ //recorre la lista doblemente enlazada -"O(n)"
        numNodos++; //suma 1 a numNodos -"O(n)"
        head = head->next; //avanza al nodo siguiente -"O(n)"
    }
    return numNodos; //retorna la cant de nodos como entero
}

debido al loop dentro de la funcion que recorre la lista hasta el ultimo nodo, esta misma corresponde a O(n) siendo el n el ultimo nodo de la lista enlazada, es decir, el peor caso.

void maxHeapify(Nodo** head, int posicion, int heapzise){
    int l = leftChild(posicion);//nodo izquierdo - Θ(1)
    int r = rightChild(posicion);//nodo derecho - Θ(1)
    int cantNodos=0;- "n"
    cantNodos=countNodos(*head); //cantidad de nodos- "n"
    int largest;- "n"
    if ((l<=heapzise)&&((rNodo(*head, l)->number) > (rNodo(*head, posicion))->number)){Θ(1)
        largest = l;Θ(1)
    } else{
        largest=posicion;Θ(1)
    }
    if ((r<=heapzise) && (rNodo(*head, r)->number > (rNodo(*head, largest)->number))){Θ(1)
        largest=r;Θ(1)
    }
    if (largest!=posicion){-Θ(1)
        swap(head, rNodo(*head, posicion), ((rNodo(*head, largest))));Θ(1)
        maxHeapify(head, largest,heapzise); - O(log n)
    }
}

el max-Heapify corresponde a Θ(log(n)) debido a que ordena respecto a la topologia max-heap que se adopta, este procedimiento asegura que el arbol cumple con la topologia y por ende, su costo es O(log n)

Nodo* buildMaxHeap(Nodo* headRef){
    int aLargo=countNodos(headRef);- Θ(1)
    int i = (aLargo/2);- Θ(1)
    for (int j = i; j > 0; --j) {
        maxHeapify(&headRef,j,aLargo);//realiza el max heapify - O(log n)
    }
    return headRef;
}

corresponde a O(n log n) ya que se construye un arbol de tipo max-heap este es el tipo de estructura que usaremos para sorting a partir de un arreglo no ordenado, en este caso, para listas enlazadas y su costo es lineal O(n) (cuando buscamos su costo exacto) o bien O(n log n), sabiendo que el arbol tiene una profundidad de log n. Por ende su costo final es O(n log n).

Nodo* heapsort(Nodo* head_ref){
    Nodo* tmp = head_ref; - Θ(1)
    tmp=buildMaxHeap(tmp); - O(n log n)
    int heapzise = countNodos(tmp); - Θ(1)
    for (int i = countNodos(tmp); i>=2 ; i--) { O(n)
        swap(&tmp, rNodo(tmp, 1), rNodo(tmp, i)); //realiza el swap del primer nodo con el ultimo - Θ(1)
        heapzise--;-O(n)
        maxHeapify(&tmp,1,heapzise); //realiza el maxHeapify con nodo tmp y la posicion 1, siendo el heap el que cambia o disminuye (se saca) - Θ(log(n))
    }
    return tmp;
}

El algoritmo de heapsort final corresponde a O(n log n) + O(n)*Θ(log(n)), siendo el peor caso el O(n log n) por lo tanto, luego de sacado todo lo anterior, se puede concluir que la complejidad algoritmica para el codigo hecho corresponde a O(n log n).
De esta misma forma, llegamos a la conclusion de que este cumple debido a que el heapsort usa una estructura de datos llamados heap, el heap es un tipo de arreglo (que en la tarea se reemplaza por listas doblemente enlazadas) que puede representarse mediante un arbol binario. cada nodo del arbol corresponde a un elemento de las listas enlazadas.

```

```BinarySearch

int binarySearch(Nodo* head_ref,int numero,int pInicio, int pFinal){
    Nodo* tmp=head_ref; - Θ(1)
    Nodo* nMedio = NULL;- Θ(1)
    int pMedio = 0;- Θ(1)
    if (pInicio==pFinal){- Θ(1)
        return pInicio;- Θ(1)
    } else{- Θ(1)
        pMedio= (pInicio+pFinal)/2;- Θ(1)
        nMedio = rNodo(head_ref, pMedio);- Θ(1)
        if (numero <= nMedio->number){- Θ(1)
            binarySearch(tmp,numero,pInicio,pMedio); Θ(n)
        } else {
            binarySearch(tmp,numero,pMedio+1,pFinal);  Θ(n)
        }
    }
}

el 

```