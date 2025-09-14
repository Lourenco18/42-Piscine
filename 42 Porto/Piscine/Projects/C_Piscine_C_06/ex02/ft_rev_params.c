/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:52:18 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 21:52:38 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void putstrln(char *s)
{
    while (*s)
        write(1, s++, 1);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i;

    i = argc - 1;
    while (i > 0)
    {
        putstrln(argv[i]);
        i--;
    }
    return (0);
}
