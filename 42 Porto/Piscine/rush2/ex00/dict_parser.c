/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:38:46 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/17 13:08:00 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"       // Inclui o header com structs e protótipos de funções.

#define BUF_SIZE 4096      // Define o tamanho do buffer para leitura do ficheiro.

// -------- Função que lê todo o conteúdo de um ficheiro e retorna como string --------
char	*read_file(char *filename)
{
	int		fd;            // Descritor de ficheiro.
	int		size;          // Quantidade de bytes lidos.
	char	*buffer;       // Buffer onde o conteúdo será armazenado.

	fd = open(filename, O_RDONLY);   // Abre ficheiro apenas para leitura.
	if (fd < 0)                      // Se falhar a abrir o ficheiro.
		return (NULL);
	buffer = malloc(sizeof(char) * (BUF_SIZE + 1)); // Aloca buffer.
	if (!buffer)                      // Se malloc falhar.
	{
		close(fd);
		return (NULL);
	}
	size = read(fd, buffer, BUF_SIZE); // Lê até BUF_SIZE bytes do ficheiro.
	if (size < 0)                      // Se ocorrer erro durante a leitura.
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[size] = '\0';               // Termina string com '\0'.
	close(fd);                          // Fecha o ficheiro.
	return (buffer);                    // Retorna conteúdo lido.
}

// -------- Função que cria um nó do dicionário com key e value --------
t_dict	*create_dict_node(char *key, char *value)
{
	t_dict	*node;

	node = malloc(sizeof(t_dict));     // Aloca memória para o nó.
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);        // Duplica a chave.
	node->value = ft_strdup(value);    // Duplica o valor.
	node->next = NULL;                 // Inicializa ponteiro next como NULL.
	return (node);                     // Retorna o nó criado.
}

// -------- Função auxiliar que ignora espaços e tabs --------
void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t') // Avança índice enquanto houver espaço ou tab.
		(*i)++;
}

// -------- Função que extrai key e value de uma linha do dicionário --------
int	extract_key_value(char *str, int *i, char *key, char *value)
{
	int	j;

	j = 0;
	skip_spaces(str, i);                  // Ignora espaços no início da linha.
	while (str[*i] && str[*i] != ':' && str[*i] != '\n') // Lê caracteres da chave.
		key[j++] = str[(*i)++];
	key[j] = '\0';                        // Termina chave com '\0'.
	if (str[*i] != ':')                   // Se não houver ':', linha inválida.
		return (0);
	(*i)++;                               // Avança índice para depois dos ':'.
	skip_spaces(str, i);                  // Ignora espaços após ':'.
	j = 0;
	while (str[*i] && str[*i] != '\n')   // Lê caracteres do valor até nova linha.
		value[j++] = str[(*i)++];
	value[j] = '\0';                      // Termina valor com '\0'.
	while (str[*i] == '\n')               // Ignora múltiplas novas linhas.
		(*i)++;
	return (1);                            // Retorna 1 se conseguiu extrair key e value.
}
