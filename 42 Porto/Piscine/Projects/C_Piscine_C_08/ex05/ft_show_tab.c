/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:57:03 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 09:57:26 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

static void ft_putstr(char *s)
{
    while (s && *s)
        write(1, s++, 1);
}

static void ft_putnbr(int n)
{
    char c;
    if (n < 0)
    {
        write(1, "-", 1);
        if (n == -2147483648)
        {
            /* case min int */
            write(1, "2147483648", 10);
            return ;
        }
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}

void ft_show_tab(struct s_stock_str *par)
{
    int i = 0;
    while (par && par[i].str)
    {
        ft_putstr(par[i].str);
        write(1, "\n", 1);
        ft_putnbr(par[i].size);
        write(1, "\n", 1);
        ft_putstr(par[i].copy);
        write(1, "\n", 1);
        i++;
    }
}
