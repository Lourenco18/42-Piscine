/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:14:39 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/04 17:56:09 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_alpha(char *str);

/*
int	main(void)
{
	printf("ola: %d\n", ft_str_is_alpha("ola"));
	printf("AmaNHA: %d\n", ft_str_is_alpha("AmaNHA"));
	printf("Hello!: %d\n", ft_str_is_alpha("Hello!"));
	printf(" : %d\n", ft_str_is_alpha(" "));
	printf("\\n: %d\n", ft_str_is_alpha("\n"));
	return (0);
}
*/

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}
