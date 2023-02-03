#include <stdlib.h>
#include <stdio.h>
#include "rlutil.h"

void menu(int &op);

main()
{
	
	int opc;
	
	do
	{
		menu(opc);
		
	}while(opc != 4);

}

void menu(int &op)
{
	//Aqui no usamos system("cls") ya que esta funcion no sirve en linux
	rlutil::cls();
	printf(" ____________________\n");
	printf("/========MENU========\\\n");
	printf("|                    |\n");
	printf("|       Opcion1      |\n");
	printf("|       Opcion       |\n");
	printf("|       Opcion3      |\n");
	printf("\\____________________/\n");
	rlutil::locate(8,4);
	printf("%c",175);
	op = rlutil::getkey();
	rlutil::locate(30,8);
	printf("Opcion --> %d",op);	
	getch();
	
	
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
