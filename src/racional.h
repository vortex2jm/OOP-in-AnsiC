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

    struct Racional_Interface_st const * methods;    //Prototyped above

    long int * value;   //array (num/den)
};
//TYPING RACIONAL STRUCTURE
typedef struct Racional_st Racional_t;
typedef struct Racional_st* Racional_pt;

//==============================================================//

//INTERFACE STRUCTURE
struct Racional_Interface_st{

    //=============SUPER CLASS METHODS==========================//

    Racional_t * (*copy) (const Racional_t * const rac);
    Racional_t * (*assign) (const Racional_t * const rac1, Racional_t * const rac2);
    Racional_t * (*add) (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
    Racional_t * (*sub) (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
    Racional_t * (*mult) (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
    Racional_t * (*div) (const Racional_t * const rac1, const Racional_t * const rac2, Racional_t * const res);
    Racional_t * (*ac_add) (Racional_t * const rac1, const Racional_t * const rac2);
    Racional_t * (*ac_sub) (Racional_t * const rac1, const Racional_t * const rac2);
    Racional_t * (*ac_mult) (Racional_t * const rac1, const Racional_t * const rac2);
    Racional_t * (*ac_div) (Racional_t * const rac1, const Racional_t * const rac2);
    int (*compare) (const Racional_t * const rac1, const Racional_t * const rac2);
    char * (*print) (const Racional_t * const rac);
    void (*destruct) (Racional_t * rac);

    //================EXCLUSIVE METHODS=========================//

    void (*get) (const Racional_t * const rac, long int * num, long int * den);
    void (*set) (Racional_t * const rac, long int num, long int den);
    long int (*get_num) (const Racional_t * const rac);
    void (*set_num) (Racional_t * const rac, long int num);
    long int (*get_den) (const Racional_t * const rac);
    void (*set_den) (Racional_t * const rac, long int den);
    double (*float_value) (const Racional_t * const rac);
    Racional_t * (*invert) (Racional_t * const rac);
    Racional_t * (*irreduceble) (Racional_t * const rac);
};

//TYPING INTERFACE STRUCTURE
typedef struct Racional_Interface_st Racional_Interface_t;
typedef struct Racional_Interface_st *Racional_Interface_pt;

//==============================================================//

//CONSTRUCTOR PROTOTYPE
Racional_t * Racional_Constructor(long int num, long int den);

#endif //!RACIONAL_H