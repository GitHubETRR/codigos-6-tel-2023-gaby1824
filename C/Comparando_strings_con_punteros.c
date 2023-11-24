// Comparando dos strings con punteros

#include <stdio.h>
#include <stdio_ext.h>

#define CANT_MAX 100

int comparador_strings(char *, char *);

int main() {
    char string_1[CANT_MAX], string_2[CANT_MAX];
    char *p_string_1 = &string_1[0], *p_string_2 = &string_2[0]; //Apunto los dos punteros a la dirección 0 del string
    printf("Ingrese el primer string: ");
    scanf("%s", string_1);
    __fpurge(stdin);
    printf("Ingrese el segundo string: ");
    scanf("%s", string_2);
    int resultado = comparador_strings(string_1, string_2);
    if (resultado == 0) {
        printf("Los dos strings son iguales\n");
    } else {
        printf("Los dos strings son diferentes\n");
    }
    return 0;
}

int comparador_strings(char *p_1, char *p_2) {
    int retorno = 0;
    for (int i = 0; i <= CANT_MAX; i++) {
        if (p_1[i] != p_2[i]) {
            retorno = 1;
            break;
        }
    }
    return (retorno);
}
