#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char a[32];
	int i=0;
	bool bandera = false;
	
	printf(">Ingrese palabra: ");
	scanf("%s",a);
	
	while(a[i]!=NULL && !bandera)
	{
		if(a[i]>=65 && a[i]<=90)
		{
			bandera = true;
			printf("HAY MAYUSCULA!!");
			printf("\nEl valor es: %d", a[i]);
		}
		i++;
	}
	
	if(!bandera)
	{
		printf("NO HAY MAYUSCULA :( ");
	}
}
