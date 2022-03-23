#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "matriz_double.h"

#define RED_COLOR "\033[31m"
#define RESET_COLOR "\033[0m"


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
static Matrix_t * Identity_ (Matrix_t * matrix, unsigned int tam);
static Matrix_t * Scale_mult_ (Matrix_t * const matrix, double num);
static Matrix_t * Dot_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres);
static Matrix_t * Transpose_ (Matrix_t * matrix); //verificar const no ponteiro
static Matrix_t * Add_column_ (Matrix_t * matrix);
static Matrix_t * Add_row_ (Matrix_t * matrix);
static Matrix_t * Reverse_horizontal_ (Matrix_t * const matrix);
static Matrix_t * Reverse_vertical_ (Matrix_t * const matrix);
static Matrix_t * Sort_ (Matrix_t * const matrix);
static double Max_value_ (const Matrix_t * const matrix);
static double Min_value_ (const Matrix_t * const matrix);
static double Get_Value_ (const Matrix_t * const matrix, unsigned int place[2]);
static unsigned int * Get_Size_(const Matrix_t * const matrix);
static void Set_Value_ (Matrix_t * const matrix, unsigned int place[2], double value);


//==========ADDITIONAL FUNCTIONS PROTOTYPES=================//

static void EqualizeTam(unsigned int tam1[2], unsigned int tam2[2]);
static void Put(double ** matrix, unsigned int tam[2], double value);
static int EqualSize(unsigned int tam1[2], unsigned int tam2[2]);


//====================================CONSTRUCTOR IMPLEMENTATION=================================//
//======TYPES=====//
//->fill
//->zeroed
//->rand
Matrix_t * Matrix_double_2D_constructor(unsigned int tam[2], char type, double * matrix){

    if((type == 'f') && (matrix == NULL)){

        printf(RED_COLOR"To construct a fill matrix, you have to pass the last function argument -> double ** <...>\n"RESET_COLOR);
        exit(1);
    }
    if((type != 'f') && (type != 'z') && (type != 'r')){

        printf(RED_COLOR"Constructor error! This type doesn't exist! :/\n"RESET_COLOR);
        exit(1);
    }

    Matrix_t * mat = (Matrix_t*) malloc(sizeof(Matrix_t));

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
    // mat = (Matrix_t *) Num_constroi((Numero_t *)mat);
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
        .min_value = &Min_value_,
        .get_size = &Get_Size_,
        .get_value = &Get_Value_,
        .set_value = &Set_Value_
    };
    mat->methods = &matTab;


    //ASSIGNING OTHER FIELDS
    mat->tam = (unsigned int*) malloc(sizeof(unsigned int) * 2);
    for(int x=0;x<2;x++){

        mat->tam[x] = tam[x];
    }

    // ALLOCATING MATRIX
    mat->matrix = (double **)malloc(sizeof(double *) * tam[0]); //allocating rows
    
    for(int x=0;x<tam[0];x++){

        mat->matrix[x] = (double *)malloc(sizeof(double) * tam[1]);
    } //allocating columns


    if(type == 'z'){

        Put(mat->matrix,mat->tam,0);
    }

    else if(type == 'r'){

        srand(time(NULL));

        for(int x=0;x<tam[0];x++){
            for(int y=0;y<tam[1];y++){

                mat->matrix[x][y] = (double)rand() / (double)(RAND_MAX) * 100;
            }
        }
    }

    else if(type == 'f'){

        int count =0;
        for(int x=0;x<tam[0];x++){
            for(int y=0;y<tam[1];y++){

                mat->matrix[x][y] = matrix[count];
                count++;
            }
        }
    }

    return mat;
}

//==========================IMPLEMENTING ADDITIONAL FUNCTIONS=======================//

//to equalize arrays
static void EqualizeTam(unsigned int tam1[2], unsigned int tam2[2]){

    for(int x=0;x<2;x++){

        tam2[x] = tam1[x];
    }
}

//to put a number on all sites of matrix
static void Put(double ** matrix, unsigned int tam[2], double value){

    for(int x=0;x<tam[0];x++){
        for(int y=0;y<tam[1];y++){

            matrix[x][y] = value;
        }
    }
}

//to verify if 2 matrices have same size
static int EqualSize(unsigned int tam1[2], unsigned int tam2[2]){

    if((tam1[0] == tam2[0]) && (tam1[1] == tam2[1])) return 1;

    return 0;
}


//======================================IMPLEMENTING EXCLUSIVE METHODS===============================//

static Matrix_t * Resize_ (Matrix_t * matrix, unsigned int tam[2]){

    //if sizes are similar, returns same matrix

    if(EqualSize(matrix->tam,tam)) return matrix;

    //=====else resize=============================================//

    //reallocating
    matrix->matrix = realloc(matrix->matrix,sizeof(double *) * tam[0]);
    for(int x=0;x<tam[0];x++){
        matrix->matrix[x] = realloc(matrix->matrix[x],sizeof(double) * tam[1]);
    }
    
    int diffRow = tam[0] - matrix->tam[0];
    int diffColumn = tam[1] - matrix->tam[1];

    //putting zeros in new allocated spaces

    if(diffRow > 0){

        for(int x = matrix->tam[0];x<tam[0];x++){
            for(int y=0;y<tam[1];y++){

                matrix->matrix[x][y] = 0;
            }
        }
    }

    if(diffColumn > 0){

        for(int y = matrix->tam[1]; y<tam[1];y++){
            for(int x=0;x<tam[0];x++){

                matrix->matrix[x][y] = 0;
            }
        }
    }

    EqualizeTam(tam,matrix->tam);

    return matrix;
}
//=====================================================================================//

static Matrix_t * Ones_ (Matrix_t * matrix, unsigned int tam[2]){

    //if sizes are equal, only put ones 

    if(EqualSize(matrix->tam,tam)){             //ERRORR

        Put(matrix->matrix, matrix->tam,1);
        return matrix;
    }

    //========else, realloc==================================//

    //Reallocating
    matrix->matrix = realloc(matrix->matrix,sizeof(double *) * tam[0]);
    for(int x=0;x<tam[0];x++){
        matrix->matrix[x] = realloc(matrix->matrix[x],sizeof(double) * tam[1]);
    }

    EqualizeTam(tam,matrix->tam);
    Put(matrix->matrix, matrix->tam,1);

    return matrix;
}
//=============================================================================================//

static Matrix_t * Identity_ (Matrix_t * matrix, unsigned int tam){

    //if matrix has same size of integer "tam", only create indentity matrix
    if((matrix->tam[0] == tam) && (matrix->tam[1] == tam)){

        Put(matrix->matrix,matrix->tam,0);
        for(int x=0;x<tam;x++){

            matrix->matrix[x][x] = 1;
        }

        return matrix;
    }

    //=======================================================// 
    //else realloc correct size to create the matrix
    matrix->matrix = realloc(matrix->matrix,sizeof(double *) * tam);
    for(int x=0;x<tam;x++){
        matrix->matrix[x] = realloc(matrix->matrix[x],sizeof(double) * tam);
    }

    unsigned int newTam[2] = {tam,tam};

    EqualizeTam(newTam,matrix->tam);
    Put(matrix->matrix,matrix->tam,0);

    for(int x=0;x<tam;x++){

            matrix->matrix[x][x] = 1;
    }

    return matrix;
}
//=============================================================================================//

static Matrix_t * Scale_mult_ (Matrix_t * const matrix, double num){

    for(int x =0; x<matrix->tam[0];x++){
        for(int y=0;y<matrix->tam[1];y++){

            matrix->matrix[x][y] *= num;
        }
    }

    return matrix;
}
//=============================================================================================//

static Matrix_t * Dot_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres){


    if(matrix1->tam[1] != matrix2->tam[0]){

        printf(RED_COLOR"Error: Impossible to multiply matrices with these dimensions :/\n"RESET_COLOR);
        exit(1);
    }

    if(matrixres->tam[0] != matrix1->tam[0] || matrixres->tam[1] != matrix2->tam[1]){

        matrixres->matrix = realloc(matrixres->matrix, sizeof(double *) * matrix1->tam[0]);
        for(int x=0;x<matrix2->tam[1];x++){
            matrixres->matrix[x] = realloc(matrixres->matrix[x], sizeof(double) * matrix2->tam[1]);
        }
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0;y<matrix2->tam[1];y++){

            double num=0;
            for(int z = 0;z<matrix1->tam[1];z++){

                num += matrix1->matrix[x][z] * matrix2->matrix[z][y];
            }

            matrixres->matrix[x][y] = num;
        }
    }

    return matrixres;
}
//=============================================================================================//

static Matrix_t * Transpose_ (Matrix_t * matrix){

    double mat[matrix->tam[1]][matrix->tam[0]];

    //creating an auxiliar transpose matrix
    for(int x =0; x<matrix->tam[1];x++){
        for(int y=0;y<matrix->tam[0];y++){

            mat[x][y] = matrix->matrix[y][x];
        }
    }


    //if they have same sizes, copy them
    if(matrix->tam[0] == matrix->tam[1]){

        
        for(int x=0;x<matrix->tam[0];x++){
            for(int y=0; y<matrix->tam[1];y++){

                matrix->matrix[x][y] = mat[x][y];
            }
        }

        return matrix;
    }

    //=====================================================//
    //else, realloc and next, copy them
    matrix->matrix = realloc(matrix->matrix,sizeof(double *) * matrix->tam[1]);
    for(int x=0;x<matrix->tam[1];x++){
        matrix->matrix[x] = realloc(matrix->matrix[x],sizeof(double) * matrix->tam[0]);
    }


    for(int x=0;x<matrix->tam[1];x++){
        for(int y=0; y<matrix->tam[0];y++){

            matrix->matrix[x][y] = mat[x][y];
        }
    }

    unsigned int aux;
    aux = matrix->tam[0];
    matrix->tam[0] = matrix->tam[1];
    matrix->tam[1] = aux;

    return matrix;
}
//=============================================================================================//

static Matrix_t * Add_column_ (Matrix_t * matrix){

    
    for(int x=0;x<matrix->tam[0];x++){

        matrix->matrix[x] = realloc(matrix->matrix[x], sizeof(double) * (matrix->tam[1] + 1));
    }

    
    for(int x=0;x<matrix->tam[0];x++){

        matrix->matrix[x][matrix->tam[1]] = 0;
    }

    matrix->tam[1] += 1;
    
    return matrix;
}   
//=============================================================================================//

static Matrix_t * Add_row_ (Matrix_t * matrix){


    matrix->matrix = realloc(matrix->matrix,sizeof(double *) * (matrix->tam[0] + 1));
    matrix->matrix[matrix->tam[0]] = realloc(matrix->matrix[matrix->tam[0]], sizeof(double) * matrix->tam[1]);

    for(int x =0;x<matrix->tam[1];x++){

        matrix->matrix[matrix->tam[0]][x] = 0;
    }

    matrix->tam[0] += 1;

    return matrix;
}
//=============================================================================================//

static Matrix_t * Reverse_horizontal_ (Matrix_t * const matrix){

    double mat[matrix->tam[0]][matrix->tam[1]];

    for(int x=0;x<matrix->tam[0];x++){
        for(int y=0;y<matrix->tam[1];y++){

            mat[x][y] = matrix->matrix[x][y];
        }
    }


    for(int y=0, z=(matrix->tam[1] - 1) ; y<matrix->tam[1] ; y++, z--){

        for(int x =0; x<matrix->tam[0];x++){

            matrix->matrix[x][y] = mat[x][z];
        }
    }

    return matrix;
}
//=============================================================================================//

static Matrix_t * Reverse_vertical_ (Matrix_t * const matrix){

    unsigned int row = matrix->tam[0];
    unsigned int column = matrix->tam[1];

    double mat[row][column];

    for(int x=0;x<matrix->tam[0];x++){
        for(int y=0;y<matrix->tam[1];y++){

            mat[x][y] = matrix->matrix[x][y];
        }
    }


    for(int x=0, w=(matrix->tam[0] - 1) ; x<matrix->tam[0] ; x++, w--){

        for(int y=0;y<matrix->tam[1];y++){

            matrix->matrix[x][y] = mat[w][y];
        }
    }

    return matrix;
}
//=============================================================================================//

static Matrix_t * Sort_ (Matrix_t * const matrix){

    unsigned int size = matrix->tam[0] * matrix->tam[1];
    double array[size], aux;
    int count = 0;

    //Assigning matrix to array
    for(int x=0;x<matrix->tam[0];x++){
        for(int y =0; y<matrix->tam[1];y++){

            array[count] = matrix->matrix[x][y];
            count++;
        }
    }

    //Sorting array 
    for(int x=0;x<size;x++){
        for(int y=x+1;y<=size;y++){

            if(array[y] < array[x]){

                aux = array[x];
                array[x] = array[y];
                array[y] = aux;
            }
        }
    }

    //Assigning array to matrix
    count =0;
    for(int x=0;x<matrix->tam[0];x++){
        for(int y =0; y<matrix->tam[1];y++){

            matrix->matrix[x][y] = array[count];
            count++;
        }
    }

    return matrix;
}
//=============================================================================================//

static double Max_value_ (const Matrix_t * const matrix){

    unsigned int size = matrix->tam[0] * matrix->tam[1];
    double array[size], aux;
    int count = 0;

    
    //Assigning matrix to array
    for(int x=0;x<matrix->tam[0];x++){
        for(int y =0; y<matrix->tam[1];y++){

            array[count] = matrix->matrix[x][y];
            count++;
        }
    }


    //Putting max value on first index
    for(int x = 1;x<size;x++){

        if(array[x] > array[0]){

            aux = array[x];
            array[x] = array[0];
            array[0] = aux;
        }
    }

    return array[0];

}
//=============================================================================================//

static double Min_value_ (const Matrix_t * const matrix){

    unsigned int size = matrix->tam[0] * matrix->tam[1];
    double array[size], aux;
    int count = 0;

    
    //Assigning matrix to array
    for(int x=0;x<matrix->tam[0];x++){
        for(int y =0; y<matrix->tam[1];y++){

            array[count] = matrix->matrix[x][y];
            count++;
        }
    }


    //Putting min value on first index
    for(int x = 1;x<size;x++){

        if(array[x] < array[0]){

            aux = array[x];
            array[x] = array[0];
            array[0] = aux;
        }
    }

    return array[0];
}
//=============================================================================================//

static double Get_Value_ (const Matrix_t * const matrix, unsigned int place[2]){

    if(place[0] > matrix->tam[0] || place[1] > matrix->tam[1]){

        printf(RED_COLOR"Error: There's no element in this index\n"RESET_COLOR);
        exit(1);
    }

    return matrix->matrix[place[0] - 1][place[1] - 1];
}
//=============================================================================================//

static unsigned int * Get_Size_(const Matrix_t * const matrix){

    static unsigned int size[2];

    for(int x =0; x<2;x++){

        size[x] = matrix->tam[x];
    }

    return size;
}
//=============================================================================================//

static void Set_Value_ (Matrix_t * const matrix, unsigned int place[2], double value){

    if(place[0] > matrix->tam[0] || place[1] > matrix->tam[1]){

        printf(RED_COLOR"Error: There's no element in this index\n"RESET_COLOR);
        exit(1);
    }

    matrix->matrix[place[0] - 1][place[1] -1] = value;
}
//=============================================================================================//


//======================================IMPLEMENTING SUPER CLASS METHODS===============================//


static Matrix_t * Copy_ (const Matrix_t * const matrix){

    Matrix_t * matrix2 = Matrix_double_2D_constructor(Get_Size_(matrix),'z',NULL);

    for(int x=0;x<matrix->tam[0];x++){
        for(int y=0;y<matrix->tam[1];y++){

            matrix2->matrix[x][y] = matrix->matrix[x][y];
        }
    }

    return matrix2;
}

static inline Numero_t * copy_ (const Numero_t * const num){


    return (Numero_t *) Copy_((Matrix_t *) num);
}
//=============================================================================================//

static Matrix_t * Assign_ (const Matrix_t * const matrix1,  Matrix_t * const matrix2){

    if(!EqualSize(matrix1->tam,matrix2->tam)){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrix2->matrix[x][y] = matrix1->matrix[x][y];
        }
    }

    return matrix2;
}


static inline Numero_t * assign_ (const Numero_t * const num1,  Numero_t * const num2){

    return (Numero_t *) Assign_((Matrix_t*)num1, (Matrix_t*)num2);
}
//=============================================================================================//

static Matrix_t * Add_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres){

    if((!EqualSize(matrix1->tam,matrix2->tam)) || (!EqualSize(matrix1->tam, matrixres->tam))){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrixres->matrix[x][y] = matrix1->matrix[x][y] + matrix2->matrix[x][y];
        }
    }

    return matrixres;
}


static inline Numero_t * add_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){


    return (Numero_t*) Add_((Matrix_t*)num1, (Matrix_t*)num2, (Matrix_t*)res);
}
//=============================================================================================//

static Matrix_t * Sub_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres){

    if((!EqualSize(matrix1->tam,matrix2->tam)) || (!EqualSize(matrix1->tam, matrixres->tam))){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrixres->matrix[x][y] = matrix1->matrix[x][y] - matrix2->matrix[x][y];
        }
    }

    return matrixres;
}

static inline Numero_t * sub_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){

    return (Numero_t*) Sub_((Matrix_t*)num1, (Matrix_t*)num2, (Matrix_t*)res);
}
//=============================================================================================//

static Matrix_t * Mult_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres){

    if((!EqualSize(matrix1->tam,matrix2->tam)) || (!EqualSize(matrix1->tam, matrixres->tam))){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrixres->matrix[x][y] = matrix1->matrix[x][y] * matrix2->matrix[x][y];
        }
    }

    return matrixres;
}

static inline Numero_t * mult_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){

    return (Numero_t*) Mult_((Matrix_t*)num1, (Matrix_t*)num2, (Matrix_t*)res);
}
//=============================================================================================//

static Matrix_t * Div_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2, Matrix_t * const matrixres){

    if((!EqualSize(matrix1->tam,matrix2->tam)) || (!EqualSize(matrix1->tam, matrixres->tam))){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrixres->matrix[x][y] = matrix1->matrix[x][y] / matrix2->matrix[x][y];
        }
    }

    return matrixres;
}

static inline Numero_t * div_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){

    return (Numero_t*) Div_((Matrix_t*)num1, (Matrix_t*)num2, (Matrix_t*)res);
}
//=============================================================================================//

static Matrix_t * Ac_add_ (Matrix_t * const matrix1, const Matrix_t * const matrix2){

    if(!EqualSize(matrix1->tam,matrix2->tam)){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrix1->matrix[x][y] = matrix1->matrix[x][y] + matrix2->matrix[x][y];
        }
    }

    return matrix1;
}

static Numero_t * ac_add_ (Numero_t * const num1, const Numero_t * const num2){

    return (Numero_t*) Ac_add_((Matrix_t*)num1, (Matrix_t*)num2);
}
//=============================================================================================//

static Matrix_t * Ac_sub_ (Matrix_t * const matrix1, const Matrix_t * const matrix2){

    if(!EqualSize(matrix1->tam,matrix2->tam)){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrix1->matrix[x][y] -= matrix2->matrix[x][y];
        }
    }

    return matrix1;
}

static Numero_t * ac_sub_ (Numero_t * const num1, const Numero_t * const num2){

    return (Numero_t*) Ac_sub_((Matrix_t*)num1, (Matrix_t*)num2);
}
//=============================================================================================//

static Matrix_t * Ac_mult_ (Matrix_t * const matrix1, const Matrix_t * const matrix2){

    if(!EqualSize(matrix1->tam,matrix2->tam)){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrix1->matrix[x][y] *= matrix2->matrix[x][y];
        }
    }

    return matrix1;
}

static Numero_t * ac_mult_ (Numero_t * const num1, const Numero_t * const num2){

    return (Numero_t*) Ac_mult_((Matrix_t*)num1, (Matrix_t*)num2);
}
//=============================================================================================//

static Matrix_t * Ac_div_ (Matrix_t * const matrix1, const Matrix_t * const matrix2){

    if(!EqualSize(matrix1->tam,matrix2->tam)){

        printf(RED_COLOR"Impossible assign matrices with different sizes!\n"RESET_COLOR);
        exit(1);
    }

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            matrix1->matrix[x][y] /= matrix2->matrix[x][y];
        }
    }

    return matrix1;
}

static Numero_t * ac_div_ (Numero_t * const num1, const Numero_t * const num2){

    return (Numero_t*) Ac_div_((Matrix_t*)num1, (Matrix_t*)num2);
}
//=============================================================================================//

static int Compare_ (const Matrix_t * const matrix1, const Matrix_t * const matrix2){

    if(!EqualSize(matrix1->tam,matrix2->tam)) return 0;

    for(int x=0; x<matrix1->tam[0];x++){
        for(int y=0; y<matrix1->tam[1];y++){

            if(matrix1->matrix[x][y] != matrix2->matrix[x][y]){

                return 0;
            }
        }
    }

    return 1;
}

static int compare_ (const Numero_t * const num1, const Numero_t * const num2){

    return Compare_((Matrix_t*)num1, (Matrix_t*)num2);
}
//=============================================================================================//

static char * Print_ (const Matrix_t * const matrix){

    static char string[1000];

    for(int x=0; x<matrix->tam[0];x++){
        for(int y=0; y<matrix->tam[1];y++){

            printf("%.2lf ", matrix->matrix[x][y]);
            sprintf(string,"%.2lf ", matrix->matrix[x][y]);
        }
        printf("\n");
        sprintf(string,"\n");
    }
    printf("\n");

    return string;
}

static char * print_ (const Numero_t * const num){

    return Print_((Matrix_t*)num);
}
//=============================================================================================//

static void Destruct_ (Matrix_t * matrix){

    destruct_((Numero_t*)matrix);
}

static void destruct_ (Numero_t * num){

    for(int x=0;x< ((Matrix_t*)num)->tam[0];x++){

        if(((Matrix_t*)num)->matrix[x] != NULL) free(((Matrix_t*)num)->matrix[x]);
    }
    
    if(((Matrix_t*)num)->matrix != NULL) free(((Matrix_t*)num)->matrix);

    if(((Matrix_t*)num)->tam != NULL) free(((Matrix_t*)num)->tam );

    if(((Matrix_t*)num) != NULL) free(((Matrix_t*)num));    
}
