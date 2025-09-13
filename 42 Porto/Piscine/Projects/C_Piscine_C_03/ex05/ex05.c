/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:50:03 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/13 15:50:36 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlen(char *str)
{
    unsigned int i;
2
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int i;
    unsigned int j;
    unsigned int dest_len;
    unsigned int src_len;

    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    if (size <= dest_len)
        return (size + src_len);
    i = dest_len;
    j = 0;
    while (src[j] != '\0' && i + 1 < size)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest_len + src_len);
}
