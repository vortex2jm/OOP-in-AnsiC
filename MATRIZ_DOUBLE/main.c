#include <stdio.h>
#include <stdlib.h>
#include "matriz_double.h"


int main(int argc, char const *argv[]){

    Matrix_t * mat = NULL;
    unsigned int tam[2] = {2,2};

    mat = Matrix_double_2D_constructor(tam,'z',NULL);


  
    return 0;
}
