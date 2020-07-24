#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_list.h"
#include "bicicleta.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList *this = NULL;
    this= (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {


        this->size=0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {

        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;

    if(this!= NULL && nodeIndex >=0 && nodeIndex<ll_len(this))
    {

        nodo= this->pFirstNode;

        while(nodeIndex>0)
        {
            nodo= nodo->pNextNode;
            nodeIndex--;

        }

    }

    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo;


    Node* nodoAnterior;

    if(this != NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        nuevoNodo = (Node*)malloc(sizeof(Node));
        if(nuevoNodo!=NULL)
        {

            nuevoNodo->pElement=pElement;
            if(nodeIndex==0)
            {

                nuevoNodo->pNextNode = this->pFirstNode;
                this->pFirstNode=nuevoNodo;


            }
            else
            {

                nodoAnterior = getNode(this, nodeIndex-1);

                nuevoNodo->pNextNode = nodoAnterior->pNextNode;
                nodoAnterior->pNextNode = nuevoNodo;


            }
            this->size++;
            returnAux=0;
        }


    }



    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!= NULL)
    {


        if(addNode(this,ll_len(this),pElement)==0)
        {

            returnAux=0;
        }


    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this!=NULL && index >= 0 && index<ll_len(this))
    {

        auxNode = getNode(this,index);
        if(auxNode!=NULL)
        {

            returnAux=auxNode->pElement;
        }

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL && index >=0 && index<ll_len(this))
    {
        auxNode=getNode(this,index);
        if(auxNode!=NULL)
        {

            auxNode->pElement=pElement;
            returnAux = 0;
        }

    }




    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* actual;
    Node* anterior;

    if(this != NULL && index >=0 && index<ll_len(this))
    {

        actual = getNode(this,index);

        if(actual!=NULL)
        {

            if(index==0)
            {

                this->pFirstNode = actual->pNextNode;
                this->size--;
                free(actual);
                returnAux = 0;
            }
            else
            {

                anterior = getNode(this,index-1);
                if(anterior!=NULL)
                {
                    anterior->pNextNode = actual->pNextNode;
                    this->size--;
                    free(actual);
                    returnAux = 0;

                }

            }

        }

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int TAM;

    if(this !=NULL)
    {
        TAM = ll_len(this);

        for(int i=TAM; i >=0; i--)
        {

            ll_remove(this,i);
        }

        returnAux = 0;
    }




    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_clear(this))
            free(this);
        returnAux=0;
    }







    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
    if(this!=NULL)
    {
        tam=ll_len(this);

        for(int i = 0; i<tam; i++)
        {

            if(ll_get(this,i)==pElement)
            {

                returnAux=i;
                break;
            }

        }

    }


    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=0;

        if(this->pFirstNode==NULL)
        {
            returnAux = 1;

        }

    }




    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{

    return addNode(this, index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {

        returnAux = ll_get(this,index);
        if(ll_remove(this,index))
        {

            returnAux = NULL;

        }
    }



    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
    if(this!=NULL)
    {
        returnAux = 0;
        tam=ll_len(this);

        for(int i=0; i<tam; i++)
        {
            if(ll_get(this,i)==pElement)
            {

                returnAux=1;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;
    void* elemento;

    if(this!=NULL && this2!=NULL)
    {
        returnAux =1;
        tam=ll_len(this2);

        for(int i=0; i<tam; i++)
        {
            elemento=ll_get(this2,i);
            if((ll_contains(this,elemento)) == 0)
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* elemento;
    if(!(this==NULL || from<0 || from>ll_len(this) || to<=from || to>ll_len(this)))
    {

        cloneArray = ll_newLinkedList();

        if(cloneArray!=NULL)
        {

            for(int i =from; i<to; i++)
            {

                elemento = ll_get(this,i);
                ll_add(cloneArray,elemento);
            }

        }


    }




    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;


    cloneArray = ll_subList(this, 0, ll_len(this));




    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int tam;
    void* aux;
    if(this != NULL && pFunc != NULL && order>=0 && order<=1)
    {
        tam = ll_len(this);
        for(int i=0; i<tam-1; i++)
        {

            for(int j = i+1; j<tam; j++)
            {

                if(pFunc(ll_get(this,i),ll_get(this,j))>0 && order == 1)
                {

                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);
                }
                else if(pFunc(ll_get(this,i),ll_get(this,j)) <0 && order == 0)
                {

                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);




                }
            }

        }
        returnAux = 0;
    }

    return returnAux;

}

//devuelve un nuevo linkedlist

LinkedList* ll_filter(LinkedList* this, int(*pfunc)(void*))
{

    void* elemento;
    LinkedList* listaFiltrada = NULL;

    if(this!=NULL && *pfunc!= NULL)
    {
        listaFiltrada = ll_newLinkedList();
        if(listaFiltrada!=NULL)
        {

            for(int i=0; i<ll_len(this); i++)
            {
                elemento=ll_get(this,i);
                if(pfunc(elemento))
                {
                    ll_add(listaFiltrada,elemento);
                }
            }
        }
    }
    return listaFiltrada;
}

/*
int filtrarPorSueldo (void* empleado){

    Employee* auxEmp;
    int auxReturn = 0;
    if(empleado!=NULL){

        auxEmp = (Employee*)empleado;
        if(auxEmp->sueldo>25000){

            auxReturn=1;

        }




    }
    return auxReturn;
}*/
LinkedList* ll_map(LinkedList* this, void*(*pfunc)(void*)){

int tam;
void* elementos;
LinkedList* auxLista=NULL;

if(this!=NULL && *pfunc!=NULL){
 auxLista=ll_newLinkedList();
 tam=ll_len(this);
    for(int i=0;i<tam;i++){
    elementos=ll_get(this,i);
    elementos=pfunc(elementos);
    if(elementos!=NULL){
      ll_add(auxLista,elementos);
    }
    }


}
return auxLista;
}

int  ll_sortX2 (LinkedList* this, int (* pFunc) ( void *, void *), int (* pFunc2) ( void *, void *), int order) {
	int returnAux = 0 ;
	void* element1;
	void* element2;
	if(this!= NULL && pFunc!= NULL && (order == 1 || order == 0 )) {
		for ( int i = 0 ; i < ll_len(this) -1 ; i++) {
			for ( int j=i + 1 ; j< ll_len(this); j++) {
				element1 = ll_get(this, i); // copio el primer elemento.
				element2 = ll_get(this, j); // copio el segundo elemento.

				// Si los elementos son distintos, orden de alcalde menor / menor a mayor.
				if (( pFunc (element1, element2)> 0 && order) || ( pFunc (element1, element2) <0 && !order)) {
					ll_set (this, i, element2); // Cambio de lugar el segundo elemento.
					ll_set (this, j, element1); // Cambio de lugar el primer elemento.
				// Si los elementos son iguales, ordeno con la segunda funci�n.
				} else  if ( pFunc(element1, element2) == 0 ) {
					if ( pFunc2(element1, element2) > 0 ) {
						ll_set(this, i, element2);
						ll_set(this, j, element1);
					}
				}
			}
			returnAux = 1 ;
		}
	}
	return returnAux;
}

