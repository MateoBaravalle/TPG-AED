#ifndef _TpgAed
#define _TpgAed

const int RUTINA_MAXTAM = 3800;

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct socios
{
    char apeynom[60];
    char dom[30];
    int dni;
    fecha fec;
    int edad;
    int peso;
    long long telefono;
    char rutina[RUTINA_MAXTAM];
    char ind[100];
};

struct usuario
{
    int id; //Tipo de Usuario
    int dni;
	char userName[15];
    char password[35];
};

bool validUser(char u[15])
{
// Verificar largo del nombre de usuario
	int largo = strlen(u);
	
	if (largo < 6 || largo > 10)
	{
		printf("Debe tener entre 6 y 10 caracteres!");
		return false;
	}
	
// Verificar primer caracter es letra minúscula
	if (!islower(u[0]))
	{
		printf("El 1er Caracter debe ser minuscula!");
		return false;
	}

// Contar letras mayúsculas y dígitos
	int mayusculas = 0;
	int digitos = 0;
	for (int i = 0; i < largo; i++)
	{
		if (isupper(u[i]))
		{
			mayusculas++;
		}
		else if (isdigit(u[i]))
		{
			digitos++;
		}
		else if (!islower(u[i]) && strchr("+-/*?¿!i", u[i]) == NULL)
		{
			printf("Fuera de \"+-/*?¿!i\" no se permiten Simbolos!");
			return false;
		}
	}

// Verificar cantidad de letras mayúsculas y dígitos
	if (mayusculas<2 || digitos>3) 
	{
		return false;
	}

// El nombre de usuario es válido
	return true;
}

bool validPasw(char p[15])
{
// Verificar largo del nombre de usuario
	int largo = strlen(p);
	
	if (largo < 6 || largo > 32)
	{
		printf("Debe tener entre 6 y 32 caracteres!");
		return false;
	}
//Contador de numeros consecutivos
	int consec = 0;
	
	for(int i=0;i<largo && consec<=3;i++)
	{
		if(isdigit(p[i]))
		{
			consec++;	
		}
		else
		{
			consec = 0;	
		}
	}
	
	if(consec>3)
	{
		printf("No mas de 3 Nros consecutivos!",consec);
		return false;
	}

	bool mayus = false;
	bool minus = false;
	bool num = false;
	
	for(int i=0;i<largo;i++)
	{
		if(islower(p[i])) //minuscula
		{
			minus = true;
		}
		else if(isupper(p[i])) //mayuscula
		{
			mayus = true;	
		}
		else if(isdigit(p[i])) //numero
		{
			num = true;
			
		}
		else
		{
			printf("Solo caracteres alfanumericos!!");
			return false; //Caracter no alfanumerico
		}
	}
	
// Verificar que haya mayuscula, minuscula y numero

	if(!mayus || !minus || !num)
	{
		printf("Al menos una Mayuscula, minuscula y Numero!");
		return false;
	}
		

//Verificacion de letras consecutivas acendentemente

	for(int i=0; i<largo-1;i++)
	{
		if(isalpha(p[i]) && isalpha(p[i+1]))
		{
			if(p[i]-p[i+1]==-1 || p[i]-p[i+1]==31 || p[i]-p[i+1]==-33)
			{
				printf("Sin letras consecutvas en orden ascendente! (Ab)");
				return false;
			}
		}
	}
	
	return true;
}

void systemBlock()
{
	
	printf ("Maximo de intentos alcanzados\n");
	printf ("El sistema esta bloqueado, preciona ESC para salir");
	
	int key = 0;
	
	do
	{
		key = rlutil::getkey();
		
	}while (key != 0);
	
	exit(1);
}

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
	int enter = 0;
	
	while(enter !=1)
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
	
		enter = rlutil::getkey();
		
		switch(enter)
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

void coachSubmenu(int &op)
{
	int yCord=0;
	int enter = 0;

	while(enter !=1)
	{
		rlutil::locate(1,1);
		printf("  Subir(W)/Bajar(S)/Selec(Enter)\n");
		printf("       _____________________\n");
		printf("      /=======GymStats======\\\n");
		printf("      |                     |\n");
		printf("      |        Coach        |\n");
		printf("      |                     |\n");
		printf("      |        Rutina       |\n");
		printf("      |      Asistencia     |\n");
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
	
		enter = rlutil::getkey();
		
		switch(enter)
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
                        op = 0;
                        break;
                    case 1:
                        op = 1;
                        break;
                    case 4:
                        op = 4;
                        break;
				}
				break;
		}
	}	
}

void login(int &opc,int cod)
{	
	char usuario[15];
	char password[15];
	int intentos = 0;
	bool found = false;
 	
	FILE *arch;
 	
	arch=fopen("Usuarios.dat","rb");
	
	if (arch == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
 	
 	
	while(intentos<3)
	{
		
		rlutil::cls();
		rlutil::locate(1,1);
		
		printf("       _______________________________________________\n");
		printf("      /===================GymStats===================\\\n");
		printf("      |                                              |\n");
		printf("      |                    Login                     |\n");
		printf("      |                _____________                 |\n");
		printf("      |    Usuario    |             |                |\n");
		printf("      |                ¯¯¯¯¯¯¯¯¯¯¯¯¯                 |\n");
		printf("      |              ______________________________  |\n");
		printf("      |  Contraseña |                              | |\n");
		printf("      |              ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯  |\n");
		printf("      |                                              |\n");
		printf("      |                Volver (ESC)                  |\n");
		printf("      \\_____________________________________________/\n");
		rlutil::locate(1,15);
		printf("Intentos Restantes --> %d",3-intentos++);
		
		rlutil::locate(24,6);
		
		char c;
		int i=0;
		int z=0;
		
		//Usuario		
		while ((c = getch()) != 27 && i<11) 
		{
			if(c == 8)
			{
				if(i>0)
				{
					printf("\b  \b");
					i--;
				}
			}
			else
			{
				if (c == 13 || i==10)  
				{
		            usuario[i] = '\0'; 
		            break;            
		        }
		        else
		        {
		        	printf("%c",c);
				}
		        usuario[i] = c;        
		        i++;
			}
	    }
	    
	    //Si presiono ESC
	    if(c == 27)
	    {
	    	opc = 2;
	    	fclose(arch);
			return;	
		}
		
		fflush(stdin);
	    rlutil::locate(23,9);
	    
	    //Contraseña	    
		while ((c = getch()) != 27 && i<33) 
		{
			if(c == 8)
			{
				if(z>0)
				{
					printf("\b  \b");
					z--;
				}
			}
			else
			{
				if (c == '\r' || z==32)  
				{
		            password[z] = '\0'; 
		            break;            
		        }
		        else
		        {
		        	printf("%c",c);
				}
		        password[z] = c;        
		        z++;
			}
	    }
		
		//Si presiono ESC
		if(c == 27)
	    {
	    	opc = 2;
	    	fclose(arch);
			return;	
		}
		
		fflush(stdin);
		
		
		struct usuario user;
		
		fseek(arch,0,SEEK_SET);
		fread(&user,sizeof(user),1,arch);
		
		do
		{
			if (strcmp(usuario,user.userName) == 0)
			{	
				if(strcmp(password,user.password) == 0)
				{
					if(cod == user.id)
					{
						opc = 0;
						
						switch(user.id)
						{
							case 0:  //COACH
							{
								rlutil::locate(18,4);
								printf("Coach Logeado correctamente!!");
								sleep(2);
								
								break;
							}
							case 1: //RECEPCION
							{
								rlutil::locate(14,4);
								printf("Recepcion Logeado correctamente!!");
								sleep(2);
								
								break;
							}
							case 2: //ADMIN
							{
								rlutil::locate(18,4);
								printf("Admin Logeado correctamente!!");
								sleep(2);
								
								break;
							}
						}
					}
					else
					{
						rlutil::locate(21,4);
						printf("Usuario no Autorizado!!");
						sleep(2);
					}
				}
				else
				{
					rlutil::locate(18,4);
	        		printf("Contraseña Incorrecta!!");
	        		sleep(2);
				}
				
	            found = true;
				break;
	        }
	        
			
	        fread(&user,sizeof(usuario),1,arch);
	        
		}while(!feof(arch));
	
		if (!found) 
		{  
	    	rlutil::locate(18,4);
	    	printf("Usuario Inexistente!!");
	    	sleep(2);
		}
	}
	
	if(intentos==3)
	{
		system("cls");
		opc = 1;
	}
	
	fclose(arch);
}

void visorRutina()
{
    socios s;
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

    while (fread(&s, sizeof(s), 1, archivo))
    {
        if (s.dni == dni)
        {
            printf("Rutina: %s\n", s.rutina);
            printf("Presione E para editar o ESC para salir\n");
            
            
            while(1)
            {
            	opcion = rlutil::getkey();
            	fflush(stdin);
            	
            	if (opcion == 'e')
	            {
	            	char RutinaNueva[RUTINA_MAXTAM];
	                
					printf("Ingrese la nueva rutina: ");
	                fgets(RutinaNueva, RUTINA_MAXTAM, stdin);
	                RutinaNueva[strcspn(RutinaNueva, "\n")] = '\0';
	                
					if(strlen(RutinaNueva) <= RUTINA_MAXTAM)
	                {
	                	strncpy(s.rutina, RutinaNueva, RUTINA_MAXTAM);
	                	fseek(archivo, -sizeof(struct socios), SEEK_CUR);
	                	fwrite(&s, sizeof(struct socios), 1, archivo);
	                	printf("Rutina actualizada exitosamente\n");
	                	break;
					}
					else
					{
						printf("La rutina es demasiado larga. Debe ser menor o igual a %d caracteres\n",RUTINA_MAXTAM);
					}
	                
	            }
	            else if (opcion == 0) // Valor de ESC en ASCII
	            {
	                break;
	            }
			}
        }
    }

    fclose(archivo);
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
	
	fflush(stdin);
	
	fseek(arch,0,SEEK_SET);
	
	fread(&aux,sizeof(aux),1,arch);
	
	do
	{
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
			printf("= TELEFONO:%lld\n",aux.telefono);
			printf("= --INDICACIONES MEDICAS--\n");
			printf("  > %s\n",aux.ind);
			printf("=============================================\n");
			getch();
			
            found = true;
            break;
        }
        fread(&aux,sizeof(socios),1,arch);
        
	}while(!feof(arch));

	if (!found) 
	{  
		
		rlutil::cls();
		
		system("cls");
		printf("=============================================\n");
		printf("=       ***  REGISTRO DE SOCIOS  ***        =\n");
		printf("=============================================\n");
		printf(" *NO INSERTE ESPACIOS*                      =\n");
		printf("= NOMBRE Y APELLIDO :\n");
		printf("= DOMICILIO:\n");
		printf("= --FECHA DE INICIO--\n");
		printf("= * DIA:\n");
		printf("= * MES:\n");
		printf("= * ANIO:\n");
		printf("= EDAD:\n");
		printf("= PESO:\n");
		printf("= TELEFONO:\n");
		printf("= --INDICACIONES MEDICAS--\n");
		printf("  >\n\n");
		printf("=============================================\n");
		
		aux.dni = dnibuscar;
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
		scanf("%lld",&aux.telefono);
		rlutil::locate(4,15);
		scanf("%s",aux.ind);
		fflush(stdin);
		
		fseek(arch,sizeof(socios),SEEK_END);
		fwrite(&aux,sizeof(socios),1,arch);
    }

	fclose(arch);
}

void RegistrarUsuarios()
{
	usuario user;
	
	int dnibuscar;
	char id[15]; 
 	
	FILE *arch;
 	
	arch=fopen("Usuarios.dat","a+b");
 	
	rlutil::cls();
	printf("=============================================\n");
	printf("=     ****   REGISTRO DE USUARIO  ****      =\n");
	printf("=============================================\n");
	printf("=                                           =\n");
	printf("= INGRESE DNI -->                           =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	rlutil::locate(19,5);
	scanf("%d",&dnibuscar);
	
	
	bool found = false;
	
	fflush(stdin);
	
	fseek(arch,0,SEEK_SET);
	
	fread(&user,sizeof(user),1,arch);
	
	do
	{
		printf("%d -- %d\n",dnibuscar,user.dni);
    	
		if (dnibuscar == user.dni)
		{
			rlutil::cls();
			
			switch(user.id)
			{
				case 0:
					strcpy(id, "COACH");
					break;
				case 1:
					strcpy(id, "RECEPCION");
					break;
				case 2:
					strcpy(id, "ADMINISTRACION");
					break;
			}
			
			printf("=============================================\n");
			printf("=           USUARIO REGISTRADO               =\n");
			printf("=============================================\n");
			printf("= DNI : %d\n",user.dni);	
			printf("= USER ID: %d -- %s\n",user.id,id);
			printf("= NOMBRE DE USUARIO: %s\n",user.userName);
			printf("= CONTRASEÑA: %s\n",user.password);
			printf("=============================================\n");
			getch();
			
            found = true;
            break;
        }
        fread(&user,sizeof(usuario),1,arch);
        
	}while(!feof(arch));

	if (!found) 
	{  
		
		rlutil::cls();
		
		system("cls");
		printf("=============================================\n");
		printf("=      ***  REGISTRO DE USUARIO  ***        =\n");
		printf("=============================================\n");
		printf("= DNI :\n");
		printf("= USER ID :\n");
		printf("= NOMBRE DE USUARIO :\n\n");
		printf("= CONTRASEÑA :\n\n");
		printf("=============================================\n");
		
		user.dni = dnibuscar;
		rlutil::locate(8,4); 
		printf("%d",user.dni);
		rlutil::locate(12,5);
		scanf("%d",&user.id);
		rlutil::locate(22,6);
		scanf("%s",user.userName);
		fflush(stdin);
		while(!validUser(user.userName))
		{
			getch();
			rlutil::locate(1,7);
			for (int i = 1; i < rlutil::tcols(); i++)
			{
		        printf(" ");
		    }
			
			rlutil::locate(22,6);
			printf("            ");
			rlutil::locate(22,6);
			scanf("%s",user.userName);
			fflush(stdin);			
		}
		
		rlutil::locate(15,8);
		scanf("%s",user.password);
		fflush(stdin);
		while(!validPasw(user.password))
		{
			getch();
			rlutil::locate(1,9);
			for (int i = 1; i <= rlutil::tcols(); i++)
			{
		        printf(" ");
		    }
			rlutil::locate(15,8);
			printf("                                 ");
			rlutil::locate(15,8);
			fflush(stdin);	
			scanf("%s",user.password);
					
		}
		
		fseek(arch,sizeof(usuario),SEEK_END);
		fwrite(&user,sizeof(usuario),1,arch);
    }

	fclose(arch);
}


#endif
