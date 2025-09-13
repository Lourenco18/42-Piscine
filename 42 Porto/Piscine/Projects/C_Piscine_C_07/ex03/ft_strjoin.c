/* ft_strjoin.c */
#include <stdlib.h>

static int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;
    int j;
    int tot;
    int seplen;
    char *res;
    char *p;

    if (size == 0)
    {
        res = (char *)malloc(1);
        if (res)
            res[0] = '\0';
        return (res);
    }
    seplen = ft_strlen(sep);
    tot = 0;
    i = 0;
    while (i < size)
    {
        tot += ft_strlen(strs[i]);
        i++;
    }
    tot += seplen * (size - 1);
    res = (char *)malloc(tot + 1);
    if (!res)
        return (0);
    p = res;
    i = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j])
            *p++ = strs[i][j++];
        if (i + 1 < size)
        {
            j = 0;
            while (sep[j])
                *p++ = sep[j++];
        }
        i++;
    }
    *p = '\0';
    return (res);
}
