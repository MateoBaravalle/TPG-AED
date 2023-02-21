#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rlutil.h"
#include "TpgAed.h"



main()
{
	int op1=0, op2=0, op3=0, op4=0;
	
	do
	{
		menu(op1);
	
		switch(op1) //Depende de la pos Y del cursor
		{
			case 0: //COACH
			{
				do
				{
					if(op2 != 2)
						coach(op2);
				
					switch(op2)
					{
						case 0: // Login
						{
							while(op3!=2)
							{
								login(op3,0); // COACH
								
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
							op3 = 0;
							
							break;
						}	
						case 1: // visor de Turnos notLogin
						{
							//coachList();	
							printf("AQUI ESTA LA LISTA DE ASISTENCIAS!!");
							getch();
							break;
						}	
						case 2: //Usuario logeado
						{
							while(op4!=4)
							{
								coachSubmenu(op4);
								
								switch(op4)
								{
									case 0:
										
										visorRutina(); //visor de Rutina
										break;
									
									case 1:
										
										//coachList(); // Visor de Turnos
										printf("AQUI ESTA LA LISTA DE ASISTENCIAS!!");
										getch();
										break;
											
									case 4:
										break;
								}	
							}	
						}
						case 4: //Atras
							break;
					}
					
				}while(op2!=4);
				
				break;	
			}
		/*	case 1: //RECEPCION
			{
				int op2 = 0;
					
				while(op2!=4)
				{
					recep(op);
				
					switch(op)
					{
						case 0:
						
							login();
							break;
						
						case 1:
							
							regSoc();
							break;
						
						case 4:
							break;
					}
				}
				break;
			}
			case 2: //ADMINISTRACION
			{
				int op2 = 0;
				
				while(op2!=4)
				{
					
					op=4;
					switch(op)
					{
						case 0:
						login();
							break;
						case 4:
							break;
					}
				}
				break;
			}
		*/		
			
			case 4: //SALIR
				
				break;
		}
	}while(op1!=4);
	
	printf("AGRADECIMIENTO / INTEGRANTES");
	
	return 0;
}

