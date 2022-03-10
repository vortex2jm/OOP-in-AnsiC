#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "racional.h"

//===========SUPER CLASS METHODS PROTOTYPES=========WILL BE OVERWRITED============//

static Numero_pt copy_ (const Numero_pt const num);

static Numero_pt assign_ (const Numero_pt const num1,  Numero_pt const num2);

static Numero_pt add_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res);

static Numero_pt sub_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res);

static Numero_pt mult_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res);

static Numero_pt div_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res);

static Numero_pt ac_add_ (Numero_pt const num1, const Numero_pt const num2);

static Numero_pt ac_sub_ (Numero_pt const num1, const Numero_pt const num2);

static Numero_pt ac_mult_ (Numero_pt const num1, const Numero_pt const num2);

static Numero_pt ac_div_ (Numero_pt const num1, const Numero_pt const num2);

static int compare_ (const Numero_pt const num1, const Numero_pt const num2);

static char * print_ (const Numero_pt const num);

static void destruct_ (Numero_pt num);

//======================OVERWRITE METHODS PROTOTYPES======================//

static Racional_pt Copy_ (const Racional_pt const rac);

static Racional_pt Assign_ (const Racional_pt const rac1, Racional_pt const rac2);

static Racional_pt Add_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

static Racional_pt Sub_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

static Racional_pt Mult_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

static Racional_pt Div_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

static Racional_pt Ac_Add_ (Racional_pt const rac1, const Racional_pt const rac2);

static Racional_pt Ac_Sub_ (Racional_pt const rac1, const Racional_pt const rac2);

static Racional_pt Ac_Mult_ (Racional_pt const rac1, const Racional_pt const rac2);

static Racional_pt Ac_Div_ (Racional_pt const rac1, const Racional_pt const rac2);

static int Compare_ (const Racional_pt const rac1, const Racional_pt const rac2);

static char * Print_ (const Racional_pt const rac1);

static void Destruct_ (Racional_pt rac);

//=====================EXCLUSIVE METHODS PROTOTYPES=======================================//

static void Get_ (const Racional_pt const rac, long int * num, long int * den);

static void Set_ (Racional_pt const rac, long int num, long int den);

static long int Get_Num_ (const Racional_pt const rac);

static void Set_Num_ (Racional_pt const rac, long int num);

static long int Get_Den_ (const Racional_pt const rac);

static void Set_Den_ (Racional_pt const rac, long int den);

static double Float_Value_ (const Racional_pt const rac);

static Racional_pt Inverse_ (const Racional_pt const rac);

//========================================================================================//

//================CONSTRUCTOR METHOD IMPLEMENTATION=========================//

Racional_pt Racional_Constructor(long int num, long int den){


    Racional_pt rac = (Racional_pt) malloc(sizeof(Racional_pt));    //Dinamic alocation for Racional type

    //Constructing super class virtual table
    static NumeroVtbl_t numTab = {

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

    //Assigning super class on racional class
    rac = (Racional_pt) Num_constroi((Numero_pt)rac); //downcasting 
    
    rac->super.metodo = &numTab;

    //=======================================================//

    //Constructing racional's virtual table
    static Racional_Interface_t racTab = {

        .copy = &Copy_,
        .assign = &Assign_,
        .add = &Add_,
        .sub = &Sub_,
        .mult = &Mult_,
        .div = &Div_,
        .ac_add = &Ac_Add_,
        .ac_sub = &Ac_Sub_,
        .ac_mult = &Ac_Mult_,
        .ac_div = &Ac_Div_,
        .compare = &Compare_,
        .print = &Print_,
        .destruct = &Destruct_,
        .get = &Get_,
        .set = &Set_,
        .get_num = &Get_Num_,
        .set_num = &Set_Num_,
        .get_den = &Get_Den_,
        .set_den = &Set_Den_,
        .float_value = &Float_Value_,
        .inverse = &Inverse_
    };

    rac->module = &racTab;

    rac->value[0] = num;
    rac->value[1] = den;

    return rac;
}


//==============EXCLUSIVE METHODS IMPLEMENTATION=======================//

static void Get_ (const Racional_pt const rac, long int * num, long int * den){

    *num = rac->value[0];
    *den = rac->value[1];
}

