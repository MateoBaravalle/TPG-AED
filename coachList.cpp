#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct turnos
{
	int	horario; --> //Mañana (0) - Tarde (1)
	int actividad; --> // Actividades (0-3)
	int dni;
}

struct socios
{
    char apeynom[60];
    char dom[30];
    int dni;
    fecha fec;
    int edad;
    int peso;
    long long telefono;
    char rutina[RUTINA_MAXTAM];
    char ind[100];
};

void coachList();

main()
{

	coachlist();

}

ARCHIVOS --> Turnos.dat / Socios.dat

Turnos --> Lista de DNIs

0 - 1 //Mañana (0) - Tarde (1)

0, 1, 2, 3 // Actividades (0-3)

buscar DNIs que cumplan con horario y activ

guardar en vector DNIs int vector[30]

Socios --> Nombres correspondientes

socios aux vas trayendo datos - dni

printf(apeynom);

void coachList()
{

}

