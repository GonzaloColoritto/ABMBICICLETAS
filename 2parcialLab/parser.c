#include <stdio.h>
#include <stdlib.h>
#include "ll_list.h"
#include "bicicleta.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE *pFile, LinkedList *pArrayList) {

	eBicicleta* bicicleta;

	char id[100];
	char nombreDuenio[128];
	char tipo[100];
	char tiempo[100];

	int todoOk = 0;
	int flag = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (flag) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombreDuenio,tipo,tiempo);

				flag = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombreDuenio,tipo,tiempo);

			bicicleta = bicicleta_newParametros(id, nombreDuenio, tipo,tiempo);



			if (bicicleta != NULL) {
				ll_add(pArrayList, bicicleta);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}


