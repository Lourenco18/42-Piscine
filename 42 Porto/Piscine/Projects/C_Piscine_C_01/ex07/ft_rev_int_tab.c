/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx <xxx@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:38:52 by xxx          #+#    #+#             */
/*   Updated: 2025/08/29 11:56:46 by xxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}
/*
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int i;
    ft_rev_int_tab(arr, 5);
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
*/
