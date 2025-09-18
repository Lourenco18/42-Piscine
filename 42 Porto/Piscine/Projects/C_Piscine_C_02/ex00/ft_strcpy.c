/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:12:11 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/03 18:01:39 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strcpy(char *dest, char *src);

/*
int	main(void)
{
	char	src[60];
	char	dest[60];

	ft_strcpy(src, "Keep swimming pls xD");
	printf("The src string is: %s\n", src);
	ft_strcpy(dest, src);
	printf("The dest string is: %s\n", dest);
	return (0);
}
*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
