/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:52:24 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 21:52:34 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_strcmp(char *a, char *b)
{
    while (*a && *b && *a == *b)
    {
        a++;
        b++;
    }
    return ((unsigned char)*a - (unsigned char)*b);
}

static void putstrln(char *s)
{
    while (*s)
        write(1, s++, 1);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    char *tmp;

    i = 1;
    while (i < argc)
    {
        j = 1;
        while (j + 1 < argc)
        {
            if (ft_strcmp(argv[j], argv[j + 1]) > 0)
            {
                tmp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        putstrln(argv[i]);
        i++;
    }
    return (0);
}
