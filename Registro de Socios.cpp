#include <stdlib.h>
#include <stdio.h>
#include "rlutil.h"
#include <string.h>

/* MODULO RECEPCIÓN
Esta parte del proyecto esta dirigida al personal de atención al público, que atiende y registran los socios
del gimnasio, en una base de datos. Cada socios puede participar de 1 o más actividades, (Zumba,
Spining, y pilate), cada actividad tiene asignado un entrenador por turno, dicho entrenador puede tener
más de un horario disponible como así también puede brindar entrenamiento en distintas actividades.
Cada socio se identifica con un numero de socio y de igual forma cada entrenador se identifica con un
Legajo de Entrenador.
El sistema deberá contar con:

a) Registro de socio. Para cada Socio se deberá registrar Nombre, Apellido DNI, Edad, peso,
Indicaciones médicas (Donde es posible registrar si el socio esta restringido para alguna
actividad), Altura Peso, Dirección, Teléfono, Fecha de ingreso.

b) Registro de actividad. Una vez registrado el socio, este podrá inscribirse en distintas actividades
pudiendo elegir el horario y entrenador.
c) listado de participantes, de una actividad determinada, por horario y entrenador.
d) Listado de fecha de pago. La cual estará relacionada con la fecha de ingreso.
Además se tiene la opción de registrar por cada socio una rutina indicada por el entrenador en un texto
no mayor a 380 palabras, para esto cada operador deberá identificarse en el sistema con un nombre de
usuario y contraseña.*/

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct socios
{
	char apeynom[60];
	char dom[20];
	int dni;
	fecha fec;
	int edad;
	int peso;
	int telefono;
	char rutina; //corregir - completar
	char ind[100];
};

main ()
{
	socios reg;
	
	printf("=============================================\n");
	printf("=            REGISTRO DE SOCIOS             =\n");
	printf("=============================================\n");
	printf("                                           \n");
	printf("= NOMBRE Y APELLIDO :\n");
	printf("= DOMICILIO:\n");
	printf("= DNI:\n");
	printf("= --FECHA DE INICIO--\n");
	printf("= * DIA:\n");
	printf("= * MES:\n");
	printf("= * ANIO:\n");
	printf("= EDAD:\n");
	printf("= PESO:\n");
	printf("= TELEFONO:\n");
	printf("= RUTINA DEL ENTRENADOR:\n"); //rutina no mayor a 380 palabras - completar
	printf("= INDICACIONES MEDICAS:\n");
	printf("                                           \n");
	printf("=============================================\n");
	
	rlutil::locate(22,5);
	gets(reg.apeynom);
	_flushall();
	rlutil::locate(13,6);
	gets(reg.dom);
	_flushall();
	rlutil::locate(7,7);
	scanf("%d",&reg.dni);
	rlutil::locate(9,9);
	scanf("%d",&reg.fec.dia);
	rlutil::locate(9,10);
	scanf("%d",&reg.fec.mes);
	rlutil::locate(10,11);
	scanf("%d",&reg.fec.anio);
	rlutil::locate(8,12);
	scanf("%d",&reg.edad);
	rlutil::locate(8,13);
	scanf("%d",&reg.peso);
	rlutil::locate(12,14);
	scanf("%d",&reg.telefono);
	rlutil::locate(11,15);
	gets(reg.ind);
	_flushall();
	
	system("PAUSE");
	return 0;
}

