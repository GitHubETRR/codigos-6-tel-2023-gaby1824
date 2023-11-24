// Ver flotante con union
#include <stdio.h>

union {
    unsigned char lugar[4];
    float valor;
}conversor;

int main()
{
    printf("Ingrese el valor que quiere ver en hexadecimal\n");
    scanf("%f", &conversor.valor);
    printf("0x%X%X%X%X", conversor.lugar[3], conversor.lugar[2], conversor.lugar[1], conversor.lugar[0]);
    return 0;
}
