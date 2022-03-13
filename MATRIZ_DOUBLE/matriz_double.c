#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "matriz_double.h"

#define RED_COLOR "\033[31m"
#define RESET_COLOR "\033[31m"


//=====================================SUPER CLASS METHODS PROTOTYPES===============================//

static Numero_t * copy_ (const Numero_t * const num);
static Numero_t * assign_ (const Numero_t * const num1,  Numero_t * const num2);
static Numero_t * add_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res);
static Numero_t * sub_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res);
static Numero_t * mult_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res);
static Numero_t * div_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res);
static Numero_t * ac_add_ (Numero_t * const num1, const Numero_t * const num2);
static Numero_t * ac_sub_ (Numero_t * const num1, const Numero_t * const num2);
static Numero_t * ac_mult_ (Numero_t * const num1, const Numero_t * const num2);
static Numero_t * ac_div_ (Numero_t * const num1, const Numero_t * const num2);
static int compare_ (const Numero_t * const num1, const Numero_t * const num2);
static char * print_ (const Numero_t * const num);
static void destruct_ (Numero_t * num);

//=========================================MATRIZ DOUBLE CLASS PROTOTYPES===============================================//

//=============================SHARED METHODS====================================//

static Matrix_t * Copy_ (const Matrix_t * const matrix);
static Matrix_t * Assign_ (const Matrix_t * const matrix1,  Matrix_t * const matrix2);
static Matrix_t * Add_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
static Matrix_t * Sub_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
static Matrix_t * Mult_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
static Matrix_t * Div_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
static Matrix_t * Ac_add_ (Matrix_t * const matrix1, const Matrix_t * const matrix2);
static Matrix_t * Ac_sub_ (Matrix_t * const matrix1, const Matrix_t * const matrix2);
static Matrix_t * Ac_mult_ (Matrix_t * const matrix1, const Matrix_t * const matrix2);
static Matrix_t * Ac_div_ (Matrix_t * const matrix1, const Matrix_t * const matrix2);
static int Compare_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2);
static char * Print_ (const Matrix_t * const matrix);
static void Destruct_ (Matrix_t * matrix);

//===========================EXCLUSIVE METHODS PROTOTYPES==================================//

static Matrix_t * Resize_ (Matrix_t * matrix, unsigned int tam[2]);
static Matrix_t * Ones_ (Matrix_t * matrix, unsigned int tam[2]); //VERIFICAR A PRESENÇA DO CONST NO PONTEIRO
static Matrix_t * Identity_ (Matrix_t * matrix, unsigned int tam[2]);
static Matrix_t * Scale_mult_ (Matrix_t * const matrix, double num);
static Matrix_t * Dot_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2);
static Matrix_t * Transpose_ (Matrix_t * matrix); //verificar const no ponteiro
static Matrix_t * Add_column_ (Matrix_t * matrix);
static Matrix_t * Add_row_ (Matrix_t * matrix);
static Matrix_t * Reverse_horizontal_ (Matrix_t * const matrix);
static Matrix_t * Reverse_vertical_ (Matrix_t * const matrix);
static Matrix_t * Sort_ (Matrix_t * const matrix);
static double Max_value_ (const Matrix_t * const matrix);
static double Min_value_ (const Matrix_t * const matrix);


//==========ADDITIONAL FUNCTIONS PROTOTYPES=================//

static void EqualizeMatrix(double ** matrix1, double ** matrix2, unsigned int tam[2]);
static void EqualizeTam(unsigned int tam1[2], unsigned int tam2[2]);
static void Put(double ** matrix, unsigned int tam[2], double value);


//====================================CONSTRUCTOR IMPLEMENTATION=================================//
//======TYPES=====//
//->fill
//->zeroed
//->rand
Matrix_t * Matrix_double_2D_constructor(unsigned int tam[2], char * type, double ** matrix){

    if((type == "fill") && (matrix == NULL)){

        printf(RED_COLOR"To construct a fill matrix, you have to pass the last function argument -> double ** <...>\n"RESET_COLOR);
        exit(1);
    }
    if((type != "fill") && (type != "zeroed") && (type != "rand")){

        printf(RED_COLOR"Constructor error! This type doesn't exist! :/\n"RESET_COLOR);
        exit(1);
    }

    static Matrix_t * mat;

    static NumeroVtbl_t numTab =  {

       .copia = &copy_,
       .atribui = &assign_,
       .soma = &add_,
       .subt = &sub_,
       .mult = &mult_,
       .divd = &div_,
       .ac_soma = &ac_add_,
       .ac_subt = &ac_sub_,
       .ac_mult = &ac_mult_,
       .ac_divd = &ac_div_,
       .compara = &compare_,
       .imprime = &print_,
       .destroi = &destruct_
    };

    //Assigning super class
    mat = (Matrix_t *) Num_constroi((Numero_t *)mat);
    mat->super.metodo = &numTab;

    static Matrix_interface_t matTab = {

        .copy = &Copy_,
        .assign = &Assign_,
        .add = &Add_,
        .sub = &Sub_,
        .mult = &Mult_,
        .div = &Div_,
        .ac_add = &Ac_add_,
        .ac_sub = &Ac_sub_,
        .ac_mult = &Ac_mult_,
        .ac_div = &Ac_div_,
        .compare = &Compare_,
        .print = &Print_,
        .destruct = &Destruct_,
        .resize = &Resize_,
        .ones = &Ones_,
        .identity = &Identity_,
        .scale_mult = &Scale_mult_,
        .dot = &Dot_,
        .transpose = &Transpose_,
        .add_column = &Add_column_,
        .add_row = &Add_row_,
        .reverse_horizontal = &Reverse_horizontal_,
        .reverse_vertical = &Reverse_vertical_,
        .sort = &Sort_,
        .max_value = &Max_value_,
        .min_value = &Min_value_
    };


    //ASSIGNING OTHER FIELDS
    mat->methods = &matTab;
    mat->tam = tam;

    mat->matrix = (double **)malloc(sizeof(double *) * tam[0]); //allocating rows
    
    for(int x=0;x<tam[0];x++){

        mat->matrix[x] = (double *)malloc(sizeof(double) * tam[1]);
    } //allocating columns


    if(type == "zeroed"){

        Put(mat->matrix,mat->tam,0);
    }

    else if(type == "rand"){

        srand(time(NULL));

        for(int x=0;x<tam[0];x++){
            for(int y=0;y<tam[1];y++){

                mat->matrix[x][y] = (double)rand() / (double)(RAND_MAX) * 100;
            }
        }
    }

    else if(type == "fill"){

        for(int x=0;x<tam[0];x++){
            for(int y=0;y<tam[1];y++){

                mat->matrix[x][y] = matrix[x][y];
            }
        }
    }

    return mat;
}

//==========================IMPLEMENTING ADDITIONAL FUNCTIONS=======================//

static void EqualizeMatrix(double ** matrix1, double ** matrix2, unsigned int tam[2]){

    for(int x=0;x<tam[0];x++){
        for(int y=0;y<tam[1];y++){

            matrix2[x][y] = matrix1[x][y];
        }
    }
}

static void EqualizeTam(unsigned int tam1[2], unsigned int tam2[2]){

    for(int x=0;x<2;x++){

        tam2[x] = tam1[x];
    }
}

static void Put(double ** matrix, unsigned int tam[2], double value){

    for(int x=0;x<tam[0];x++){
        for(int y=0;y<tam[1];y++){

            matrix[x][y] = value;
        }
    }
}


//======================================IMPLEMENTING EXCLUSIVE METHODS===============================//

static Matrix_t * Resize_ (Matrix_t * matrix, unsigned int tam[2]){

    //DO IT AGAIN

    //reallocating
    matrix->matrix = realloc(matrix->matrix,sizeof(double *) * tam[0]);
    for(int x=0;x<tam[0];x++){
        matrix->matrix[x] = realloc(matrix->matrix[x],sizeof(double) * tam[1]);
    }
    
    return matrix;
}


//=====================================================================================//
static Matrix_t * Ones_ (Matrix_t * matrix, unsigned int tam[2]){

    //Reallocating
    matrix->matrix = realloc(matrix->matrix,sizeof(double *) * tam[0]);
    for(int x=0;x<tam[0];x++){
        matrix->matrix[x] = realloc(matrix->matrix[x],sizeof(double) * tam[1]);
    }

    EqualizeTam(tam,matrix->tam);
    Put(matrix->matrix,matrix->tam,1);

    return matrix;
}

