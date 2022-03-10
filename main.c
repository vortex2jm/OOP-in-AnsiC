/* main.c */
/* teste do tipo de dados meudouble */
#include <stdio.h>
#include "meu_complexo.h"

int main ()
{

/** ------ PARTE ORIGINAL DO PROGRAMA MEU_COMPLEXO ------*/
	MeuComplexo_pt ptC1=NULL, ptC2=NULL, ptC3=NULL, ptC4=NULL;

	/*veja que aqui neste ponto faço chamadas de algumas funções
	 * através dos ponteiros que estão na tabela vtbl (ponteiro "metodo")
	 * da superclasse "Numero". Como as funções desta tabela esperam
	 * receber "ponteiro para Numero_t", preciso converter o ptX1 para
	 * Numero_pt e depois converter o resultado "de volta" para
	 * MeuDouble_pt */

	ptC1 = Complexo_constroi (ptC1, 10.0, 20.0);

	ptC2 = ptC1->Metodo->copia (ptC1);

	printf ("Os dois numeros sao %s %s \n",
				ptC1->Metodo->imprime (ptC1),
				ptC2->Metodo->imprime (ptC2));

    ptC3 = Complexo_constroi (ptC3, 0.0, 0.0);
    ptC3 = ptC2->Metodo->atribui (ptC2, ptC3);
    printf ("ptC3 recebeu o valor de Y2 = %s \n",
				ptC3->Metodo->imprime (ptC3));


    ptC3 = ptC1->Metodo->soma(ptC1, ptC2, ptC3);
    printf ("ptC3 recebeu a soma de Y1 com Y2 = %s \n",
				ptC3->Metodo->imprime (ptC3));

    ptC3 = ptC3->Metodo->subt(ptC3, ptC2, ptC3);
    printf ("ptC3 recebeu a subtracao de Y3 com Y2 = %s \n",
				ptC3->Metodo->imprime (ptC3));

    ptC3 = ptC1->Metodo->mult(ptC1, ptC2, ptC3);
    printf ("ptC3 recebeu a multiplicacao de Y1 com Y2 = %s \n",
                 ptC3->Metodo->imprime (ptC3));

    ptC3 = ptC1->Metodo->divd(ptC1, ptC2, ptC3);
    printf ("ptC3 recebeu a divisão de Y1 com Y2 = %s \n",
                 ptC3->Metodo->imprime (ptC3));

    ptC3 = ptC1->Metodo->ac_soma(ptC3, ptC2);
    printf ("ptC3 foi somado com Y2 = %s \n",
				ptC3->Metodo->imprime (ptC3));

    ptC3 = ptC3->Metodo->ac_subt(ptC3, ptC2);
    printf ("ptC3 foi subtraido de Y2 = %s \n",
				ptC3->Metodo->imprime (ptC3));

    ptC3 = ptC1->Metodo->ac_mult(ptC3, ptC2);
    printf ("ptC3 foi multiplicado por Y2 = %s \n",
                 ptC3->Metodo->imprime (ptC3));

    ptC3 = ptC1->Metodo->ac_divd(ptC3, ptC2);
    printf ("ptC3 foi dividido por Y2 = %s \n",
                 ptC3->Metodo->imprime (ptC3));

    if (ptC1->Metodo->compara(ptC1,ptC2)==0)
    {
       printf ("Y1 eh igual a Y2 = %s\n", ptC1->Metodo->imprime(ptC1));
    }
    if (ptC1->Metodo->compara(ptC2,ptC3)>0)
    {
       printf ("Y2 eh maior que Y3 \n");
    }
    if (ptC1->Metodo->compara(ptC2,ptC3)<0)
    {
       printf ("Y2 eh menor que Y3 \n");
    }




   //IMPLEMENTAÇÃO DOS ATALHOS================!!!!!!!!!!!!!!
   double a,b;
   Get(ptC1,&a,&b);
   printf("\n\n\n%lf e %lf", a,b);

   ptC4 = Complexo_constroi(ptC4,0.0,0.0);
   Soma(ptC1,ptC2,ptC4);
   printf("\n\n\n ptC4 = %s\n", ptC4->Metodo->imprime(ptC4));
   //=========================================================//





	ptC1->Metodo->destroi (ptC1);
	ptC2->Metodo->destroi (ptC2);
   ptC3->Metodo->destroi (ptC3);
   ptC4->Metodo->destroi (ptC4);
	return (0);
}








