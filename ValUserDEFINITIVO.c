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
	FILE *arch;
	
	int band=0;
	int x,y=0;
	int mayus=0;
    int num=0;	
    int repetido=0;
   
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
	char CAD1[100];
	scanf(" %s",CAD1);
	
	
	
	//LONGITUD
	//puts(CAD1);
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

    //VALIDACION REPETICION DE USUARIO
    //LEE LOS USUARIOS YA REGISTRADOS
        char palabra[100];
		arch=fopen("Usuarios.txt","r");
		
	
	   while(!feof(arch)){
		   
		 fgets(palabra,100,arch);  //obtiene una linea del archivo
		 //repetido=strcmp(CAD1,palabra);
		 y=0;
		 for(int i=0;i<longitud;i++){
			 
			 printf("\ny= %d",y);
			 if(palabra[i]!=CAD1[i]){
				 y=-1;
		 }else y=y+1;
		
		if(y==longitud){
			printf("\nERROR. usuario ya existente en base de datos"); 
			goto usuario;
			band=1;
			repetido=1;
			 }else {
				
				 
				 repetido=0;
				 
			 }
		
		}
		
		
		
		 
		   
	   }
               

                 
fclose(arch);
if(repetido==0 && band==0){
		         
	    //ESCRIBE EL USUARIO
		arch=fopen("Usuarios.txt","a");
		fprintf(arch,strcat(CAD1,"\n"));
		printf("\nUSUARIO ACEPTADO");
		fclose(arch);
			 
			 }else{
				 if(repetido==1){
				 
				 printf("\nERROR. usuario ya existente en base de datos");  
		         band=1; 
			 }
			}
	
		
		
		
	if(band==1) {
		goto usuario;
	}
	return 0;
	
	
	
	
}

