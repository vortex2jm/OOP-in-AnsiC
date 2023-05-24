#include <stdio.h>
#include <stdlib.h>
#include "racional.h"
#include "matriz_double.h"

#define RED "\033[1;31m"    
#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define RESET_COLOR "\033[0m"

int main(){

    printf(RED"===============================TESTANDO MÉTODOS DOS RACIONAIS============================\n\n"RESET_COLOR);  

    Racional_pt rac1 = NULL, rac2 = NULL, rac3= NULL;

    rac1 = Racional_Constructor(3,8);
    printf(CYAN"Construindo rac1! Valor de rac1 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac1->methods->print(rac1));
   
    rac2 = rac1->methods->copy(rac1);
    printf(CYAN"Copiando o valor de rac1 para rac2! Valor de rac2 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac2->methods->print(rac2));

    rac3 = Racional_Constructor(1,1);
    printf(CYAN"Construindo rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    rac3->methods->assign(rac2, rac3);
    printf(CYAN"Atribuindo o valor de rac2 à rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    rac3->methods->add(rac1,rac2,rac3);
    printf(CYAN"Somando rac1 + rac2 e colocando o resultado em rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    rac3->methods->sub(rac1,rac2,rac3);
    printf(CYAN"Subtraindo rac1 - rac2 e colocando o resultado em rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));
    
    rac3->methods->mult(rac1,rac2,rac3);
    printf(CYAN"Multiplicando rac1 * rac2 e colocando o resultado em rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    rac3->methods->div(rac1,rac2,rac3);
    printf(CYAN"Dividindo rac1 / rac2 e colocando o resultado em rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    rac1->methods->ac_add(rac1,rac2);
    printf(CYAN"Somando rac1 + rac2 e colocando o valor em rac1! Valor de rac1 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac1->methods->print(rac1));

    rac1->methods->ac_sub(rac1,rac2);
    printf(CYAN"Subtraindo rac1 - rac2 e colocando o valor em rac1! Valor de rac1 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac1->methods->print(rac1));

    rac1->methods->ac_mult(rac1,rac2);
    printf(CYAN"Multiplicando rac1 * rac2 e colocando o valor em rac1! Valor de rac1 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac1->methods->print(rac1));

    rac1->methods->ac_div(rac1,rac2);
    printf(CYAN"Dividindo rac1 / rac2 e colocando o valor em rac1! Valor de rac1 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac1->methods->print(rac1));

    printf(CYAN"Comparando rac1 com rac2!\n"RESET_COLOR);
    if(rac1->methods->compare(rac1,rac2)) {

        printf(CYAN"rac1 = \n\n"RESET_COLOR);
        printf("%s\n\n", rac1->methods->print(rac1));
        printf(CYAN"rac2 = \n\n"RESET_COLOR);
        printf("%s\n\n", rac2->methods->print(rac2));
        printf("RAC1 E RAC2 SAO IGUAIS\n\n"); 
    }

    else{

        printf(CYAN"rac1 = \n\n"RESET_COLOR);
        printf("%s\n\n", rac1->methods->print(rac1));
        printf(CYAN"rac2 = \n\n"RESET_COLOR);
        printf("%s\n\n", rac2->methods->print(rac2));
        printf("RAC1 E RAC2 SAO DIFERENTES\n\n");
    } 

    long int num = 0, den = 0;
    rac3->methods->get(rac3, &num, &den);
    printf(CYAN"Pegando os valores de rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));
    printf(CYAN"Numerador = \n\n"RESET_COLOR);
    printf("%ld\n\n", num);
    printf(CYAN"Denominador = \n\n"RESET_COLOR);
    printf("%ld\n\n", den);

    rac3->methods->set(rac3,7,9);
    printf(CYAN"Colocando 7 no numerador e 9 no denominador de rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    printf(CYAN"Pegando numerador de rac3 = \n\n"RESET_COLOR);
    printf("%ld\n\n", rac3->methods->get_num(rac3));

    printf(CYAN"Pegando o denominador de rac3 = \n\n"RESET_COLOR);
    printf("%ld\n\n", rac3->methods->get_den(rac3));

    rac3->methods->set_num(rac3,17);
    printf(CYAN"Mudando o valor do numerador de rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    rac3->methods->set_den(rac3,44);
    printf(CYAN"Mudando o valor do denominador de rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    printf(CYAN"Valor decimal de rac3 = \n\n"RESET_COLOR);
    printf("%lf\n\n", rac3->methods->float_value(rac3));

    rac3->methods->invert(rac3);
    printf(CYAN"Invertendo os valores de rac3! Valor de rac3 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac3->methods->print(rac3));

    printf(CYAN"Valor de rac1 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac1->methods->print(rac1));
    rac1->methods->irreduceble(rac1);
    printf(CYAN"Valor irredutivel de rac1 = \n\n"RESET_COLOR);
    printf("%s\n\n", rac1->methods->print(rac1));

    rac1->methods->destruct(rac1);
    rac2->methods->destruct(rac2);
    rac3->methods->destruct(rac3);

//===========================================================================================================//

    printf(PURPLE"==========================TESTANDO MÉTODOS DAS MATRIZES DE DOUBLE===============================\n\n");

    Matrix_pt mat1 = NULL, mat2 = NULL, mat3 = NULL, mat4 = NULL, mat5 = NULL;

    unsigned int size[2] = {3,4}, size2[2] = {4,4}, size3[2] = {3,3}, size4[2] = {4,3};
    double array[12] = {2,3,5,1,7,8,2,9,4,8,3,6};

    mat1 = Matrix_double_2D_constructor(size2,'z', NULL);
    printf(YELLOW"Construindo uma matriz de double zerada! mat1 = \n\n"RESET_COLOR);
    mat1->methods->print(mat1);

    mat2 = Matrix_double_2D_constructor(size2,'r',NULL);
    printf(YELLOW"Construindo uma matriz com valores randomicos! mat2 = \n\n"RESET_COLOR);
    mat2->methods->print(mat2);

    mat3 = Matrix_double_2D_constructor(size,'f',array);
    printf(YELLOW"Construindo uma matriz com valores escolhidos pelo usuario! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat4 = mat3->methods->copy(mat3);
    printf(YELLOW"Copiando mat3 em mat4! mat4 = \n\n"RESET_COLOR);
    mat4->methods->print(mat4);

    mat1->methods->assign(mat2,mat1);
    printf(YELLOW"Atribuindo o valor de mat2 a mat1! mat1 = \n\n"RESET_COLOR);
    mat1->methods->print(mat1);

    mat5 = Matrix_double_2D_constructor(size,'z',NULL);
    mat3->methods->add(mat3,mat4,mat5);
    printf(YELLOW"Somando mat3 e mat4 e colocando o valor em mat5! mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat3->methods->sub(mat3,mat4,mat5);
    printf(YELLOW"Subtraindo mat3 de mat4 e colocando o valor em mat5! mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat3->methods->mult(mat3,mat4,mat5);
    printf(YELLOW"Multiplicando mat3 e mat4 elemento a elemento e colocando o valor em mat5! mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat3->methods->div(mat3,mat4,mat5);
    printf(YELLOW"Dividindo mat3 por mat4 elemento a elemento e colocando o valor em mat5! mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat3->methods->ac_add(mat3,mat4);
    printf(YELLOW"Somando mat3 e mat4 e colocando o valor em mat3! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->ac_sub(mat3,mat4);
    printf(YELLOW"Suubtraindo mat3 de mat4 e colocando o valor em mat3! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->ac_mult(mat3,mat4);
    printf(YELLOW"Multiplicando mat3 e mat4 elemento a elemento e colocando o valor em mat3! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->ac_div(mat3,mat4);
    printf(YELLOW"Dividindo mat3 por mat4  elemento a elemento e colocando o valor em mat3! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    printf(YELLOW"Comparando mat3 e mat4!\n"RESET_COLOR);
    if(mat3->methods->compare(mat3,mat4)) printf(YELLOW"mat3 e mat4 são iguais!!!\n\n"RESET_COLOR);
    else printf(YELLOW"mat3 e mat4 sao diferentes!!!\n\n"RESET_COLOR);

    printf(YELLOW"mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat5->methods->resize(mat5, size4);
    printf(YELLOW"Resizing mat5 to 4 x 3 !!! mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat5->methods->ones(mat5, size4);
    printf(YELLOW"Transformando mat5 em uma matriz preenchida com '1'! mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat5->methods->identity(mat5, 4);
    printf(YELLOW"Transformando mat5 em uma matriz identidade 4x4! mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat5->methods->scale_mult(mat5, 2.5);
    printf(YELLOW"Multiplicando mat5 por 2.5! mt5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);

    mat5->methods->identity(mat5, 4);
    printf(YELLOW"Transformando mat5 em uma matriz identidade para multiplicar por mat2!\n"RESET_COLOR);
    printf(YELLOW"mat5 = \n\n"RESET_COLOR);
    mat5->methods->print(mat5);
    printf(YELLOW"mat2 = \n\n"RESET_COLOR);
    mat2->methods->print(mat2);

    mat5->methods->dot(mat2,mat5,mat1);
    printf(YELLOW"Multiplicando mat2 por mat5 segundo as regras da algebra linear e colocando o resultado em mat1!!! mat1 = \n\n"RESET_COLOR);
    mat1->methods->print(mat1);

    printf(YELLOW"mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);
    mat3->methods->transpose(mat3);
    printf(YELLOW"Transpondo mat3!!! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->add_column(mat3);
    printf(YELLOW"Adicionando uma coluna em mat3!!! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->add_row(mat3);
    printf(YELLOW"Adicionando uma linha em mat3!!! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->reverse_horizontal(mat3);
    printf(YELLOW"Revertendo a ordem das colunas de mat3!!! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->reverse_vertical(mat3);
    printf(YELLOW"Revertendo a ordem das linhas de mat3!!! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    mat3->methods->sort(mat3);
    printf(YELLOW"Ordenando os valores da matriz em ordem crescente!!! mat3 = \n\n"RESET_COLOR);
    mat3->methods->print(mat3);

    printf(YELLOW"O maior valor de mat3 eh = \n\n"RESET_COLOR);
    printf("%.2lf\n\n", mat3->methods->max_value(mat3));

    printf(YELLOW"O menor valor de mat3 eh = \n\n"RESET_COLOR);
    printf("%.2lf\n\n", mat3->methods->min_value(mat3));

    printf(YELLOW"Pegando o valor da posicao 3x3 de mat3! Valor = \n\n"RESET_COLOR);
    printf("%.2lf\n\n", mat3->methods->get_value(mat3, size3));

    printf(YELLOW"Muudando o valor da posicao 3x3 de mat3! Valor = \n\n"RESET_COLOR);
    mat3->methods->set_value(mat3,size3,99);
    mat3->methods->print(mat3);

    mat1->methods->destruct(mat1);
    mat2->methods->destruct(mat2);
    mat3->methods->destruct(mat3);
    mat4->methods->destruct(mat4);
    mat5->methods->destruct(mat5);

    return 0;
}
