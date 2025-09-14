/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:02:07 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 10:03:05 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 4096

static void putstr_err(char *s)
{
    while (*s)
        write(2, s++, 1);
}

int main(int argc, char **argv)
{
    int fd;
    ssize_t r;
    char buf[BUF_SIZE];

    if (argc == 1)
    {
        putstr_err("File name missing.\n");
        return 1;
    }
    if (argc > 2)
    {
        putstr_err("Too many arguments.\n");
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        putstr_err("Cannot read file.\n");
        return 1;
    }
    while ((r = read(fd, buf, BUF_SIZE)) > 0)
        write(1, buf, r);
    close(fd);
    return 0;
}
