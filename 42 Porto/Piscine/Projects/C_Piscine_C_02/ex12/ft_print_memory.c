#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i = 0, j;
    unsigned char *p = (unsigned char *)addr;
    char hex[] = "0123456789abcdef";

    while (i < size)
    {
        // 1) Endereço em hexadecimal (16 dígitos)
        unsigned long addr_val = (unsigned long)(p + i);
        char buffer[16];
        for (j = 0; j < 16; j++)
        {
            buffer[15 - j] = hex[addr_val % 16];
            addr_val /= 16;
        }
        write(1, buffer, 16);
        write(1, ": ", 2);

        // 2) Conteúdo em hexadecimal (16 bytes por linha)
        for (j = 0; j < 16; j++)
        {
            if (i + j < size)
            {
                unsigned char c = p[i + j];
                char b[2];
                b[0] = hex[c / 16];
                b[1] = hex[c % 16];
                write(1, b, 2);
            }
            else
                write(1, "  ", 2);

            if (j % 2 == 1)
                write(1, " ", 1);
        }

        // 3) Conteúdo em ASCII
        for (j = 0; j < 16 && i + j < size; j++)
        {
            unsigned char c = p[i + j];
            if (c >= 32 && c <= 126)
                write(1, &c, 1);
            else
                write(1, ".", 1);
        }

        write(1, "\n", 1);
        i += 16;
    }

    return addr;
}

int main(void)
{
    char str[] = "memoria";
    ft_print_memory(str, sizeof(str));
    return 0;
}

