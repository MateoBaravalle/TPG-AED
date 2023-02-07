#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rlutil.h"

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


void RegistrarSocios();

 main()
 {
 	RegistrarSocios();
 	return 0;
 }
 
 void RegistrarSocios()
 {
	int dnibuscar;
 	
	FILE *arch;
 	
	arch=fopen("Socios.dat","a+b");
 	
	rlutil::cls();
	printf("=============================================\n");
	printf("=     ****   REGISTRO DE SOCIOS   ****      =\n");
	printf("=============================================\n");
	printf("=                                           =\n");
	printf("= INGRESE DNI -->                           =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	rlutil::locate(19,5);
	scanf("%d",&dnibuscar);
	
	socios aux;
	
	bool found = false;
	fread(&aux,sizeof(aux),1,arch);
	
	while(!feof(arch))
	{
		printf("ARCH %d -- IN %d",aux.dni,dnibuscar);
		getch();
    	if (dnibuscar == aux.dni)
		{
			rlutil::cls();
			
			printf("=============================================\n");
			printf("=            SOCIO REGISTRADO               =\n");
			printf("=============================================\n");
			printf("= NOMBRE Y APELLIDO : %s\n",aux.apeynom);	
			printf("= DOMICILIO: %s\n",aux.dom);
			printf("= --FECHA DE INICIO--\n");
			printf("= * DIA: %d\n",aux.fec.dia);
			printf("= * MES: %d\n",aux.fec.mes);
			printf("= * ANIO: %d\n",aux.fec.anio);
			printf("= EDAD: %d\n",aux.edad);
			printf("= PESO: %d\n",aux.peso);
			printf("= TELEFONO:%d\n",aux.telefono);
			printf("= RUTINA DEL ENTRENADOR:%s\n",aux.rutina);
			printf("= --INDICACIONES MEDICAS--\n");
			printf("  > %s\n",aux.ind);
			printf("=============================================\n");
			getch();
			
            found = true;
            break;
        }
        fread(&aux,sizeof(socios),1,arch);
	}

	if (!found) 
	{  
		rlutil::cls();
		
		system("cls");
		printf("=============================================\n");
		printf("=       ***  REGISTRO DE SOCIOS  ***        =\n");
		printf("=============================================\n");
		printf("                                            =\n");
		printf("= NOMBRE Y APELLIDO :\n");
		printf("= DOMICILIO:\n");
		printf("= --FECHA DE INICIO--\n");
		printf("= * DIA:\n");
		printf("= * MES:\n");
		printf("= * ANIO:\n");
		printf("= EDAD:\n");
		printf("= PESO:\n");
		printf("= TELEFONO:\n");
		printf("= RUTINA DEL ENTRENADOR:\n");
		printf("= --INDICACIONES MEDICAS--\n");
		printf("  >\n\n");
		printf("=============================================\n");
		
		
		rlutil::locate(22,5); 
		scanf("%s",aux.apeynom);
		fflush(stdin);
		rlutil::locate(13,6);
		scanf("%s",aux.dom);
		fflush(stdin);
		rlutil::locate(9,8);
		scanf("%d",&aux.fec.dia);
		rlutil::locate(9,9);
		scanf("%d",&aux.fec.mes);
		rlutil::locate(10,10);
		scanf("%d",&aux.fec.anio);
		rlutil::locate(8,11);
		scanf("%d",&aux.edad);
		rlutil::locate(8,12);
		scanf("%d",&aux.peso);
		rlutil::locate(12,13);
		scanf("%d",&aux.telefono);
		rlutil::locate(4,16);
		scanf("%s",aux.ind);
		fflush(stdin);
		
		fseek(arch,sizeof(socios),SEEK_END);
		fwrite(&aux,sizeof(socios),1,arch);
    }

	fclose(arch);
 }
