/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:25:47 by dasantos          #+#    #+#             */
/*   Updated: 2025/08/30 13:28:15 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>



int main(void)
{
    printf("Result (\"abc\"): %d\n", ft_str_is_uppercase("abc"));      // 0
    printf("Result (\"ABC\"): %d\n", ft_str_is_uppercase("ABC"));      // 1
    printf("Result (\"abc123\"): %d\n", ft_str_is_uppercase("abc123")); // 0
    printf("Result (\"\"): %d\n", ft_str_is_uppercase(""));           // 1
    printf("Result (NULL): %d\n", ft_str_is_uppercase(NULL));         // 1
    return 0;
}
    */
