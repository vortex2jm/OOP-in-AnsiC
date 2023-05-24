#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "racional.h"

//===========SUPER CLASS METHODS PROTOTYPES=========WILL BE OVERWRITED============//

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

//======================OVERWRITE METHODS PROTOTYPES======================//

static Racional_t * Copy_ (const Racional_t * const rac);
static Racional_t * Assign_ (const Racional_t * const rac1, Racional_t * const rac2);
static Racional_t * Add_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
static Racional_t * Sub_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
static Racional_t * Mult_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
static Racional_t * Div_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
static Racional_t * Ac_Add_ (Racional_t * const rac1, const Racional_t * const rac2);
static Racional_t * Ac_Sub_ (Racional_t * const rac1, const Racional_t * const rac2);
static Racional_t * Ac_Mult_ (Racional_t * const rac1, const Racional_t * const rac2);
static Racional_t * Ac_Div_ (Racional_t * const rac1, const Racional_t * const rac2);
static int Compare_ (const Racional_t * const rac1, const Racional_t * const rac2);
static char * Print_ (const Racional_t * const rac1);
static void Destruct_ (Racional_t * rac);

//=====================EXCLUSIVE METHODS PROTOTYPES=======================================//

static void Get_ (const Racional_t * const rac, long int * num, long int * den);
static void Set_ (Racional_t * const rac, long int num, long int den);
static long int Get_Num_ (const Racional_t * const rac);
static void Set_Num_ (Racional_t * const rac, long int num);
static long int Get_Den_ (const Racional_t * const rac);
static void Set_Den_ (Racional_t * const rac, long int den);
static double Float_Value_ (const Racional_t * const rac);
static Racional_t * Invert_ (Racional_t * const rac);
static Racional_t * Irreduceble_ (Racional_t * const rac);
//========================================================================================//

//========================ADDITIONAL FUNCTIONS PROTOTYPE=============================//

static long int Mdc(long int m,long int n); //euclides algorithm


//================CONSTRUCTOR METHOD IMPLEMENTATION=========================//

Racional_t * Racional_Constructor(long int num, long int den){

    if(!den){
        printf("Division by zero doesn't exist! Choose another number C:  ->  ");
        exit(1);
    }

    Racional_t * rac = (Racional_t*) malloc(sizeof(Racional_t));

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
    // rac = (Racional_t *) Num_constroi((Numero_t *)rac); //downcasting 
    
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

    rac->methods = &racTab;

    rac->value = (long int *) malloc(sizeof(long int) * 2);

    if(rac->value == NULL){

        printf("Alocating memory error :: rac.value");
        exit(1);
    }

    rac->value[0] = num;
    rac->value[1] = den;

    return rac;
}

//==========================ADDITIONAL FUNCTIONS IMPLEMENTATION============================//

long int Mdc(long int m,long int n){    //euclides algorithm

    if(n==0) return m;
    return Mdc(n,m%n);
}

static Racional_t * Irreduceble_ (Racional_t * const rac){

    long int num = Get_Num_(rac);
    long int den = Get_Den_(rac);
    long int res = 2; 
    
    while(res > 1){

        res = Mdc(abs(num),abs(den));
        num = num/res;
        den = den/res;
    }

    Set_(rac,num,den);

    return rac;
}


//==============EXCLUSIVE METHODS IMPLEMENTATION=======================//

static void Get_ (const Racional_t * const rac, long int * num, long int * den){

    *num = rac->value[0];
    *den = rac->value[1];
}

static void Set_ (Racional_t * const rac, long int num, long int den){

    rac->value[0] = num;
    rac->value[1] = den;
}

static long int Get_Num_ (const Racional_t * const rac){

    return rac->value[0];
}

static void Set_Num_ (Racional_t * const rac, long int num){

    rac->value[0] = num;
}

static long int Get_Den_ (const Racional_t * const rac){

    return rac->value[1];
}

static void Set_Den_ (Racional_t * const rac, long int den){

    rac->value[1] = den;
}

static double Float_Value_ (const Racional_t * const rac){

    return (double)rac->value[0]/(double)rac->value[1];
}

static Racional_t * Invert_ (Racional_t * const rac){

    long int aux = rac->value[0];
    rac->value[0] = rac->value[1];
    rac->value[1] = aux;

    return rac;
}

//====================================IMPLEMENTATION OF EQUIVALENT GLOBAL METHODS =====================================//

//================================= COPY

static inline Racional_t * Copy_ (const Racional_t * const rac){

    return (Racional_t *) copy_((Numero_t *)rac); //doublecasting
}

static Numero_t * copy_ (const Numero_t * const num){

    assert(num != NULL);

    Numero_t * num2 = (Numero_t *)Racional_Constructor(Get_Num_((Racional_t *)num), Get_Den_((Racional_t *)num));

    return (Numero_t *)num2;
}
//================================= ASSIGN

static inline Racional_t * Assign_ (const Racional_t * const rac1, Racional_t * const rac2){

    return (Racional_t *) assign_((Numero_t *)rac1,(Numero_t *)rac2);
}

static Numero_t * assign_ (const Numero_t * const num1,  Numero_t * const num2){

    Set_((Racional_t *)num2, Get_Num_((Racional_t *)num1), Get_Den_((Racional_t *)num1));

    return (Numero_t *)num2;
}
//================================ ADD

static inline Racional_t * Add_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res){

    return (Racional_t *) add_((Numero_t *)rac1, (Numero_t *)rac2, (Numero_t *)res);
}

static Numero_t * add_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){

    long int numA,numB,denA,denB;

    Get_((Racional_t *)num1, &numA, &denA);
    Get_((Racional_t *)num2, &numB, &denB);

    long int num, den;
    den = denA * denB;
    num = (den/denA*numA) + (den/denB*numB);    

    Set_((Racional_t *)res, num, den);

    Irreduceble_((Racional_t *)res);

    return (Numero_t *)res;
}
//================================ SUB

static inline Racional_t * Sub_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res){

    return (Racional_t *) sub_((Numero_t *)rac1, (Numero_t *)rac2, (Numero_t *)res);
}

static Numero_t * sub_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){

    long int numA,numB,denA,denB;

    Get_((Racional_t *)num1, &numA, &denA);
    Get_((Racional_t *)num2, &numB, &denB);

    long int num, den;
    den = denA * denB;
    num = (den/denA*numA) - (den/denB*numB);    

    Set_((Racional_t *)res, num, den);

    Irreduceble_((Racional_t *)res);

    return (Numero_t *)res;
}
//=============================== MULT

static inline Racional_t * Mult_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res){

    return (Racional_t *) mult_((Numero_t *)rac1, (Numero_t *)rac2, (Numero_t *)res);
}

static Numero_t * mult_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){

    Set_((Racional_t *)res,
                            Get_Num_((Racional_t *)num1) * Get_Num_((Racional_t *)num2),
                            Get_Den_((Racional_t *)num1) * Get_Den_((Racional_t *)num2)
    );

    Irreduceble_((Racional_t *)res);

    return (Numero_t *)res;
}
//=============================== DIV

static Racional_t * Div_ (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res){

    return (Racional_t *) div_((Numero_t *)rac1, (Numero_t *)rac2, (Numero_t *)res);
}

static Numero_t * div_ (const Numero_t * const num1, const Numero_t * const num2, Numero_t * const res){

    Invert_((Racional_t *)num2);
    Mult_((Racional_t *)num1, (Racional_t *)num2, (Racional_t *)res);
    Irreduceble_((Racional_t *)res);
    Invert_((Racional_t *)num2);

    return (Numero_t *)res;
}

//============================== AC_ADD

static Racional_t * Ac_Add_ (Racional_t * const rac1, const Racional_t * const rac2){

    return (Racional_t *) ac_add_((Numero_t *)rac1, (Numero_t *)rac2);
}

static Numero_t * ac_add_ (Numero_t * const num1, const Numero_t * const num2){

    long int numA,numB,denA,denB;

    Get_((Racional_t *)num1, &numA, &denA);
    Get_((Racional_t *)num2, &numB, &denB);

    long int num, den;
    den = denA * denB;
    num = (den/denA*numA) + (den/denB*numB);    

    Set_((Racional_t *)num1, num, den);

    Irreduceble_((Racional_t *)num1);

    return (Numero_t *)num1;
}
//============================== AC_SUB

static Racional_t * Ac_Sub_ (Racional_t * const rac1, const Racional_t * const rac2){

    return (Racional_t *) ac_sub_((Numero_t *)rac1, (Numero_t *)rac2);
}

static Numero_t * ac_sub_ (Numero_t * const num1, const Numero_t * const num2){

    long int numA,numB,denA,denB;

    Get_((Racional_t *)num1, &numA, &denA);
    Get_((Racional_t *)num2, &numB, &denB);

    long int num, den;
    den = denA * denB;
    num = (den/denA*numA) - (den/denB*numB);    

    Set_((Racional_t *)num1, num, den);

    Irreduceble_((Racional_t *)num1);

    return (Numero_t *)num1;
}
//============================== AC_MULT

static Racional_t * Ac_Mult_ (Racional_t * const rac1, const Racional_t * const rac2){

    return (Racional_t *) ac_mult_((Numero_t *)rac1, (Numero_t *)rac2);
}

static Numero_t * ac_mult_ (Numero_t * const num1, const Numero_t * const num2){

    Set_((Racional_t *)num1,
                            Get_Num_((Racional_t *)num1) * Get_Num_((Racional_t *)num2),
                            Get_Den_((Racional_t *)num1) * Get_Den_((Racional_t *)num2)
    );

    Irreduceble_((Racional_t *)num1);

    return (Numero_t *)num1;
}
//============================== AC_DIV

static Racional_t * Ac_Div_ (Racional_t * const rac1, const Racional_t * const rac2){

    return (Racional_t *) ac_div_((Numero_t *)rac1, (Numero_t *)rac2);
}

static Numero_t * ac_div_ (Numero_t * const num1, const Numero_t * const num2){

    Invert_((Racional_t *)num2); 
    Ac_Mult_((Racional_t *)num1, (Racional_t *)num2);    
    Irreduceble_((Racional_t *)num1);
    Invert_((Racional_t *)num2);

    return (Numero_t *)num1;
}
//============================== COMPARE

static int Compare_ (const Racional_t * const rac1, const Racional_t * const rac2){

    return compare_((Numero_t *)rac1, (Numero_t *)rac2);
}

static int compare_ (const Numero_t * const num1, const Numero_t * const num2){

    if((double)Get_Num_((Racional_t *)num1) / (double)Get_Den_((Racional_t *)num1)  ==
       (double)Get_Num_((Racional_t *)num2) / (double)Get_Den_((Racional_t *)num2)
    )return 1;
    
    else return 0;
}
//============================== PRINT

static char * Print_ (const Racional_t * const rac1){

    return print_((Numero_t *)rac1);
}

static char * print_ (const Numero_t * const num){

    static char string[10];
    long int numerator,den;
    Get_((Racional_t *)num,&numerator,&den);

    if(!numerator) sprintf(string,"0\n"); //numerador = 0 

    else if(den == 1) sprintf(string,"%ld\n",numerator); //denominador = 1

    else if(den == -1) sprintf(string,"%ld\n", numerator *(-1));

    else if((numerator < 0 && den > 0) || (numerator > 0 && den < 0)) sprintf(string,"-%d/%d\n",abs(numerator), abs(den));
    
    else sprintf(string,"%d/%d\n",abs(numerator), abs(den));

    return string;
}
//============================== DESTRUCT

static void Destruct_ (Racional_t * rac){

    destruct_((Numero_t *)rac);
}

static void destruct_ (Numero_t * num){

    free(((Racional_t *)num)->value);
    free((Racional_t*)num);
}