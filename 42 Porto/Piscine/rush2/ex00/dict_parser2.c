/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:22:33 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/14 18:22:57 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	append_dict_node(t_dict **dict, t_dict **last, t_dict *new_node)
{
	if (!*dict)
		*dict = new_node;
	else
		(*last)->next = new_node;
	*last = new_node;
}

int	handle_parse_line(char *content, int *i, t_dict **dict, t_dict **last)
{
	char	key[64];
	char	value[256];
	t_dict	*new_node;

	if (extract_key_value(content, i, key, value))
	{
		new_node = create_dict_node(key, value);
		if (!new_node)
			return (0);
		append_dict_node(dict, last, new_node);
	}
	else
	{
		while (content[*i] && content[*i] != '\n')
			(*i)++;
		if (content[*i] == '\n')
			(*i)++;
	}
	return (1);
}

t_dict	*parse_dict(char *filename)
{
	char	*content;
	int		i;
	t_dict	*dict;
	t_dict	*last;

	content = read_file(filename);
	if (!content)
		return (NULL);
	i = 0;
	dict = NULL;
	last = NULL;
	while (content[i])
	{
		if (!handle_parse_line(content, &i, &dict, &last))
		{
			free_dict(dict);
			free(content);
			return (NULL);
		}
	}
	free(content);
	return (dict);
}
