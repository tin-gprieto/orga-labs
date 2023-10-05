#include <stdio.h>
#include <string.h>
#include "intercambiar.h"

int main() {
    char cadena[] = "Orga del computador";

    intercambiar(cadena);

    printf("%s\n", cadena);

    return 0;
}

void intercambiar_aux(char *cadena)
{
    int fin = strlen(cadena) - 1;
    int inicio = 0;

    while(inicio < fin)
    {
        char letra_inicio = cadena[inicio];
        char letra_fin = cadena[fin];

        cadena[inicio] = letra_fin;
        cadena[fin] = letra_inicio;
        inicio++;
        fin++;
    }
}

int strlen_aux(char *cadena)
{
    int longitud = 0;

    while(cadena[longitud] != '/0')
    {
        longitud++;
    }
    return longitud;
}
