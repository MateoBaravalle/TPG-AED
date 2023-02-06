#ifndef _TpgAed
#define _TpgAed

void menu(int &op)
{
	int yCord=0;
	
	while(op!=1)
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
			case 1:  //Enter
				switch(yCord)
				{
					case 0:
						op=0;
						break;
					case 1:
						op=1;
						break;
					case 2:
						op=2;
						break;
					case 4:
						op=4;
						break;
				}
				break;
		}
	}
}

void coach(int &op)
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
		printf("      |    IniciarSesion    |\n");
		printf("      |    Rutina/Socio     |\n");
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
						//inicioSesion();
						break;
					case 1:
						//Rutina_Soc();
						break;
					case 4:
						op=1;
						break;
				}
				break;
		}
	}	
}




#endif
