#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Fechadepago()
{
	FILE *arch;
	arch = fopen ("Socios.dat","rb");
	if (arch == NULL)
	{
 		printf ("no se pudo abrir el archivo");
	}
	else
	{
		printf ("ingrese un numero de dni: ");
		
		fread(&dni, sizeof(int), 1, arch);
  	 	
		printf("La fecha de ingreso fue: %d/%d/%d ", &reg.fec.dia,&reg.fec.mes, &reg.fec.anio );
		
		fclose(arch)
	}
}


