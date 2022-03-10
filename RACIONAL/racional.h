#ifndef RACIONAL_H
#define RACIONAL_H
//Necessary modules
#include "numero.h"

//INTERFACE PROTOTYPE
struct Racional_Interface_st;

//==============================================================//

//RACIONAL STRUCTURE
struct Racional_st {

    Numero_t super;     //super class = struct Numero_st

    struct Racional_Interface_st const * module;    //Prototyped above

    long int * value;   //array (num/den)
};
//TYPING RACIONAL STRUCTURE
typedef struct Racional_st Racional_t;
typedef struct Racional_st* Racional_pt;

//==============================================================//

//INTERFACE STRUCTURE
struct Racional_Interface_st{

    //=============SUPER CLASS METHODS==========================//

    Racional_pt (*copy) (const Racional_pt const rac);

    Racional_pt (*assign) (const Racional_pt const rac1, Racional_pt const rac2);

    Racional_pt (*add) (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

    Racional_pt (*sub) (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

    Racional_pt (*mult) (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

    Racional_pt (*div) (const Racional_pt const rac1, const Racional_pt const rac2, Racional_pt const res);

    Racional_pt (*ac_add) (Racional_pt const rac1, const Racional_pt const rac2);

    Racional_pt (*ac_sub) (Racional_pt const rac1, const Racional_pt const rac2);

    Racional_pt (*ac_mult) (Racional_pt const rac1, const Racional_pt const rac2);

    Racional_pt (*ac_div) (Racional_pt const rac1, const Racional_pt const rac2);

    int (*compare) (const Racional_pt const rac1, const Racional_pt const rac2);

    char * (*print) (const Racional_pt const rac);

    void (*destruct) (Racional_pt rac);

    //================EXCLUSIVE METHODS=========================//

    void (*get) (const Racional_pt const rac, long int * num, long int * den);

    void (*set) (Racional_pt const rac, long int num, long int den);

    long int (*get_num) (const Racional_pt const rac);

    void (*set_num) (Racional_pt const rac, long int num);

    long int (*get_den) (const Racional_pt const rac);

    void (*set_den) (Racional_pt const rac, long int den);

    double (*float_value) (const Racional_pt const rac);

    Racional_pt (*inverse) (const Racional_pt const rac);

};

//TYPING INTERFACE STRUCTURE
typedef struct Racional_Interface_st Racional_Interface_t;
typedef struct Racional_Interface_st *Racional_Interface_pt;

//==============================================================//

//CONSTRUCTOR PROTOTYPE
Racional_pt Racional_Constructor(long int num, long int den);

//==============================================================//

//FUNCTIONS SHORTCUTS (simplification interface)

//void Get(const Racional_pt const rac, log int * num, long int * den){


//}


#endif //!RACIONAL_H