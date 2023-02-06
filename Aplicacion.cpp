#include <stdlib.h>
#include <stdio.h>
#include "rlutil.h"
#include "TpgAed.h"


main()
{
	int op1=0, op2=0, op3=0, op4=0;
	
	while(op1!=4)
	{
		menu(op1);
	
		switch(op1)
		{
			case 0:
				
				while(op2!=4)
				{
					coach(op2);
				
					switch(op2)
					{
						case 0: // No se logeo aun
							
							while(op3!=2)
							{
								login(op3);
								
								switch(op3)
								{
									//OPCIONES
									case 0: //usuario existente
										
										while(op4!=4)
										{
											coachSubmenu(op4);
											
											switch(op4)
											{
												case 0:
													
													visorRutina();
													break;
												
												case 1:
													
													coachList();
													break;
														
												case 4:
													break;
											}	
										}
										op4 = 0;
										
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
						
						case 1: // visor de Turnos notLogin
							
							while(op3!=4)
							{
								coachList(op3);	
							}
							
							break;
						
						case 2: //Usuario logeado
							
							while(op4!=4)
							{
								coachSubmenu(op4);
								
								switch(op4)
								{
									case 0:
										
										visorRutina(); //visor de Rutina
										break;
									
									case 1:
										
										coachList(); // Visor de Turnos
										break;
											
									case 4:
										break;
								}	
							}
							
						case 4: //Atras
							break;
					}
				}
				op2 = 0;
				
				break;
			case 1:
					
				while(op!=4)
				{
					recep(op);
				
					switch(op)
					{
						case 0:
						//	login();
							break;
						case 1:
						//	coachList();
							break;
						case 4:
							break;
					}
				}
				break;
			case 2:
					
				while(op!=4)
				{
					//admin(op);
					op=4;
					switch(op)
					{
						case 0:
						//	login();
							break;
						case 1:
						//	coachList();
							break;
						case 4:
							break;
					}
				}
				break;
			case 4:
				
				break;
		}
	}
	
	printf("AGRADECIMIENTO / INTEGRANTES");
	
}

