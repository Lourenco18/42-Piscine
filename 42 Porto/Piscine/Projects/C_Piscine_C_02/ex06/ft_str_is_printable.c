/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:30:31 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/13 13:04:55 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] >= 126)
		{
			return (0);
			i++;
		}
	}
	return (1);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_str_is_printable("Hello, World!")); // 1
    printf("%d\n", ft_str_is_printable("Hello\tWorld!"));   // 0
    printf("%d\n", ft_str_is_printable("Hello\0World!"));   // 0
    printf("%d\n", ft_str_is_printable(""));                             // 1
    return 0;
}
*/
