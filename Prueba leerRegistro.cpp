#include <stdio.h>
#include <stdlib.h>
#include "rlutil.h"
#include "TpgAed.h"

void leerRegistro()
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

main()
{
	leerRegistro();
	return 0;
}



