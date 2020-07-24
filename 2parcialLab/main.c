#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "bicicleta.h"
#include "ll_list.h"
#include "Controller.h"
#include "parser.h"
#include <ctype.h>
#include "string.h"
#include "informes.h"
int main()
{
    char seguir = 's';
    char confirmacion;
    //int opcion;
    LinkedList* listaBicicletas = ll_newLinkedList();
    LinkedList* listaBicicletasFiltrada=NULL;

    do
    {

        switch(menuInicio())
        {

        case 1:
            if(controller_loadFromText("bicicletas.csv",listaBicicletas)==0)
            {
                printf("Datos Cargados con exito\n");
                system("pause");
            }
            else
            {

                printf("Error en la carga de datos\n");
                system("pause");
            }
            break;

        case 2:

            if(!controller_ListBicicleta(listaBicicletas))
            {

                printf("Listadas con exito\n");
            }
            else
            {
                printf("Error al listar\n");
            }


            break;

        case 3:
            listaBicicletas=ll_map(listaBicicletas,setearTiempo);
            if(!controller_ListBicicleta(listaBicicletas))
            {

                printf("Listadas con exito\n");
            }
            else
            {
                printf("Error al listar\n");
            }
            break;

        case 4:
             listaBicicletasFiltrada=ll_newLinkedList();
            switch(menuTipo())
            {

            case 1:
                listaBicicletasFiltrada=ll_filter(listaBicicletas,filtrarporBmx);
                if(!controller_ListBicicleta(listaBicicletasFiltrada))
                {
                    controller_saveAsText("bicicletasBMX.csv",listaBicicletasFiltrada);
                    printf("Filtradas y guardadas con exito en 'bicicletasBMX.csv' \n");
                }
                else
                {
                    printf("Error al filtrar\n");
                }

                break;

            case 2:
                listaBicicletasFiltrada=ll_filter(listaBicicletas,filtrarporPlayera);
                if(!controller_ListBicicleta(listaBicicletasFiltrada))
                {
                    controller_saveAsText("bicicletasPLAYERA.csv",listaBicicletasFiltrada);
                    printf("Filtradas y guardadas con exito en 'bicicletasPLAYERA.csv' \n");
                }
                else
                {
                    printf("Error al filtrar\n");
                }
                break;

            case 3:
                listaBicicletasFiltrada=ll_filter(listaBicicletas,filtrarporPaseo);
                if(!controller_ListBicicleta(listaBicicletasFiltrada))
                {
                    controller_saveAsText("bicicletasPASEO.csv",listaBicicletasFiltrada);
                    printf("Filtradas y guardadas con exito en 'bicicletasBMX.csv' \n");
                }
                else
                {
                    printf("Error al filtrar\n");
                }
                break;

            case 4:
                listaBicicletasFiltrada=ll_filter(listaBicicletas,filtrarporMtb);
                if(!controller_ListBicicleta(listaBicicletasFiltrada))
                {
                    controller_saveAsText("bicicletasMTB.csv",listaBicicletasFiltrada);
                    printf("Filtradas y guardadas con exito en 'bicicletasmtb.csv' \n");
                }
                else
                {
                    printf("Error al filtrar\n");
                }
                break;
            }

            break;

        case 5:

            if(ll_sortX2(listaBicicletas,Object_sortTipo,Object_sortTiempo,1)){
                if(!controller_ListBicicleta(listaBicicletas)){

                    printf("Orden mostrado de forma ascendente\n");
                }else{
                printf("Error al listar en orden\n");
                }

               }
            break;

        case 6:
            if(controller_saveAsText("bicicletas2.csv",listaBicicletas)){

                printf("Guardado con exito\n");
            }else{

            printf("Error al guardar\n");
            }
            break;

        case 7:
            printf(" ¿Desea salir? S/N: ");
            fflush(stdin);
            scanf("%c",&confirmacion);

            confirmacion=tolower(confirmacion);

            if(confirmacion=='s')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");
    }
    while(seguir=='s');
}
