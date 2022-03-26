#include  <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "numero.h"

//========METHODS PROTOTYPES=========================================//

static  Numero_pt Num_copia_ (Numero_t const * const me);
static  Numero_pt Num_atribui_ (Numero_t const * const me,Numero_t * const   outro) ;
static  Numero_pt Num_soma_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt Num_subt_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt Num_mult_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt Num_divd_  (Numero_t const * const  me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt Num_ac_soma_  (Numero_t * const me,Numero_t const * const outro);
static  Numero_pt Num_ac_subt_  (Numero_t * const me,Numero_t const * const outro);
static  Numero_pt Num_ac_mult_  (Numero_t * const me,Numero_t const * const outro);
static  Numero_pt Num_ac_divd_  (Numero_t * const me,Numero_t const * const outro);
static  int	Num_compara_ 	(Numero_t const * const me,Numero_t const * const outro);
static  char * Num_imprime_  (Numero_t const * const me);
static  void   Num_destroi_  (Numero_t * me);


//IMPLEMENTING CONSTRUCTOR
  Numero_pt Num_constroi (Numero_pt  me)
{
	/* aloca dinamicamente uma area de memoria para um Numero_t */
	me = (Numero_t *) malloc (sizeof(Numero_t));
	if (me == NULL)
	{	
	    printf ("Error alocating a Number type :/\n");
	    exit (1);
	}

    static struct NumeroVtbl const vtbl = {
       	&Num_copia_,
        &Num_atribui_,
        &Num_soma_,
        &Num_subt_,
        &Num_mult_,
        &Num_divd_,
        &Num_ac_soma_,
        &Num_ac_subt_,
        &Num_ac_mult_,
        &Num_ac_divd_,
        &Num_compara_,
        &Num_imprime_,
        &Num_destroi_
     };

     me->metodo = &vtbl; 

     return (me);
}


//METHODS IMPLEMENTATION

static inline Numero_pt Num_copia_ (Numero_t const * const    me)
{
	assert (0);
	printf ("%p",(void *)me);
	return (Numero_pt) NULL;
}

static inline Numero_pt Num_atribui_ (Numero_t const * const    me,
									  Numero_t       * const    outro)
{
	assert (0);  /* função virtual ... nunca deve ser chamada */
	printf ("%p %p",(void *)me, (void *)outro);
	return (Numero_pt) NULL;  /*faço retorno para evitar erro de
	                            compilação */
}

static inline Numero_pt Num_soma_  (Numero_t const * const    me,
									Numero_t const * const    outro,
									Numero_t       * const    res)
{
	assert (0);
	printf ("%p %p %p",(void *)me, (void *)outro, (void *)res);
	return (Numero_pt) NULL;
}

static inline Numero_pt Num_subt_  (Numero_t const * const    me,
									Numero_t const * const    outro,
									Numero_t       * const    res)
{
	assert (0);
	printf ("%p %p %p",(void *)me, (void *)outro, (void *)res);
	return (Numero_pt) NULL;
}

static inline Numero_pt Num_mult_  (Numero_t const * const    me,
									Numero_t const * const    outro,
									Numero_t       * const    res)
{
	assert (0);
	printf ("%p %p %p",(void *)me, (void *)outro, (void *)res);

	return (Numero_pt) NULL;
}

static inline Numero_pt Num_divd_  (Numero_t const * const    me,
									Numero_t const * const    outro,
									Numero_t       * const    res)
{
	assert (0);
	printf ("%p %p %p",(void *)me, (void *)outro, (void *)res);
	return (Numero_pt) NULL;
}

static inline Numero_pt Num_ac_soma_  (Numero_t       * const    me,
									   Numero_t const * const    outro)
{
	assert (0);
	printf ("%p %p",(void *)me, (void *)outro);
	return (Numero_pt) NULL;
}

static inline Numero_pt Num_ac_subt_  (Numero_t       * const    me,
									   Numero_t const * const    outro)
{
	assert (0);
	printf ("%p %p",(void *)me, (void *)outro);
	return (Numero_pt) NULL;
}

static inline Numero_pt Num_ac_mult_  (Numero_t       * const    me,
									   Numero_t const * const    outro)
{
	assert (0);
	printf ("%p %p",(void *)me, (void *)outro);
	return (Numero_pt) NULL;
}

static inline Numero_pt Num_ac_divd_  (Numero_t       * const    me,
									   Numero_t const * const    outro)
{
	assert (0);
	printf ("%p %p",(void *)me, (void *)outro);
	return (Numero_pt) NULL;
}


static inline int	Num_compara_ 	(Numero_t const * const    me,
									 Numero_t const * const    outro)
{
	assert (0);
	printf ("%p %p",(void *)me, (void *)outro);
	return (0);
}


static inline char * Num_imprime_  (Numero_t const * const    me)
{
	assert (0);
	printf ("%p",(void *)me);
	return (char *) NULL;
}

static inline void Num_destroi_ (Numero_t * me)
{
	/* *free (me); */
}