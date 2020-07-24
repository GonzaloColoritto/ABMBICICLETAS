#include <stdio.h>
#include <stdlib.h>
#include "bicicleta.h"
#include <ctype.h>
#include "string.h"

int getRamdom(void){
int retorno;

retorno=rand()%50+71;

return retorno;
}


void* setearTiempo(void* bicicleta){

    eBicicleta* auxBici;

    if(bicicleta!=NULL){
        auxBici = (eBicicleta*) bicicleta;
       bicicleta_setTiempo(auxBici,getRamdom());

    }
return auxBici;
}



int filtrarPorTiempo(void* bicicleta){
int retorno=0;
    eBicicleta* auxBici;

    if(bicicleta!=NULL){
        auxBici = (eBicicleta*) bicicleta;
        if(auxBici->tiempo<50){
            retorno=1;
        }
    }
return retorno;
}

int filtrarporPlayera(void* bicicleta){

int retorno=0;
    eBicicleta* auxBici;

    if(bicicleta!=NULL){
        auxBici = (eBicicleta*) bicicleta;
        if(!strcmp(auxBici->tipoBici,"PLAYERA")){
            retorno=1;
        }
    }
return retorno;
}
int filtrarporMtb(void* bicicleta){

int retorno=0;
    eBicicleta* auxBici;

    if(bicicleta!=NULL){
        auxBici = (eBicicleta*) bicicleta;
        if(!strcmp(auxBici->tipoBici,"MTB")){
            retorno=1;
        }
    }
return retorno;

}
int filtrarporBmx(void* bicicleta){

int retorno=0;
    eBicicleta* auxBici;

    if(bicicleta!=NULL){
        auxBici = (eBicicleta*) bicicleta;
        if(!strcmp(auxBici->tipoBici,"BMX")){
            retorno=1;
        }
    }
return retorno;
}
int filtrarporPaseo(void* bicicleta){


int retorno=0;
    eBicicleta* auxBici;

    if(bicicleta!=NULL){
        auxBici = (eBicicleta*) bicicleta;
        if(!strcmp(auxBici->tipoBici,"PASEO")){
            retorno=1;
        }
    }
return retorno;
}
int  Object_sortTipo ( void * tipo1, void * tipo2) {
	char tipo_1 [20];
	char tipo_2 [20];
	int retorno =0;

	bicicletaGetTipo(tipo1, tipo_1);
	bicicletaGetTipo(tipo2, tipo_2);

	if ( strcmp (tipo_1, tipo_2)> 0 ) {
		retorno = 1 ;
	} else  if ( strcmp(tipo_1, tipo_2) < 0 ) {
		retorno = -1 ;
	}

	return retorno ;
}


int  Object_sortTiempo ( void * tiempo1, void * tiempo2) {
int tiempo_1;
int tiempo_2;
int retorno = 0 ; // si los tiempos son iguales, devuelve 0

bicicletaGetTiempo(tiempo1, &tiempo_1);
bicicletaGetTiempo(tiempo2, &tiempo_2);

if (tiempo_1> tiempo_2) {
	retorno = 1 ;
} else  if (tiempo_1 <tiempo_2) {
	retorno = -1 ;
	}
	return retorno;
}
