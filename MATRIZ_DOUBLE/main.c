#include <stdio.h>
#include <stdlib.h>
#include "matriz_double.h"


int main(int argc, char const *argv[]){

    Matrix_pt mat =NULL, mat2 = NULL, mat3 = NULL, mat4 = NULL, mat5=NULL;
    unsigned int tam[2] = {2,2}, tam2[2] = {3,3}, tam3[2] = {2,3};
    double array[4] = {1,2,3,4};


    mat = Matrix_double_2D_constructor(tam,'z',NULL);
    mat->methods->print(mat);

    mat2 = Matrix_double_2D_constructor(tam,'f',array);
    mat2->methods->print(mat2);

    mat3 = Matrix_double_2D_constructor(tam,'r',NULL);
    mat3->methods->print(mat3);

    mat->methods->assign(mat2,mat);
    mat->methods->print(mat);

    printf("%d %d\n", mat->methods->compare(mat,mat2), mat->methods->compare(mat,mat3));

    mat->methods->destruct(mat);
    mat2->methods->destruct(mat2);
    mat3->methods->destruct(mat3);

    return 0;
}
