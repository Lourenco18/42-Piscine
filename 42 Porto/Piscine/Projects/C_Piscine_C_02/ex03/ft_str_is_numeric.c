/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:20:27 by dasantos          #+#    #+#             */
/*   Updated: 2025/08/30 13:23:31 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
/*
#include <stdio.h>



int main(void)
{
    printf("Result (\"12345\"): %d\n", ft_str_is_numeric("12345")); // 1
    printf("Result (\"42porto\"): %d\n", ft_str_is_numeric("42porto")); // 0
    printf("Result (\"\"): %d\n", ft_str_is_numeric("")); // 1
    printf("Result (\"0000\"): %d\n", ft_str_is_numeric("0000")); // 1
    return 0;
}
    */
