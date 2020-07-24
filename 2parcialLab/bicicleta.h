#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{

int id_bike;
char nombreDuenio[20];
char tipoBici[10];
int tiempo;

}eBicicleta;

int bicicletaGetId(eBicicleta* bicicleta,int* id);
int bicicletaGetNombre(eBicicleta* bicicleta, char nombre[20]);
int bicicletaGetTipo(eBicicleta* bicicleta, char tipo[15]);
int bicicletaGetTiempo(eBicicleta* bicicleta, int* tiempo);
eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr);
int bicicleta_setTiempo(eBicicleta* this,int tiempoCarrera);
int bicicleta_setTipo(eBicicleta* this,char* tipo);
eBicicleta* bicicleta_new();
int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_setNombre(eBicicleta* this,char* nombre);


#endif // BICICLETA_H_INCLUDED
