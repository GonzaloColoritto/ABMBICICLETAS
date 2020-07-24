#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "bicicleta.h"
int menuInicio(){
int opcion;
system("cls");

printf("CARRERA DE BICICLETAS\n\n");

printf("1-CARGAR ARCHIVO\n");
printf("2-LISTAR BICICLETAS\n");
printf("3-ASIGNAR TIEMPO\n");
printf("4-FILTRAR Y GUARDAR\n");
printf("5-\n");
printf("6-GUARDAR ARCHIVO EN: BICICLETAS2\n");
printf("7-SALIR\n");


 printf("Ingrese una opcion:");
 scanf("%d",&opcion);

return opcion;
}

int menuTipo(){
int opcion;
system("cls");


printf("1-BMX\n");
printf("2-PLAYERA\n");
printf("3-PASEO\n");
printf("4-MTB\n");



 printf("Ingrese una opcion:");
 scanf("%d",&opcion);

return opcion;
}
