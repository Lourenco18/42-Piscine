/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:03:34 by dasantos          #+#    #+#             */
/*   Updated: 2025/08/30 13:13:42 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] | 32) >= 'a' && (str[i] | 32 <= 'z')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>



int main(void)
{
    printf("Result (\"abc\"): %d\n", ft_str_is_alpha("abc"));      // 1
    printf("Result (\"ABC\"): %d\n", ft_str_is_alpha("ABC"));      // 1
    printf("Result (\"abc123\"): %d\n", ft_str_is_alpha("abc123")); // 0
    printf("Result (\"\"): %d\n", ft_str_is_alpha(""));           // 1
    printf("Result (NULL): %d\n", ft_str_is_alpha(NULL));         // 1
    return 0;
}
    */
