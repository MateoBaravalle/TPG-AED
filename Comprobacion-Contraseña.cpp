#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

bool VerificarPassword (char p[32]);

main()
{
	char clave[32];
	bool comprobacion;
	char caracter;
	int i = 0;
	
	printf("\t\tIngrese contraseña ----> ");
/*	while(caracter = getch())
	{
		if(caracter == 13){
			break;
		}else{							//CONTRASEÑA CON ASTERISCOS
		printf("*");
		clave[i] = caracter;
		i++;
		} 

	}
*/
	scanf("%s", clave);
	
	comprobacion = VerificarPassword(clave);
	
	if(comprobacion)
	{
		printf("\n\t\t***La password ingresada es correcta***");
	} else{
		printf("\n\t\t***La password ingresada es incorrecta***");
	}
	
	return 0;
}

bool VerificarPassword (char p[32])
{
	bool tamano = false;
	bool minuscula = false;
	bool mayuscula = false;
	bool numero = false;
	int tam = strlen(p);
	int cnum = 0;
	int coderror = 0;
	
	if(tam >= 6 && tam <= 32)
	{
		tamano = true;
	}
	
	for(int i=0; i < 32; i++)
	{
		if(p[i] >= 65 && p[i] <= 90)
		{
			mayuscula = true;
			cnum = 0;
		}

		else if(p[i] >= 97 && p[i] <= 122)
		{
			minuscula = true;
			cnum = 0;
		}

		else if(p[i] >= 48 && p[i] <= 57)
		{
			numero = true;
			cnum++;
		}
		
	}
	if(cnum > 3)
	{
		numero = false;
	}
	
	if(mayuscula && minuscula && tamano && numero)
	{
		return true;
	}
	else{
		return false;
	}
}

