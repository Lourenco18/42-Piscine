/* ************************************************************************** */   // Comentário decorativo gerado automaticamente pelo 42 (estilo de cabeçalho).
/*                                                                            */
/*                                                        :::      ::::::::   */ // Informação sobre o ficheiro (nome).
/*   rush-02.h                                          :+:      :+:    :+:   */ // Nome do ficheiro de header.
+/*                                                    +:+ +:+         +:+     */ // Informação de formatação (estilo 42).
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */ // Autor do ficheiro (nome e email institucional).
/*                                                +#+#+#+#+#+   +#+           */ // Informação de formatação.
/*   Created: 2025/09/14 18:26:24 by dsilva-c          #+#    #+#             */ // Data e hora da criação do ficheiro.
+/*   Updated: 2025/09/14 18:28:26 by dsilva-c         ###   ########.fr       */ // Última atualização do ficheiro.
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H                // "Include guard" → evita que o header seja incluído várias vezes.
# define RUSH_02_H               // Define a macro RUSH_02_H se ainda não tiver sido definida.

# include <unistd.h>             // Biblioteca para funções de baixo nível (ex: write, read).
# include <stdlib.h>             // Biblioteca standard (ex: malloc, free, atoi).
# include <fcntl.h>              // Biblioteca para flags de abertura de ficheiros (ex: open, O_RDONLY).

typedef struct s_dict            // Definição de uma estrutura para o dicionário.
{
	char			*key;        // "key" → chave numérica em formato string (ex: "42").
	char			*value;      // "value" → valor em palavras (ex: "forty-two").
	struct s_dict	*next;       // Ponteiro para o próximo nó (lista ligada).
}	t_dict;                       // Nome do tipo → agora pode-se usar "t_dict" em vez de "struct s_dict".

// --------- Protótipos de funções ---------

t_dict	*parse_dict(char *filename);            // Lê um ficheiro de dicionário e cria lista ligada com key/value.
void	free_dict(t_dict *dict);                // Liberta memória da lista ligada (dicionário).
char	*convert_number(unsigned int nb, t_dict *dict);    // Converte número inteiro em string por extenso.
char	*convert_scale(unsigned int nb, unsigned int scale, t_dict *dict); // Converte parte do número em determinada escala (mil, milhão, etc).
char	*convert_hundreds(unsigned int nb, t_dict *dict);  // Converte centenas em texto.
char	*convert_tens(unsigned int nb, t_dict *dict);      // Converte dezenas e unidades em texto.
char	*find_in_dict(unsigned int key, t_dict *dict);     // Procura chave no dicionário e devolve valor correspondente.
char	*join_strings(char *s1, char *s2);                 // Junta duas strings numa só (com alocação dinâmica).
char	*copy_join_strings(char *result, char *s1, char *s2, int len1); // Função auxiliar para juntar strings.
char	*read_file(char *filename);                        // Lê o conteúdo de um ficheiro e devolve numa string.
t_dict	*create_dict_node(char *key, char *value);         // Cria um nó do dicionário (aloca e inicializa).
void	skip_spaces(char *str, int *i);                    // Avança índice `i` numa string, ignorando espaços.
int		extract_key_value(char *str, int *i, char *key, char *value); // Extrai par key/value de uma linha do ficheiro.
int		ft_strlen(char *str);                              // Implementação própria da função strlen (conta chars).
char	*ft_strdup(char *src);                             // Duplica string (aloca memória nova).
int		ft_atoi(char *str);                                // Converte string para inteiro (versão simplificada).
void	ft_putstr(char *str);                              // Escreve uma string no output (stdout).
int		ft_is_numeric(char *str);                          // Verifica se uma string contém apenas dígitos (0-9).

#endif                                      // Fecha o "include guard" iniciado com #ifndef.
