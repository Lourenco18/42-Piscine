int ft_str_is_numeric(char *str)
{
    if (!str) // string NULL não conta como vazia
        return 0;

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return 0; // encontrou algo que não é número
        str++;
    }
    return 1; // só tinha números (ou estava vazia)
}


/*
#include <stdio.h>



int main(void)
{
    printf("Result (\"12345\"): %d\n", ft_str_is_numeric("12345")); // 1
    printf("Result (\"42porto\"): %d\n", ft_str_is_numeric("42porto")); // 0
    printf("Result (\"\"): %d\n", ft_str_is_numeric("")); // 1
    printf("Result (\"0000\"): %d\n", ft_str_is_numeric("0000")); // 1
    return 0;
}
    */
