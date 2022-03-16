/*
*
*	-= PGD DEFINIÇÃO PADRÃO PARA FUNÇÕES INICIAIS =-
*	Protioso Gerenciamento de Dados
*	Autor: Protioso ([VGS]Protioso_OC)
*
*/

#include "a_samp"
//      PSF
#include "PSF"

//      Definição do usuário
#include "PGD\PGD_USER_DEF"

//      Arquivos base
#include "PGD\1.3F2#PGD_LIB\#PGD_File\#FILE-PGD_B\FILE-PGD_DI.&1"
#include "PGD\1.3F2#PGD_LIB\#PGD_File\#FILE-PGD_B\FILE-PGD.&B"
#include "PGD\1.3F2#PGD_LIB\#PGD_File\#FILE-PGD_B\FILE-PGD_B.&1"
#include "PGD\1.3F2#PGD_LIB\#PGD_SQLite\#SQLITE-PGD_B\SQLite-PGD.&B"
#include "PGD\1.3F2#PGD_LIB\#PGD_SQLite\#SQLITE-PGD_B\SQLite-PGD_B.&1"

//      Arquivos para formulação
#include "PGD\1.3F2#PGD_LIB\#PGD_File\#FILE-PGD_F\FILE-PGD_F.&F"
#include "PGD\1.3F2#PGD_LIB\#PGD_File\#FILE-PGD_F\#FILE-PGD_ESCRITA\FILE-PGD_E.&FP"
#include "PGD\1.3F2#PGD_LIB\#PGD_File\#FILE-PGD_F\#FILE-PGD_LEITURA\FILE-PGD_L.&FP"
#include "PGD\1.3F2#PGD_LIB\#PGD_SQLite\#SQLITE-PGD_F\SQLite-PGD_F.&F"
#include "PGD\1.3F2#PGD_LIB\#PGD_SQLite\#SQLITE-PGD_F\#SQLITE-PGD_ESCRITA\SQLite-PGD_E.&FP"
#include "PGD\1.3F2#PGD_LIB\#PGD_SQLite\#SQLITE-PGD_F\#SQLITE-PGD_LEITURA\SQLite-PGD_L.&FP"
//-----------------------------------------------------------------------------|

//      File
stock pgd_EscreverStr(arquivo[], chave[], prefixo[2] = ":", valor[]) return pgd_EscreverChave(arquivo, chave, valor, prefixo);
stock pgd_EscreverInt(arquivo[], chave[], prefixo[2] = ":", valor) return pgd_EscreverChave(arquivo, chave, psf_IntStr(valor), prefixo);
stock pgd_EscreverFloat(arquivo[], chave[], prefixo[2] = ":", Float:valor) return pgd_EscreverChave(arquivo, chave, psf_FloatStr(valor), prefixo);
stock pgd_EscreverBool(arquivo[], chave[], prefixo[2] = ":", bool:valor) return (valor) ? pgd_EscreverChave(arquivo, chave, "1", prefixo) : pgd_EscreverChave(arquivo, chave, "0", prefixo);

stock pgd_CarregarInt(arquivo[], chave[], prefixo[2] = ":") return strval(pgd_CarregarChave(arquivo, chave, prefixo));
stock bool:pgd_CarregarBool(arquivo[], chave[], prefixo[2] = ":") return (strval(pgd_CarregarChave(arquivo, chave, prefixo))) ? true : false;
stock Float:pgd_CarregarFloat(arquivo[], chave[], prefixo[2] = ":") return floatstr(pgd_CarregarChave(arquivo, chave, prefixo));

stock pgd_ChaveExiste(arquivo[], chave[], prefixo[2] = ":")
{
	if(strlen(chave) > MAX_CHAVE_CHAR)
	{
		printf("[PGD]: Checar chave - chave '%s' excedeu o limite de caracteres definido (MAX %d)!", chave, MAX_CHAVE_CHAR);
		return 0;
	}
	if(pgd_ArquivoExiste(arquivo))
	{
		new
			str[MAX_PGD_CHAR],
			strbusca[MAX_PGD_CHAR],
			File:ArqM;

        pgd_FormatarCP(strbusca, chave, prefixo);
		ArqM = fopen(arquivo, io_read);
		while(fread(ArqM, str, sizeof(str), false))
		{
			if(pgd_VerificarLinha(str, strbusca))
			{
				fclose(ArqM);
				return 1;
			}
		}
		fclose(ArqM);
	}
	return 0;
}

stock pgd_CopiarDados(arquivo_principal[], arquivo_destino[], bool:ad_a = true)
{
	if(pgd_ArquivoExiste(arquivo_principal))
	{
		new
			str[MAX_PGD_LINHA_CHAR],
			File:ArqP,
			File:ArqD;

	    if(!pgd_ArquivoExiste(arquivo_destino)) pgd_CriarArquivo(arquivo_destino);
	    ArqP = fopen(arquivo_principal, io_read);
	    if(!ad_a) ArqD = fopen(arquivo_destino, io_append);
	    else
		{
			ArqD = fopen(arquivo_destino, io_write);
			fwrite(ArqD, "");
			fclose(ArqD);
			ArqD = fopen(arquivo_destino, io_append);
		}
		while(fread(ArqP, str, sizeof(str), false))	fwrite(ArqD, str);
		fclose(ArqP);
		fclose(ArqD);
		return 1;
	}
	return 0;
}

stock pgd_RenomearArquivo(nome_antigo[], novo_nome[])
{
	if(!pgd_ArquivoExiste(nome_antigo) || pgd_ArquivoExiste(novo_nome)) return 0;
	pgd_CriarArquivo(novo_nome);
	pgd_CopiarDados(nome_antigo, novo_nome);
	pgd_ApagarArquivo(nome_antigo);
	return 1;
}

//      SQLite
stock pgd_SQLInserirStr(dbnome[], tabela_nome[], coluna[], dados[]) _PGD_SQLINSERIRSTR;
stock pgd_SQLInserirInt(dbnome[], tabela_nome[], coluna[], dados) return pgd_SQLInserirDados(dbnome, tabela_nome, coluna, psf_IntStr(dados));
stock pgd_SQLInserirFloat(dbnome[], tabela_nome[], coluna[], Float:dados) return pgd_SQLInserirDados(dbnome, tabela_nome, coluna, psf_FloatStr(dados));
stock pgd_SQLInserirBool(dbnome[], tabela_nome[], coluna[], bool:dados) return (dados) ? pgd_SQLInserirDados(dbnome, tabela_nome, coluna, "1") : pgd_SQLInserirDados(dbnome, tabela_nome, coluna, "0");

stock pgd_SQLEscreverInt(dbnome[], tabela_nome[], coluna[], where[], dados) return pgd_SQLEscreverDados(dbnome, tabela_nome, coluna, where, psf_IntStr(dados));
stock pgd_SQLEscreverFloat(dbnome[], tabela_nome[], coluna[], where[], Float:dados) return pgd_SQLEscreverDados(dbnome, tabela_nome, coluna, where, psf_FloatStr(dados));
stock pgd_SQLEscreverBool(dbnome[], tabela_nome[], coluna[], where[], bool:dados) return (dados) ? pgd_SQLEscreverDados(dbnome, tabela_nome, coluna, where, "1") : pgd_SQLEscreverDados(dbnome, tabela_nome, coluna, where, "0");

stock pgd_SQLCarregarInt(dbnome[], tabela[], coluna[], where[]) return strval(pgd_SQLCarregarDados(dbnome, tabela, coluna, where));
stock bool:pgd_SQLCarregarBool(dbnome[], tabela[], coluna[], where[]) return  (strval(pgd_SQLCarregarDados(dbnome, tabela, coluna, where))) ? true : false;
stock Float:pgd_SQLCarregarFloat(dbnome[], tabela[], coluna[], where[]) return floatstr(pgd_SQLCarregarDados(dbnome, tabela, coluna, where));
