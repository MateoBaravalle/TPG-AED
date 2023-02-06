#include <stdlib.h>
#include <stdio.h>
#include "rlutil.h"
#include <string.h>
#include <conio.h>

struct User{
	char user[10], pass[32], name[60];
};

int CheckUser(struct User u){
		int in=0;
		FILE *archUsers;
		archUsers = fopen("Users.dat","rb");
		User currentU; 
		if(archUsers==null){
			printf("Error: no se encuentra el archivo de usuarios.");
			in=1;
		}
		else{
			do{
				fread(&currentU, sizeof(u), 1, archUsers);
				if(u.user==currentU.name && u.pass==currentU.pass) int=1;
				else fseek(archUsers,sizeof(u),SEEK_CUR);
			}while(feof(archUsers)==0)
		}
		return in;		
}

void Login(int &in,int &yCord, struct User &u){
	int xCord=22;

	rlutil::locate(1,1);
	printf("  Subir(W)/Bajar(S)/Selec(Enter)\n");
	printf("       _____________________________\n");
	printf("      /===========GymStats==========\\\n");
	printf("      |                             |\n");
	printf("      |            Login            |\n");
	printf("      |              ____________   |\n");
	printf("      |  Usuario    |            |  |\n");
	printf("      |              ¯¯¯¯¯¯¯¯¯¯¯¯   |\n");
	printf("      |              ____________   |\n");
	printf("      |  Contraseña |            |  |\n");
	printf("      |              ¯¯¯¯¯¯¯¯¯¯¯¯   |\n");
	printf("      |                             |\n");
	printf("      |            Salir            |\n");
	printf("      \\_____________________________/\n");

// Ubicacion del Puntero
	rlutil::locate(xCord,7+yCord);
	printf("%c\n\n",95);	
	rlutil::hidecursor();
	int key = rlutil::getkey();
	
	switch(key)
	{
		case 119: //Arriba
			if(yCord!=0) yCord=yCord-3;
			break;	
		case 115: //Abajo
			if(yCord!=6) yCord=yCord+3;
			break;
		case 1:
			switch(yCord)
			{
				case 0:
					gets(u.user);
					yCord=3;
					break;
				case 3:
					gets(u.pass);
					CheckUser(u);
					break;
				case 6:
					op=1;
					break;
			}
			break;
	}
}

main(){
	int in=0, i=0, yCord=0;
	char caracter;
	User u;
	do{
		in = Login(in,yCord,u);
	}while(in !=1);
	if(in==0) printf("\n\nUsuario o contraseña incorrectos.");
	else Menu();
}
