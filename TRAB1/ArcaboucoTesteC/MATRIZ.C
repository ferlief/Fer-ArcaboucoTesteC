/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo MATRIZ
*
*  Arquivo gerado:              MATRIZ.C
*  Letras identificadoras:      MAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: INF 1301 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: aw - Alexandre Werneck
*           fr - Fernanda Camelo Ribeiro
*			vo - Vinicius de Luiz de Oliveira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   afv   29/08/2013 In�cio do desenvolvimento
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include "LISTA.H"

#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor do elemento da matriz - 05/09/2013
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do elemento
*
***********************************************************************/

typedef struct tpElemMatriz {

        struct tpElemMatriz * pNoNoroeste ; 
			/* Adjacente da quina superior esquerda */
		
        struct tpElemMatriz * pNoNorte ;
			/* Adjacente de cima */

        struct tpElemMatriz * pNoNordeste ;
            /* Adjacente da quina superior direita */
            
        struct tpElemMatriz * pNoOeste ; 
            /* Adjacente da esqueda */
            
        struct tpElemMatriz * pNoLeste ;
            /* Adjacente da direita */

        struct tpElemMatriz * pNoSudoeste ;
            /* Adjacente da quina inferior esquerda */
            
        struct tpElemMatriz * pNoSul ;
            /* Adjacente de baixo */

        struct tpElemMatriz * pNoSudeste ;
            /* Adjacente da quina inferior direita */

        struct LIS_tpMatLista * Lista;
			/* Lista para o elemento da Matriz do tipo LISTA que armazena caracteres */

} tpElemMatriz ;


/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor da raiz de uma matriz
*
*
*  $ED Descri��o do tipo
*	  A raiz da matriz indica o in�cio da matriz , refere-se ao elemento (0,0)
*	  A estrutura matriz tamb�m armazena uma refer�ncia ao n� ind�ce 
*	  de coluna para a cria��o da matriz.
*	  Atrav�s do n� corrente pode-se navegar a matriz.
*
***********************************************************************/

typedef struct MAT_tgMatriz {

        tpElemMatriz * pNoRaiz ;
            /* Ponteiro para a raiz da matriz */

		tpElemMatriz * pNoIndLinha ;
            /* Ponteiro para a indice de linha da matriz */

        tpElemMatriz * pNoCorr ;
            /* Ponteiro para o n� corrente da matriz */

} MAT_tpMatriz ;


/***** Prot�tipos das fun��es encapsuladas no m�dulo *****/

static MAT_tpCondRet PreparaEstruturaMatriz( MAT_tpMatriz * tpMat , int numElementos ) ;

static MAT_tpCondRet CriarNoRaiz( MAT_tpMatriz * tpMat , int numElementos ) ;

static void DestroiMatriz( MAT_tpMatriz * tpMatExc ) ;

static void DestroiNoMatriz( MAT_tpMatriz * tpMatExc );

static tpElemMatriz * CriarNo( ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: MAT CriarMatriz - 05/09/2013
*  
****/

MAT_tpCondRet MAT_CriarMatriz( MAT_tppMatriz *tpMat , int numElementos){
	   
		MAT_tpCondRet CondRet ;

		MAT_tppMatriz mMatriz ;

		if((*tpMat) != NULL)
		{
			DestroiMatriz( (*tpMat) ); 
		} /* if */
		
		mMatriz = ( MAT_tppMatriz ) malloc ( sizeof ( MAT_tpMatriz ) );
			/* Malloc para gerar um ponteiro de matriz */

		   
	   if(mMatriz == NULL)
	   {
		   return MAT_CondRetFaltouMemoria ;
	   } /* if */
	   
	   mMatriz->pNoCorr      = NULL;
	   mMatriz->pNoRaiz      = NULL;
	   mMatriz->pNoIndLinha  = NULL;

	   CondRet = CriarNoRaiz(mMatriz , numElementos);
			 /* Inicializo a estrutura da matriz setando a raiz */

	   if(CondRet != MAT_CondRetOK)
	   {
		return CondRet;
	   } /* if */


	   (*tpMat) = ( MAT_tpMatriz* ) malloc( sizeof( MAT_tppMatriz )) ;

		if ( (*tpMat) == NULL )
		{
			return MAT_CondRetFaltouMemoria ;
		} /* if */

		(*tpMat) = mMatriz ;


		return MAT_CondRetOK ;
}


/***************************************************************************
*
*  Fun��o: MAT InsereListaMatriz - 05/09/2013
*
*	Percorre a estrutura da matriz procurando espa�o vazio para
*	armazenar a lista criada.
*  
****/

MAT_tpCondRet MAT_InsereListaMatriz( LIS_tpMatLista * lt, MAT_tppMatriz tpMat){


	if( lt == NULL ){
		return MAT_CondRetListaVazia ;
	} /* if */

	if ( tpMat == NULL )
    {
        return MAT_CondRetMatrizNaoExiste ;
    } /* if */
	
	tpMat->pNoCorr     = tpMat->pNoRaiz;
	tpMat->pNoIndLinha = tpMat->pNoCorr;

	  /* procura a pr�xima posi��o de mem�ria vazia para inserir a lista */
	while(tpMat->pNoCorr != NULL){
		if(tpMat->pNoCorr->Lista == NULL){
				tpMat->pNoCorr->Lista = lt;
				return MAT_CondRetOK;
		}else{
			if(tpMat->pNoCorr->pNoLeste == NULL){
				tpMat->pNoCorr     = tpMat->pNoIndLinha->pNoSul;
				tpMat->pNoIndLinha = tpMat->pNoCorr;
			}else{
				tpMat->pNoCorr = tpMat->pNoCorr->pNoLeste;
			} /* if */
		}/* if */
	}

	return MAT_CondRetMatrizCheia ;
		/* sem lugar para inserir */

}

/***************************************************************************
*
*  Fun��o: MAT IrNoNorte - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoNorte(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoNorte == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

      tpMat->pNoCorr = tpMat->pNoCorr->pNoNorte ;

      return MAT_CondRetOK ;

} /* Fim do IrNoNorte */

/***************************************************************************
*
*  Fun��o: MAT IrNoNordeste - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoNordeste(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoNordeste == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

      tpMat->pNoCorr = tpMat->pNoCorr->pNoNordeste ;

      return MAT_CondRetOK ;

} /* Fim do IrNoNordeste */

/***************************************************************************
*
*  Fun��o: MAT IrNoLeste - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoLeste(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoLeste == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

	  tpMat->pNoCorr = tpMat->pNoCorr->pNoLeste ;

      return MAT_CondRetOK ;

} /* Fim do MAT IrNoLeste */

/***************************************************************************
*
*  Fun��o: MAT IrNoSudeste - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoSudeste(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoSudeste == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

      tpMat->pNoCorr = tpMat->pNoCorr->pNoSudeste ;

      return MAT_CondRetOK ;

} /* Fim do MAT IrNoSudeste */

/***************************************************************************
*
*  Fun��o: MAT IrNoSul - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoSul(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoSul == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

      tpMat->pNoCorr = tpMat->pNoCorr->pNoSul ;

      return MAT_CondRetOK ;

} /* Fim do MAT IrNoSul */

/***************************************************************************
*
*  Fun��o: MAT IrNoSudoeste - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoSudoeste(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoSudoeste == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

      tpMat->pNoCorr = tpMat->pNoCorr->pNoSudoeste ;

      return MAT_CondRetOK ;

} /* Fim do MAT IrNoSudoeste */

/***************************************************************************
*
*  Fun��o: MAT IrNoOeste - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoOeste(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoOeste == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

      tpMat->pNoCorr = tpMat->pNoCorr->pNoOeste ;

      return MAT_CondRetOK ;

} /* Fim do MAT IrNoOeste */

/***************************************************************************
*
*  Fun��o: MAT IrNoNoroeste - 05/09/2013
*  
****/
   
MAT_tpCondRet MAT_IrNoNoroeste(MAT_tpMatriz * tpMat){

	  if ( tpMat == NULL )
      {
         return MAT_CondRetMatrizNaoExiste ;
      } /* if */

      if ( tpMat->pNoCorr == NULL )
      {
         return MAT_CondRetMatrizVazia ;
      } /* if */

	  if ( tpMat->pNoCorr->pNoNoroeste == NULL )
      {
         return MAT_CondRetNaoPossuiNo ;
      } /* if */

      tpMat->pNoCorr = tpMat->pNoCorr->pNoNoroeste ;

      return MAT_CondRetOK ;

} /* Fim do MAT IrNoNoroeste */




/***************************************************************************
*
*  Fun��o: MAT Obter Lista corrente
*  ****/

MAT_tpCondRet MAT_ObterListaCorr( LIS_tpMatLista * lst_valor , MAT_tpMatriz * tpMat)
{

    if ( tpMat == NULL )
    {
        return MAT_CondRetMatrizNaoExiste  ;
    } /* if */
	if ( tpMat->pNoCorr == NULL )
    {
        return MAT_CondRetMatrizVazia ;
    } /* if */
	if ( tpMat->pNoCorr->Lista == NULL )
    {
        return MAT_CondRetNoMatrizSemLista ;
    } /* if */
    
	if(lst_valor == tpMat->pNoCorr->Lista)
	{
		return MAT_CondRetOK  ;
	}

	return MAT_CondRetNoListaDiferente ;
		/* Lista passada diferente da corrente */

} /* Fim fun��o: MAT Obter Lista corrente */


/***************************************************************************
*
*  Fun��o: MAT Ir para n� raiz
*  ****/

MAT_tpCondRet MAT_IrRaiz( MAT_tpMatriz * tpMat )
{

    if ( tpMat == NULL )
    {
        return MAT_CondRetMatrizNaoExiste  ;
    } /* if */
    if ( tpMat->pNoCorr == NULL )
    {
        return MAT_CondRetMatrizVazia ;
    } /* if */

    if ( tpMat->pNoRaiz != NULL )
    {
		tpMat->pNoCorr = tpMat->pNoRaiz ;
        return MAT_CondRetOK ;
    } else {
        return MAT_CondRetNohEhRaiz ;
    } /* if */

} /* Fim fun��o: MAT Ir para n� raiz */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: MAT Destruir a estrutura da matriz
*		Chamada recursiva que percorre os elementos do n� corrente
*		da um free quando chega no �ltimo elemento
*
*  $EAE Assertivas de entradas esperadas
*     pMatriz != NULL
*
***********************************************************************/

void DestroiMatriz( MAT_tpMatriz * tpMatExc )
   {

	   if ( tpMatExc != NULL )
      {
         if ( tpMatExc->pNoCorr != NULL )
         {
			 DestroiNoMatriz( tpMatExc ) ;
         } /* if */
         free( tpMatExc ) ;
         tpMatExc = NULL ;
      } /* if */

	   

   } /* Fim fun��o: MAT Destruir a estrutura da matriz */

/***********************************************************************
*
*  $FC Fun��o: MAT Destruir a estrutura da matriz
*		Chamada recursiva que percorre os elementos do n� corrente
*		da um free quando chega no �ltimo elemento
*
*  $EAE Assertivas de entradas esperadas
*     pMatriz != NULL
*
***********************************************************************/

void DestroiNoMatriz( MAT_tpMatriz * tpMatExc )
   {

	  if ( tpMatExc->pNoCorr->pNoSudeste != NULL )
      {
		 tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoSudeste;
         free(tpMatExc->pNoCorr->pNoSudeste);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  if ( tpMatExc->pNoCorr->pNoSul != NULL )
      {
         tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoSul;
         free(tpMatExc->pNoCorr->pNoSul);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  if ( tpMatExc->pNoCorr->pNoSudoeste != NULL )
      {
         tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoSudoeste;
         free(tpMatExc->pNoCorr->pNoSudoeste);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  if ( tpMatExc->pNoCorr->pNoLeste != NULL )
      {
         tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoLeste;
		 free(tpMatExc->pNoCorr->pNoLeste);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  if ( tpMatExc->pNoCorr->pNoOeste != NULL )
      {
         tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoOeste;
         free(tpMatExc->pNoCorr->pNoOeste);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  if ( tpMatExc->pNoCorr->pNoNordeste != NULL )
      {
         tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoNordeste;
         free(tpMatExc->pNoCorr->pNoNordeste);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  if ( tpMatExc->pNoCorr->pNoNorte != NULL )
      {
         tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoNorte;
         free(tpMatExc->pNoCorr->pNoNorte);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  if ( tpMatExc->pNoCorr->pNoNoroeste != NULL )
      {
         tpMatExc->pNoCorr = tpMatExc->pNoCorr->pNoNoroeste;
         free(tpMatExc->pNoCorr->pNoNoroeste);
		 DestroiNoMatriz( tpMatExc ) ;
      } /* if */

	  free( tpMatExc->pNoCorr ) ;

   } /* Fim fun��o: MAT Destruir a estrutura da matriz */


/***********************************************************************
*
*  $FC Fun��o: MAT Prepara a estrutura da matriz - 05/09/2013
*
*  $FV Valor retornado
*     MAT_CondRetOK
*	  MAT_CondRetFaltouMemoria
*	  ....
*
***********************************************************************/

MAT_tpCondRet PreparaEstruturaMatriz( MAT_tpMatriz * tpMat , int numElementos ){

	int i = 0, j = 0;

	tpElemMatriz * tpElemLesteCabeca   = NULL;
	tpElemMatriz * tpElemSudesteCabeca = NULL;
	tpElemMatriz * tpElemSulCabeca     = NULL;
	tpElemMatriz * tpElemLesteNo	   = NULL;
	tpElemMatriz * tpElemSudesteNo	   = NULL;
	tpElemMatriz * tpElemSulNo		   = NULL;
	tpElemMatriz * tpElem			   = CriarNo( );
	if(tpElem == NULL)
	{
		return MAT_CondRetFaltouMemoria ;
	}

	if(numElementos == 1){
		tpMat->pNoCorr       = tpElem;
		tpMat->pNoRaiz       = tpElem;
		tpMat->pNoIndLinha   = tpElem;
		return MAT_CondRetOK;
	}

	numElementos = numElementos - 1;

	

	for(i=0;i<=numElementos;i++){

		for(j=0;j<=numElementos;j++){	

								
					/* testa a condic�o para 3 adjacentes */
				if((i==0 || i==numElementos) && (j==0 || j==numElementos)){

					if(i==0 && j==0){
						tpMat->pNoCorr       = tpElem;
						tpMat->pNoRaiz       = tpElem;
						tpMat->pNoIndLinha   = tpElem;

						tpElemLesteCabeca   = CriarNo( );
						tpElemSudesteCabeca = CriarNo( );
						tpElemSulCabeca     = CriarNo( );
						if(tpElemLesteCabeca==NULL || tpElemSudesteCabeca==NULL || tpElemSulCabeca==NULL){
							return MAT_CondRetFaltouMemoria ;
						}						
						tpMat->pNoCorr->pNoLeste     = tpElemLesteCabeca;
						tpMat->pNoCorr->pNoSudeste   = tpElemSudesteCabeca;
						tpMat->pNoCorr->pNoSul       = tpElemSulCabeca;


					}
					if(i==0 && j==numElementos){
						
						tpMat->pNoCorr->pNoLeste->pNoSul       = tpMat->pNoCorr->pNoSudeste;
						tpMat->pNoCorr->pNoLeste->pNoSudoeste  = tpMat->pNoCorr->pNoSul;
						tpMat->pNoCorr->pNoLeste->pNoOeste     = tpMat->pNoCorr;


						tpMat->pNoCorr = tpMat->pNoCorr->pNoLeste ;
							/* seta como corrente */

					}
					if(i==numElementos && j==0){

						tpMat->pNoIndLinha->pNoSul->pNoNorte     = tpMat->pNoIndLinha;
						tpMat->pNoIndLinha->pNoSul->pNoNordeste  = tpMat->pNoIndLinha->pNoLeste;
						tpMat->pNoIndLinha->pNoSul->pNoLeste     = tpMat->pNoIndLinha->pNoSudeste;


						tpMat->pNoCorr      = tpMat->pNoIndLinha->pNoSul;
							/* seta como corrente */

						tpMat->pNoIndLinha  = tpMat->pNoIndLinha->pNoSul;
							/* seta como indice da linha */

					}
					if(i==numElementos && j==numElementos){

						tpMat->pNoCorr->pNoLeste->pNoNorte     = tpMat->pNoCorr->pNoNordeste;
						tpMat->pNoCorr->pNoLeste->pNoNoroeste  = tpMat->pNoCorr->pNoNorte;
						tpMat->pNoCorr->pNoLeste->pNoOeste     = tpMat->pNoCorr;

						tpMat->pNoCorr  = tpMat->pNoCorr->pNoLeste;
							/* seta como corrente */

					}

				}

					 /* testa a condi��o para 5 adjacentes */
				else if(i==0 || i==numElementos || j==0 || j==numElementos){


					if(i==0 && (j!=numElementos || j!=0)){
						
						tpMat->pNoCorr->pNoLeste->pNoSul      = tpMat->pNoCorr->pNoSudeste;
						tpMat->pNoCorr->pNoLeste->pNoSudoeste = tpMat->pNoCorr->pNoSul;
						tpMat->pNoCorr->pNoLeste->pNoOeste    = tpMat->pNoCorr;

						tpElemLesteNo   = CriarNo( );
						tpElemSudesteNo = CriarNo( );
						if(tpElemLesteNo==NULL || tpElemSudesteNo==NULL){
							return MAT_CondRetFaltouMemoria ;
						}
						tpMat->pNoCorr->pNoLeste->pNoLeste    = tpElemLesteNo;
						tpMat->pNoCorr->pNoLeste->pNoSudeste  = tpElemSudesteNo;

						tpMat->pNoCorr  = tpMat->pNoCorr->pNoLeste;
							/* seta como corrente */

					}

					if(j==0 && (i!=numElementos || i!=0)){

						tpMat->pNoIndLinha->pNoSul->pNoLeste    = tpMat->pNoIndLinha->pNoSudeste;				
						tpMat->pNoIndLinha->pNoSul->pNoNordeste = tpMat->pNoIndLinha->pNoLeste;
						tpMat->pNoIndLinha->pNoSul->pNoNorte    = tpMat->pNoIndLinha;

						tpElemSulNo     = CriarNo( );
						tpElemSudesteNo = CriarNo( );
						if(tpElemSulNo==NULL || tpElemSudesteNo==NULL){
							return MAT_CondRetFaltouMemoria ;
						}
						tpMat->pNoIndLinha->pNoSul->pNoSudeste  = tpElemSudesteNo;
						tpMat->pNoIndLinha->pNoSul->pNoSul      = tpElemSulNo;

						tpMat->pNoCorr      = tpMat->pNoIndLinha->pNoSul;
							/* seta como corrente */

						tpMat->pNoIndLinha  = tpMat->pNoIndLinha->pNoSul;
							/* seta como indice da linha */

					}
					if(i==numElementos && (j!=numElementos || j!=0)){
			    
						tpMat->pNoCorr->pNoLeste->pNoLeste    = tpMat->pNoCorr->pNoNordeste->pNoSudeste;
						tpMat->pNoCorr->pNoLeste->pNoNordeste = tpMat->pNoCorr->pNoNordeste->pNoLeste;
						tpMat->pNoCorr->pNoLeste->pNoNorte    = tpMat->pNoCorr->pNoNordeste;
						tpMat->pNoCorr->pNoLeste->pNoNoroeste = tpMat->pNoCorr->pNoNorte;
						tpMat->pNoCorr->pNoLeste->pNoOeste    = tpMat->pNoCorr;

						tpMat->pNoCorr  = tpMat->pNoCorr->pNoLeste;
							/* seta como corrente */

					}
					if(j==numElementos && (i!=numElementos || i!=0)){

						tpMat->pNoCorr->pNoLeste->pNoNorte     = tpMat->pNoCorr->pNoNordeste;
						tpMat->pNoCorr->pNoLeste->pNoSul       = tpMat->pNoCorr->pNoSudeste;
						tpMat->pNoCorr->pNoLeste->pNoSudoeste  = tpMat->pNoCorr->pNoSul;
						tpMat->pNoCorr->pNoLeste->pNoOeste     = tpMat->pNoCorr;
						tpMat->pNoCorr->pNoLeste->pNoNoroeste  = tpMat->pNoCorr->pNoNorte;

						tpMat->pNoCorr  = tpMat->pNoCorr->pNoLeste;
							/* seta como corrente */

					}

				}
					/* 8 adjacentes */
				else{

						tpMat->pNoCorr->pNoLeste->pNoNorte     = tpMat->pNoCorr->pNoNordeste;
						tpMat->pNoCorr->pNoLeste->pNoNordeste  = tpMat->pNoCorr->pNoNordeste->pNoLeste;
						tpMat->pNoCorr->pNoLeste->pNoLeste     = tpMat->pNoCorr->pNoNordeste->pNoSudeste;
						tpMat->pNoCorr->pNoLeste->pNoSul       = tpMat->pNoCorr->pNoSudeste;
						tpMat->pNoCorr->pNoLeste->pNoSudoeste  = tpMat->pNoCorr->pNoSul;
						tpMat->pNoCorr->pNoLeste->pNoOeste     = tpMat->pNoCorr;
						tpMat->pNoCorr->pNoLeste->pNoNoroeste  = tpMat->pNoCorr->pNoNorte;
						tpElemSudesteNo   = CriarNo( );
						if(tpElemSudesteNo==NULL){
							return MAT_CondRetFaltouMemoria ;
						}
						tpMat->pNoCorr->pNoLeste->pNoSudeste   = tpElemSudesteNo;


						tpMat->pNoCorr = tpMat->pNoCorr->pNoLeste;
							/* seta como corrente */

				}
		}

	}

	 
	return MAT_CondRetOK;

}

/***********************************************************************
*
*  $FC Fun��o: ARV Criar n� da �rvore
*
*  $FV Valor retornado
*     Ponteiro para o n� criado.
*     Ser� NULL caso a mem�ria tenha se esgotado.
*     Os ponteiros do n� criado estar�o nulos e o valor � igual ao do
*     par�metro.
*
***********************************************************************/

   tpElemMatriz * CriarNo( )
   {

      tpElemMatriz * pNoMatriz ;
      pNoMatriz = ( tpElemMatriz * ) malloc( sizeof( tpElemMatriz )) ;
      if ( pNoMatriz == NULL )
      {
         return NULL ;
      } /* if */

	  pNoMatriz->Lista       = NULL ;
	  pNoMatriz->pNoLeste    = NULL ;
	  pNoMatriz->pNoNordeste = NULL ;
	  pNoMatriz->pNoNoroeste = NULL ;
	  pNoMatriz->pNoNorte    = NULL ;
	  pNoMatriz->pNoOeste    = NULL ;
	  pNoMatriz->pNoSudeste  = NULL ;
	  pNoMatriz->pNoSudoeste = NULL ;
	  pNoMatriz->pNoSul      = NULL ;

      return pNoMatriz ;

   } /* Fim fun��o: ARV Criar n� da �rvore */


/***********************************************************************
*
*  $FC Fun��o: MAT Criar n� raiz da matriz
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*     MAT_CondRetNaoCriouRaiz
*
***********************************************************************/

MAT_tpCondRet CriarNoRaiz( MAT_tpMatriz* tpMat , int numElementos )
{

    MAT_tpCondRet CondRet ;

	if ( tpMat->pNoRaiz == NULL )
    {

		CondRet = PreparaEstruturaMatriz(tpMat, numElementos);		
				/* Criar a estrutura da matriz de acordo com a quantidade elementos passados */

		if ( CondRet != MAT_CondRetOK )
        {
        return CondRet ;
        } /* if */


        return MAT_CondRetOK  ;
    } /* if */

    return MAT_CondRetNaoCriouRaiz ;

} /* Fim fun��o: MAT Criar n� raiz da matriz */

/********** Fim do m�dulo de implementa��o: M�dulo matriz **********/

