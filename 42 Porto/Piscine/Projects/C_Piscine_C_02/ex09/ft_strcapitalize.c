char *ft_strcapitalize(char *str)
{
    int i = 0;
    int new_w = 1; 

    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || 
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9'))
        {
            if (new_w) // se for a primeira letra da palavra
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] -= 32; // transforma em maiúscula
                new_w = 0;
            }
            else // se for o resto da palavra
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] += 32; // transforma em minúscula 
            }
        }
        else
        {
            new_w = 1; // quando é um espaço
        }
        i++;
    }
    return str;
}

/*
#include <stdio.h>

int main(void)
{
    char str2[] = "hello, world!";
    char str3[] = "12345";
    char str4[] = "";

    printf("Result (\"%s\"): %s\n", str2, ft_strcapitalize(str2)); 
    printf("Result (\"%s\"): %s\n", str3, ft_strcapitalize(str3));
    printf("Result (\"%s\"): %s\n", str4, ft_strcapitalize(str4)); 
    return 0;
}
    */

