/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: x <xxxx@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:23:05 by xxxx          #+#    #+#             */
/*   Updated: 2025/09/15 19:23:05 by xxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_range.c */
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *arr;
    int size;
    int i;

    if (min >= max)
        return (0);
    size = max - min;
    arr = (int *)malloc(size * sizeof(int));
    if (!arr)
        return (0);
    i = 0;
    while (i < size)
    {
        arr[i] = min + i;
        i++;
    }
    return (arr);
}
