#if ! defined( LISTA_ )
#define LISTA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.H
*  Letras identificadoras:      LIS
*
*  Projeto: INF 1301 - Verificador de Xeque-Mate
*  Gestor:  Flavio Bevilacqua
*  Autores: afv:  aw - Alexandre Werneck
*                 fr - Fernanda C Ribeiro
*                 vo - Vinicius de Luiz de Oliveira
*
*  $HA Historico de evolucao:
*     Vers�o  Autor    Data     Observacoes
*     Y       afv   xx/xx/2013  finalizacao do desenvolvimento do modulo
*     1       afv   19/out/2013 inicio do desenvolvimento do modulo
*
*  $ED Descri��o do m�dulo
*     Implementa listas gen�ricas duplamente encadeadas.
*     Podem existir n listas em opera��o simultaneamente.
*     As listas possuem uma cabe�a encapsulando o seu estado.
*
*     Cada lista � homog�nea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que cont�m.
*
*     Os ponteiros para os dados s�o copiados para elementos da lista.
*     N�o � copiado o valor apontado por estes ponteiros.
*
*     O controle da destrui��o do valor de um elemento a ser exclu�do
*     � realizado por uma fun��o fornecida pelo usu�rio do m�dulo.
*
*     Cada lista referencia uma fun��o que determina como devem ser
*     desalocados os dados nela contidos.
*
*     A fun��o de libera��o dos valores contidos nos elementos deve
*     assegurar a libera��o de todos os espa�os referenciados pelo
*     valor contido em um elemento.
*     Esta fun��o � chamada antes de se desalocar um elemento
*     de uma lista.
*     Caso n�o seja necess�rio desalocar o valor referenciado pelo
*     elemento, o ponteiro para a fun��o de libera��o poder� ser NULL .
*     Caso o elemento da lista seja a �nica �ncora do valor referenciado,
*     esta fun��o deve promover a destrui��o (free) desse valor e
*     de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( LISTA_OWN )
   #define LISTA_EXT
#else
   #define LISTA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         LIS_CondRetOK = 0,
               /* Concluiu corretamente */

         LIS_CondRetListaVazia = 1 ,
               /* A lista n�o cont�m elementos */

         LIS_CondRetFimLista = 2,
               /* Foi atingido o fim de lista */

         LIS_CondRetNaoAchou = 3,
               /* N�o encontrou o valor procurado */

         LIS_CondRetFaltouMemoria = 9
               /* Faltou mem�ria ao tentar criar um elemento de lista ou uma lista */

   } LIS_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Criar lista
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
*     LIS_CondRetFaltouMemoria - N�o conseguiu criar a lista.
*     LIS_CondRetOK - Conseguiu criar a lista com sucesso.
*
***********************************************************************/

   LIS_tpCondRet LIS_CriarLista(
             void   ( * ExcluirValor ) ( void * pDado ) , LIS_tppLista * pLista ) ;

/***********************************************************************
*
*  $FC Fun��o: LIS  &Destruir lista
*
*  $ED Descri��o da fun��o
*     Destr�i a lista fornecida.
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     Inicialmente a lista torna-se vazia para depois a libera��o.
*     *N�o existe previs�o para poss�veis falhas de execu��o.
*
*  $FV Valor retornado
*     LIS_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   LIS_tpCondRet LIS_DestruirLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Esvaziar lista
*
*  $ED Descri��o da fun��o
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a ser esvaziada.
*     A lista fornecida n�o dever� esta vazia.
*
*  $FV Valor retornado
*     LIS_CondRetOK - Elementos eliminados com sucesso.
*
***********************************************************************/

   LIS_tpCondRet LIS_EsvaziarLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Inserir elemento antes
*
*  $ED Descri��o da fun��o
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento, tipo definido 
               pelo usu�rio.
*              Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK - Se conseguiu inserir o elemento corretamente.
*     LIS_CondRetFaltouMemoria - Elemento n�o foi inserido.
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista ,
                                           void * pValor        ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Inserir elemento ap�s
*
*  $ED Descri��o da fun��o
*     Insere novo elemento ap�s o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     Par�metros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento, tipo definido 
*                 pelo usu�rio.
*                 Pode ser NULL
*           
*
*  $FV Valor retornado
*        LIS_CondRetOK - Se conseguiu inserir o elemento corretamente.
*        LIS_CondRetFaltouMemoria - Elemento n�o foi inserido.
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista ,
                                          void * pValor        ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Excluir elemento
*
*  $ED Descri��o da fun��o
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento � esquerda do corrente, este ser� o novo corrente.
*     Se n�o existir e existir o elemento � direita, este se tornar� corrente.
*     Se este tamb�m n�o existir a lista tornou-se vazia.
*
*  $EP Par�metros
*     pLista    - Ponteiro para a lista na qual deve excluir o corrente.
*
*  $FV Valor retornado
*     LIS_CondRetOK - Se o elemento foi exclu�do com sucesso.
*     LIS_CondRetListaVazia - Se a lista est� vazia.
*     LIS_CondRetFaltouMemoria - Se n�o conseguiu excluir o elemento.
*
***********************************************************************/

   LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Obter refer�ncia para o valor contido no elemento
*
*  $ED Descri��o da fun��o
*     Obtem a refer�ncia para o valor contido no elemento corrente da lista
*
*  $EP Par�metros
*     pLista      - Ponteiro para a lista onde est� o corrente.
*     pContListaM - Ponteiro ao qual ser� atribu�do o valor a ser retornado.
*
*  $FV Valor retornado
*     LIS_CondRetOK           - Se o elemento corrente da lista existe, retorna.
*     LIS_CondRetListaVazia   - Se a lista estiver vazia, n�o � poss�vel retornar valor.
*
***********************************************************************/

  LIS_tpCondRet LIS_ObterValor( LIS_tppLista pLista , void **pContListaM ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Ir para o elemento inicial
*
*  $ED Descri��o da fun��o
*     Torna corrente o primeiro elemento da lista.
*     Faz nada se a lista est� vazia.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a manipular.
*
*  $FV Valor retornado
*     LIS_CondRetOK - Foi ao in�cio da lista.
*
***********************************************************************/

   LIS_tpCondRet LIS_IrInicioLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Ir para o elemento final
*
*  $ED Descri��o da fun��o
*     Torna corrente o elemento final da lista.
*     Faz nada se a lista est� vazia.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a manipular
*
*  $FV Valor retornado
*     LIS_CondRetOK - Foi ao final da lista.
*
***********************************************************************/

   LIS_tpCondRet LIS_IrFinalLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Avan�ar elemento
*
*  $ED Descri��o da fun��o
*     Avan�a o elemento corrente numElem elementos na lista
*     Se numElem for positivo avan�a em dire��o ao final
*     Se numElem for negativo avan�a em dire��o ao in�cio
*     numElem pode ser maior do que o n�mero de elementos existentes na
*     dire��o desejada
*     Se numElem for zero somente verifica se a lista est� vazia
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista a ser manipulada
*     numElem - o n�mero de elementos a andar
*
*  $FV Valor retornado
*     CondRetOK         - Se numElem elementos tiverem sido andados
*     CondRetFimLista   - Se encontrou o fim da lista antes de andar numElem
*                         elementos
*     CondRetListaVazia - Se a lista est� vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,
                                              int numElem ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Procurar elemento contendo valor
*
*  $ED Descri��o da fun��o
*     Procura o elemento que referencia o valor dado.
*     A fun��o compara ponteiro e n�o conte�do apontado com a fun��o do usu�rio.
*
*  $EP Par�metros
*     pLista       - Ponteiro para a lista onde procura.
*     pValor       - Ponteiro para o valor procurado;
*                    Pode ser NULL.
*     ComparaValor - Ponteiro para funcao de comparacao
*                    de valores encontrados e procurados
*
*  $FV Valor retornado
*     LIS_CondRetOK  - Se encontrou;
*                      O elemento corrente � o elemento encontrado.
*
*     LIS_CondRetNaoAchou     - Se o ponteiro n�o foi encontrado.
*                               O elemento corrente continua o mesmo.
*     LIS_CondRetListaVazia   - Se a lista estiver vazia.
*
***********************************************************************/

   LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,
                                    void * pValor ,
                                    int ( * ComparaValor ) ( void * pValorCorr , void * pValorBuscado ) ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Checa se a origem � nula
*
*  $ED Descri��o da fun��o
*     Faz uma verifica��o se o ponteiro para origem da lista � NULL.
*     Com isso a lista est� vazia.
*
*  $EP Par�metros
*     pLista       - Ponteiro para a lista.
*
*  $FV Valor retornado
*     LIS_CondRetOK           - Se existe elemento na lista.
*     LIS_CondRetListaVazia   - Se a lista estiver vazia e Origem � NULL.
*
***********************************************************************/

LIS_tpCondRet LIS_ChecaOrigemNulo(LIS_tppLista pLista) ;

/***********************************************************************
*
*  $FC Fun��o: LIS  &Retorna quantidade de elementos
*
*  $ED Descri��o da fun��o
*     Retorna o numero de elementos presentes na lista.
*
*  $EP Par�metros
*     pLista       - Ponteiro para a lista.
*
*  $FV Valor retornado
*     &numElem     - com o valor de pLista->numElem
*
***********************************************************************/

LIS_tpCondRet LIS_NumElem( LIS_tppLista pLista , int * numElem );

#undef LISTA_EXT

/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif
