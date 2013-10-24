
/***************************************************************************
*
*  $MCD M�dulo de defini��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.H
*  Letras identificadoras:      LIS
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