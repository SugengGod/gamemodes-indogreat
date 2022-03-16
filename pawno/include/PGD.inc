/*
*
*	-= PGD INCLUDE =-
*	Protioso Gerenciamento de Dados
*       				File/SQLite
*
*	Autor: Protioso ([VGS]Protioso_OC)
*  	Primeira versão: 12 de abril de 2009 - 1.0 
* 	Atualizações: 26 de junho de 2009 - 1.1
* 				  12 de julho de 2009 - 1.2
* 				  15 de agosto de 2009 - 1.2F2 (1.2 formulação 2)
* 				  10 de novembro de 2009 - 1.2F3 (1.2 formulação 3)
* 				  13 de novembro de 2009 - 1.3 
* 				  4 de dezembro de 2009 - 1.3F2 (1.3 formulação 2 - versão em uso)
*
*/

#include "PGD\1.3F2#PGD_LIB\PGD_DPPFI"

/*Lista de funções PGD -----------------------------------------------------------------------------||

native pgd_CriarArquivo(nome_arquivo[]);
native pgd_ApagarArquivo(nome_arquivo[]);
native pgd_ArquivoExiste(nome_arquivo[]);
native pgd_EscreverStr(arquivo[], chave[], prefixo[2] = ":", valor[]);
native pgd_EscreverInt(arquivo[], chave[], prefixo[2] = ":", valor);
native pgd_EscreverFloat(arquivo[], chave[], prefixo[2] = ":", Float:valor);
native pgd_EscreverBool(arquivo[], chave[], prefixo[2] = ":", bool:valor);
native pgd_CarregarStr(arquivo[], chave[], prefixo[2] = ":");
native pgd_CarregarInt(arquivo[], chave[], prefixo[2] = ":");
native pgd_CarregarBool(arquivo[], chave[], prefixo[2] = ":");
native pgd_CarregarFloat(arquivo[], chave[], prefixo[2] = ":");
native pgd_ChaveExiste(arquivo[], chave[], prefixo[2] = ":");
native pgd_CopiarDados(arquivo_principal[], arquivo_destino[], bool:ad_a = true);
native pgd_MudarValor(arquivo[], linha, c_linha_nova[]);
native pgd_ApagarChave(arquivo[], chave[], prefixo[2] = ":");
native pgd_ApagarLinha(arquivo[], linha);
native pgd_EscreverArquivo(arquivo[], linha[], bool:comparar_igual = false);
native pgd_RenomearArquivo(nome_antigo[], novo_nome[]);

native pgd_SQLCriarDatabase(dbnome[]);
native pgd_SQLApagarDatabase(dbnome[]);
native pgd_SQLDatabaseExiste(dbnome[]);
native pgd_SQLCriarTabela(dbnome[], tabela_nome[], coluna[]);
native pgd_SQLLimparTabela(dbnome[], tabela_nome[]);
native pgd_SQLVerificarColuna(dbnome[], tabela_nome[], where[]);
native pgd_SQLInserirLivre(dbnome[], tabela_nome[], coluna_str[], dados[]);
native pgd_SQLInserirStr(dbnome[], tabela_nome[], coluna[], dados[]);
native pgd_SQLInserirInt(dbnome[], tabela_nome[], coluna[], dados);
native pgd_SQLInserirFloat(dbnome[], tabela_nome[], coluna[], Float:dados);
native pgd_SQLInserirBool(dbnome[], tabela_nome[], coluna[], bool:dados);
native pgd_SQLEscreverStr(dbnome[], tabela_nome[], coluna[], where[], dados[]);
native pgd_SQLEscreverInt(dbnome[], tabela_nome[], coluna[], where[], dados);
native pgd_SQLEscreverFloat(dbnome[], tabela_nome[], coluna[], where[], Float:dados);
native pgd_SQLEscreverBool(dbnome[], tabela_nome[], coluna[], where[], bool:dados);
native pgd_SQLCarregarStr(dbnome[], tabela[], coluna[], where[]);
native pgd_SQLCarregarInt(dbnome[], tabela[], coluna[], where[]);
native pgd_SQLCarregarBool(dbnome[], tabela[], coluna[], where[]);
native pgd_SQLCarregarFloat(dbnome[], tabela[], coluna[], where[]);
native pgd_SQLValorExiste(dbnome[], tabela[], coluna[], where[]);
native pgd_SQLApagarDados(dbnome[], tabela[], where[]);

/---------------------------------------------------------------------------------------------------||*/
