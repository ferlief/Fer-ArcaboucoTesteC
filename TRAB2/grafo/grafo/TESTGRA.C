/***************************************************************************
*  $MCI M�dulo de implementa��o: TGRAF Testa m�dulo grafo de v�rtices
*
*  Arquivo gerado:              TESTGRA.C
*  Letras identificadoras:      TGRA
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: aw - Alexandre Werneck
*           fr - Fernanda Camelo Ribeiro
*			vo - Vinicius de Luiz de Oliveira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   afv   03/out/2013 In�cio do desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.H"

#include    "Generico.h"
#include    "LerParm.h"

#include	"GRAFO.H"
#include    "VERTICE.H"
#include    "LISTA.H"

/***********************************************************************
* Opera��es em Grafo
*
***********************************************************************/
static const char CRIAR_GRAFO_CMD			[ ] = "=criargrafo"           ;
static const char CRIAR_VERTIVE_GRAFO_CMD	[ ] = "=criarverticegrafo"    ;
static const char CRIA_ARESTA_CMD       	[ ] = "=criararesta"          ;
static const char EXCLUIR_VERT_CMD   		[ ] = "=excluirvertice"       ;
static const char EXCLUIR_ARES_CMD   		[ ] = "=excluiraresta"        ;
static const char INSERE_VERT_ORIG_CMD      [ ] = "=inserirvertorigens"   ;
static const char OBTER_VALOR_VERT_CMD		[ ] = "=obtervalorvertcorr"   ;
static const char MUDAR_VALOR_VERT_CMD      [ ] = "=mudarvalorvertcorr"   ;
static const char DEFINIR_CORR_GRA_CMD      [ ] = "=definircorrentegra"   ;
static const char DESTRUIR_GRA_CMD          [ ] = "=destruirgrafo"        ;


#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_GRAFO       10
#define DIM_VALOR          100

GRA_tppGrafo    vtGrafo[ DIM_VT_GRAFO ] ;


/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static int ValidarInxGrafo( int inxGrafo , int Modo ) ;

static void TES_excluirInfo (void * pValor);

static void TES_excluirConteudo ( void * pValor );

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***********************************************************************
*
* Fun��o: TGRA Testar grafo
*
*    Comandos dispon�veis:
*
*    =criargrafo                   inxGrafo  DestruirVal CondRetEsp
*    =criarverticegrafo            inxGrafo  nome        casa       CondRetEsp
*    =criararesta                  casa      casa        inxGrafo   nome         CondRetEsp
*    =excluirvertice               inxGrafo  CondRetEsp
*    =excluiraresta                casa      casa        inxGrafo   CondRetEsp
*    =inserirvertorigens           inxGrafo  casa        CondRetEsp
*    =obtervalorvertcorr           inxGrafo  nome        CondRetEsp
*    =mudarvalorvertcorr           inxGrafo  nome        CondRetEsp
*    =definircorrentegra           inxGrafo  casa        CondRetEsp
*    =destruirgrafo                inxGrafo  CondRetEsp
*
***********************************************************************/


/***********************************************************************
*
*  $FC Fun��o: TGRA Efetuar opera��es de teste espec�ficas para grafo
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     matriz sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	  GRA_tpCondRet CondRetObtido   = GRA_CondRetOK ;
      GRA_tpCondRet CondRetEsperada = GRA_CondRetFaltouMemoria ;

      char ValorDado     = '\0' ;
	  char ValorOrig     = '\0' ;
	  char ValorDest     = '\0' ;

	  char StringDado[DIM_VALOR];

	  int inxGrafo     = -1 ,
          NumLidos     = -1 ,
		  i            = 0  ;
	  
		/* Testar GRA Criar grafo */

		if ( strcmp( ComandoTeste , CRIAR_GRAFO_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &inxGrafo , &CondRetEsperada ) ;

            if ( (NumLidos != 2) || ( ! ValidarInxGrafo(inxGrafo, VAZIO) ) )
            {
               return TST_CondRetParm ;
            } /* if */

			vtGrafo[ inxGrafo ] = NULL;

			CondRetObtido = GRA_CriarGrafo( &vtGrafo[ inxGrafo ] , TES_excluirInfo );

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar grafo." );

         } /* fim ativa: Testar GRA Criar grafo */		


		/* Testar GRA Criar vertice para grafo */

		else if( strcmp( ComandoTeste , CRIAR_VERTIVE_GRAFO_CMD ) == 0 )
		{

			NumLidos = LER_LerParametros ( "isci" , &inxGrafo , &StringDado , &ValorDado , &CondRetEsperada );

			if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = GRA_CriaVerticeGrafo( vtGrafo[ inxGrafo ] , StringDado , ValorDado , TES_excluirConteudo );

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar vertice no grafo." );


		} /* fim ativa: Testar GRA Criar vertice para grafo */


		/* Testar GRA Inserir aresta */

		else if(strcmp ( ComandoTeste, CRIA_ARESTA_CMD ) == 0)
		{
			NumLidos = LER_LerParametros ( "ccisi" , &ValorOrig, &ValorDest , &inxGrafo, &StringDado , &CondRetEsperada );
			if(NumLidos != 5){
				return TST_CondRetParm;
			}

			CondRetObtido = GRA_CriarAresta( ValorOrig , ValorDest , vtGrafo[ inxGrafo ] , StringDado  );

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar aresta." );

		} /* fim ativa: Testar GRA Inserir aresta */

				
		/* Testar GRA Excluir v�rtice */

		else if (strcmp (ComandoTeste, EXCLUIR_VERT_CMD) == 0)
		{
			NumLidos = LER_LerParametros ( "ii" , &inxGrafo , &CondRetEsperada );
			if(NumLidos != 2){

				return TST_CondRetParm;

			}

			CondRetObtido = GRA_ExcluirVerticeCorrente( vtGrafo[ inxGrafo ] );

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao excluir v�rtice." );

		} /* fim ativa: Testar GRA Excluir v�rtice */

		
		
		/* Testar GRA Obter valor do v�rtice corrente */

		else if(strcmp (ComandoTeste, OBTER_VALOR_VERT_CMD) == 0)
		{
			NumLidos = LER_LerParametros ( "isi" , &inxGrafo , &StringDado , &CondRetEsperada );
			if(NumLidos != 3){
				return TST_CondRetParm;
			}
			
			CondRetObtido = GRA_ChecarNomeVerticeCorrente( vtGrafo[inxGrafo] , StringDado );

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter valor do v�rtice corrente." );

		} /* fim ativa: Testar GRA Obter valor do v�rtice corrente */

		/* Testar GRA Mudar valor do v�rtice corrente */

		else if(strcmp (ComandoTeste, MUDAR_VALOR_VERT_CMD) == 0)
		{
			NumLidos = LER_LerParametros ( "isi" , &inxGrafo , &StringDado , &CondRetEsperada );
			if(NumLidos != 3){
				return TST_CondRetParm;
			}
			
			CondRetObtido = GRA_MudarNomeVerticeCorrente( vtGrafo[inxGrafo] , StringDado );

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter valor do v�rtice corrente." );

		} /* fim ativa: Testar GRA Mudar valor do v�rtice corrente */


		/* Testar GRA Inserir v�rtice no in�cio da lista de origens */

		else if(strcmp (ComandoTeste, INSERE_VERT_ORIG_CMD ) == 0)
		{
			NumLidos = LER_LerParametros ( "ici" , &inxGrafo , &ValorDado , &CondRetEsperada );

			if(NumLidos != 3){
				return TST_CondRetParm;
			}
			
			CondRetObtido = GRA_InsereOrigem(vtGrafo[ inxGrafo ] , ValorDado);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir vertice na lista de origens" );

		} /* fim ativa: Testar GRA Inserir v�rtice no in�cio da lista de origens */

		/* Testar GRA Inserir v�rtice no in�cio da lista de origens */

		else if(strcmp (ComandoTeste, EXCLUIR_ARES_CMD ) == 0)
		{
			NumLidos = LER_LerParametros ( "ccii" , &ValorDado , &ValorDest ,  &inxGrafo , &CondRetEsperada );

			if(NumLidos != 4){
				return TST_CondRetParm;
			}
			
			CondRetObtido = GRA_ExcluirAresta( ValorDado , ValorDest , vtGrafo[ inxGrafo ]);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao excluir aresta" );

		} /* fim ativa: Testar GRA Inserir v�rtice no in�cio da lista de origens */

		/* Testar GRA Definir corrente */

		else if(strcmp (ComandoTeste, DEFINIR_CORR_GRA_CMD ) == 0)
		{

			NumLidos = LER_LerParametros ( "ici" , &inxGrafo , &ValorDado , &CondRetEsperada );

			if(NumLidos != 3){
				return TST_CondRetParm;
			}

			CondRetObtido = GRA_DefinirCorrente( vtGrafo[ inxGrafo ] , ValorDado);

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao definir corrente" );

		} /* fim ativa: Testar GRA Inserir v�rtice no in�cio da lista de origens */

		/* Testar GRA Destruir Grafo */

		else if(strcmp (ComandoTeste, DESTRUIR_GRA_CMD ) == 0)
		{

			NumLidos = LER_LerParametros ( "ii" , &inxGrafo , &CondRetEsperada );

			if(NumLidos != 2){
				return TST_CondRetParm;
			}

			CondRetObtido = GRA_DestruirGrafo( vtGrafo[ inxGrafo ]);

			vtGrafo[ inxGrafo ] = NULL;

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao destruir grafo!" );

		} /* fim ativa: Testar GRA Destruir Grafo */

				

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TGRA Efetuar opera��es de teste espec�ficas para grafo */


/***********************************************************************
*
*  $FC Fun��o: TGRA -Validar indice de grafo
*
***********************************************************************/

   int ValidarInxGrafo( int inxGrafo , int Modo )
   {

      if ( ( inxGrafo <  0 )
		  || ( inxGrafo >= DIM_VT_GRAFO ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtGrafo[ inxGrafo ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtGrafo[ inxGrafo ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim fun��o: TGRA -Validar indice de grafo */

/***********************************************************************
*
*  $FC Fun��o: TES -Excluir conteudo alocado em grafo
*
***********************************************************************/


void TES_excluirInfo ( void * pValor )
{

    free( ( void * ) pValor ) ;

} /* Fim fun��o: TST -Excluir informacao */

/***********************************************************************
*
*  $FC Fun��o: TES -Excluir conteudo alocado v�rtice do grafo
*
***********************************************************************/

void TES_excluirConteudo ( void * pValor )
{

	VER_DestruirVertice ((VER_tppVerticeCont *) pValor);

}


/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

