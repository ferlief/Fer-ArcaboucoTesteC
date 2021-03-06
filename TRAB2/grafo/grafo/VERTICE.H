#if ! defined( VERTICE_ )
#define VERTICE_
/***************************************************************************
*
*  $MCI M�dulo de defini��o: VER Vertice
*
*  Arquivo gerado:              VERTICE.H
*  Letras identificadoras:      VER
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
*     1       afv   19/out/2013 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*       Implementa v�rtices com cont�udo string.
*
***************************************************************************/
 
#if defined( VERTICE_OWN )
   #define VERTICE_EXT
#else
   #define VERTICE_EXT extern
#endif


/***** Declara��es exportadas pelo m�dulo *****/

typedef struct VER_tagVertice * VER_tppVerticeCont ;

/***********************************************************************
*
*  $TC Tipo de dados: VER Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de v�rtice
*
***********************************************************************/

   typedef enum {

         VER_CondRetOK = 0,
               /* Concluiu corretamente */

         VER_CondRetNaoAchou = 1,
               /* N�o encontrou o valor procurado */

		 VER_CondRetVerVazio = 2,
               /* Vertice vazio procurado */

         VER_CondRetFaltouMemoria = 9
               /* Faltou mem�ria ao tentar criar um elemento de v�rtice */

   } VER_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: VER  &Criar v�rtice
*
*  $ED Descri��o da fun��o
*     Cria um v�rtice e recebe uma string a ser atribu�da como valor
*     do elemento �nico da estrutura v�rtice.
*
*  $EP Par�metros
*     pVertice  - ponteiro para o vertice a ser criado
*	  Nome      - String a ser inserida
*
*  $FV Valor retornado
*     VER_CondRetOK  - v�rtice criado com sucesso
*     VER_CondRetFaltouMemoria - v�rtice n�o foi criado.
*
***********************************************************************/

   VER_tpCondRet VER_CriarVertice( VER_tppVerticeCont * pVertice , char * Nome  ) ;


/***********************************************************************
*
*  $FC Fun��o: VER  &Destruir v�rtice
*
*  $ED Descri��o da fun��o
*     Destr�i o v�rtice fornecido.
*     Elimina primeiro o valor do elemento, setando nome como vazio.
*     Aponta o elemento vertice para null
*
*  $EP Par�metros
*     pVertice  - vertice a ser exclu�do
*
*  $FV Valor retornado
*     VER_CondRetOK       - destruiu o v�rtice
*
***********************************************************************/

   VER_tpCondRet VER_DestruirVertice( VER_tppVerticeCont * pVertice) ;

/***********************************************************************
*
*  $FC Fun��o: VER  &Mudar valor do v�rtice
*
*  $ED Descri��o da fun��o
*     Modifica o valor do v�rtice
*     Objetivo da fun��o � modificar o r�tulo da string armazenada no v�rtice
*
*  $EP Par�metros
*     pVertice  - vertice a ser modificado
*     Nome      - nova string que ir� substituir o valor anterior
*
*  $FV Valor retornado
*     VER_CondRetOK       - modificou sem erros
*     VER_CondRetNaoAchou - v�rtice nulo
*     VER_CondRetVerVazio - v�rtice sem valor ou parametro Nome fornecido vazio
*
***********************************************************************/

   VER_tpCondRet VER_MudarNomeVertice( VER_tppVerticeCont pVertice , char * Nome  ) ;

/***********************************************************************
*
*  $FC Fun��o: VER  &Obter valor do v�rtice
*
*  $ED Descri��o da fun��o
*     Compara o nome passado como parametro com o valor do vertice passado
*
*  $EP Par�metros
*     pVertice  - vertice a ser comparado
*     Nome      - string a ser comparada
*
*  $FV Valor retornado
*     VER_CondRetOK       - valores iguais
*     VER_CondRetNaoAchou - v�rtice nulo
*     VER_CondRetVerVazio - v�rtice sem valor ou parametro Nome fornecido vazio
*
***********************************************************************/

VER_tpCondRet VER_ObterValor( VER_tppVerticeCont pVertice , char * Nome  ) ;


/***********************************************************************
*
*  $FC Fun��o: VER  &Retornar valor do v�rtice
*
*  $ED Descri��o da fun��o
*     Retorna por par�metro o valor do v�rtice tamb�m passado por par�metro
*
*  $EP Par�metros
*     pVertice  - vertice a ser analisado
*     Nome      - string a ser atribu�da o valor do v�rtice
*
*  $FV Valor retornado
*     VER_CondRetOK       - valor do v�rtice v�lido, atribui��o bem sucedida
*     VER_CondRetNaoAchou - v�rtice nulo
*     VER_CondRetVerVazio - v�rtice sem valor ou parametro Nome fornecido vazio
*
***********************************************************************/

VER_tpCondRet VER_RetornaValor( VER_tppVerticeCont pVertice , char * nome  ) ;



#undef VERTICE_EXT

/********** Fim do m�dulo de defini��o: VER  V�rtice **********/

#else
#endif