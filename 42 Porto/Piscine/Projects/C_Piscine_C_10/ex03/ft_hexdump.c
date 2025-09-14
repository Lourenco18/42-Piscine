/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:02:52 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 10:03:05 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define LINelen 16

static void print_hex_offset(unsigned int offset)
{
    char buf[9];
    int i;
    for (i = 8; i--; )
    {
        int nibble = (offset >> (i*4)) & 0xF;
        buf[8-1-i] = "0123456789abcdef"[nibble];
    }
    buf[8] = '\0';
    write(1, buf, 8);
    write(1, "  ", 2);
}

static void print_hex_bytes(unsigned char *b, int n)
{
    int i;
    for (i = 0; i < 16; i++)
    {
        if (i < n)
        {
            char hex[3];
            hex[0] = "0123456789abcdef"[b[i] / 16];
            hex[1] = "0123456789abcdef"[b[i] % 16];
            write(1, hex, 2);
        }
        else
            write(1, "  ", 2);
        if (i % 2) write(1, " ", 1);
    }
}

static void print_ascii(unsigned char *b, int n)
{
    int i;
    write(1, " |", 2);
    for (i = 0; i < n; i++)
    {
        char c = (b[i] >= 32 && b[i] <= 126) ? b[i] : '.';
        write(1, &c, 1);
    }
    write(1, "|\n", 2);
}

int main(int argc, char **argv)
{
    int fd;
    unsigned char buf[LINelen];
    ssize_t r;
    unsigned int offset = 0;

    if (argc == 1)
    {
        fd = 0;
    }
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0) return 1;
    }
    while ((r = read(fd, buf, LINelen)) > 0)
    {
        print_hex_offset(offset);
        print_hex_bytes(buf, (int)r);
        print_ascii(buf, (int)r);
        offset += r;
    }
    if (fd != 0) close(fd);
    return 0;
}
