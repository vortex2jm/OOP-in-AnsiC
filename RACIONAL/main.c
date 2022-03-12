#include <stdio.h>
#include <stdlib.h>
#include "racional.h"



int main(){

    Racional_pt rac1=NULL, rac2=NULL, rac3=NULL, rac4=NULL, rac5=NULL;

    rac1 = Racional_Constructor(4,8);
    rac2 = Racional_Constructor(4,8);
    rac3 = Racional_Constructor(1,1);

    //ADICIONAR
    rac1->module->add(rac1,rac2,rac3);
    printf("O valor de rac3 eh = %s", rac3->module->print(rac3));

    //SUBTRAIR
    rac1->module->sub(rac1,rac2,rac3);
    printf("O valor de rac3 eh = %s", rac3->module->print(rac3));

    //MULTIPLICAR
    rac1->module->mult(rac1,rac2,rac3);
    printf("O valor de rac3 eh = %s", rac3->module->print(rac3));

    //DIVIDIR
    rac1->module->div(rac1,rac2,rac3);
    printf("O valor de rac3 eh = %s", rac3->module->print(rac3));

    //VALOR DECIMAL
    double value = rac1->module->float_value(rac1);
    printf("O valor de rac1 eh = %lf\n", value);

    //IRREDUTIVEL
    rac2 = rac2->module->irreduceble(rac2);
    printf("O valor irredutivel de rac2 eh = %s", rac2->module->print(rac2));

    //CÓPIA
    rac4 = rac1->module->copy(rac1);
    printf("O valor de rac4 eh = %s", rac4->module->print(rac4));

    //COMPARANDO
    if(rac1->module->compare(rac1,rac2)) printf("rac1 e rac2 são iguais\n");
    else printf("rac1 e rac2 são diferentes");

    //CONSTRUINDO
    rac5 = Racional_Constructor(1,1);
    printf("O valor de rac5 eh = %s", rac5->module->print(rac5));

    //ATRIBUINDO
    rac1->module->assign(rac1,rac5);
    printf("O valor de rac5 eh = %s", rac5->module->print(rac5));
    
    rac1->module->destruct(rac1);
    rac2->module->destruct(rac2);
    rac3->module->destruct(rac3);
    rac4->module->destruct(rac4);
    rac5->module->destruct(rac5);

    return 0;
}