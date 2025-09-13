/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:49:52 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/13 15:49:52 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    if (*to_find == '\0')
    {
        return (str);
    }
    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (str[i + j] == to_find[j] && to_find[j] != '\0')
        {
            j++;
        }
        if (to_find[j] == '\0')
        {
            return (&str[i]);
        }
        i++;
    }
    return (0);
}
