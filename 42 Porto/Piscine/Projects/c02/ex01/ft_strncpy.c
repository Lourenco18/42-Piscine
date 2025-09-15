/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:54:49 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/13 13:03:10 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char src[] = "42 portoadsadasdas";
    char dest[50];

    ft_strncpy(dest, src, 10);
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    return (0);
}
    */
