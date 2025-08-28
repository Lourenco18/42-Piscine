/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:39:51 by dasantos          #+#    #+#             */
/*   Updated: 2025/08/28 17:22:12 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str )

{
	int 	i;
	
	i = 0;
	while (str[i])
	{
		char	c;

		c = *str[i];
		write(1, &c, 1);
		i++;
	}
}


int main(void)
{
    ft_putstr("frase para exerccio05");
    return 0;
}

