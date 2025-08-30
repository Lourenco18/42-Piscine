#include <unistd.h>

void ft_putstr_non_printable(char *str)
{
    int i = 0;
    char hex_digits[] = "0123456789abcdef";

    while (str[i] != '\0')
    {
        if (str[i] < 32 || str[i] == 127)
        {
            char c = (unsigned char)str[i];
            write(1, "\\", 1);
            write(1, &hex_digits[c / 16], 1); 
            write(1, &hex_digits[c % 16], 1); 
        }
        else
        {
            write(1, &str[i], 1);
        }
        i++;
    }
}
/*
int main(void)
{
    char str[] = "Ola\nesta bem?\tFim\x7f";

    ft_putstr_non_printable(str);
    write(1, "\n", 1);
    return 0;
}
    */
