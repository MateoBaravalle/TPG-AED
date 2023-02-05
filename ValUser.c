/*
Cátedra: Algoritmos y Estructuras de Datos
GESTIÓN Y AUTENTICACIÓN DE USUARIOS
Nombre de usuario:
Quedará definido por una cantidad mínima de 6 caracteres y máxima de 10,
los cuales podrán ser
letras, números y/o símbolos del conjunto (+, -, /,*,?,¿,!,i). 
Deberá cumplir con los siguientes
requisitos:
a) Ser único para cada usuario registrado.
b) Comenzar con una letra minúscula.
c) Tener al menos 2 letras mayúsculas.
d) Tener como máximo 3 dígitos 
 
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int band=0;
	int x;
	int mayus=0;
    int num=0;	
	printf("\nGESTION Y AUNTENTICACION DE USUARIOS");
	
	printf("\ncantidad mínima de 6 caracteres y máxima de 10");
	printf("\nlos cuales podrán ser: ");
	printf("\nletras, números y/o símbolos del conjunto (+, -, /,*,?,¿,!,i).");
    printf("\nDeberá cumplir con los siguientes");
    printf("\nrequisitos:");
    printf("\na) Ser único para cada usuario registrado.");
    printf("\nb) Comenzar con una letra minúscula.");
    printf("\nc) Tener al menos 2 letras mayúsculas.");
    printf("\nd) Tener como máximo 3 dígitos ");
usuario:
printf("\n\n\n\n\n\n");
	printf("\n\ningrese su nombre de usuario: ");
	char CAD1[11];
	scanf("%s",CAD1);
	printf("%s ",CAD1);
	
	
	//LONGITUD
	puts(CAD1);
	int longitud;
	longitud=strlen(CAD1);
	
	
	
	//BUCLE ERROR
	
		
		//VALIDACION DE LONGITUD
        if (longitud<6 || longitud>10){
	    printf("\nERROR. la longitud debe ser entre 6 y 10 caracteres");
	    band=1;
	    }
        else {
			band=0;
	    
        }
        
        
        
        	//VALIDACIION CARACETERES(+, -, /,*,?,¿,!,i)
	        for(int i =0;i<longitud;i++){	
		    x=CAD1[i];
	     	if (x==43 || x==45 || x==47 || x==42 || x==63 || x==168 || x==33 ||x==173){
			band=0;
            }else{
				if(CAD1[i]>= 'a' && CAD1[i]<= 'z'){
					band=0;
					}
					else{ if (CAD1[i]>= 'A' && CAD1[i]<= 'Z'){
		                               mayus=mayus+1;
		                              
	        }else{
				 if (x>= 48 && x<= 57){
		    num=num+1;
	        }
	        else{
	    	band=1;
            printf("\nERROR. el usuario contiene un simbolo no permitido");
            }
            }
		}
	}
}
            
            
            
            
		
            
            
            
         //VALIDACION PRIMER LETRA MINUSCULA
	     if (CAD1[0]>= 'a' && CAD1[0]<= 'z')
         band=0;
         else{
		 printf("\nERROR. la primera letra no es minuscula");
		 band=1;
	     }
	
	
	
	
	
	//VALIDACION DE MAYUSCULAS
    if(mayus<2){
	band=1;
	mayus=0;
	printf("\nERROR. necesitas al menos 2 letras mayusculas");
    }   
    
    
    
    //VALIDACION DE MAXIMO 3 DIGITOS
    if(num>3){
		 
	band=1;
	printf("\nERROR. como maximo son 3 digitos");
	printf("\nERROR. como maximo son 3 digitos Y vos tenes %d ",num);
	 num=0;	
    }   


		
		
		
	if(band==1) {
		
		band=0;
     	
       
		goto usuario;
	}
	
	
	
	
	
	
	
	return 0;
	
	
	
	
}

