// Pasaje por valor o por referencia

#include <stdio.h>

void pasaje_por_valor(int);
void pasaje_por_referencia(int *);

int main(){
    int a = 10;
    pasaje_por_valor(a);
    printf("El valor de a en el main es = %d \n", a);
    
    int b = 27;
    int *p_b = &b; //Apunto un puntero a b
    pasaje_por_referencia(p_b); //Paso la dirección de memoria donde esta b
    printf("El valor de b en el main es = %d \n", *p_b);
    
    return 0;
}

void pasaje_por_valor(int a){
    a++;
    printf("El valor de a en pasaje por valor es = %d \n", a);
}

void pasaje_por_referencia(int *p){
    (*p)++; //Aumenta en 1 el contenido del puntero
    printf("El valor de b en pasaje por referencia es = %d \n", *p);
}
