/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:38:46 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/14 18:07:44 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

#define BUF_SIZE 4096

char	*read_file(char *filename)
{
	int		fd;
	int		size;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}
	size = read(fd, buffer, BUF_SIZE);
	if (size < 0)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}

t_dict	*create_dict_node(char *key, char *value)
{
	t_dict	*node;

	node = malloc(sizeof(t_dict));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
}

int	extract_key_value(char *str, int *i, char *key, char *value)
{
	int	j;

	j = 0;
	skip_spaces(str, i);
	while (str[*i] && str[*i] != ':' && str[*i] != '\n')
		key[j++] = str[(*i)++];
	key[j] = '\0';
	if (str[*i] != ':')
		return (0);
	(*i)++;
	skip_spaces(str, i);
	j = 0;
	while (str[*i] && str[*i] != '\n')
		value[j++] = str[(*i)++];
	value[j] = '\0';
	while (str[*i] == '\n')
		(*i)++;
	return (1);
}
