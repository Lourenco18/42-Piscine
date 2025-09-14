/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:02:18 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 10:03:05 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 4096

static void print_error(char *filename)
{
    char *msg = strerror(errno);
    write(2, filename, strlen(filename));
    write(2, ": ", 2);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
}

int main(int argc, char **argv)
{
    int i;
    int fd;
    ssize_t r;
    char buf[BUF_SIZE];

    if (argc == 1)
    {
        /* read stdin */
        while ((r = read(0, buf, BUF_SIZE)) > 0)
            write(1, buf, r);
        return 0;
    }
    for (i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            print_error(argv[i]);
            continue;
        }
        while ((r = read(fd, buf, BUF_SIZE)) > 0)
            write(1, buf, r);
        close(fd);
    }
    return 0;
}
