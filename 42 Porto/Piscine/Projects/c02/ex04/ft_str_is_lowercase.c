/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:20:00 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/03 21:39:35 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_lowercase(char *str);

/*
int	main(void)
{
	printf("alma: %d\n", ft_str_is_lowercase("alma"));
	printf("f3l1z: %d\n", ft_str_is_lowercase("f3l1z"));
	printf(": %d\n", ft_str_is_lowercase(""));
	return (0);
}
*/

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}
