#include <unistd.h>

void ft_print_alphabet(void)
{
    char letter = 'z';
    while (letter >= 'a')
    {
        write(1, &letter, 1);
        letter--;
    }
}

/*
int main(void)
{
    ft_print_alphabet();
    write(1, "\n", 1);
    return 0;
}
*/



