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

static Racional_pt Invert_ (Racional_pt const rac);



//========================================================================================//

//========================ADDITIONAL FUNCTIONS PROTOTYPE=============================//

static long int Mdc(long int m,long int n); //euclides algorithm

static Racional_pt Irreduceble_ (Racional_pt const rac);


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
        .invert = &Invert_,
        .irreduceble = &Irreduceble_
    };

    rac->module = &racTab;

    rac->value[0] = num;
    rac->value[1] = den;

    return rac;
}

//==========================ADDITIONAL FUNCTIONS IMPLEMENTATION============================//

long int Mdc(long int m,long int n){    //euclides algorithm

    if(n==0) return m;
    Mdc(n,m%n);
}

static Racional_pt Irreduceble_ (Racional_pt const rac){

    long int num = Get_Num_(rac);
    long int den = Get_Den_(rac);
    long int res = Mdc(abs(num),abs(den));
    
    while(res > 1){

        num = num/res;
        den = den/res;
    }

    Set_(rac,num,den);

    return rac;
}


//==============EXCLUSIVE METHODS IMPLEMENTATION=======================//

static void Get_ (const Racional_pt const rac, long int * num, long int * den){

    *num = rac->value[0];
    *den = rac->value[1];
}

static void Set_ (Racional_pt const rac, long int num, long int den){

    rac->value[0] = num;
    rac->value[1] = den;
}

static long int Get_Num_ (const Racional_pt const rac){

    return rac->value[0];
}

static void Set_Num_ (Racional_pt const rac, long int num){

    rac->value[0] = num;
}

static long int Get_Den_ (const Racional_pt const rac){

    return rac->value[1];
}

static void Set_Den_ (Racional_pt const rac, long int den){

    rac->value[1] = den;
}

static double Float_Value_ (const Racional_pt const rac){

    return (double)rac->value[0]/(double)rac->value[1];
}

static Racional_pt Invert_ (Racional_pt const rac){

    long int aux = rac->value[0];
    rac->value[0] = rac->value[1];
    rac->value[1] = aux;

    return rac;
}

//====================================IMPLEMENTATION OF EQUIVALENT GLOBAL METHODS =====================================//

//================================= COPY

static inline Racional_pt Copy_ (const Racional_pt const rac){

    return (Racional_pt) copy_((Numero_pt)rac); //doublecasting
}

static Numero_pt copy_ (const Numero_pt const num){

    assert(num != NULL);

    Numero_pt num2 = (Numero_pt)Racional_Constructor(Get_Num_((Racional_pt)num), Get_Den_((Racional_pt)num));

    return (Numero_pt)num2;
}
//================================= ASSIGN

static inline Racional_pt Assign_ (const Racional_pt const rac1, Racional_pt const rac2){

    return (Racional_pt) assign_((Numero_pt)rac1,(Numero_pt)rac2);
}

static Numero_pt assign_ (const Numero_pt const num1,  Numero_pt const num2){

    Set_((Racional_pt)num2, Get_Num_((Racional_pt)num1), Get_Den_((Racional_pt)num1));

    return (Numero_pt)num2;
}
//================================ ADD

static Racional_pt Add_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res){

    return (Racional_pt) add_((Numero_pt)rac1, (Numero_pt)rac2, (Numero_pt)res);
}

static Numero_pt add_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res){

    long int numA,numB,denA,denB;

    Get_((Racional_pt)num1, &numA, &denA);
    Get_((Racional_pt)num2, &numB, &denB);

    long int num, den;
    den = denA * denB;
    num = (den/denA*numA) + (den/denB*numB);    

    Set((Racional_pt)res, num, den);

    Irreduceble_((Racional_pt)res);

    return (Numero_pt)res;
}
//================================ SUB

static Racional_pt Sub_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res){

    return (Racional_pt) sub_((Numero_pt)rac1, (Numero_pt)rac2, (Numero_pt)res);
}

static Numero_pt sub_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res);


static Racional_pt Mult_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res){

    return (Racional_pt) mult_((Numero_pt)rac1, (Numero_pt)rac2, (Numero_pt)res);
}

static Numero_pt mult_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res);


static Racional_pt Div_ (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res){

    return (Racional_pt) div_((Numero_pt)rac1, (Numero_pt)rac2, (Numero_pt)res);
}

static Numero_pt div_ (const Numero_pt const num1, const Numero_pt const num2, Numero_pt const res);








