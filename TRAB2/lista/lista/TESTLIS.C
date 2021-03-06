/***************************************************************************
*
*  $MCI M�dulo de implementa��o: TLIS Teste lista duplamente encadeada
*
*  Arquivo gerado:              TESTLIS.C
*  Letras identificadoras:      TLIS
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: aw - Alexandre Werneck
*           fr - Fernanda Camelo Ribeiro
*           vo - Vinicius de Luiz de Oliveira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       afv   01/out/2013 in�cio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "LISTA.H"


static const char RESET_LISTA_CMD         [ ] = "=resetteste"     ;
static const char CRIAR_LISTA_CMD         [ ] = "=criarlista"     ;
static const char DESTRUIR_LISTA_CMD      [ ] = "=destruirlista"  ;
static const char ESVAZIAR_LISTA_CMD      [ ] = "=esvaziarlista"  ;
static const char INS_ELEM_ANTES_CMD      [ ] = "=inselemantes"   ;
static const char INS_ELEM_APOS_CMD       [ ] = "=inselemapos"    ;
static const char EXC_ELEM_CMD            [ ] = "=excluirelem"    ;
static const char OBTER_VALOR_CMD         [ ] = "=obtervalor"     ;
static const char IR_INICIO_CMD           [ ] = "=irinicio"       ;
static const char IR_FIM_CMD              [ ] = "=irfinal"        ;
static const char AVANCAR_ELEM_CMD        [ ] = "=avancarelem"    ;


#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

LIS_tppLista   vtListas[ DIM_VT_LISTA ] ;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void DestruirValor( void * pValor ) ;

   static int ValidarInxLista( int inxLista , int Modo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS &Testar lista
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 10 listas, identificadas pelos �ndices 0 a 10
*
*     Comandos dispon�veis:
*
*     =resetteste
*           - anula o vetor de listas. Provoca vazamento de mem�ria
*     =criarlista                   inxLista  inxLista	CondRetEsp
*     =destruirlista                inxLista  inxLista	CondRetEsp
*     =esvaziarlista                inxLista  inxLista	CondRetEsp
*     =inselemantes                 inxLista  inxLista	StringDado	CondRetEsp
*     =inselemapos                  inxLista  inxLista	StringDado	CondRetEsp
*     =excluirelem                  inxLista  inxLista	CondRetEsp
*     =obtervalor                   inxLista  inxLista	StringDado	CondRetEsp
*     =irinicio                     inxLista  inxLista	CondRetEsp
*     =irfinal                      inxLista  inxLista	CondRetEsp
*     =avancarelem                  inxLista  inxLista	numElem CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxLista  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

	  LIS_tpCondRet CondRetObtido ;

      char   StringDado[  DIM_VALOR ] ;

      int ValEsp = -1 ;

      int i ;

      int numElem = -1 ;

      StringDado[ 0 ] = 0 ;

      /* Efetuar reset de teste de lista */

         if ( strcmp( ComandoTeste , RESET_LISTA_CMD ) == 0 )
         {

            for( i = 0 ; i < DIM_VT_LISTA ; i++ )
            {
               vtListas[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de lista */

      /* Testar Criar lista */

         else if ( strcmp( ComandoTeste , CRIAR_LISTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                       &inxLista , &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = LIS_CriarLista( DestruirValor, &vtListas[ inxLista ] ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
               "Erro ao criar nova lista."  ) ;

         } /* fim ativa: Testar Criar lista */

      /* Testar Destruir lista */

         else if ( strcmp( ComandoTeste , DESTRUIR_LISTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &inxLista , &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = LIS_DestruirLista( vtListas[ inxLista ] ) ;

            vtListas[ inxLista ] = NULL ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
               "N�o foi poss�vel destruir lista."  ) ;

         } /* fim ativa: Testar Destruir lista */

      /* Testar Esvaziar lista */

         else if ( strcmp( ComandoTeste , ESVAZIAR_LISTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &inxLista , &CondRetEsp  ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = LIS_EsvaziarLista( vtListas[ inxLista ] ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
               "Erro ao esvaziar lista."  ) ;

         } /* fim ativa: Testar Esvaziar lista */

      /* Testar Inserir elemento antes */

         else if ( strcmp( ComandoTeste , INS_ELEM_ANTES_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */
			
           CondRetObtido = LIS_InserirElementoAntes( vtListas[ inxLista ] , StringDado ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao inserir antes."                   ) ;

         } /* fim ativa: Testar Inserir elemento antes */

      /* Testar Inserir elemento apos */

         else if ( strcmp( ComandoTeste , INS_ELEM_APOS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */
			
            CondRetObtido = LIS_InserirElementoApos( vtListas[ inxLista ] , StringDado ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao inserir apos."                   ) ;

         } /* fim ativa: Testar Inserir elemento apos */

      /* Testar Excluir elemento */

         else if ( strcmp( ComandoTeste , EXC_ELEM_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                  &inxLista , &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = LIS_ExcluirElemento( vtListas[ inxLista ] );

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condi��o de retorno errada ao excluir."   ) ;

         } /* fim ativa: Testar Excluir elemento */

      /* Testar Obter refer�ncia para o valor contido no elemento */

         else if ( strcmp( ComandoTeste , OBTER_VALOR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = LIS_ObterValor( vtListas[ inxLista ] , (void**)StringDado );

			return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condi��o de retorno errada ao checar valor."   ) ;

         } /* fim ativa: Testar Obter refer�ncia para o valor 
              contido no elemento */

      /* Testar Ir para o elemento inicial */

         else if ( strcmp( ComandoTeste , IR_INICIO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxLista , &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = LIS_IrInicioLista( vtListas[ inxLista ] ) ;

			return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condi��o de retorno errada ao ir in�cio."   ) ;

         } /* fim ativa: Testar Ir para o elemento inicial */

      /* Testar Ir para o elemento final */

         else if ( strcmp( ComandoTeste , IR_FIM_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxLista , &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = LIS_IrFinalLista( vtListas[ inxLista ] ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condi��o de retorno errada ao ir fim da lista."   ) ;

         } /* fim ativa: Testar Ir para o elemento final */

      /* Testar Avan�ar elemento */

         else if ( strcmp( ComandoTeste , AVANCAR_ELEM_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" , &inxLista , &numElem ,
                                &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = LIS_AvancarElementoCorrente( vtListas[ inxLista ] , numElem ) ;

            return TST_CompararInt( CondRetEsp ,  CondRetObtido ,
                      "Condicao de retorno errada ao avancar elemento" ) ;

         } /* fim ativa: Testar Avan�ar elemento */


      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TLIS &Testar lista */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim fun��o: TLIS -Destruir valor */


/***********************************************************************
*
*  $FC Fun��o: TLIS -Validar indice de lista
*
***********************************************************************/

   int ValidarInxLista( int inxLista , int Modo )
   {

      if ( ( inxLista <  0 )
        || ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtListas[ inxLista ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtListas[ inxLista ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim fun��o: TLIS -Validar indice de lista */

/********** Fim do m�dulo de implementa��o: TLIS Teste lista de s�mbolos **********/