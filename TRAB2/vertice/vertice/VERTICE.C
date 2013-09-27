/***************************************************************************
*  $MCI M�dulo de implementa��o: VER Vertice
*
*  Arquivo gerado:              VERTICE.C
*  Letras identificadoras:      VER
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: afv
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       afv   19/09/2013 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#include "LISTA.H"

// verificar quais bibliotecas iremos realmente utilizar no projeto

#define VERTICE_OWN
#include "VERTICE.H"
#undef VERTICE_OWN

VER_tpCondRet Ret;

/***********************************************************************
*
*  $TC Tipo de dados: VER Elemento V�rtice
*
*
***********************************************************************/

   typedef struct tagElemVertice {

	   char Nome[80];
		/* Nome do v�rtice */

	   struct LIS_tppLista * listaAntecessores;
		/* ponteiro para lista de antecessores */

	   struct LIS_tppLista * listaSucessores;
	    /* ponteiro para lista de sucessores */

   } tpElemVertice ;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor da cabe�a de lista
*
*
***********************************************************************/

   typedef struct VER_tagVertice {

	   tpElemVertice * tpElemVer;

	   VER_tagVertice * tpElemProx;

   } VER_tpVertice ;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

void SetarVertice( VER_tppVertice pVertice ) ;

void limparNome(char Nome[]) ;


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: LIS  &Criar lista
*  ****/

   VER_tpCondRet VER_CriarVertice( VER_tpVertice * pVertice )
   {

      VER_tpVertice * pVerticeM = ( VER_tpVertice * ) malloc( sizeof( VER_tpVertice )) ;
      if ( pVerticeM == NULL )
      {
		  return VER_CondRetFaltouMemoria ;
      } /* if */

      SetarVertice( pVerticeM ) ;

	  pVertice = ( VER_tpVertice * ) malloc( sizeof( VER_tpVertice )) ;

	  pVertice = pVerticeM;

	  return VER_CondRetOK ;

   } /* Fim fun��o: LIS  &Criar lista */

/***************************************************************************
*
*  Fun��o: LIS  &Destruir lista
*  ****/

   VER_tpCondRet VER_DestruirVertice( VER_tppVertice pVertice )
   {

      #ifdef _DEBUG
         assert( pVertice != NULL ) ;
      #endif

      Ret = VER_EsvaziarVertice( pVertice ) ;

	  if(Ret != VER_CondRetOK)
	  {
		  return Ret;
	  }

      free( pVertice ) ;

	  if(pVertice == NULL)
	  {
		  return VER_CondRetOK ;
	  }

	  return VER_CondRetNaoAchou ;

   } /* Fim fun��o: LIS  &Destruir lista */

/***************************************************************************
*
*  Fun��o: LIS  &Esvaziar lista
*  ****/

   VER_tpCondRet VER_EsvaziarVertice( VER_tppVertice pVertice )
   {

	  tpElemVertice * pElem ;

      #ifdef _DEBUG
         assert( pVertice != NULL ) ;
      #endif

	  pElem = pVertice->tpElemVer ;

      while ( pElem != NULL )
      {
		  pElem->listaAntecessores = NULL;
		  pElem->listaSucessores   = NULL;
		  limparNome(pElem->Nome);
      } /* while */

      SetarVertice( pVertice ) ;

	  return VER_CondRetOK;

   } /* Fim fun��o: LIS  &Esvaziar lista */

/***************************************************************************
*
*  Fun��o: VER  &Criar elemento de V�rtice
*  ****/

   VER_tpCondRet VER_CriarElementoVertice( LIS_tppLista * pLista1, LIS_tppLista * pLista2, char Nome[]  ){

	   tpElemVertice * tpVert = (tpElemVertice *) malloc ( sizeof(tpElemVertice) );

	   if(tpVert == NULL){
		   return VER_CondRetFaltouMemoria ;
	   }

	   if(pLista1 == NULL || pLista2 == NULL){
		   return VER_CondRetListaVerticeVazia ;
	   }

	   tpVert->listaAntecessores = pLista1;

	   tpVert->listaSucessores   = pLista2;

	   strcpy(tpVert->Nome, Nome);

	   return VER_CondRetOK;

   } /* Fim fun��o: LIS  &Esvaziar lista */

/***************************************************************************
*
*  Fun��o: LIS  &Inserir elemento antes
*  ****/

   VER_tpCondRet VER_InserirElementoNoVertice ( VER_tppVertice tpVertice, VER_tppElemVertice pVertice   )
   {

	   #ifdef _DEBUG
         assert( tpVertice != NULL ) ;
      #endif

	  #ifdef _DEBUG
         assert( pVertice != NULL ) ;
      #endif
      	   		 
        if (tpVertice == NULL)
        {
        return VER_CondRetVerticeNaoExiste ;
        } /* if */

		if (pVertice == NULL)
        {
        return VER_CondRetElemVerticeNaoExiste ;
        } /* if */

		tpVertice->tpElemVer  = pVertice;

		tpVertice->tpElemProx = tpVertice;

        return VER_CondRetOK ;

   } /* Fim fun��o: LIS  &Inserir elemento antes */


/***************************************************************************
*
*  Fun��o: LIS  &Excluir elemento
*  ****/

   VER_tpCondRet VER_ExcluirVertice( VER_tppVertice tpVertice )
   {

      #ifdef _DEBUG
         assert( tpVertice  != NULL ) ;
      #endif

      if ( tpVertice == NULL )
      {
         return VER_CondRetVerticeNulo ;
      } /* if */

	  if( tpVertice->tpElemVer != NULL )
	  {
		  return VER_CondRetVerticeContemElemento;
	  }

	  tpVertice->tpElemProx = NULL;

	  free(tpVertice);

      return VER_CondRetOK ;
      
   } /* Fim fun��o: LIS  &Excluir elemento */


   VER_tpCondRet VER_ExcluirElementoVertice( VER_tppVertice tpVertice )
   {

	   if ( tpVertice == NULL )
      {
         return VER_CondRetVerticeNulo ;
      } /* if */

	  if( tpVertice->tpElemVer == NULL )
	  {
		  return VER_CondRetVerticeVazio;
	  }

	  if(tpVertice->tpElemVer != NULL)
	  {
		  tpVertice->tpElemVer->listaAntecessores = NULL;
		  tpVertice->tpElemVer->listaSucessores   = NULL;
		  limparNome(tpVertice->tpElemVer->Nome);
	  }

	   return VER_CondRetOK;

   }
/***************************************************************************
*
*  Fun��o: LIS  &Obter refer�ncia para o valor contido no elemento
*  ****/

   VER_tpCondRet VER_ObterValorElemVertice( VER_tppVertice tpVertice , char Nome[] )
   {

      #ifdef _DEBUG
         assert( tpVertice != NULL ) ;
      #endif

		 if( strcmp (tpVertice->tpElemVer->Nome , Nome) )
		{
			return VER_CondRetOK;			
		}

		return VER_CondRetNaoAchou;

   } /* Fim fun��o: LIS  &Obter refer�ncia para o valor contido no elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o elemento inicial
*  ****/

   VER_tpCondRet VER_ConheceCaminho(  VER_tppVertice tpVerticeOrig ,  VER_tppVertice tpVerticeDest )
   {
	   LIS_tppLista * listaTmp;

      #ifdef _DEBUG
         assert( tpVerticeOrig != NULL ) ;
      #endif

      #ifdef _DEBUG
         assert( tpVerticeDest != NULL ) ;
      #endif

		 listaTmp = tpVerticeOrig->tpElemVer->listaSucessores;
	
		 while(listaTmp != NULL)
		 {
			 if(listaTmp->pOrigemLista == tpVerticeDest->tpElemVer)
			 {
				 return VER_CondRetOK;	
			 }
		 }		
	  

   } /* Fim fun��o: LIS  &Ir para o elemento inicial */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o elemento final
*  ****/

   LIS_tpCondRet IrFinalLista( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      if(pLista->pElemCorr == NULL)
	  {
		  return LIS_CondRetListaVazia;
	  }
	  if(pLista->pFimLista == NULL)
	  {
		  return LIS_CondRetNaoAchou;
	  }

      pLista->pElemCorr = pLista->pFimLista ;

	  return LIS_CondRetOK;


   } /* Fim fun��o: LIS  &Ir para o elemento final */

/***************************************************************************
*
*  Fun��o: LIS  &Avan�ar elemento
*  ****/

   LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,
                                              int numElem )
   {

      int i ;

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      /* Tratar lista vazia */

         if ( pLista->pElemCorr == NULL )
         {

            return LIS_CondRetListaVazia ;

         } /* fim ativa: Tratar lista vazia */

      /* Tratar avan�ar para frente */

         if ( numElem > 0 )
         {

            pElem = pLista->pElemCorr ;
            for( i = numElem ; i > 0 ; i-- )
            {
               if ( pElem == NULL )
               {
                  break ;
               } /* if */
               pElem    = pElem->pProx ;
            } /* for */

            if ( pElem != NULL )
            {
               pLista->pElemCorr = pElem ;
               return LIS_CondRetOK ;
            } /* if */

            pLista->pElemCorr = pLista->pFimLista ;
            return LIS_CondRetFimLista ;

         } /* fim ativa: Tratar avan�ar para frente */

      /* Tratar avan�ar para tr�s */

         else if ( numElem < 0 )
         {

            pElem = pLista->pElemCorr ;
            for( i = numElem ; i < 0 ; i++ )
            {
               if ( pElem == NULL )
               {
                  break ;
               } /* if */
               pElem    = pElem->pAnt ;
            } /* for */

            if ( pElem != NULL )
            {
               pLista->pElemCorr = pElem ;
               return LIS_CondRetOK ;
            } /* if */

            pLista->pElemCorr = pLista->pOrigemLista ;
            return LIS_CondRetFimLista ;

         } /* fim ativa: Tratar avan�ar para tr�s */

      /* Tratar n�o avan�ar */

         return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Avan�ar elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Procurar elemento contendo valor
*  ****/

   LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,
                                    void * pValor        )
   {

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista  != NULL ) ;
      #endif

      if ( pLista->pElemCorr == NULL )
      {
         return LIS_CondRetListaVazia ;
      } /* if */

      for ( pElem  = pLista->pElemCorr ;
            pElem != NULL ;
            pElem  = pElem->pProx )
      {
         if ( pElem->pValor == pValor )
         {
            pLista->pElemCorr = pElem ;
            return LIS_CondRetOK ;
         } /* if */
      } /* for */

      return LIS_CondRetNaoAchou ;

   } /* Fim fun��o: LIS  &Procurar elemento contendo valor */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: LIS  -Liberar elemento da lista
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pelo valor do elemento e o
*     pr�prio elemento.
*
***********************************************************************/

   void LiberarElemento( LIS_tppLista   pLista ,
                         tpElemLista  * pElem   )
   {

      if ( pElem->pValor != NULL )
      {
         ExcluirValor( pElem ) ;
      } /* if */

      free( pElem ) ;

	  if(pLista->numElem >= 0)
	  {
		  pLista->numElem-- ;
	  } /* if */


   } /* Fim fun��o: LIS  -Liberar elemento da lista */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Excluir o valor do elemento
*
***********************************************************************/

   void ExcluirValor (tpElemLista  * pElem )
   {
	   free (pElem->pValor);
   }


/***********************************************************************
*
*  $FC Fun��o: LIS  -Criar o elemento
*
***********************************************************************/

   tpElemLista * CriarElemento( void * pValor  )
   {

      tpElemLista * pElem ;

      pElem = ( tpElemLista * ) malloc( sizeof( tpElemLista )) ;
      if ( pElem == NULL )
      {
         return NULL ;
      } /* if */

      pElem->pValor = pValor ;
      pElem->pAnt   = NULL  ;
      pElem->pProx  = NULL  ;

      return pElem ;

   } /* Fim fun��o: LIS  -Criar o elemento */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Limpar a cabe�a da lista
*
***********************************************************************/

   void SetarVertice( VER_tppVertice pVertice )
   {

	   pVertice->tpElemProx = NULL;
	   pVertice->tpElemVer  = NULL;

   } /* Fim fun��o: LIS  -Limpar a cabe�a da lista */

   void limparNome(char Nome[]){

	   int i = 0;
	   while( Nome != NULL ){
		   Nome[i] = NULL;
		   i++;
	   }

   }

/********** Fim do m�dulo de implementa��o: LIS  Lista duplamente encadeada **********/
