/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:59:22 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/05 11:04:00 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_printable(char *str);

/*
int	main(void)
{
	printf("02a+CTw]©Š»: %d\n", ft_str_is_printable("02a+CTw]©Š»"));
	printf("02a+CTw]: %d\n", ft_str_is_printable("02a+CTw]"));
	printf("©Š»: %d\n", ft_str_is_printable("©Š»"));
	printf(": %d\n", ft_str_is_printable(""));
	return (0);
}
*/

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}
