/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:01:39 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/03 20:54:22 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_numeric(char *str);

/*
int	main(void)
{
	printf("Ol08. Tudo bem?9: %d\n", ft_str_is_numeric("Ol08. Tudo bem?9"));
	printf("4567: %d\n", ft_str_is_numeric("4567"));
	return (0);
}
*/

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
