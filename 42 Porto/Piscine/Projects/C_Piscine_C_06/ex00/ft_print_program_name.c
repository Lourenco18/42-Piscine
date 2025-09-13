/* ft_print_program_name.c */
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
