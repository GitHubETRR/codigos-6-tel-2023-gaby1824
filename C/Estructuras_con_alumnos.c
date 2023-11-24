#include <stdio.h>
#define LIM 30  //las variables que tengan LIM van a tener un máximo de 30 caracteres
#define MAX_ALUMNOS 3  //Cantidad de alumnos que vamos a registrar

struct info_alumns {  //Definimos el esqueleto de la estructura
    char nombre[LIM];
    char apellido[LIM];
    char edad;
    int dni;
    char localidad[LIM];
}

alumnos[Max_alumnos];  //Cantidad de alumnos que voy a registrar

int main(void){
    for(unsigned char i=0;i<Max_alumnos;i++){
        printf("Alumnos N°%d", i+1);  //No es i++ porque me asigna 1 a i
        printf("\nIngrese el nombre del alumno:");
        scanf("%s",alumnos[i].nombre);
        printf("Ingrese el apellido del alumno:");
        scanf("%s",alumnos[i].apellido);
        printf("Ingrese la edad del alumno:");
        scanf("%s",&alumnos[i].edad);
        printf("Ingrese el dni del alumno:");
        scanf("%d",&alumnos[i].dni);
        printf("Ingrese la localidad del alumno:");
        scanf("%s",alumnos[i].localidad);        
    }
}
