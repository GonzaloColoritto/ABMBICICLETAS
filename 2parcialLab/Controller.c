#include <stdio.h>
#include <stdlib.h>
#include "ll_list.h"
#include "bicicleta.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

   int controller_loadFromText(char *path, LinkedList *pArrayList) {

	FILE* pFile;
	int paso = -1;


	pFile = fopen("bicicletas.csv", "r");
	if (pFile != NULL) {
		parser_FromText(pFile, pArrayList);

		paso = 0;
	}
	fclose(pFile);
    return paso;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *//*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    int paso=-1;
    pFile= fopen("datos.bin","rb");

    if(pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        paso=0;
    }


    fclose(pFile);
    return paso;
}*/

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
 int controller_arrayMaxID(LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int TAM;
    int currentID;
    int idMaximo = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        TAM = ll_len(pArrayListEmployee);
        for(i=0; i<TAM; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            employee_getId(pAux, &currentID);
            if(currentID > idMaximo)
            {
                idMaximo = currentID;
            }
        }
    }
    idMaximo += 1;
    return idMaximo;
}*/
/*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pAux  = employee_new();
    char bufferCadena[128];
    int bufferInt, bufferInt2;
    int id;
    if(pArrayListEmployee != NULL && pAux != NULL)
    {
        id = controller_arrayMaxID(pArrayListEmployee);
        if(id != -1)
        {
            if(utn_getName("\nIngrese  nombre: ", "\nError: Nombre invalido. Ingreselo nuevamente: ", 0, 128, 2, bufferCadena))
            {
                return retorno;
            }
            if(utn_getUnsignedInt("\nIngrese  horas trabajadas: ", "\nError: Horas invalidas. Ingreselo nuevamente: ", 0, 4, 0, 24, 2, &bufferInt))
            {
                return retorno;
            }
            if(utn_getUnsignedInt("\nIngrese  sueldo: ", "\nError: Sueldo invalido. Ingreselo nuevamente: ", 0, 100, 0, 1000000, 2, &bufferInt2))
            {
                return retorno;
            }
            employee_setId(pAux, id);
            employee_setNombre(pAux, bufferCadena);
            employee_setHorasTrabajadas(pAux, bufferInt);
            employee_setSueldo(pAux, bufferInt2);
            ll_add(pArrayListEmployee, pAux);
            printf("\nEmpleado ingresado correctamente\n");
            retorno = 0;
        }
    }
    return retorno;
}*/

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
 int controller_buscarId(LinkedList* pArrayListEmployee, int id, int* indice)
{
    Employee* pAux;
    int TAM = ll_len(pArrayListEmployee);
    int i;
    int retorno = -1;
    int bufferInt;
    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<TAM; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            employee_getId(pAux, &bufferInt);
            if(bufferInt == id)
            {
                retorno = 0;
                *indice = i;
                break;
            }
        }
    }
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferInt;
    int opcion;
    int indice;
    char bufferChar[128];
    Employee* pAux = NULL;
    if(pArrayListEmployee != NULL)
    {
        if(!utn_getUnsignedInt("\nIngrese el ID: ", "\nError: ID invalida. Ingreselo nuevamente: ", 0, 5, 0, 24, 2, &bufferInt))
        {

            if(!controller_buscarId(pArrayListEmployee, bufferInt, &indice))
            {
                pAux = ll_get(pArrayListEmployee, indice);
                printf("ID  NOMBRE HS.TRABAJADAS SUELDO\n\n");
                printf("%d   %s          %d        %d \n",pAux->id,pAux->nombre,pAux->horasTrabajadas,pAux->sueldo);
                if(!utn_getUnsignedInt("\n1) Editar Nombre\n2) Editar Horas Trabajadas\n3) Editar sueldo\n4) Salir\n", "\nError: Opcion invalida. Ingresela nuevamente: ", 0, 5, 0, 24, 2, &opcion))
                {
                    switch(opcion)
                    {
                    case 1:
                        if(!utn_getName("\nIngrese el nombre: ", "\nError: Nombre invalido. Ingreselo nuevamente: ", 0, 128, 2, bufferChar))
                        {
                            employee_setNombre(pAux, bufferChar);
                            retorno = 0;
                        }
                        break;
                    case 2:
                        if(!utn_getUnsignedInt("\nIngrese las horas trabajadas: ", "\nError: Horas invalidas. Ingreselo nuevamente: ", 0, 4, 0, 24, 2, &bufferInt))
                        {
                            employee_setHorasTrabajadas(pAux, bufferInt);
                            retorno = 0;
                        }
                        break;
                    case 3:
                        if(!utn_getUnsignedInt("\nIngrese el sueldo: ", "\nError: Sueldo invalido. Ingreselo nuevamente: ", 0, 100, 0, 1000000, 2, &bufferInt))
                        {
                            employee_setSueldo(pAux, bufferInt);
                            retorno = 0;
                        }
                        break;
                    case 4:
                        printf("Edicion cancelada\n");

                        break;
                    default:
                        printf("ERROR - Opcion invalida.");
                        break;
                    }
                }
            }
        }
        else
        {
            return retorno;
        }
    }
    if(!retorno)
    {
        printf("Empleado ingresado correctamente.");
    }
    return retorno;
}

* \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *//*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     int retorno = -1;
    int bufferInt;
    int indice;
    Employee* pAux = NULL;
    if(pArrayListEmployee != NULL)
    {
        if(!utn_getUnsignedInt("\nIngrese el ID: ", "\nError: ID invalida. Ingreselo nuevamente: ", 0, 5, 0, 24, 2, &bufferInt))
        {
            if(!controller_buscarId(pArrayListEmployee, bufferInt, &indice))
            {
                retorno = 0;
                pAux = ll_pop(pArrayListEmployee, indice);
                employee_delete(pAux);
                printf("Empleado eliminado correctamente.");
            }
        }
        else
        {
            return retorno;
        }
    }
    return retorno;

}
*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListBicicleta(LinkedList* pArrayListBicicleta)
{

    int retorno=-1;
    eBicicleta* lista;
    int id;
    char nombre[20];
    char tipo[15];
    int tiempo;


    if(pArrayListBicicleta==NULL)
    {

    printf("No hay bicicletas para listar\n");

    }else{

printf("ID          NOMBRE          TIPO   TIEMPO\n\n");
    retorno=0;
        for (int i=0;i<ll_len(pArrayListBicicleta);i++)
        {

        lista = ll_get(pArrayListBicicleta,i);

        bicicletaGetId(lista,&id);
        bicicletaGetNombre(lista,nombre);
        bicicletaGetTipo(lista,tipo);
        bicicletaGetTiempo(lista,&tiempo);

        printf("ID:%03d   %10s   %10s   %d \n",id,nombre,tipo,tiempo);

        }

    }
    return retorno;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBicicletas)
{
    int paso=0;
    eBicicleta* lista;
    FILE* pfile = fopen(path, "w");
    int id;
    char nombre[20];
    char tipo[15];
    int tiempo;
    int flag=0;



    if(path!=NULL && pArrayListBicicletas!=NULL)
    {

        for(int i=0;i<ll_len(pArrayListBicicletas);i++)
        {

            lista = ll_get(pArrayListBicicletas,i);
            bicicletaGetId(lista,&id);
            bicicletaGetNombre(lista,nombre);
            bicicletaGetTipo(lista,tipo);
            bicicletaGetTiempo(lista,&tiempo);

            if(!flag)
            {
                    fprintf(pfile,"%s,%s,%s,%s\n","id","nombre","tipo","tiempo");
                    flag=1;
            }

            fprintf(pfile,"%d,%s,%s,%d\n",id,nombre,tipo,tiempo);

        }
        paso=1;

    }
    fclose(pfile);



    return paso;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *//*
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int paso=-1;
    FILE* pFileBin;
    Employee* listaBin;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {

        pFileBin = fopen(path,"wb");

        for(int i=0;i>ll_len(pArrayListEmployee);i++)
        {
            listaBin = (Employee*) ll_get(pArrayListEmployee, i);

            fwrite(listaBin,sizeof(Employee),1,pFileBin);

        }

        fclose(pFileBin);
        ll_clear(pArrayListEmployee);
        paso=0;
        printf("FUNCIONA\n");
    }else
    {
        printf("No funciona\n");

    }
    system("pause");
    return paso;
}*/











