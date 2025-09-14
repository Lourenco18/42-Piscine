/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:57:06 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 09:57:26 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

static int  ft_strlen(char *s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return i;
}

static char *ft_strdup(const char *s)
{
    int len = ft_strlen((char *)s);
    char *d = (char *)malloc(len + 1);
    int i;

    if (!d)
        return NULL;
    i = 0;
    while (i < len)
    {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
    return d;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *arr;
    int i;

    arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
    if (!arr)
        return NULL;
    i = 0;
    while (i < ac)
    {
        arr[i].size = ft_strlen(av[i]);
        arr[i].str = av[i];
        arr[i].copy = ft_strdup(av[i]);
        if (av[i] && arr[i].copy == NULL)
        {
            /* em caso de falha, libertar o que foi alocado */
            int j;
            for (j = 0; j < i; j++)
                free(arr[j].copy);
            free(arr);
            return NULL;
        }
        i++;
    }
    arr[i].str = 0; /* sentinel */
    return arr;
}
