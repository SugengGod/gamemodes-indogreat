/*
*
*	-= PSF INCLUDE =-
*	Protioso String Funções
*
*	Autor: Protioso ([VGS]Protioso_OC)
*  	Primeira versão: 12 de abril de 2009 - 1.0
* 	Atualizações: 12 de junho de 2009 - 1.1
* 				  13 de junho de 2009 - 1.2
*                 10 de novembro de 2009 - 1.2F2
*                 4 de dezembro de 2009 - 1.2F3 (1.2 formulação 3 - versão em uso)
*
*/

#include "PSF\1.2F3#PSF_LIB\PSF_DPPFI"

/*Lista de funções PSF -----------------------------------------------------------------------------||

native psf_PCODStr(str[], taxa = TAXA_MEDIANA);
native psf_PCODNumero(numeral);
native psf_CopiarStr(str_recebe[], str_origem[]);
native psf_CopiarStrL(str_recebe[], str_origem[], pos_inicial_origem, pos_final_origem);
native psf_ParteExiste(str[], parte[]);
native psf_CharStr(c);
native psf_FloatStr(Float:f);
native psf_IntStr(i);
native psf_CharFiltrado(c[3]);
native psf_Filtrar(str[]);
native psf_ReverterFiltro(str[]);
native psf_SubstituirChar(str[], cs[], ct[], bool:ler_case_sensitive = true);
native psf_ContagemChar(str[], cC[], bool:ler_case_sensitive = true);
native psf_PosChar(str[], cC[], quantia_procurada, bool:ler_case_sensitive = true);
native psf_FormatarStrTexto(str[]);
native psf_LimparStr(str[]);
native psf_strtokCI(str[], casa_inicial, charseparador[] = " ");
native psf_strtokCL(str[], casa_inicial, casa_final, charseparador[] = " ");
native psf_strtok(str[], &casa_inicial, charseparador[] = " ");
native psf_PegarValorEntreCharStr(str[], c[MAX_psf_char_separador], vezesbuscarprimeirochar, vezesbuscarsegundochar);
native psf_PegarValorEntreCharFloat(str[], c[MAX_psf_char_separador], vezesbuscarprimeirochar, vezesbuscarsegundochar);
native psf_PegarValorEntreCharInt(str[], c[MAX_psf_char_separador], vezesbuscarprimeirochar, vezesbuscarsegundochar);
native psf_PegarValorEntreCharBool(str[], c[MAX_psf_char_separador], vezesbuscarprimeirochar, vezesbuscarsegundochar);
native psf_PegarValorStr(str[], pos_inicial, pos_final);
native psf_PegarValorFloat(str[], pos_inicial, pos_final);
native psf_PegarValorInt(str[], pos_inicial, pos_final);
native psf_PegarValorBool(str[], pos_inicial, pos_final);
native psf_StrNumerica(str[]);
native psf_InverterStr(str[256]);

/---------------------------------------------------------------------------------------------------||*/
