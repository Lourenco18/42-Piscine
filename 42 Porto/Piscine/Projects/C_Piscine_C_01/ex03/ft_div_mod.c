/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx <xxx@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:14:07 by xxx          #+#    #+#             */
/*   Updated: 2025/08/28 16:14:17 by xxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>

int main(void)
{
    int div, mod;
    ft_div_mod(10, 3, &div, &mod);
    printf("div = %d, mod = %d\n", div, mod);
    return 0;
}
*/
