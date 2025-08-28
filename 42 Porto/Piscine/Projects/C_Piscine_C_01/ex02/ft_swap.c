/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:03:22 by dasantos          #+#    #+#             */
/*   Updated: 2025/08/28 16:05:56 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
#include <stdio.h>

int main(void)
{
    int x = 1, y = 2;
    printf("Antes: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("Depois: x = %d, y = %d\n", x, y);
    return 0;
}
*/
