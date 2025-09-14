/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:02:50 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 10:03:05 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

static void print_error(char *name)
{
    char *msg = strerror(errno);
    write(2, name, strlen(name));
    write(2, ": ", 2);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
}

static long get_file_size(int fd)
{
    off_t off = lseek(fd, 0, SEEK_END);
    if (off == (off_t)-1) return -1;
    return (long)off;
}

int main(int argc, char **argv)
{
    int i = 1;
    long c = 0;
    int fd;
    char *endptr;
    char *buf;
    long size;
    ssize_t r;

    if (argc < 3)
    {
        write(2, "Usage: ./ft_tail -c N file...\n", 30);
        return 1;
    }
    if (strcmp(argv[1], "-c") != 0)
    {
        write(2, "Only -c option supported\n", 25);
        return 1;
    }
    c = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || c < 0)
    {
        write(2, "Invalid number\n", 15);
        return 1;
    }
    for (i = 3; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0) { print_error(argv[i]); continue; }
        size = get_file_size(fd);
        if (size < 0) { print_error(argv[i]); close(fd); continue; }
        if (c > size) c = size;
        if (lseek(fd, -c, SEEK_END) == (off_t)-1) { print_error(argv[i]); close(fd); continue; }
        buf = (char *)malloc(c);
        if (!buf) { close(fd); return 1; }
        r = read(fd, buf, c);
        if (r > 0) write(1, buf, r);
        free(buf);
        close(fd);
    }
    return 0;
}
