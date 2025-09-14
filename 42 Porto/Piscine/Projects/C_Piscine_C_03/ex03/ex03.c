/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:49:45 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 19:14:25 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int i;
    unsigned int j;

    i = 0;
    while (dest[i])
    {
        i++;
    }
    j = 0;
    while (src[j] && j < nb)
    {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}
