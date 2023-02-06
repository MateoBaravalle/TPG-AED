#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    char rutina[3800];
    char ind[100];
};


void Fechadepago()
{
	FILE *arch;
	arch = fopen ("Socios.dat","rb");
	
	int dni;
	
	bool b=false;
	
	socios aux;
	
	if (arch == NULL)
	{
 		printf ("no se pudo abrir el archivo");
	}
	else
	{
		
		printf ("ingrese un numero de dni: ");
		scanf ("%d", &dni);
		
		while(fread(&aux, sizeof(aux), 1, arch))
		{
			if(dni == aux.dni)
			{
				printf("La fecha de ingreso fue: %d/%d/%d ", aux.fec.dia, aux.fec.mes, aux.fec.anio);
				
				b=true;
			}
		}
		
		if(!b)
		{
			printf("no se encontraron coincidencias");
		}
		
		fclose(arch);
	
	}
}

main()
{
	Fechadepago();
	
	return 0;
	
	
	
	
	
	
}


