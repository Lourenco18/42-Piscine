/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:58:33 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/14 17:58:39 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*find_in_dict(unsigned int key, t_dict *dict)
{
	t_dict			*current;
	unsigned int	dict_key;

	current = dict;
	while (current)
	{
		dict_key = (unsigned int)ft_atoi(current->key);
		if (dict_key == key)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

char	*convert_scale(unsigned int nb, unsigned int scale, t_dict *dict)
{
	char	*left;
	char	*scale_word;
	char	*remaining;
	char	*result;
	char	*temp;

	left = convert_number(nb / scale, dict);
	scale_word = find_in_dict(scale, dict);
	result = join_strings(left, scale_word);
	free(left);
	if (nb % scale == 0)
		return (result);
	remaining = convert_number(nb % scale, dict);
	temp = join_strings(result, remaining);
	free(result);
	free(remaining);
	return (temp);
}

char	*convert_hundreds(unsigned int nb, t_dict *dict)
{
	char	*temp;
	char	*hundred_word;
	char	*remaining;
	char	*result;

	temp = convert_number(nb / 100, dict);
	hundred_word = find_in_dict(100, dict);
	result = join_strings(temp, hundred_word);
	free(temp);
	if (nb % 100 == 0)
		return (result);
	remaining = convert_number(nb % 100, dict);
	temp = join_strings(result, remaining);
	free(result);
	free(remaining);
	return (temp);
}

char	*convert_tens(unsigned int nb, t_dict *dict)
{
	char	*temp;
	char	*result;

	temp = find_in_dict((nb / 10) * 10, dict);
	if (nb % 10 == 0)
		return (ft_strdup(temp));
	result = join_strings(temp, convert_number(nb % 10, dict));
	return (result);
}
