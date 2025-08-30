int ft_str_is_printable(char *str){
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] < 32 || str[i] > 126)
            return 0;
        i++;
    }
    return 1;
}

#include <stdio.h>
/*
int main(void)
{
    printf("Result (\"Hello, World!\"): %d\n", ft_str_is_printable("Hello, World!")); // 1
    printf("Result (\"Hello\tWorld!\"): %d\n", ft_str_is_printable("Hello\tWorld!"));   // 0
    printf("Result (\"Hello\0World!\"): %d\n", ft_str_is_printable("Hello\0World!"));   // 0
    printf("Result (\"\"): %d\n", ft_str_is_printable(""));                             // 1
    return 0;
}*/