#include <stdlib.h>
#include <stdio.h>
#include "rlutil.h"

void menu(int &op,int &yCord);

main()
{
	
	
	int opc=0,yCord=0;
	
	do
	{
		menu(opc,yCord);
		
	}while(opc !=1);

}

void menu(int &op,int &yCord)
{

	rlutil::locate(1,1);
	printf("  Subir(W)/Bajar(S)/Selec(Enter)\n");
	printf("       _____________________\n");
	printf("      /=======GymStats======\\\n");
	printf("      |                     |\n");
	printf("      |   Tipo de Usuario   |\n");
	printf("      |                     |\n");
	printf("      |        Coach        |\n");
	printf("      |      Recepcion      |\n");
	printf("      |        Admin        |\n");
	printf("      |                     |\n");
	printf("      |        Salir        |\n");
	printf("      \\____________________/\n");

// Ubicacion del Puntero
	rlutil::locate(13,7+yCord);
	printf("%c\n\n",175);
	rlutil::locate(23,7+yCord);
	printf("%c\n\n",174);
	
	rlutil::hidecursor();

	int key = rlutil::getkey();
	
	switch(key)
	{
		case 119: //Arriba
			
			if(yCord!=0)
				if(yCord>2)
					yCord-=2;
				else
					yCord--;
			
			break;	
		case 115: //Abajo
			
			if(yCord!=4)
				if(yCord!=2)
					yCord++;
				else
					yCord+=2;
			
			break;
		case 1:
			switch(yCord)
			{
				case 0:
					//recepcion();
					break;
				case 1:
					//administracion();
					break;
				case 2:
					//entrenadores();
					break;
				case 4:
					op=1;
					break;
			}
			break;
	}
	
	/* INGRESO MANUAL CON VALIDACION
	rlutil::locate(30,8);
	printf("Opcion: ");	
	if(scanf("%d",&op)!=1)
	{
		_flushall();
		rlutil::locate(25,10);
		printf("Entrada invalida!!");
		rlutil::locate(18,11);
		printf("Por favor ingrese un Numero valido %c",175);
		op = 1;
		getch();
	}
	*/
}
