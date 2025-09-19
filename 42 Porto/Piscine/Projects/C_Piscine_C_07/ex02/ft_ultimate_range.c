/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:23:08 by xxxx          #+#    #+#             */
/*   Updated: 2025/09/15 19:23:08 by xxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_ultimate_range.c */
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int size;
    int *arr;
    int i;

    if (min >= max)
    {
        *range = 0;
        return (0);
    }
    size = max - min;
    arr = (int *)malloc(size * sizeof(int));
    if (!arr)
    {
        *range = 0;
        return (-1);
    }
    i = 0;
    while (i < size)
    {
        arr[i] = min + i;
        i++;
    }
    *range = arr;
    return (size);
}
