/***************************************************************************
*  $MCI M�dulo de implementa��o: TVER Teste v�rtice
*
*  Arquivo gerado:              TESTVER.c
*  Letras identificadoras:      TVER
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\TESTVER.BSW
*
*  Projeto: INF 1301 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: aw - Alexandre Werneck
*           fr - Fernanda Camelo Ribeiro
*	        vo - Vinicius de Luiz de Oliveira
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

#include    "Vertice.h"


static const char RESET_VERTICE_CMD			 [ ] = "=resetteste"       ;
static const char CRIAR_VERTICE_CMD			 [ ] = "=criavertice"      ;
static const char DESTRUIR_VERTICE_CMD		 [ ] = "=destruirvertice"  ;
static const char MUDAR_VALOR_VERTICE_CMD	 [ ] = "=mudarvalorvert"   ;
static const char OBTER_VALOR_VERTICE_CMD	 [ ] = "=obtervalorvert"   ;
static const char RETORNAR_VALOR_VERTICE_CMD [ ] = "=retornarvalorvert"   ;

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_VERTICE   10
#define DIM_VT_VALOR     80

VER_tppVerticeCont   vtVertices[ DIM_VT_VERTICE ] ;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static int ValidarInxVertice( int inxVertice , int Modo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TVER &Testar v�rtice
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 10 v�rtices, identificadas pelos �ndices 0 a 10
*
*     Comandos dispon�veis:
*
*     =resetteste
*           - anula o vetor de v�rtices. Provoca vazamento de mem�ria
*     =criavertice                   inxVertice string CondRetEsp
*     =destruirvertice               inxVertice CondRetEsp
*     =mudarvalorvert                inxVertice string CondRetEsp
*     =obtervalorvert                inxVertice string CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxVertice  = -1 ,
          numLidos    = -1 ,
          CondRetEsp  = -1  ;

	  int i = 0;

	  char StringDado[DIM_VT_VALOR];

	  VER_tpCondRet CondRetObtido ;

      /* Efetuar reset de teste de v�rtice */

         if ( strcmp( ComandoTeste , RESET_VERTICE_CMD ) == 0 )
         {

            for( i = 0 ; i < DIM_VT_VERTICE ; i++ )
            {
               vtVertices[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de v�rtice */

      /* Testar Criarv�rtice */

         else if ( strcmp( ComandoTeste , CRIAR_VERTICE_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxVertice , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxVertice( inxVertice , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = VER_CriarVertice( &vtVertices[ inxVertice ] , StringDado ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
               "Erro ao criar novo v�rtice."  ) ;

         } /* fim ativa: Testar Criarv�rtice */

      /* Testar Destruir v�rtice */

         else if ( strcmp( ComandoTeste , DESTRUIR_VERTICE_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &inxVertice , &CondRetEsp ) ;

            if ( numLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = VER_DestruirVertice( vtVertices[ inxVertice ] ) ;

            vtVertices[ inxVertice ] = NULL ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
               "N�o foi poss�vel destruir v�rtice."  ) ;

         } /* fim ativa: Testar Destruir v�rtice */

		  /* Testar Mudar valor do v�rtice */

         else if ( strcmp( ComandoTeste , MUDAR_VALOR_VERTICE_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                               &inxVertice , StringDado , &CondRetEsp ) ;

            if ( numLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = VER_MudarNomeVertice( vtVertices[ inxVertice ] , StringDado ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
               "N�o foi poss�vel mudar valor do v�rtice."  ) ;

         } /* fim ativa: Testar Mudar valor do v�rtice */

		  /* Testar Obter valor do v�rtice */

         else if ( strcmp( ComandoTeste , OBTER_VALOR_VERTICE_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                               &inxVertice , StringDado , &CondRetEsp ) ;

            if ( numLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = VER_ObterValor( vtVertices[ inxVertice ] , StringDado ) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido ,
               "N�o foi poss�vel obter valor do v�rtice."  ) ;

         } /* fim ativa: Testar Obter valor do v�rtice */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TVER &Testar v�rtice */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: TVER -Validar indice de v�rtice
*
***********************************************************************/

   int ValidarInxVertice( int inxVertice , int Modo )
   {

      if ( ( inxVertice <  0 )
        || ( inxVertice >= DIM_VT_VERTICE ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtVertices[ inxVertice ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtVertices[ inxVertice ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim fun��o: TVER -Validar indice de v�rtice */

/********** Fim do m�dulo de implementa��o: TVER Teste v�rtices **********/

