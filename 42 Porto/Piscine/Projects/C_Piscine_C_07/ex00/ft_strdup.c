/* ft_strdup.c */
#include <stdlib.h>

static int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(char *src)
{
    int len;
    char *res;
    int i;

    len = ft_strlen(src);
    res = (char *)malloc(len + 1);
    if (!res)
        return (0);
    i = 0;
    while (i < len)
    {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}
