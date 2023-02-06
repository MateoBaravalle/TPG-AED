#include <stdlib.h>
#include <stdio.h>
#include "rlutil.h"
#include <string.h>

void RegistrarSocios();

 main()
 {
 	RegistrarSocios();
 }
 
 void RegistrarSocios()
 {
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
	
 	int dnibuscar;
 	FILE *arch;
 	arch=fopen("Socios.dat","a+b"); //creacion y apertura de archivo de socios 
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
	fseek(arch,sizeof(socios) ,SEEK_SET);
	fread(&aux,sizeof(socios),1,arch);	
	
	bool found = false;
    	while(!feof(arch)) {
        if (dnibuscar == aux.dni) {
            found = true;
            break;
        }
      }
    
     if (found) {
                
				printf("    ******  USUARIO EXISTENTE  ******    ");
				system("cls");
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
				printf("= PESO: %d\n"),aux.peso;
				printf("= TELEFONO:%d\n"),aux.telefono;
				printf("= RUTINA DEL ENTRENADOR:\n"); //rutina no mayor a 380 palabras - completar
				printf("= INDICACIONES MEDICAS: %s\n");
				printf("                                           \n");
	            printf("=============================================\n");
				getch();
				
    } else {
    	        
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
				printf("= RUTINA DEL ENTRENADOR:\n"); //rutina no mayor a 380 palabras - completar
				printf("= INDICACIONES MEDICAS:\n");
				printf("                                           \n");
				printf("=============================================\n");
				
			
				fwrite(&aux,sizeof(socios),1,arch);
				_flushall();
				rlutil::locate(21,5); 
				_flushall();
				gets(aux.apeynom);
				rlutil::locate(13,6);
				gets(aux.dom);
				_flushall();
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
				rlutil::locate(11,14);
				gets(aux.ind);
				_flushall();
				
				
    }
	 fclose(arch);
 }
