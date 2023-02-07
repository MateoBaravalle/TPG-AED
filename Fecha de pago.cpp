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
	
	bool b=false;
	
	socios aux;
	socios aux2;
	
	if (arch == NULL)
	{
		
 		printf ("no se pudo abrir el archivo");
 		
	}
	else
	{
		
		checkpoint:
		
		printf ("ingrese un dia:  ");
		scanf ("%d", &aux2.fec.dia);
		
		if (aux2.fec.dia <= 31 && aux2.fec.dia != 0)
		{
		
			printf ("ingrese un mes:  ");
			scanf ("%d", &aux2.fec.mes);
			
			if(aux2.fec.mes <= 12 && aux2.fec.mes != 0)
			{
			
				printf ("ingrese un anio: ");
				scanf ("%d", &aux2.fec.anio);
			
			}else
			{
			
				printf("no pa no seas tonto, vamos denuevo\n\n\n\n");
				system("pause");
				system("cls");
				goto checkpoint;
				
			}
			
		}else
		{
			
			printf("no pa no seas tonto, vamos denuevo\n\n\n\n");
			system("pause");
			system("cls");
			goto checkpoint;
			
		}
		
		printf("\n\n\n\nla fecha ingresada es: %d/%d/%d\n", aux2.fec.dia, aux2.fec.mes, aux2.fec.anio);
		
		while(fread(&aux, sizeof(aux), 1, arch))
		{
			
			if(aux2.fec.anio >= aux.fec.anio)
			{
				
				if (aux2.fec.mes > aux.fec.mes)
				{
					
					if(aux2.fec.dia > aux.fec.dia)
					{
						
						printf("\n=> el gil de mierda que debe es: %d,", aux.dni);
						printf(" y debe desde: %d/%d/%d ", aux.fec.dia, aux.fec.mes, aux.fec.anio);
						
						
						b=true;
				
					}
					
				}
					
			}
			
		}
		
		if(!b)
		{
		
			printf("\n=> no se encontraron coincidencias");
			
		}
		
	}
	
	fclose(arch);
	
}

main()
{
	
	Fechadepago();
	printf("\n");
	return 0;
	
}
