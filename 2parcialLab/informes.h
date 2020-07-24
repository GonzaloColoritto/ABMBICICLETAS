#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "bicicleta.h"
int filtrarPorTiempo(void* bicicleta);
int filtrarporPlayera(void* bicicleta);
int filtrarporMtb(void* bicicleta);
int filtrarporBmx(void* bicicleta);
int filtrarporPaseo(void* bicicleta);
void* setearTiempo(void* bicicleta);
int getRamdom(void);
int  Object_sortTiempo ( void * tiempo1, void * tiempo2);
int  Object_sortTipo ( void * tipo1, void * tipo2);
#endif // INFORMES_H_INCLUDED
