/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:40:09 by dasantos          #+#    #+#             */
/*   Updated: 2025/08/30 13:42:14 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    char str2[] = "hello, world!";
    char str3[] = "12345";
    char str4[] = "";

    printf("Result (\"%s\"): %s\n", str2, ft_strupcase(str2)); 
    printf("Result (\"%s\"): %s\n", str3, ft_strupcase(str3));
    printf("Result (\"%s\"): %s\n", str4, ft_strupcase(str4)); 
    return 0;
}
    */
