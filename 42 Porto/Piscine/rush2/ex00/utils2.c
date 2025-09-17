/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:49:01 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/14 17:49:27 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_dict(t_dict *dict)
{
	t_dict	*temp;

	while (dict)
	{
		temp = dict;
		dict = dict->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

char	*join_strings(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 2));
	if (!result)
		return (NULL);
	return (copy_join_strings(result, s1, s2, len1));
}

char	*copy_join_strings(char *result, char *s1, char *s2, int len1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[j])
		result[i++] = s1[j++];
	if (len1 > 0 && s2)
		result[i++] = ' ';
	j = 0;
	while (s2 && s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
