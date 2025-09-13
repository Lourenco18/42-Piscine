/* ft_convert_base.c */
#include <stdlib.h>

/* helpers: valid base, index of char in base, atoi_base, itoa_base */

static int base_len(char *b)
{
    int i = 0;
    while (b[i])
        i++;
    return (i);
}

static int base_valid(char *b)
{
    int i, j;
    int len;

    len = base_len(b);
    if (len < 2)
        return (0);
    i = 0;
    while (i < len)
    {
        if (b[i] == '+' || b[i] == '-' || b[i] == ' ' ||
            (b[i] >= 9 && b[i] <= 13))
            return (0);
        j = i + 1;
        while (j < len)
        {
            if (b[i] == b[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

static int idx_in_base(char c, char *b)
{
    int i = 0;
    while (b[i])
    {
        if (b[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

static int ft_atoi_base(char *s, char *base)
{
    int sign = 1;
    int val = 0;
    int idx;

    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    while (*s == '+' || *s == '-')
    {
        if (*s == '-')
            sign = -sign;
        s++;
    }
    while ((idx = idx_in_base(*s, base)) != -1)
    {
        val = val * base_len(base) + idx;
        s++;
    }
    return (val * sign);
}

static char *ft_itoa_base(int nbr, char *base_to)
{
    int base = base_len(base_to);
    long n = nbr;
    char buf[35]; /* suficiente para int em bases pequenas */
    int i = 0;
    int neg = 0;
    char *res;
    int len;

    if (n == 0)
    {
        res = (char *)malloc(2);
        if (!res) return (0);
        res[0] = base_to[0];
        res[1] = '\0';
        return (res);
    }
    if (n < 0)
    {
        neg = 1;
        n = -n;
    }
    while (n > 0)
    {
        buf[i++] = base_to[n % base];
        n /= base;
    }
    if (neg)
        buf[i++] = '-';
    /* reverse */
    len = i;
    res = (char *)malloc(len + 1);
    if (!res) return (0);
    i = 0;
    while (i < len)
    {
        res[i] = buf[len - 1 - i];
        i++;
    }
    res[len] = '\0';
    return (res);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int num;

    if (!base_valid(base_from) || !base_valid(base_to))
        return (0);
    num = ft_atoi_base(nbr, base_from);
    return (ft_itoa_base(num, base_to));
}
