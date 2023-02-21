#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rlutil.h"

void coachSubmenu(int &op)
{
	int yCord=0;

	while(op !=1)
	{
		rlutil::locate(1,1);
		printf("  Subir(W)/Bajar(S)/Selec(Enter)\n");
		printf("       _____________________\n");
		printf("      /=======GymStats======\\\n");
		printf("      |                     |\n");
		printf("      |        Coach        |\n");
		printf("      |                     |\n");
		printf("      |       Rutinas       |\n");
		printf("      |        Lista	    |\n");
		printf("      |                     |\n");
		printf("      |                     |\n");
		printf("      |        Atras        |\n");
		printf("      \\____________________/\n");
		
		// Ubicacion del Puntero
		rlutil::locate(9,7+yCord);
		printf("%c\n\n",175);
		rlutil::locate(27,7+yCord);
		printf("%c\n\n",174);
		
		rlutil::hidecursor();
	
		int key = rlutil::getkey();
		
		switch(key)
		{
			case 119: //Arriba
				
				if(yCord!=0)
					if(yCord>1)
						yCord-=3;
					else
						yCord--;
				
				break;	
			case 115: //Abajo
				
				if(yCord!=4)
					if(yCord!=1)
						yCord++;
					else
						yCord+=3;
				
				break;
			case 1:
				switch(yCord)
				{
					case 0:
						//visorRutinas();
						break;
					case 1:
						//coachlist();
						break;
					case 4:
						op=1;
						break;
				}
				break;
		}
	}	
}

int main() 
{
	int opcion = 0;
	coachSubmenu(opcion);
}
