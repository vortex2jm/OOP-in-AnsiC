#include <stdio.h>
#include <stdlib.h>
#include "matriz_double.h"


int main(int argc, char const *argv[]){

    Matrix_pt mat =NULL, mat2 = NULL, mat3 = NULL, mat4 = NULL;
    unsigned int tam[2] = {2,2}, tam2[2] = {3,3};
    double array[4] = {1,2,3,4};


    mat = Matrix_double_2D_constructor(tam,'z',NULL);
    mat->methods->print(mat);

    mat2 = Matrix_double_2D_constructor(tam,'f',array);
    mat2->methods->print(mat2);

    mat3 = Matrix_double_2D_constructor(tam,'r',NULL);
    mat3->methods->print(mat3);

    mat2->methods->scale_mult(mat2,2.0);
    mat2->methods->print(mat2);

    mat3->methods->ac_add(mat3,mat2);
    mat3->methods->print(mat3);

    mat->methods->add(mat2,mat3,mat);
    mat->methods->print(mat);

    mat->methods->transpose(mat);
    mat->methods->print(mat);

    //mat4 = mat4->methods->dot(mat2,mat);
    //mat4->methods->print(mat4);

    mat->methods->identity(mat,2);
    mat->methods->print(mat);

    mat->methods->ones(mat,tam2);
    mat->methods->print(mat);

   // mat->methods->destruct(mat);
   // mat2->methods->destruct(mat2);
    //mat3->methods->destruct(mat3);

    return 0;
}
