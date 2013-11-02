#if ! defined( JOGO_ )
#define JOGO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: JOG  JOGO do tabuleiro
*
*  Arquivo gerado:              JOGO.H
*  Letras identificadoras:      JOG
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
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
*     1       afv   19/out/2013 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa a cria��o de elementos do tipo JOGO para tabuleiro
*
***************************************************************************/
 
#if defined( JOGO_OWN )
   #define JOGO_EXT
#else
   #define JOGO_EXT extern
#endif

#include "PECA.H"

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma JOGO */

typedef struct JOG_tagListaPeca * JOG_tppJogo ;


/* Tipo refer�ncia para uma PECA DO JOGO */

typedef struct JOG_tagPecaJogo * JOG_tppPecaJogo ;

/***********************************************************************
*
*  $TC Tipo de dados: JOG Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da JOGO
*
***********************************************************************/

typedef enum {

	 JOG_CondRetOK = 0 ,
		   /* Concluiu corretamente */

	 JOG_CondRetJogoNulo = 1 ,

	 JOG_CondRetFaltouMemoria = 9
		   /* Faltou mem�ria ao tentar criar um elemento de JOGO */

} JOG_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: JOG  &Criar JOGO
*
*
***********************************************************************/

JOG_tpCondRet JOG_CriarJogo(JOG_tppJogo * pJogo);

JOG_tpCondRet JOG_InserirPecaTimeB(JOG_tppJogo pJOGO , PEC_tppPeca pTipoPeca);

JOG_tpCondRet JOG_InserirPecaTimeA(JOG_tppJogo pJOGO , PEC_tppPeca pTipoPeca);


#undef JOGO_EXT

/********** Fim do m�dulo de defini��o: JOG  JOGO do tabuleiro **********/

#else
#endif