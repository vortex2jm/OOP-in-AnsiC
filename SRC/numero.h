//THIS CLASS WILL BE THE SUPER CLASS
#ifndef NUMERO_H
#define NUMERO_H

#include <stdint.h>

//STRUCTURES PROTOTYPES
struct NumeroVtbl;
struct Numero_st;

//STRUCTURE IMPLEMENTATION
struct Numero_st {
    struct NumeroVtbl const * metodo; /* ptr p/ os métodos */
} ;
typedef struct Numero_st 	Numero_t;
typedef struct Numero_st 	* Numero_pt;


//VIRTUAL TABLE
struct NumeroVtbl {

	Numero_pt 	(*copia)	(Numero_t const * const me);
    Numero_pt 	(*atribui)	(Numero_t const * const  me, Numero_t * const  outro);
    Numero_pt 	(*soma)		(Numero_t const * const  me, Numero_t const * const  outro, Numero_t * const res);
    Numero_pt 	(*subt)		(Numero_t const * const  me,Numero_t const * const  outro,Numero_t * const res);
    Numero_pt 	(*mult)		(Numero_t const * const  me,Numero_t const * const  outro,Numero_t * const res);
    Numero_pt 	(*divd)		(Numero_t const * const  me,Numero_t const * const  outro,Numero_t * const res);
    Numero_pt 	(*ac_soma)	(Numero_t * const  me,Numero_t const * const  outro);
    Numero_pt 	(*ac_subt)	(Numero_t * const  me,Numero_t const * const outro);
    Numero_pt 	(*ac_mult)	(Numero_t * const  me,Numero_t const * const outro);
    Numero_pt 	(*ac_divd)	(Numero_t * const  me,Numero_t const * const outro);
    int			(*compara)	(Numero_t const * const  me,Numero_t const * const  outro);
    char *      (*imprime)  (Numero_t const * const  me);
    void        (*destroi)  (Numero_t * me);
};

typedef struct NumeroVtbl NumeroVtbl_t;
typedef struct NumeroVtbl * NumeroVtbl_pt;


//CONSTRUCTOR IMPLEMENTATION
Numero_pt	Num_constroi(Numero_pt me);


//SHORTCUTS
static inline Numero_pt Num_copia	(Numero_t const * const me) {
 return (  me->metodo->copia(me));
}

static inline Numero_pt Num_atribui(Numero_t const * const  me,
									Numero_t       * const  outro)
{
 return (me->metodo->atribui(me, outro));
}

static inline Numero_pt Num_soma (Numero_t const * const  me,
								  Numero_t const * const  outro,
								  Numero_t       * const res)
{
 return (me->metodo->soma(me, outro, res));
}

static inline Numero_pt Num_subt (Numero_t const * const  me,
								  Numero_t const * const  outro,
								  Numero_t       * const res)
{
 return (me->metodo->subt(me, outro, res));
}

static inline Numero_pt Num_mult (Numero_t const * const  me,
								  Numero_t const * const  outro,
								  Numero_t       * const res)
{
 return (me->metodo->mult(me, outro, res));
}

static inline Numero_pt Num_divd (Numero_t const * const  me,
								  Numero_t const * const  outro,
								  Numero_t       * const res)
{
 return (me->metodo->divd(me, outro, res));
}

static inline Numero_pt Num_ac_soma (Numero_t       * const  me,
									 Numero_t const * const outro)
{
 return (me->metodo->ac_soma(me, outro));
}

static inline Numero_pt Num_ac_subt (Numero_t       * const  me,
									 Numero_t const * const outro)
{
 return (me->metodo->ac_subt(me, outro));
}

static inline Numero_pt Num_ac_mult (Numero_t       * const  me,
									 Numero_t const * const outro)
{
 return (me->metodo->ac_mult(me, outro));
}

static inline Numero_pt Num_ac_divd (Numero_t        * const  me,
									 Numero_t const * const outro)
{
 return (me->metodo->ac_divd(me, outro));
}

static inline int	Num_compara	  ( Numero_t const * const  me,
									Numero_t const * const  outro)
{
 return (me->metodo->compara(me, outro));
}

static inline char * Num_imprime (Numero_t const * const  me)
{
 return (me->metodo->imprime)(me);
}

static inline void  Num_destroi (Numero_t  *   me)
{
  /* (me->metodo->destroi)(me)*/;
}


#endif /* FIM DO NUMERO_H */
