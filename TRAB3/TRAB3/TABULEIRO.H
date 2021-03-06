#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: TAB  Tabuleiro de xadrez
*
*  Arquivo gerado:              TABULEIRO.H
*  Letras identificadoras:      TAB
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
*     Armazena as fun��es de tabuleiro, contem as instru��es do jogo.
*
***************************************************************************/
 
#if defined( TABULEIRO_OWN )
   #define TABULEIRO_EXT
#else
   #define TABULEIRO_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um tabuleiro */

typedef struct TAB_tagTabuleiro * TAB_tppTabuleiro ;

typedef struct tpElemCasa * TAB_ElemCasa ;

typedef struct TAB_tgEstCasa * TAB_tppEstCasa ;

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK = 0,
               /* Concluiu corretamente */

		 TAB_TimeAVazio = 1 ,

		 TAB_TimeBVazio = 2 ,

		 TAB_CondRetNaoAchou = 3 ,

		 TAB_CondRetFimLista = 4 ,

		 TAB_CondRetListaVazia = 5 ,

		 TAB_CondRetTabuleiroNulo = 6 ,

		 TAB_CondRetTabuleiroListaNula = 7 ,

		 TAB_CondRetCorrenteNulo = 8 ,

         TAB_CondRetFaltouMemoria = 9
               /* Faltou mem�ria ao tentar criar um tabuleiro */

   } TAB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: TAB  &Criar lista
*
*  $ED Descri��o da fun��o
*     Cria uma lista gen�rica duplamente encadeada.
*     Os poss�veis tipos s�o desconhecidos inicialmente.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     pLista  - ponteiro para o elemento do tipo de lista a ser alocado.
*     ExcluirValor  - ponteiro para a fun��o que processa a
*                     exclus�o do valor referenciado pelo elemento
*                     a ser exclu�do.
*                     Ver descri��o do m�dulo.
*                     Esta fun��o � criada no m�dulo que utiliza a lista.
*
*  $FV Valor retornado
*     TAB_CondRetFaltouMemoria - N�o conseguiu criar a lista.
*     TAB_CondRetOK - Conseguiu criar a lista com sucesso.
*
***********************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro( TAB_tppTabuleiro * pTabuleiro) ;

   TAB_tpCondRet TAB_ApresentaTabuleiro( TAB_tppTabuleiro pTabuleiro );

   TAB_tpCondRet TAB_CriarTipoPeca(TAB_tppTabuleiro pTabuleiro , char * Nome , int Diagonal , int Reta , int QtdeMov);

   TAB_tpCondRet TAB_ApresentaTipoPecas(TAB_tppTabuleiro pTabuleiro) ;

   TAB_tpCondRet TAB_ProcuraPeca(TAB_tppTabuleiro pTabuleiro , char * NomeBuscado , void ** PecaBuscada);

   TAB_tpCondRet TAB_IrInicioListaPecas(TAB_tppTabuleiro pTabuleiro);

   TAB_tpCondRet TAB_ObterTipoPeca(TAB_tppTabuleiro pTabuleiro , void ** pPeca);

   TAB_tpCondRet TAB_AvancarTipoPeca(TAB_tppTabuleiro pTabuleiro , int val);

   TAB_tpCondRet TAB_SetarCorrente( TAB_tppTabuleiro pTabuleiro , char * NomeCasa );

   TAB_tpCondRet TAB_InserirConteudoCasa(TAB_tppTabuleiro pTabuleiro , void * pPeca);


   /** caminhos **/
   TAB_tpCondRet TAB_IrNoNorte(TAB_tppEstCasa tpTab);
   TAB_tpCondRet TAB_IrNoNordeste(TAB_tppEstCasa tpTab);
   TAB_tpCondRet TAB_IrNoLeste(TAB_tppEstCasa tpTab);
   TAB_tpCondRet TAB_IrNoSudeste(TAB_tppEstCasa tpTab);
   TAB_tpCondRet TAB_IrNoSul(TAB_tppEstCasa tpTab);
   TAB_tpCondRet TAB_IrNoSudoeste(TAB_tppEstCasa tpTab);
   TAB_tpCondRet TAB_IrNoOeste(TAB_tppEstCasa tpTab);
   TAB_tpCondRet TAB_IrNoNoroeste(TAB_tppEstCasa tpTab);

   TAB_tpCondRet TAB_IrInicioCasas( TAB_tppTabuleiro pTabuleiro  );
   TAB_tpCondRet TAB_AvancarCasas( TAB_tppTabuleiro pTabuleiro , int val );
   TAB_tpCondRet TAB_ObterConteudo( TAB_tppTabuleiro pTabuleiro , void ** pConteudo );
   TAB_tpCondRet TAB_ObterCasa(TAB_tppTabuleiro pTabuleiro , void ** pConteudo);
   TAB_tpCondRet TAB_ObterVertice(TAB_tppTabuleiro pTabuleiro , void ** Vertice);


#undef TABULEIRO_EXT

/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif
