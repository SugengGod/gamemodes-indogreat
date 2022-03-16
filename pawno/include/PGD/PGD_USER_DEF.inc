/*
*
*	-= PGD DEFINIÇÃO DO USUÁRIO =-
*	Protioso Gerenciamento de Dados
*	Autor: Protioso ([VGS]Protioso_OC)
*   Obs.: Os valores deste arquivo podem ser editados!
*
*/

//      Definições para formato FILE ------------------------------------------|
#define MAX_CHAVE_CHAR 64
/*
* Isto define o tamanho máximo de uma chave.
------------------------------------------------------------------------------*/
#define MAX_VALOR_CHAR 256
/*
* Isto define o tamanho máximo de um valor
* que será contido em uma chave.
------------------------------------------------------------------------------*/
#define MAX_PGD_LINHA_CHAR 512
/*
* Isto define o tamanho máximo de leitura e
* escrita de uma linha em um arquivo.
* Obs.: Usado na função pgd_EscreverArquivo.
------------------------------------------------------------------------------*/
//      Definições para formato SQLite ----------------------------------------|
#define MAX_PGD_SQLITE_GERAL 256
/*
* Isto define o tamanho máximo do formato de
* funções gerais de SQLite do PGD, como query's por exemplo.
------------------------------------------------------------------------------*/
#define MAX_PGD_SQLITE_QUERY_LIVRE 512
/*
* Isto define o tamanho máximo do formato da
* query da função pgd_SQLInserirLivre.
------------------------------------------------------------------------------*/
