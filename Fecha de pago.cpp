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
	
	int dia, mes, anio;
	
	if (arch == NULL)
	{
		
 		printf ("no se pudo abrir el archivo");
 		
	}
	else
	{
		
		checkpoint:
		
		printf ("ingrese un dia:  ");
		scanf ("%d", &dia);
		
		if (dia <= 31 && dia != 0)
		{
		
			printf ("ingrese un mes:  ");
			scanf ("%d", &mes);
			
			if(mes <= 12 && mes != 0)
			{
			
				printf ("ingrese un anio: ");
				scanf ("%d", &anio);
			
			}else
			{
			
				printf("Fecha no valida, ingrese denuevo\n\n\n\n");
			
				system("pause");
			
				system("cls");
	
				goto checkpoint;
				
			}
			
		}else
		{
			
			printf("Fecha no valida, ingrese denuevo\n\n\n\n");
			
			system("pause");
			
			system("cls");
			
			goto checkpoint;
			
		}
		
		printf("\n\n\n\nLa fecha ingresada es: %d/%d/%d\n", dia,mes,anio);
		
		while(fread(&aux, sizeof(aux), 1, arch))
		{
			
			if(anio > aux.fec.anio)
			{
				
				b=true;
				
				if (mes > aux.fec.mes)
				{
					
					b=true;
					
					if(dia > aux.fec.dia)
					{
					
						b=true;
				
					}else
					{
						
						b=false;
						1
					}
					
				}else
				{
					
					b=false;
					
				}
					
			}else
			{
				
				b=false;
				
			}
		
			if(b)
			{
		
				printf("\n=> El Socio que debe es: %d,", aux.dni);
				printf(" y debe desde: %d/%d/%d ", aux.fec.dia, aux.fec.mes, aux.fec.anio);
				
			}
			
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
