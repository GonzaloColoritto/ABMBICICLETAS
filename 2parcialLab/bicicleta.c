#include <stdio.h>
#include <stdlib.h>
#include "ll_list.h"
#include "Controller.h"
#include "bicicleta.h"
#include "menu.h"
#include "string.h"

eBicicleta* bicicleta_new(){

    return (eBicicleta*)malloc(sizeof(eBicicleta));
}
int bicicleta_setId(eBicicleta* this,int id)
{

    int retorno = -1;
	if(this != NULL && id > 0)
	{

	    this->id_bike = id;

		retorno = 0;

	}
	return retorno;

}

int bicicleta_setNombre(eBicicleta* this,char* nombre)
{
    int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(this->nombreDuenio,nombre);
	}
	return retorno;
}

int bicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		strcpy(this->tipoBici,tipo);
	}
	return retorno;

}
int bicicleta_setTiempo(eBicicleta* this,int tiempoCarrera)
{
    int retorno = -1;
	if(this != NULL && tiempoCarrera >= 0)
	{

	    this->tiempo = tiempoCarrera;

		retorno = 0;

	}
	return retorno;
}
eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr){


    eBicicleta* auxBici = NULL;

    auxBici = bicicleta_new();
    int id=atoi(idStr);
    int tiempo=atoi(tiempoStr);



    if(auxBici!=NULL)
    {
        bicicleta_setId(auxBici,id);
        bicicleta_setNombre(auxBici,nombreStr);
        bicicleta_setTipo(auxBici,tipoStr);
        bicicleta_setTiempo(auxBici,tiempo);

    }
    return auxBici;
}

int bicicletaGetId(eBicicleta* bicicleta,int* id){

int retorno = -1;
	if(bicicleta != NULL && id != NULL)
	{

	    *id = bicicleta->id_bike;

		retorno = 1;

	}
	return retorno;


}

int bicicletaGetNombre(eBicicleta* bicicleta, char nombre[20]){

int retorno=-1;

    if(bicicleta != NULL && nombre != NULL){

        strcpy(nombre,bicicleta->nombreDuenio);
        retorno=1;
    }


return retorno;
}


int bicicletaGetTipo(eBicicleta* bicicleta, char tipo[15]){


int retorno=-1;

    if(bicicleta != NULL &&tipo != NULL){

        strcpy(tipo,bicicleta->tipoBici);
        retorno=1;
    }


return retorno;
}

int bicicletaGetTiempo(eBicicleta* bicicleta, int* tiempo){


int retorno=-1;

    if(bicicleta != NULL && tiempo != NULL){

        *tiempo = bicicleta->tiempo;
        retorno=1;
    }


return retorno;
}





