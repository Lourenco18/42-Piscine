/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx <xxx@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:22:33 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/17 13:08:00 by xxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h" // Inclui o header com structs e protótipos de funções.

// -------- Função que adiciona um nó à lista ligada do dicionário --------
void	append_dict_node(t_dict **dict, t_dict **last, t_dict *new_node)
{
	if (!*dict)                // Se a lista estiver vazia, o novo nó é o primeiro.
		*dict = new_node;
	else                       // Caso contrário, liga o último nó ao novo.
		(*last)->next = new_node;
	*last = new_node;          // Atualiza ponteiro para o último nó.
}

// -------- Função que processa uma linha do dicionário --------
int	handle_parse_line(char *content, int *i, t_dict **dict, t_dict **last)
{
	char	key[64];           // Buffer para a chave (limite de 64 caracteres).
	char	value[256];        // Buffer para o valor (limite de 256 caracteres).
	t_dict	*new_node;

	if (extract_key_value(content, i, key, value)) // Tenta extrair key/value da linha.
	{
		new_node = create_dict_node(key, value);   // Cria um nó com a key/value.
		if (!new_node)                             // Se falhar a alocação.
			return (0);
		append_dict_node(dict, last, new_node);    // Adiciona o nó à lista ligada.
	}
	else                                         // Se a linha for inválida.
	{
		while (content[*i] && content[*i] != '\n') // Ignora até ao final da linha.
			(*i)++;
		if (content[*i] == '\n')                  // Ignora a nova linha.
			(*i)++;
	}
	return (1);                                  // Retorna 1 se processou a linha corretamente.
}

// -------- Função que lê o dicionário inteiro e cria a lista ligada --------
t_dict	*parse_dict(char *filename)
{
	char	*content;       // Conteúdo completo do ficheiro.
	int		i;               // Índice para percorrer o conteúdo.
	t_dict	*dict;          // Ponteiro para o início da lista ligada.
	t_dict	*last;          // Ponteiro para o último nó da lista.

	content = read_file(filename); // Lê todo o ficheiro.
	if (!content)                  // Se falhar a leitura.
		return (NULL);
	i = 0;
	dict = NULL;
	last = NULL;
	while (content[i])             // Enquanto não chegar ao fim do conteúdo.
	{
		if (!handle_parse_line(content, &i, &dict, &last)) // Processa linha a linha.
		{
			free_dict(dict);       // Liberta lista parcial se houver erro.
			free(content);         // Liberta o buffer de conteúdo.
			return (NULL);
		}
	}
	free(content);                  // Liberta buffer de conteúdo após criar a lista.
	return (dict);                  // Retorna lista ligada completa do dicionário.
}
