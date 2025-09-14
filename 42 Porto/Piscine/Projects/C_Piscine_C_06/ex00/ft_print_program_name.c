/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:52:06 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 21:52:38 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    char *s;
    (void)argc;
    s = argv[0];
    while (*s)
        write(1, s++, 1);
    write(1, "\n", 1);
    return (0);
}
