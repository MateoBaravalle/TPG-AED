#include "rlutil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


struct usuario
{
    int id; 
    int dni;
	char userName[15];
    char password[35];
};

void systemBlock();
void login(int &opc,int cod);

main()
{
	int op2 = 0;
	int op3=0;
	
	while(op3!=2) 
	{
		if(op3 != 1)
			login(op3,0);
		
		switch(op3)
		{
			//OPCIONES
			case 0: //usuario valido
				
				op2=2;
				op3=2;
		
				break;
			
			case 1: //Maximo de intentos
				
				systemBlock();
				break;
			
			case 2: //Atras
				break;
		}
		
	}
	rlutil::locate(1,16);
	printf("\nOpcion Devuelta --> %d - op2 %d",op3,op2);
	
	return 0;	
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
		printf("      |  Contraseņa |                              | |\n");
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
	    
	    //Contraseņa	    
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
	        		printf("Contraseņa Incorrecta!!");
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

void systemBlock()
{
	system("cls");
	printf ("Maximo de intentos alcanzados\n");
	printf ("El sistema esta bloqueado, preciones ESC para salir");
	
	int key = 0;
	
	do
	{
		key = rlutil::getkey();
		
	}while (key != 0);
	
	exit(1);
}
