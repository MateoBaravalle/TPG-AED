#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rlutil.h"


void systemBlock();

main()
{
	systemBlock();
	
}

void systemBlock()
{
	
	printf ("Maximo de intentos alcanzados\n");
	printf ("El sistema esta bloqueado, preciones ESC para salir");
	
	int key = 0;
	
	do
	{
		key = rlutil::getkey();
		
	}while (key != 0);
	
	exit(1);
	
	
}





