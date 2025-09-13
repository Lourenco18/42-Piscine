/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:51:06 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/13 13:05:50 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char src[] = "42 porto";
    char dest[50];

    ft_strcpy(dest, src);
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    return (0);
}
    */
