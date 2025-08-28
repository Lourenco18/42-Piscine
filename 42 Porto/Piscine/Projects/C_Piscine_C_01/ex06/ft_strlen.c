int	ft_strlen(char *str)
{
	int num = 0;

	while (*str)
	{
		num++;
		str++;
	}
	return num;
}
/*
#include <stdio.h>

int main(void)
{
    char *s = "Piscine";
    printf("Comprimento: %d\n", ft_strlen(s));
    return 0;
}
*/
