#include <stdio.h>
#include <stdlib.h>
#include "racional.h"
#include "matriz_double.h"


int main(){

    printf("===============================TESTANDO MÉTODOS DOS RACIONAIS============================\n\n");  

    Racional_pt rac1 = NULL, rac2 = NULL, rac3= NULL;

    rac1 = Racional_Constructor(3,8);
    printf("Construindo rac1! Valor de rac1 = %s\n\n",  rac1->methods->print(rac1));
   
    rac2 = rac1->methods->copy(rac1);
    printf("Copiando o valor de rac1 para rac2! Valor de rac2 = %s\n\n", rac2->methods->print(rac2));

    rac3 = Racional_Constructor(1,1);
    printf("Construindo rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    rac3->methods->assign(rac2, rac3);
    printf("Atribuindo o valor de rac2 à rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    rac3->methods->add(rac1,rac2,rac3);
    printf("Somando rac1 + rac2 e colocando o resultado em rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    rac3->methods->sub(rac1,rac2,rac3);
    printf("Subtraindo rac1 - rac2 e colocando o resultado em rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));
    
    rac3->methods->mult(rac1,rac2,rac3);
    printf("Multiplicando rac1 * rac2 e colocando o resultado em rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    rac3->methods->div(rac1,rac2,rac3);
    printf("Dividindo rac1 / rac2 e colocando o resultado em rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    rac1->methods->ac_add(rac1,rac2);
    printf("Somando rac1 + rac2 e colocando o valor em rac1! Valor de rac1 = %s\n\n", rac1->methods->print(rac1));

    rac1->methods->ac_sub(rac1,rac2);
    printf("Subtraindo rac1 - rac2 e colocando o valor em rac1! Valor de rac1 = %s\n\n", rac1->methods->print(rac1));

    rac1->methods->ac_mult(rac1,rac2);
    printf("Multiplicando rac1 * rac2 e colocando o valor em rac1! Valor de rac1 = %s\n\n", rac1->methods->print(rac1));

    rac1->methods->ac_div(rac1,rac2);
    printf("Dividindo rac1 / rac2 e colocando o valor em rac1! Valor de rac1 = %s\n\n", rac1->methods->print(rac1));

    printf("Comparando rac1 com rac2!\n");
    if(rac1->methods->compare(rac1,rac2)) printf("rac1 = %s = rac2 = %s\n\n", rac1->methods->print(rac1), rac2->methods->print(rac2));
    else printf("rac1 = %s != rac2 = %s\n\n", rac1->methods->print(rac1), rac2->methods->print(rac2));

    long int num = 0, den = 0;
    rac3->methods->get(rac3, &num, &den);
    printf("Pegando os operadores de rac3! valor de rac3 = %s, numerador = %ld, denominador = %ld\n\n", rac3->methods->print(rac3), num, den);

    rac3->methods->set(rac3,7,9);
    printf("Colocando 7 no numerador e 9 no denominador de rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    printf("Pegando numerador de rac3 = %ld\n\n", rac3->methods->get_num(rac3));

    printf("Pegando o denominador de rac3 = %ld\n\n", rac3->methods->get_den(rac3));

    rac3->methods->set_num(rac3,17);
    printf("Mudando o valor do numerador de rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    rac3->methods->set_den(rac3,44);
    printf("Mudando o valor do denominador de rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    printf("Valor decimal de rac3 = %lf\n\n", rac3->methods->float_value(rac3));

    rac3->methods->invert(rac3);
    printf("Invertendo os valores de rac3! Valor de rac3 = %s\n\n", rac3->methods->print(rac3));

    printf("Valor de rac1 = %s\n", rac1->methods->print(rac1));
    rac1->methods->irreduceble(rac1);
    printf("Valor irredutivel de rac1 = %s\n\n", rac1->methods->print(rac1));

    rac1->methods->destruct(rac1);
    rac2->methods->destruct(rac2);
    rac3->methods->destruct(rac3);

//===========================================================================================================//

    printf("==========================TESTANDO MÉTODOS DAS MATRIZES DE DOUBLE===============================");

    Matrix_pt mat1 = NULL, mat2 = NULL;

    unsigned int size[2] = {3,4};
    double array[12] = {2,3,5,1,7,8,2,9,4,8,3,0};

    return 0;
}