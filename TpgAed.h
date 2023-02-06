#ifndef _TpgAed
#define _TpgAed

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

visorRutina()
{
    struct socios s;
    int dni, opcion;
    FILE *archivo;

    printf("Ingrese el DNI: ");
    scanf("%d", &dni);

    archivo = fopen("socios.dat", "r+b");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    while (fread(&s, sizeof(struct socios), 1, archivo))
    {
        if (s.dni == dni)
        {
            printf("Rutina: %s\n", s.rutina);
            printf("Presione E para editar o ESC para salir\n");
            opcion = getch();
            if (opcion == 'E')
            {
                printf("Ingrese la nueva rutina: ");
                scanf("%s", s.rutina);
                fseek(archivo, -sizeof(struct socios), SEEK_CUR);
                fwrite(&s, sizeof(struct socios), 1, archivo);
            }
            else if (opcion == 27) // Valor de ESC en ASCII
            {
                break;
            }
        }
    }

    fclose(archivo);
}




#endif
