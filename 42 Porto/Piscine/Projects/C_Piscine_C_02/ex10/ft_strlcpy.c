/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:14:14 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/12 10:17:57 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		if (i < size - 1)
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

#include <stdio.h>
int main(void)
{
    char src[] = "Hello, World!";
    char dest[20];
    unsigned int size = 10;
    unsigned int result;

    result = ft_strlcpy(dest, src, size);
    printf("Copied string: %s\n", dest);
    printf("Result: %u\n", result);
    return 0;
}


