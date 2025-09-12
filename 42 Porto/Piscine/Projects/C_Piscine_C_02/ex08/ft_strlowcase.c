/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:45:02 by dasantos          #+#    #+#             */
/*   Updated: 2025/08/30 13:46:48 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    char str1[] = "HELLO, WORLD!";
    char str2[] = "hello, world!";
 
    char str4[] = "";

    printf("Result (\"%s\"): %s\n", str1, ft_strlowcase(str1)); 
    printf("Result (\"%s\"): %s\n", str2, ft_strlowcase(str2)); 
   
    printf("Result (\"%s\"): %s\n", str4, ft_strlowcase(str4)); 
    return 0;
}
    */
