/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx <xxx@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:33:37 by xxx          #+#    #+#             */
/*   Updated: 2025/08/29 11:35:37 by xxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		num++;
		str++;
	}
	return (num);
}
/*
#include <stdio.h>

int main(void)
{
    char *s = "Piscine";
    printf("Comprimento: %d\n", ft_strlen(s));
    return 0;
}
*/
