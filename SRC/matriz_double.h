#ifndef MATRIZ_DOUBLE_H
#define MATRIZ_DOUBLE_H

#include "numero.h"

//PROTOTYPES
struct Matrix_interface_st;
struct Matrix_st;

//PRINCIPAL STRUCTURE
struct Matrix_st{

    Numero_t super;

    struct Matrix_interface_st * methods;

    unsigned int * tam;

    double ** matrix;
};
typedef struct Matrix_st Matrix_t;
typedef struct Matrix_st * Matrix_pt;


//=========================================IMPLEMENTING METHODS VIRTUAL TABLE======================//
struct Matrix_interface_st{


    //==========================SUPER CLASS METHODS==========================//

    Matrix_t * (*copy) (const Matrix_t * const matrix);
    Matrix_t * (*assign) (const Matrix_t * const matrix1, Matrix_t * const matrix2);
    Matrix_t * (*add) (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
    Matrix_t * (*sub) (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
    Matrix_t * (*mult) (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
    Matrix_t * (*div) (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
    Matrix_t * (*ac_add) (Matrix_t * const matrix1, const Matrix_t * const matrix2);
    Matrix_t * (*ac_sub) (Matrix_t * const matrix1, const Matrix_t * const matrix2);
    Matrix_t * (*ac_mult) (Matrix_t * const matrix1, const Matrix_t * const matrix2);
    Matrix_t * (*ac_div) (Matrix_t * const matrix1, const Matrix_t * const matrix2);
    int (*compare) (const Matrix_t * const matrix1, const Matrix_t * const matrix2);
    char * (*print) (const Matrix_t * const matrix);
    void (*destruct) (Matrix_t * matrix);

    //=================================EXCLUSIVE METHODS VIRTUAL TABLE=======================================//

    Matrix_t * (*resize) (Matrix_t * matrix, unsigned int tam[2]);
    Matrix_t * (*ones) (Matrix_t * matrix, unsigned int tam[2]); 
    Matrix_t * (*identity) (Matrix_t * matrix, unsigned int tam);
    Matrix_t * (*scale_mult) (Matrix_t * const matrix, double num);
    Matrix_t * (*dot) (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
    Matrix_t * (*transpose) (Matrix_t * matrix); 
    Matrix_t * (*add_column) (Matrix_t * matrix);
    Matrix_t * (*add_row) (Matrix_t * matrix);
    Matrix_t * (*reverse_horizontal) (Matrix_t * const matrix);
    Matrix_t * (*reverse_vertical) (Matrix_t * const matrix);
    Matrix_t * (*sort) (Matrix_t * const matrix);
    double (*max_value) (const Matrix_t * const matrix);
    double (*min_value) (const Matrix_t * const matrix);
    double (*get_value) (const Matrix_t * const matrix, unsigned int place[2]);
    unsigned int * (*get_size) (const Matrix_t * const matrix);
    void (*set_value) (Matrix_t * const matrix, unsigned int place[2], double value);
};  

typedef struct Matrix_interface_st Matrix_interface_t;

//DIFFERENT CONSTRUCTORS PROTOYPES

Matrix_t * Matrix_double_2D_constructor(unsigned int tam[2], char type, double * matrix);

#endif //MATRIZ_DOUBLE_H!