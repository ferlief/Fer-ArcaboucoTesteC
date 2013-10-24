/***************************************************************************
*  $MCI M�dulo de implementa��o: PART PARTIDA
*
*  Arquivo gerado:              PRINCIPAL.C
*  Letras identificadoras:      PRI
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
*     1       afv   11/nov/2013 in�cio desenvolvimento
*
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//#include "GRAFO.H"
//#include "TABULEIRO.H"
//#include "PECA.H"

/************  Prot�tipo das fun��es encapsuladas no m�dulo  *************/


/************* Fun��o respons�vel pela execu��o da aplica��o ***************/

int main (void){
	int val;
	char tecla;
	printf("\nVERIFICADOR DE XEQUE MATE - AFV\n\n");
	printf("\n_________________________\n\n");
	printf("Informe o n�mero de pe�as por time");

	scanf("%d" , &val);
	printf("O valor informado �: %d\n" , val);

	printf("Pressione qualquer tecla para sair\n");
	scanf("%c" , &tecla);
	if(tecla != 0){
		exit(1);
	}
}


 /************* C�digo das fun��es encapsuladas no m�dulo *****************/