#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_SOCIOS 100

struct Socio 
{
    int dni;
    char actividad[50];
    char horario[50];
};

struct Socio socios[MAX_SOCIOS];
int numSocios = 0;

int iniciarSesion() 
{
    char usuario[50];
    char contrasena[50];
    
    printf("\t\t*************INICIO DE SESION**************\n");
    printf("\t\t-> Introduce el nombre de usuario: ");
    scanf("%s", usuario);

    printf("\n\t\t-> Introduce la contraseña: ");
    scanf("%s", contrasena);

    if (strcmp(usuario, "coach") == 0 && strcmp(contrasena, "1234") == 0) 
	{
        printf("\n\t\tIniciando sesion como coach\n");
        getch();
        system("cls");
        return 1;
    } else {
        printf("\n\t\tUsuario o contraseña incorrectos");
        getch();
        system("cls");   
        return 0;     
    }
}

void verListado() 
{
    printf("Listado de socios:\n");
    for (int i = 0; i < numSocios; i++) 
	{
        printf("DNI: %d\n", socios[i].dni);
        printf("Actividad: %s\n", socios[i].actividad);
        printf("Horario: %s\n", socios[i].horario);
    }
    getch();
}

void registrarRutina() 
{
    if (numSocios == MAX_SOCIOS)
	{
        printf("No se pueden registrar más socios, el límite es %d\n", MAX_SOCIOS);
        return;
    }

    int dni;
    char actividad[50];
    char horario[50];

    printf("Introduce el DNI del socio: ");
    scanf("%d", &dni);

    printf("Introduce la actividad que desarrolla: ");
    scanf("%s", actividad);

    printf("Introduce el horario: ");
    scanf("%s", horario);

    socios[numSocios].dni = dni;
    sprintf(socios[numSocios].actividad, "%s", actividad);
    sprintf(socios[numSocios].horario, "%s", horario);
    numSocios++;

    printf("Rutina registrada con exito\n");	
    getch();
    system("cls");
}

void eliminarRutina() 
{
    int dni;
    int encontrado = 0;

    printf("Introduce el DNI del socio cuya rutina deseas eliminar: ");
    scanf("%d", &dni);

    for (int i = 0; i < numSocios; i++) 
	{
        if (socios[i].dni == dni) 
		{
            encontrado = 1;
            for (int j = i; j < numSocios - 1; j++) 
			{
                socios[j].dni = socios[j + 1].dni;
                sprintf(socios[j].actividad, "%s", socios[j + 1].actividad);
                sprintf(socios[j].horario, "%s", socios[j + 1].horario);
            }
            numSocios--;
            break;
        }
    }

    if (encontrado) 
	{
        printf("Rutina eliminada con exito\n");
    } else {
        printf("No se encontró ninguna rutina con ese DNI\n");
    }
}


int main(int argc, char *argv[]) 
{
    int opcion;
    int sesionIniciada = 0;

    while (!sesionIniciada) {
        sesionIniciada = iniciarSesion();
    }

    do {
        printf("\t\t***********MENU*************\n");
        printf("\t\t1. Ver listado de socios\n");
        printf("\t\t2. Registrar rutina\n");
        printf("\t\t3. Eliminar rutina\n ");
        printf("\t\t4. Salir\n");
        printf("\t\tIntroduce una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion) {
        case 1:
            verListado();
            break;
        case 2:
            registrarRutina();
            break;
        case 3:
        	eliminarRutina();
            break;
        case 4:
            break;
        default:
            printf("***Opción inválida***\n");
            break;
        }
    } while (opcion != 4);

    return 0;
}
